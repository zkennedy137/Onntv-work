#!/usr/bin/env python3
"""
Replay the 254-byte getvar payload until a crash, with UART capture running
separately into repro/uart_live.log. Stops after the first crash so the UART
log can be read around the crash point. Uses helpers from repro_getvar.py.
"""
import sys
import time

sys.path.insert(0, "/home/claude")
from repro_getvar import send, recover, fastbootd_present, log  # noqa: E402

PAYLOAD_FILE = "/home/claude/repro/payload_001_len254.txt"
MAX_TRIES = 10

with open(PAYLOAD_FILE) as f:
    payload = f.read()

if not fastbootd_present():
    log("device not in fastbootd; aborting")
    sys.exit(1)

for n in range(1, MAX_TRIES + 1):
    res, out = send(payload, n)
    log(f"uart-replay try {n}/{MAX_TRIES} -> {res}  out={out.strip()[:80]!r}")
    if res == "crash":
        log("CRASH captured; waiting 10s so UART log has post-crash output")
        time.sleep(10)
        if not recover():
            log("device did not return to fastbootd; stopping")
        else:
            log("device back in fastbootd")
        break
else:
    log("no crash in MAX_TRIES attempts")
