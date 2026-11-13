#!/usr/bin/env python3
"""
Reproduce the fastbootd getvar crash seen during fuzz_fastbootd.py.
Sends only `getvar <name>` commands. Each payload is written to
repro/ BEFORE it is sent, so any crash can be replayed exactly.
On a crash: recover the device to fastbootd via adb, then resend the
same payload up to 3 times to test reproducibility. Stops after the
first confirmed crash so it can be inspected by hand.
"""
import os
import random
import string
import subprocess
import time
from datetime import datetime

BASE = "/home/claude/repro"
LOG = os.path.join(BASE, "repro.log")
os.makedirs(BASE, exist_ok=True)
ALPHABET = string.ascii_letters + string.digits
MAX_ITER = 60


def log(msg):
    line = f"[{datetime.now().strftime('%H:%M:%S')}] {msg}"
    print(line, flush=True)
    with open(LOG, "a") as f:
        f.write(line + "\n")


def run(args, timeout):
    try:
        r = subprocess.run(args, capture_output=True, text=True, timeout=timeout)
        return r.stdout + r.stderr, r.returncode
    except subprocess.TimeoutExpired:
        return "TIMEOUT", -1


def fastbootd_present():
    out, _ = run(["fastboot", "devices"], 15)
    return "fastbootd" in out or "fastboot" in out


def recover():
    """Wait for the box to come back; if it boots to Android, push it to fastbootd."""
    for _ in range(40):
        if fastbootd_present():
            return True
        out, _ = run(["adb", "devices"], 10)
        if "device" in out and "GUSA2427018764" in out:
            log("device is in Android; rebooting to fastbootd via adb")
            run(["adb", "reboot", "fastboot"], 20)
        time.sleep(5)
    return False


def send(payload, idx):
    """Send one getvar. Returns 'ok', 'crash', or 'other'."""
    out, _ = run(["fastboot", "getvar", payload], 8)
    if "TIMEOUT" in out or out.strip() == "" or "fastboot: error" in out:
        return "crash", out
    if "Unknown variable" in out or "FAILED" in out or "OKAY" in out:
        return "ok", out
    return "other", out


def main():
    if not fastbootd_present():
        log("device not in fastbootd; aborting")
        return
    for i in range(MAX_ITER):
        length = 257 if i == 0 else random.randint(249, 265)
        payload = "".join(random.choices(ALPHABET, k=length))
        path = os.path.join(BASE, f"payload_{i:03d}_len{length}.txt")
        with open(path, "w") as f:
            f.write(payload)
        result, out = send(payload, i)
        log(f"iter {i:03d} len={length} -> {result}  saved={path}  out={out.strip()[:80]!r}")
        if result != "crash":
            continue

        log(f"CRASH SUSPECTED on payload {path}; recovering device")
        if not recover():
            log("device did not return to fastbootd; manual intervention needed")
            return
        log("device back in fastbootd; replaying same payload to test reproducibility")
        repeats = []
        for r in range(3):
            res, out = send(payload, i)
            repeats.append(res)
            log(f"  replay {r + 1}/3 -> {res}  out={out.strip()[:80]!r}")
            if res == "crash":
                if not recover():
                    log("device did not return after replay; stopping")
                    return
        log(f"replay results: {repeats}. Stopping here for manual review.")
        return
    log("no crash in MAX_ITER attempts")


if __name__ == "__main__":
    main()
