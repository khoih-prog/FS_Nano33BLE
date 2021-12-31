# FS_Nano33BLE Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/FS_Nano33BLE.svg?)](https://www.ardu-badge.com/FS_Nano33BLE)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/FS_Nano33BLE.svg)](https://github.com/khoih-prog/FS_Nano33BLE/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/FS_Nano33BLE/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/FS_Nano33BLE.svg)](http://github.com/khoih-prog/FS_Nano33BLE/issues)

---
---

## Table of Contents

* [Why do we need this FS_Nano33BLE library](#why-do-we-need-this-FS_Nano33BLE-library)
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
  * [3. FS_Test on Nano 33 BLE with FATFS size 256KB](#3-fs_test-on-nano-33-ble-with-fatfs-size-256kb)
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

## Features

This library is just a simple LittleFS wrapper to facilitate your usage of LittleFS for the onboard flash on **MBED nRF52840-based boards such as Nano_33_BLE, Nano_33_BLE_Sense**, using [**Arduino-mbed mbed_nano** core](https://github.com/arduino/ArduinoCore-mbed)

The filesystem access uses normal [POSIX APIs](https://www.tutorialspoint.com/c_standard_library/stdio_h.htm) or [mbed FileSystem APIs](https://os.mbed.com/docs/mbed-os/v6.10/apis/file-system-apis.html)

---

### Currently supported Boards

1. **MBED nRF52840-based boards such as Nano_33_BLE, Nano_33_BLE_Sense**, etc. using [**Arduino-mbed mbed_nano** core](https://github.com/arduino/ArduinoCore-mbed)

---
---

## Prerequisites

1. [`Arduino IDE 1.8.19+` for Arduino](https://www.arduino.cc/en/Main/Software)
2. [`Arduino mbed_nano core 2.6.1+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino (Use Arduino Board Manager) MBED nRF52840-based boards such as **Nano_33_BLE, Nano_33_BLE_Sense**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)

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

```
#define FS_NANO33BLE_VERSION_MIN_TARGET      "FS_Nano33BLE v1.1.0"
#define FS_NANO33BLE_VERSION_MIN             1001000

#define _FS_LOGLEVEL_               1
#define NANO33BLE_FS_SIZE_KB        256

#define FORCE_REFORMAT              false

// Default USING_LITTLEFS. Uncomment to not USING_LITTLEFS => USING_FATFS. 
//#define USING_LITTLEFS              false

#include <FS_Nano33BLE.h>

FileSystem_MBED *myFS;

void readCharsFromFile(const char * path) 
{
  Serial.print("readCharsFromFile: "); Serial.print(path);

  FILE *file = fopen(path, "r");
  
  if (file) 
  {
    Serial.println(" => Open OK");
  }
  else
  {
    Serial.println(" => Open Failed");
    return;
  }

  char c;

  while (true) 
  {
    c = fgetc(file);
    
    if ( feof(file) ) 
    { 
      break;
    }
    else   
      Serial.print(c);
  }
   
  fclose(file);
}

void readFile(const char * path) 
{
  Serial.print("Reading file: "); Serial.print(path);

  FILE *file = fopen(path, "r");
  
  if (file) 
  {
    Serial.println(" => Open OK");
  }
  else
  {
    Serial.println(" => Open Failed");
    return;
  }

  char c;
  uint32_t numRead = 1;
  
  while (numRead) 
  {
    numRead = fread((uint8_t *) &c, sizeof(c), 1, file);

    if (numRead)
      Serial.print(c);
  }
  
  fclose(file);
}

void writeFile(const char * path, const char * message, size_t messageSize) 
{
  Serial.print("Writing file: "); Serial.print(path);

  FILE *file = fopen(path, "w");
  
  if (file) 
  {
    Serial.println(" => Open OK");
  }
  else
  {
    Serial.println(" => Open Failed");
    return;
  }
 
  if (fwrite((uint8_t *) message, 1, messageSize, file)) 
  {
    Serial.println("* Writing OK");
  } 
  else 
  {
    Serial.println("* Writing failed");
  }
  
  fclose(file);
}

void appendFile(const char * path, const char * message, size_t messageSize) 
{
  Serial.print("Appending file: "); Serial.print(path);

  FILE *file = fopen(path, "a");
  
  if (file) 
  {
    Serial.println(" => Open OK");
  }
  else
  {
    Serial.println(" => Open Failed");
    return;
  }

  if (fwrite((uint8_t *) message, 1, messageSize, file)) 
  {
    Serial.println("* Appending OK");
  } 
  else 
  {
    Serial.println("* Appending failed");
  }
   
  fclose(file);
}

void deleteFile(const char * path) 
{
  Serial.print("Deleting file: "); Serial.print(path);
  
  if (remove(path) == 0) 
  {
    Serial.println(" => OK");
  }
  else
  {
    Serial.println(" => Failed");
    return;
  }
}

void renameFile(const char * path1, const char * path2) 
{
  Serial.print("Renaming file: "); Serial.print(path1);
  Serial.print(" to: "); Serial.print(path2);
  
  if (rename(path1, path2) == 0) 
  {
    Serial.println(" => OK");
  }
  else
  {
    Serial.println(" => Failed");
    return;
  }
}

void testFileIO(const char * path) 
{
  Serial.print("Testing file I/O with: "); Serial.print(path);

  #define BUFF_SIZE     512
  
  static uint8_t buf[BUFF_SIZE];
  
  FILE *file = fopen(path, "w");
  
  if (file) 
  {
    Serial.println(" => Open OK");
  }
  else
  {
    Serial.println(" => Open Failed");
    return;
  }

  size_t i;
  Serial.println("- writing" );
  
  uint32_t start = millis();

  size_t result = 0;

  // Write a file only 1/4 of NANO33BLE_FS_SIZE_KB
  for (i = 0; i < NANO33BLE_FS_SIZE_KB / 2; i++) 
  {
    result = fwrite(buf, BUFF_SIZE, 1, file);

    if ( result != 1)
    {
      Serial.print("Write result = "); Serial.println(result);
      Serial.print("Write error, i = "); Serial.println(i);

      break;
    }
  }
  
  Serial.println("");
  uint32_t end = millis() - start;
  
  Serial.print(i / 2);
  Serial.print(" Kbytes written in (ms) ");
  Serial.println(end);
  
  fclose(file);

  printLine();

  /////////////////////////////////

  file = fopen(path, "r");
  
  start = millis();
  end = start;
  i = 0;
  
  if (file) 
  {
    start = millis();
    Serial.println("- reading" );

    result = 0;

    fseek(file, 0, SEEK_SET);

    // Read file only 1/4 of NANO33BLE_FS_SIZE_KB
    for (i = 0; i < NANO33BLE_FS_SIZE_KB / 2; i++) 
    {
      result = fread(buf, BUFF_SIZE, 1, file);

      if ( result != 1 )
      {
        Serial.print("Read result = "); Serial.println(result);
        Serial.print("Read error, i = "); Serial.println(i);

        break;
      }
    }
      
    Serial.println("");
    end = millis() - start;
    
    Serial.print((i * BUFF_SIZE) / 1024);
    Serial.print(" Kbytes read in (ms) ");
    Serial.println(end);
    
    fclose(file);
  } 
  else 
  {
    Serial.println("- failed to open file for reading");
  }
}

void printLine()
{
  Serial.println("****************************************************");
}

void setup() 
{
  Serial.begin(115200);
  while (!Serial)

  delay(1000);

  Serial.print("\nStart FS_Test on "); Serial.println(BOARD_NAME);
  Serial.println(FS_NANO33BLE_VERSION);

#if defined(FS_NANO33BLE_VERSION_MIN)
  if (FS_NANO33BLE_VERSION_INT < FS_NANO33BLE_VERSION_MIN)
  {
    Serial.print("Warning. Must use this example on Version equal or later than : ");
    Serial.println(FS_NANO33BLE_VERSION_MIN_TARGET);
  }
#endif

  myFS = new FileSystem_MBED();

  if (!myFS->init())
  {
    Serial.println("FS Mount Failed");
    
    return;
  }

  char fileName1[] = MBED_FS_FILE_PREFIX "/hello1.txt";
  char fileName2[] = MBED_FS_FILE_PREFIX "/hello2.txt";
  
  char message[]  = "Hello from Nano_33_BLE\n";
   
  printLine();
  writeFile(fileName1, message, sizeof(message));
  printLine();
  readFile(fileName1);
  printLine();

  appendFile(fileName1, message, sizeof(message));
  printLine();
  readFile(fileName1);
  printLine();

  renameFile(fileName1, fileName2);
  printLine();
  readCharsFromFile(fileName2);
  printLine();

  deleteFile(fileName2);
  printLine();
  readFile(fileName2);
  printLine();

  testFileIO(fileName1);
  printLine();
  testFileIO(fileName2);
  printLine();
  deleteFile(fileName1);
  printLine();
  deleteFile(fileName2);
  printLine();

  Serial.println( "\nTest complete" );
}

void loop() 
{
}
```
---
---

### Debug Terminal Output Samples

### 1. FS_Counting on Nano 33 BLE with LittleFS size 256KB

The following is the sample terminal output when running example [FS_Counting](examples/FS_Counting) on MBED Nano_33_BLE using **LittleFS**

```
Start FS_Test on Nano 33 BLE
LittleFS_Nano33BLE v1.1.0
[LFS] LittleFS size (KB) = 256
[LFS] LittleFS Mount OK
Deleting file: /littlefs/counts.txt => OK
Times have been run = 1
 => Open to write OK

Start FS_Test on Nano 33 BLE
LittleFS_Nano33BLE v1.1.0
[LFS] LittleFS size (KB) = 256
[LFS] LittleFS Mount OK
 => Open to read OK
Times have been run = 2
 => Open to write OK

Start FS_Test on Nano 33 BLE
LittleFS_Nano33BLE v1.1.0
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
LittleFS_Nano33BLE v1.1.0
[LFS] LittleFS size (KB) = 256
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

### 3. FS_Test on Nano 33 BLE with FATFS size 256KB

The following is the sample terminal output when running example [FS_Test](examples/FS_Test) on MBED Nano_33_BLE using **FATFS**


```
Start FS_Test on Nano 33 BLE
FATFS_Nano33BLE v1.1.0
[LFS] FATFS size (KB) = 256
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

---
---

### Contributions and Thanks

Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this library.


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


