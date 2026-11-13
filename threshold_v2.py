#!/usr/bin/env python3
"""
Clean threshold test, v2. Changes from v1:
- Crash detection: after each send, check that the device is still in
  fastbootd. A panic that lands after the reply is caught here.
- Ground truth: after a crash, read sys.boot.reason over adb.
- Runs with exactly one UART reader, started by the caller.
Alternates 249 and 250-byte names, N sends each, logging every result.
"""
import random
import string
import sys
import time

sys.path.insert(0, "/home/claude")
from repro_getvar import send, recover, fastbootd_present, log, BASE, run  # noqa: E402

OUT = BASE + "/threshold_v2.log"
N = 8
PLAN = [249, 250] * N
ALPHABET = string.ascii_letters + string.digits


def record(line):
    log(line)
    with open(OUT, "a") as f:
        f.write(line + "\n")


def boot_reason():
    out, _ = run(["adb", "shell", "getprop", "sys.boot.reason"], 20)
    return out.strip()


if not fastbootd_present():
    record("device not in fastbootd; aborting")
    sys.exit(1)

for i, length in enumerate(PLAN):
    payload = "".join(random.choices(ALPHABET, k=length))
    path = f"{BASE}/t2_{i:02d}_len{length}.txt"
    with open(path, "w") as f:
        f.write(payload)
    res, out = send(payload, i)
    time.sleep(3)
    still_there = fastbootd_present()
    verdict = "crash" if (res == "crash" or not still_there) else "ok"
    record(f"t2 {i + 1}/{len(PLAN)} len={length} send={res} "
           f"still_fastbootd={still_there} -> {verdict}  saved={path}")
    if verdict == "crash":
        reason = "unknown"
        for _ in range(40):  # wait for the box to reach Android and read the reason
            adb_out, _ = run(["adb", "devices"], 10)
            if "GUSA2427018764\tdevice" in adb_out:
                reason = boot_reason()
                break
            time.sleep(3)
        record(f"  boot reason after crash: {reason}")
        if not recover():  # pushes the box back to fastbootd
            record("device did not return to fastbootd; stopping")
            break

record("threshold v2 done")
