#!/usr/bin/env python3
"""
fastbootd fuzzer for onn 4K YOC (S905Y4)
Targets: variable name parsing, partition name parsing, download buffer handling
Run with device in fastbootd mode (adb reboot fastboot)
Logs any response deviating from the standard locked-device error
"""

import subprocess
import random
import string
import struct
import time
import sys
import os
from datetime import datetime

# ── config ──────────────────────────────────────────────────────────────────
FASTBOOT      = "fastboot"   # path to fastboot binary
LOG_FILE      = "fuzz_results.log"
TIMEOUT       = 5            # seconds per command
INTERESTING_KEYWORDS = [     # responses worth flagging
    "okay", "data", "info", "downloading",
    "fault", "crash", "exception", "segfault",
    "unknown", "invalid", "error",           # unexpected errors (not 'locked device')
]
NORMAL_RESPONSE = "locked device"            # expected boring response

# ── helpers ──────────────────────────────────────────────────────────────────
def log(msg, also_print=True):
    ts = datetime.now().strftime("%H:%M:%S.%f")[:-3]
    line = f"[{ts}] {msg}"
    if also_print:
        print(line)
    with open(LOG_FILE, "a") as f:
        f.write(line + "\n")

def run_fastboot(*args, timeout=TIMEOUT):
    """Run fastboot command, return (stdout, stderr, returncode)."""
    try:
        r = subprocess.run(
            [FASTBOOT] + list(args),
            capture_output=True, text=True, timeout=timeout
        )
        return r.stdout, r.stderr, r.returncode
    except subprocess.TimeoutExpired:
        return "", "TIMEOUT", -1
    except Exception as e:
        return "", f"EXCEPTION: {e}", -2

def is_interesting(stdout, stderr):
    """Return True if the response deviates from the normal locked-device reply."""
    combined = (stdout + stderr).lower()
    if NORMAL_RESPONSE in combined:
        return False
    if "timeout" in combined:
        return True          # hangs are interesting
    for kw in INTERESTING_KEYWORDS:
        if kw in combined:
            return True
    return False

def check_device():
    """Confirm fastbootd is reachable before fuzzing."""
    out, err, rc = run_fastboot("devices")
    if not out.strip():
        print("No fastboot device found. Put the box in fastbootd mode first.")
        sys.exit(1)
    log(f"Device found: {out.strip()}")

def report(label, payload_repr, stdout, stderr):
    log(f"*** INTERESTING *** [{label}] payload={payload_repr[:80]}")
    log(f"    stdout: {stdout[:200]}")
    log(f"    stderr: {stderr[:200]}")

# ── fuzz strategies ──────────────────────────────────────────────────────────

def fuzz_getvar_names():
    """Sweep variable name lengths and character classes."""
    log("=== FUZZ: getvar variable names ===")

    # length sweep with random ASCII
    for length in list(range(1, 256, 8)) + list(range(256, 4096, 128)) + [4096, 8192, 65535]:
        payload = ''.join(random.choices(string.ascii_letters + string.digits, k=length))
        out, err, rc = run_fastboot("getvar", payload)
        if is_interesting(out, err):
            report("getvar-length", repr(payload[:64]), out, err)

    # format string probes
    for fmt in ["%s", "%n", "%x", "%p", "%.1000d", "%1000x", "%s%s%s%s%s%s",
                "AAAA%08x.%08x.%08x", "{0}", "{{", "}}"]:
        out, err, rc = run_fastboot("getvar", fmt)
        if is_interesting(out, err):
            report("getvar-fmt", repr(fmt), out, err)

    # null bytes and special chars embedded
    specials = [
        "var\x00injected",
        "var\ninjected",
        "var\rinjected",
        "var/../../../etc/passwd",
        "var" + "\xff" * 32,
        "A" * 63 + "\x00",
    ]
    for s in specials:
        out, err, rc = run_fastboot("getvar", s)
        if is_interesting(out, err):
            report("getvar-special", repr(s), out, err)

    log("=== getvar done ===")


def fuzz_partition_names():
    """Sweep partition name handling in flash/erase/resize commands."""
    log("=== FUZZ: partition names ===")

    commands = ["flash", "erase", "resize-logical-partition",
                "create-logical-partition", "delete-logical-partition"]

    for cmd in commands:
        # length sweep
        for length in list(range(1, 128, 4)) + list(range(128, 2048, 64)) + [2048, 4096]:
            payload = ''.join(random.choices(string.ascii_lowercase, k=length))
            if cmd in ("create-logical-partition", "resize-logical-partition"):
                args = [cmd, payload, "0"]
            elif cmd == "flash":
                args = [cmd, payload, "/dev/null"]
            else:
                args = [cmd, payload]
            out, err, rc = run_fastboot(*args)
            if is_interesting(out, err):
                report(f"{cmd}-length", repr(payload[:64]), out, err)

        # path traversal and special values
        for name in ["../boot_a", "boot_a\x00evil", "A"*255, "boot_a" + "/"*64]:
            if cmd == "flash":
                args = [cmd, name, "/dev/null"]
            elif cmd in ("create-logical-partition", "resize-logical-partition"):
                args = [cmd, name, "0"]
            else:
                args = [cmd, name]
            out, err, rc = run_fastboot(*args)
            if is_interesting(out, err):
                report(f"{cmd}-special", repr(name), out, err)

    log("=== partition names done ===")


def fuzz_oem_commands():
    """Probe OEM command namespace."""
    log("=== FUZZ: oem commands ===")

    # known Amlogic / Google OEM commands to probe
    known = [
        "oem unlock", "oem lock", "oem device-info",
        "oem get-unlock-ability", "oem get_unlock_ability",
        "oem reboot-recovery", "oem reboot-bootloader",
        "oem burnmode", "oem usbdl", "oem usb-dl",
        "oem factoryreset", "oem factory-reset",
        "oem dump", "oem read", "oem write",
        "oem amlogic", "oem aml", "oem s905",
        "oem efuse-read", "oem efuse-write",
        "oem set-fuse", "oem clear-fuse",
    ]
    for cmd in known:
        parts = cmd.split()
        out, err, rc = run_fastboot(*parts)
        combined = (out + err).strip()
        log(f"  {cmd!r:40s} → {combined[:80]}")
        if is_interesting(out, err):
            report("oem-known", cmd, out, err)

    # random OEM subcommand sweep
    for _ in range(200):
        length = random.randint(1, 128)
        subcmd = ''.join(random.choices(string.ascii_lowercase + "-_", k=length))
        out, err, rc = run_fastboot("oem", subcmd)
        if is_interesting(out, err):
            report("oem-random", subcmd, out, err)

    log("=== oem commands done ===")


def fuzz_download_buffer():
    """
    Send oversized / malformed download payloads.
    fastbootd allocates a buffer for the download; probe edge cases.
    """
    log("=== FUZZ: download buffer ===")

    tmp = "/tmp/fuzz_payload.bin"

    # sizes to try: around power-of-2 boundaries and the reported max (128 MB)
    sizes = [
        0,                        # empty
        1,                        # single byte
        64 * 1024 - 1,            # 64 KB - 1
        64 * 1024,
        64 * 1024 + 1,
        1 * 1024 * 1024,          # 1 MB
        128 * 1024 * 1024 - 1,    # just under reported max
        128 * 1024 * 1024,        # exactly reported max
        128 * 1024 * 1024 + 1,    # just over reported max
        256 * 1024 * 1024,        # 2× max
    ]

    for size in sizes:
        # fill with 0xAA pattern to spot partial reads
        try:
            with open(tmp, "wb") as f:
                chunk = b"\xaa" * min(size, 4096)
                written = 0
                while written < size:
                    f.write(chunk[:min(4096, size - written)])
                    written += min(4096, size - written)
        except OSError as e:
            log(f"  skip size {size}: {e}")
            continue

        out, err, rc = run_fastboot("flash", "boot_a", tmp, timeout=30)
        label = f"download-{size}"
        log(f"  size={size:12d}  rc={rc}  err={err.strip()[:60]}")
        if is_interesting(out, err):
            report(label, f"{size} bytes", out, err)

    try:
        os.unlink(tmp)
    except OSError:
        pass

    log("=== download buffer done ===")


def fuzz_concurrent():
    """
    Send multiple fastboot commands in rapid succession without waiting.
    Race conditions in command parsing sometimes surface bugs.
    """
    log("=== FUZZ: rapid-fire / concurrent commands ===")

    procs = []
    cmds = [
        [FASTBOOT, "getvar", "all"],
        [FASTBOOT, "getvar", "A" * 256],
        [FASTBOOT, "oem", "device-info"],
        [FASTBOOT, "flash", "boot_a", "/dev/null"],
        [FASTBOOT, "erase", "userdata"],
    ]

    for _ in range(5):   # 5 rounds of parallel spam
        procs = [subprocess.Popen(cmd, stdout=subprocess.PIPE,
                                  stderr=subprocess.PIPE) for cmd in cmds]
        for p, cmd in zip(procs, cmds):
            try:
                out, err = p.communicate(timeout=TIMEOUT)
                combined = (out.decode(errors="replace") +
                            err.decode(errors="replace"))
                if is_interesting(out.decode(errors="replace"),
                                  err.decode(errors="replace")):
                    report("concurrent", str(cmd), out.decode(errors="replace"),
                           err.decode(errors="replace"))
            except subprocess.TimeoutExpired:
                p.kill()
                log(f"  TIMEOUT on concurrent {cmd}")

    log("=== concurrent done ===")


# ── main ─────────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    print(f"fastbootd fuzzer — logging to {LOG_FILE}")
    print("Make sure the box is in fastbootd mode before continuing.")
    input("Press Enter to start fuzzing...\n")

    check_device()
    log("=== Fuzzing session started ===")

    fuzz_getvar_names()
    fuzz_partition_names()
    fuzz_oem_commands()
    fuzz_download_buffer()
    fuzz_concurrent()

    log("=== Fuzzing session complete ===")
    print(f"\nDone. Check {LOG_FILE} for interesting responses.")
