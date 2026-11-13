#!/usr/bin/env python3
"""
Sweep fastboot download sizes around slab and page boundaries using
`fastboot stage`. stage only uploads data into fastbootd's staging buffer;
it does not write any partition. Detects crashes by checking that the
device is still in fastbootd after each send, then reads the boot reason
over adb. Run with exactly one UART reader started by the caller.
"""
import os
import sys
import time

sys.path.insert(0, "/home/claude")
from repro_getvar import recover, fastbootd_present, log, BASE, run  # noqa: E402

OUT = BASE + "/stage_sweep.log"
SIZES = [1, 64, 255, 256, 257, 300, 511, 512, 513, 1023, 1024, 1025,
         2047, 2048, 2049, 4095, 4096, 4097, 8191, 8192, 8193, 65535, 65536, 65537]
SAFE_DIR = BASE + "/stage"
os.makedirs(SAFE_DIR, exist_ok=True)


def record(line):
    log(line)
    with open(OUT, "a") as f:
        f.write(line + "\n")


def boot_reason_after_crash():
    for _ in range(40):
        adb_out, _ = run(["adb", "devices"], 10)
        if "GUSA2427018764\tdevice" in adb_out:
            out, _ = run(["adb", "shell", "getprop", "sys.boot.reason"], 20)
            return out.strip()
        time.sleep(3)
    return "unknown"


if not fastbootd_present():
    record("device not in fastbootd; aborting")
    sys.exit(1)

for size in SIZES:
    path = f"{SAFE_DIR}/stage_{size}.bin"
    with open(path, "wb") as f:
        f.write(b"\xaa" * size)
    out, rc = run(["fastboot", "stage", path], 30)
    time.sleep(2)
    alive = fastbootd_present()
    verdict = "ok" if alive else "crash"
    msg = out.strip().splitlines()[-1][:90] if out.strip() else ""
    record(f"stage size={size} alive={alive} -> {verdict}  tail={msg!r}")
    if not alive:
        reason = boot_reason_after_crash()
        record(f"  boot reason after crash: {reason}")
        if not recover():
            record("device did not return to fastbootd; stopping")
            break

record("stage sweep done")
