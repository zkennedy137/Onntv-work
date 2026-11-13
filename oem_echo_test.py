#!/usr/bin/env python3
"""
Check whether `fastboot oem <name>` shows the same 250-byte boundary as getvar.
Only oem commands are sent; no erase, flash, or download. Same crash detection
as threshold_v2.py: device still in fastbootd after each send, boot reason
read over adb after a crash.
"""
import random
import string
import sys
import time

sys.path.insert(0, "/home/claude")
from repro_getvar import recover, fastbootd_present, log, BASE, run  # noqa: E402

OUT = BASE + "/oem_echo.log"
ALPHABET = string.ascii_letters + string.digits
PLAN = [249, 250] * 4


def record(line):
    log(line)
    with open(OUT, "a") as f:
        f.write(line + "\n")


def boot_reason():
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

for i, length in enumerate(PLAN):
    name = "".join(random.choices(ALPHABET, k=length))
    out, _ = run(["fastboot", "oem", name], 10)
    time.sleep(2)
    alive = fastbootd_present()
    tail = out.strip().splitlines()[-1][:80] if out.strip() else ""
    verdict = "ok" if alive else "crash"
    record(f"oem {i + 1}/{len(PLAN)} len={length} alive={alive} -> {verdict}  tail={tail!r}")
    if not alive:
        record(f"  boot reason after crash: {boot_reason()}")
        if not recover():
            record("device did not return to fastbootd; stopping")
            break

record("oem echo test done")
