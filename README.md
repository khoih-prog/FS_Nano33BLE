# FS_Nano33BLE Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/FS_Nano33BLE.svg?)](https://www.ardu-badge.com/FS_Nano33BLE)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/FS_Nano33BLE.svg)](https://github.com/khoih-prog/FS_Nano33BLE/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/FS_Nano33BLE/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/FS_Nano33BLE.svg)](http://github.com/khoih-prog/FS_Nano33BLE/issues)

<a href="https://www.buymeacoffee.com/khoihprog6" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Buy Me A Coffee" style="height: 50px !important;width: 181px !important;" ></a>

---
---

## Table of Contents

* [Why do we need this FS_Nano33BLE library](#why-do-we-need-this-FS_Nano33BLE-library)
  * [Important Notes](#Important-Notes)
  * [Features](#features)
  * [Currently supported Boards](#currently-supported-boards)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Examples](#examples)
  * [  1. FS_Counting](examples/FS_Counting)
  * [  2. FS_Test](examples/FS_Test)
* [Example FS_Test](#example-fs_test)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. FS_Counting on Nano 33 BLE with LittleFS size 256KB](#1-fs_counting-on-nano-33-ble-with-littlefs-size-256kb)
  * [2. FS_Test on Nano 33 BLE with LittleFS size 256KB](#2-fs_test-on-nano-33-ble-with-littlefs-size-256kb)
  * [3. FS_Test on Nano 33 BLE with FATFS size 512KB](#3-fs_test-on-nano-33-ble-with-fatfs-size-512kb)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Why do we need this [FS_Nano33BLE library](https://github.com/khoih-prog/FS_Nano33BLE)

## Important Notes

Avoid using FATFS because the somehow (issue with the core ???) it's OK to use only with 512KB. Please use the better LittleFS, where you can select the size anywhere from 64KB to 512KB.


## Features

This library is just a simple LittleFS wrapper to facilitate your usage of LittleFS for the onboard flash on **MBED nRF52840-based boards such as Nano_33_BLE, Nano_33_BLE_Sense**, using [**Arduino-mbed mbed_nano** core](https://github.com/arduino/ArduinoCore-mbed)

The filesystem access uses normal [POSIX APIs](https://www.tutorialspoint.com/c_standard_library/stdio_h.htm) or [mbed FileSystem APIs](https://os.mbed.com/docs/mbed-os/v6.10/apis/file-system-apis.html)

---

### Currently supported Boards

1. **MBED nRF52840-based boards such as Nano_33_BLE, Nano_33_BLE_Sense**, etc. using [**Arduino-mbed mbed_nano** core](https://github.com/arduino/ArduinoCore-mbed)
2. **Seeeduino nRF52840-based boards such as SEEED_XIAO_NRF52840 and SEEED_XIAO_NRF52840_SENSE**, etc. using Seeeduino `mbed` core

---
---

## Prerequisites

1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
2. [`Arduino mbed_nano core 3.4.1+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino (Use Arduino Board Manager) MBED nRF52840-based boards such as **Nano_33_BLE, Nano_33_BLE_Sense**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)
3. `Seeeduino mbed core 2.7.2+` for Seeeduino nRF52840-based boards such as **SEEED_XIAO_NRF52840 and SEEED_XIAO_NRF52840_SENSE**

---
---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for [**FS_Nano33BLE**](https://github.com/khoih-prog/FS_Nano33BLE), then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/FS_Nano33BLE.svg?)](https://www.ardu-badge.com/FS_Nano33BLE) for more detailed instructions.

### Manual Install

Another way to install is to:

1. Navigate to [**FS_Nano33BLE**](https://github.com/khoih-prog/FS_Nano33BLE) page.
2. Download the latest release `FS_Nano33BLE-main.zip`.
3. Extract the zip file to `FS_Nano33BLE-main` directory 
4. Copy whole `FS_Nano33BLE-main` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**FS_Nano33BLE** library](https://platformio.org/lib/show/12751/FS_Nano33BLE) by using [Library Manager](https://platformio.org/lib/show/12751/FS_Nano33BLE/installation). Search for **FS_Nano33BLE** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---
---


### Examples 

 1. [FS_Counting](examples/FS_Counting)
 2. [FS_Test](examples/FS_Test)

---
---

### Example [FS_Test](examples/FS_Test)


https://github.com/khoih-prog/FS_Nano33BLE/blob/141121ee1552ddf249d09c297f5d49a838e2624e/examples/FS_Test/FS_Test.ino#L1-L371


---
---

### Debug Terminal Output Samples

### 1. FS_Counting on Nano 33 BLE with LittleFS size 256KB

The following is the sample terminal output when running example [FS_Counting](examples/FS_Counting) on MBED Nano_33_BLE using **LittleFS**

```
Start FS_Test on Nano 33 BLE
LittleFS_Nano33BLE v1.2.1
FS_size (KB) = 256
FS_ Start Address = 0xC0000
[FS] LittleFS size (KB) = 256
[LFS] LittleFS Mount OK
Deleting file: /littlefs/counts.txt => OK
Times have been run = 1
 => Open to write OK

Start FS_Test on Nano 33 BLE
LittleFS_Nano33BLE v1.2.1
[LFS] LittleFS size (KB) = 256
[LFS] LittleFS Mount OK
 => Open to read OK
Times have been run = 2
 => Open to write OK

Start FS_Test on Nano 33 BLE
LittleFS_Nano33BLE v1.2.1
[LFS] LittleFS size (KB) = 256
[LFS] LittleFS Mount OK
 => Open to read OK
Times have been run = 3
 => Open to write OK
```

---

### 2. FS_Test on Nano 33 BLE with LittleFS size 256KB

The following is the sample terminal output when running example [FS_Test](examples/FS_Test) on MBED Nano_33_BLE using **LittleFS**


```
Start FS_Test on Nano 33 BLE
LittleFS_Nano33BLE v1.2.1
FS_size (KB) = 256
FS_ Start Address = 0xC0000
[FS] LittleFS size (KB) = 256
[LFS] LittleFS Mount Fail
[LFS] Formatting... 
[LFS] 
FS Format OK. Mounting
====================================================
Writing file: /fs/hello1.txt => Open OK
* Writing OK
====================================================
Reading file: /fs/hello1.txt => Open OK
Hello from Nano_33_BLE
====================================================
Appending file: /fs/hello1.txt => Open OK
* Appending OK
====================================================
Reading file: /fs/hello1.txt => Open OK
Hello from Nano_33_BLE
Hello from Nano_33_BLE
====================================================
Renaming file: /fs/hello1.txt to: /fs/hello2.txt => OK
====================================================
readCharsFromFile: /fs/hello2.txt => Open OK
Hello from Nano_33_BLE
Hello from Nano_33_BLE
====================================================
Deleting file: /fs/hello2.txt => OK
====================================================
Reading file: /fs/hello2.txt => Open Failed
====================================================
Testing file I/O with: /fs/hello1.txt => Open OK
- writing

64 Kbytes written in (ms) 2461
====================================================
- reading

64 Kbytes read in (ms) 7
====================================================
Testing file I/O with: /fs/hello2.txt => Open OK
- writing

64 Kbytes written in (ms) 2460
====================================================
- reading

64 Kbytes read in (ms) 7
====================================================
Deleting file: /fs/hello1.txt => OK
====================================================
Deleting file: /fs/hello2.txt => OK
====================================================

Test complete

```

---

### 3. FS_Test on Nano 33 BLE with FATFS size 512KB

The following is the sample terminal output when running example [FS_Test](examples/FS_Test) on MBED Nano_33_BLE using **FATFS**


```
Start FS_Test on Nano 33 BLE
FATFS_Nano33BLE v1.2.1
FS_size (KB) = 512
FS_ Start Address = 0x80000
[FS] LittleFS size (KB) = 512
[LFS] FATFS Mount OK
====================================================
Writing file: /fs/hello1.txt => Open OK
* Writing OK
====================================================
Reading file: /fs/hello1.txt => Open OK
Hello from Nano_33_BLE
====================================================
Appending file: /fs/hello1.txt => Open OK
* Appending OK
====================================================
Reading file: /fs/hello1.txt => Open OK
Hello from Nano_33_BLE
Hello from Nano_33_BLE
====================================================
Renaming file: /fs/hello1.txt to: /fs/hello2.txt => OK
====================================================
readCharsFromFile: /fs/hello2.txt => Open OK
Hello from Nano_33_BLE
Hello from Nano_33_BLE
====================================================
Deleting file: /fs/hello2.txt => OK
====================================================
Reading file: /fs/hello2.txt => Open Failed
====================================================
Testing file I/O with: /fs/hello1.txt => Open OK
- writing

64 Kbytes written in (ms) 4374
====================================================
- reading

64 Kbytes read in (ms) 15
====================================================
Testing file I/O with: /fs/hello2.txt => Open OK
- writing

64 Kbytes written in (ms) 4374
====================================================
- reading

64 Kbytes read in (ms) 15
====================================================
Deleting file: /fs/hello1.txt => OK
====================================================
Deleting file: /fs/hello2.txt => OK
====================================================

Test complete
```

---
---

### Debug

Debug is enabled by default on Serial.

You can also change the debugging level (_FS_LOGLEVEL_) from 0 to 4

```cpp
#define FS_DEBUG_OUTPUT    Serial

// These define's must be placed at the beginning before #include "FS_Nano33BLE.h"
// _FS_LOGLEVEL_ from 0 to 4
#define _FS_LOGLEVEL_      0
```

---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the core for Arduino boards.

Sometimes, the library will only work if you update the board core to the latest version because I am using newly added functions.


---
---


### Issues

Submit issues to: [FS_Nano33BLE issues](https://github.com/khoih-prog/FS_Nano33BLE/issues)

---

## TO DO

1. Search for bug and improvement.


---

## DONE

1. Basic LittleFS wrapper for MBED nRF52840-based boards such as **Nano_33_BLE, Nano_33_BLE_Sense**, using [**Arduino-mbed mbed_nano** core](https://github.com/arduino/ArduinoCore-mbed)
2. Add Version String 
3. Add Table of Contents
4. Fix `multiple-definitions` linker error
5. Use correct `NANO33BLE_FS_START` address for `LittleFS` without wasting flash space. Check [Half size of flash #2](https://github.com/khoih-prog/FS_Nano33BLE/discussions/2)
6. Add support to Seeeduino nRF52840-based boards such as **SEEED_XIAO_NRF52840 and SEEED_XIAO_NRF52840_SENSE**, etc. using Seeeduino `mbed` core
7. Add astyle using `allman` style. Restyle the library
8. Display compile warning only when `_FS_LOGLEVEL_ > 3`

---
---

### Contributions and Thanks

Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this library.

1. Thanks to [Rob Probin](https://github.com/robzed) to report issue [Half size of flash #2](https://github.com/khoih-prog/FS_Nano33BLE/discussions/2) leading to v1.2.0

<table>
  <tr>
    <td align="center"><a href="https://github.com/robzed"><img src="https://github.com/robzed.png" width="100px;" alt="robzed"/><br /><sub><b>Rob Probin</b></sub></a><br /></td>
  </tr> 
</table>


---

## Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [GPLv3](https://github.com/khoih-prog/FS_Nano33BLE/blob/main/LICENSE)

---

## Copyright

Copyright 2021- Khoi Hoang


