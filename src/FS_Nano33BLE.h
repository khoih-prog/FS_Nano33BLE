/****************************************************************************************************************************
  FS_Nano33BLE.h - Filesystem wrapper for FS (LittleFS and FATFS) on the Mbed Nano-33-BLE
  
  For MBED nRF52840-based boards such as Nano_33_BLE, Nano_33_BLE_Sense.
  Written by Khoi Hoang

  Built by Khoi Hoang https://github.com/khoih-prog/FS_Nano33BLE
  Licensed under MIT license

  Version: 1.0.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      29/08/2021 Initial coding to support MBED nRF52840-based boards such as Nano_33_BLE, etc.
*****************************************************************************************************************************/

#ifndef _FS_NANO33BLE_H
#define _FS_NANO33BLE_H

#if !( defined(ARDUINO_ARCH_NRF52840) && defined(ARDUINO_ARCH_MBED) && defined(ARDUINO_ARDUINO_NANO33BLE) )
  #error This code is intended to run on the MBED nRF52840 platform! Please check your Tools->Board setting. 
#endif

#ifndef _FS_LOGLEVEL_
  #define _FS_LOGLEVEL_               1
#endif

////////////////////////////////////////////////

#ifndef USING_LITTLEFS
  #define USING_LITTLEFS              true
#endif

#if USING_LITTLEFS

  #define USING_FATFS                 false
  #define FS_NAME                     "LittleFS"
  
  #define MBED_FS_FILE_NAME           "littlefs"
  
  #warning Use MBED nRF52840 (such as Nano_33_BLE, Nano_33_BLE_Sense) and LittleFS
  
#else

  #define USING_FATFS                 true
  #define FS_NAME                     "FATFS"
  #define MBED_FS_FILE_NAME           "fs"
  
  #warning Use MBED nRF52840 (such as Nano_33_BLE, Nano_33_BLE_Sense) and FATFS
  
#endif

////////////////////////////////////////////////

#define FS_NANO33BLE_VERSION              FS_NAME "_Nano33BLE v1.1.0"

#define FS_NANO33BLE_VERSION_MAJOR        1
#define FS_NANO33BLE_VERSION_MINOR        1
#define FS_NANO33BLE_VERSION_PATCH        0

#define FS_NANO33BLE_VERSION_INT          1001000

////////////////////////////////////////////////

#include <Arduino.h>

#include "FS_Nano33BLE_Debug.h"

////////////////////////////////////////////////

// For Arduino' arduino-mbed core
// To check and determine if we need to init FS here
#if NANO33BLE_INITIALIZED
  #define MBED_FS_NEED_INIT               false
  #warning NANO33BLE_INITIALIZED in another place
#else
  // Better to delay until init done
  #if defined(NANO33BLE_INITIALIZED)
    #undef NANO33BLE_INITIALIZED
  #endif
  #define NANO33BLE_INITIALIZED           true
  
  #define MBED_FS_NEED_INIT               true
  
  #warning NANO33BLE_INITIALIZED in FS_NANO33BLE
#endif

#if MBED_FS_NEED_INIT

  //Use FS for MBED Nano_33_BLE
  #include "FlashIAPBlockDevice.h"
  
  #if USING_LITTLEFS
    #include "LittleFileSystem.h"
  #elif USING_FATFS
    #include "FATFileSystem.h"
  #else
    #error No FS selected  
  #endif
  
  #include "mbed.h"

  #include <stdio.h>
  #include <errno.h>
  #include <functional>

  #include "BlockDevice.h"

  #if !defined(NANO33BLE_FLASH_SIZE)
    // Using max 512KB for FS
    #define NANO33BLE_FLASH_SIZE         (1 * 1024 * 1024)
  #endif

  #if !defined(NANO33BLE_FS_LOCATION_END)
    #define NANO33BLE_FS_LOCATION_END    NANO33BLE_FLASH_SIZE
  #endif

  #if !defined(NANO33BLE_FS_SIZE_KB)
    // Using default 64KB for FS
    #define NANO33BLE_FS_SIZE_KB       (64)
    #warning Using default NANO33BLE_FS_SIZE_KB == 64KB
  #else
    #warning Using NANO33BLE_FS_SIZE_KB defined in external code 
    
    #if (NANO33BLE_FS_SIZE_KB > (NANO33BLE_FLASH_SIZE / (2 * 1024)))
      #error FlashSize too large. Max is (NANO33BLE_FLASH_SIZE / 2) = 512KB
    #endif
  #endif

  #if !defined(NANO33BLE_FS_START)
    #define NANO33BLE_FS_START           (NANO33BLE_FLASH_SIZE - (NANO33BLE_FS_SIZE_KB * 1024))
  #endif

  #if !defined(FORCE_REFORMAT)
    #define FORCE_REFORMAT            false
  #elif FORCE_REFORMAT
    #warning FORCE_REFORMAT enable. Are you sure ?
  #endif
 
  #define MBED_FS_FILE_PREFIX         "/" MBED_FS_FILE_NAME

#endif    // MBED_FS_NEED_INIT

// nRF52840 flash address from 0, length 1MB.
// Better to use max half of flash for LitleFS, must be 0x80000 (512KB)
// FLASH_BASE must be 0x80000, or crash !!!????
#define FLASH_BASE            0x80000

#if USING_LITTLEFS
  static mbed::LittleFileSystem fs(MBED_FS_FILE_NAME);
  static FlashIAPBlockDevice wholeBD(FLASH_BASE, 0x80000);
  static FlashIAPBlockDevice bd(FLASH_BASE, (NANO33BLE_FS_SIZE_KB * 1024));
#elif USING_FATFS
  static mbed::FATFileSystem fs(MBED_FS_FILE_NAME);
  static FlashIAPBlockDevice bd(FLASH_BASE, NANO33BLE_FLASH_SIZE / 2);
  //static FlashIAPBlockDevice bd(FLASH_BASE, (NANO33BLE_FS_SIZE_KB * 1024));   // Crash ??
#endif  

class FileSystem_MBED
{
public:
  FileSystem_MBED()
  {
    _size     = NANO33BLE_FS_SIZE_KB * 1024;
    _mounted  = false;
  }

  ~FileSystem_MBED() 
  {
    if (_mounted) 
    {
      unmount();      
    }
  }
  
  ////////////////////////////////////////////////

  bool init()
  {
    FS_LOGERROR1(FS_NAME " size (KB) = ", NANO33BLE_FS_SIZE_KB);
    
  #if FORCE_REFORMAT
    int error;
    
  #if USING_LITTLEFS
    error = mbed::LittleFileSystem::format(&bd);
  #else  
    error = mbed::FATFileSystem::format(&bd);
  #endif

    if (error)
    {
      FS_LOGERROR1("FS Format error, errno = ", errno);
     
      return false;
    }

  #endif

    return mount();
  }
  
  ////////////////////////////////////////////////

  bool mount()
  {
    if (!_mounted)
    {   
      int error;
      
      // 0 => OK
      _mounted = (fs.mount(&bd) == 0);

      FS_LOGERROR(_mounted ? FS_NAME " Mount OK" : FS_NAME " Mount Fail");

      if (!_mounted)
      {
        // Reformat if we can't mount the filesystem
        FS_LOGERROR("Formatting... ");

  #if USING_LITTLEFS
        error = mbed::LittleFileSystem::format(&bd);
  #else  
        error = mbed::FATFileSystem::format(&bd);
  #endif

        if (!error)
        {
          FS_LOGERROR("FS Format OK. Mounting");

          _mounted = (fs.mount(&bd) == 0);
                 
          if (_mounted)
          {
            FS_LOGERROR("FS OK");
            
            return true;
          }
          else
          {
            FS_LOGERROR("FS error. Reset. It'll be OK now after reset.");
            
            // Restart for nRF52
            NVIC_SystemReset();
            
            return false;
          }
        }
        else
        {
          FS_LOGERROR("FS Format error");
          
          return false;
        }
      }

      if (!_mounted)
      {
        FS_LOGERROR("FS error");
      } 
    }
    
    return true;
  }
  
  ////////////////////////////////////////////////

  bool unmount()
  {
    if (_mounted)
    {
      int err = fs.unmount();
    
      FS_LOGERROR1("Unmount FS ", err < 0 ? "Fail" : "OK");
   
      if (err < 0)
      {   
        return false;
      }
    }
    
    _mounted = false;
    
    return true;
  }
  
  ////////////////////////////////////////////////
  
private:

  uint32_t _size;

  bool     _mounted;  
};


#endif // ifndef _FS_NANO33BLE_H
