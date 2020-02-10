# nrf52-watch

## Overview

This repo is, at present, a work-in-progress playground for designing and
building a smartwatch based on the nrf52840 microcontroller from Nordic.

## Parts

  * [MS88SF2 nRF52840 Module](https://en.minewtech.com/bluetooth-module/MS88SF2.html)
    * Main brains. nRF52840 chipset chosen for BLE capability and low (&lt;1uA)
      sleep current.
    * Chosen for ease of solderability; other modules have pads that aren't
      accessible from the sides of the module.
  * [Sharp LS013B7DH03 1.28" Memory LCD](https://www.sharpsma.com/products?sharpCategory=Memory%20LCD&p_p_parallel=0&sharpProductRecordId=1504572)
    * Always-on display.
    * Chosen for size and small power consumption.
  * [DS1302 RTC](https://datasheets.maximintegrated.com/en/ds/DS1302.pdf)
    * Realtime clock, for real timekeeping.
    * Chosen for small power consumption and library support.

## Power

  * Project is planned to be powered by a [CR3032 coin cell](https://www.digikey.com/product-detail/en/panasonic-bsg/CR3032/P121-ND/107126),
    which has a nominal capacity of 500mAh at 3V.
  * Projected lifetime is &gt;2mo, though it remains to be seen if this is
    possible

## Software

  Since there isn't code written yet, this section is largely my notepad on
  ideas and framework setup.

  * To conserve power, everything will be interrupts-driven. 
    * This includes a 60Hz toggle for the memory LCD's EXTCOMIN pin
  * PlatformIO doesn't have a builtin for the sparkfun dev board I'm using, so
    the packages/ directory and corresponding lines in platformio.ini are a
    workaround to keep the repository as portable as possible
  * A decent amount of build hackery was needed to make the native version build
    with the dummy adafruit_gfx library

## Credits / Inspiration

  * This project uses open-source code from the following projects. Licenses are
    included alongside code where applicable.
    * [Adafruit](https://github.com/adafruit/Adafruit-GFX-Library)
    * [vhervieux on github](https://github.com/croutor/Adafruit_GFX_dummy_display)
    * [jeraymond on github](https://github.com/jeraymond/pio-sparkfun_pro_nrf52840_mini-setup)
  * This project took inspiration from these projects:
    * [Chronio](https://hackaday.io/project/12876-chronio)
    * [Samson March's Smartwatch](https://imgur.com/a/FSBwD3g)
