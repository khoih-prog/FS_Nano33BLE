# FS_Nano33BLE Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/FS_Nano33BLE.svg?)](https://www.ardu-badge.com/FS_Nano33BLE)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/FS_Nano33BLE.svg)](https://github.com/khoih-prog/FS_Nano33BLE/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/FS_Nano33BLE/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/FS_Nano33BLE.svg)](http://github.com/khoih-prog/FS_Nano33BLE/issues)

---
---

## Table of Contents

* [Changelog](#changelog)
  * [Releases v1.2.1](#releases-v121)
  * [Releases v1.2.0](#releases-v120)
  * [Releases v1.1.0](#releases-v110)
  * [Initial Releases v1.0.0](#initial-releases-v100)

---
---

## Changelog

### Releases v1.2.1

1. Add support to Seeeduino nRF52840-based boards such as **SEEED_XIAO_NRF52840 and SEEED_XIAO_NRF52840_SENSE**, etc. using Seeeduino `mbed` core
2. Add astyle using `allman` style. Restyle the library
3. Display compile warning only when `_FS_LOGLEVEL_ > 3`

### Releases v1.2.0

1. Use correct NANO33BLE_FS_START address without wasting flash space. Check [Half size of flash #2](https://github.com/khoih-prog/FS_Nano33BLE/discussions/2)
2. Enforce min 64KB / max 512KB of flash used for LittleFS by auto-adjusting NANO33BLE_FS_SIZE_KB if defined smaller than 64KB or larger than 512KB
3. Enforce 512KB of flash used for FATFS by auto-adjusting NANO33BLE_FS_SIZE_KB if defined different from 512KB
4. Update all examples

### Releases v1.1.0

1. Fix `multiple-definitions` linker error. Check [Different behaviour using the src_cpp or src_h lib #80](https://github.com/khoih-prog/ESPAsync_WiFiManager/discussions/80)
2. Update all examples

### Initial Releases v1.0.0

1. Initial coding to support MBED nRF52840-based boards such as **Nano_33_BLE, Nano_33_BLE_Sense**, etc. using [**Arduino-mbed mbed_nano** core](https://github.com/arduino/ArduinoCore-mbed)


