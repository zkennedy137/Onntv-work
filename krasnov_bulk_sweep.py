#!/usr/bin/env python3
"""
Krasnov-style check: raw bulk OUT transfers of varying size to the fastboot
interface (ep 0x01). Krasnov's report is a hardened-usercopy abort in
ffs_epfile_io, kmalloc-32 object with a 64-byte copy. Payloads are plain 'A'
bytes (not valid fastboot commands). Crash detection: device still in
fastbootd after each transfer. Boot reason read over adb after a crash.
One UART reader must be started by the caller.
"""
import sys
import time

sys.path.insert(0, "/home/claude")
import usb.core  # noqa: E402
from repro_getvar import recover, fastbootd_present, log, BASE, run  # noqa: E402

OUT = BASE + "/krasnov_bulk.log"
SIZES = [256, 257, 511, 512, 513, 257, 512]  # settle-time test: sizes at the 256/512 boundaries
EP_OUT, EP_IN = 0x01, 0x81


def record(line):
    log(line)
    with open(OUT, "a") as f:
        f.write(line + "\n")


def find_dev():
    return usb.core.find(idVendor=0x18d1, idProduct=0x4ee0)


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

def open_fresh():
    """Look the device up again, since it re-enumerates after every reboot."""
    dev = find_dev()
    if dev is None:
        return None
    # Do not call set_configuration(): on a configured FunctionFS gadget it
    # re-enumerates the device and the handle goes stale (ENODEV).
    try:
        usb.util.claim_interface(dev, 0)
    except usb.core.USBError:
        pass
    return dev


dev = None
for size in SIZES:
    if dev is None:
        dev = open_fresh()  # re-open only after a crash, reuse otherwise
    if dev is None:
        record(f"size={size}: fastboot USB device not found; stopping")
        break
    payload = b"A" * size
    err = ""
    try:
        dev.write(EP_OUT, payload, timeout=2000)
    except usb.core.USBError as e:
        err = f"write:{e}"
    reply = ""
    try:
        data = dev.read(EP_IN, 512, timeout=1000)
        reply = bytes(data).decode(errors="replace")[:60]
    except usb.core.USBError as e:
        reply = f"read:{e}"
    time.sleep(20)  # panics can land late; give the box time before judging
    alive = fastbootd_present()
    verdict = "ok" if alive else "crash"
    record(f"bulk size={size} err={err!r} reply={reply!r} alive={alive} -> {verdict}")
    if not alive:
        record(f"  boot reason after crash: {boot_reason()}")
        dev = None  # force a fresh handle after the reboot
        if not recover():
            record("device did not return to fastbootd; stopping")
            break

record("krasnov bulk sweep done")
