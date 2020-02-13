#!/bin/sh

pio run -e nrf52840 && ./uf2conv.py .pio/build/nrf52840/firmware.hex -c -f 0xADA52840
