/****************************************************************************************************************************
  FS_Nano33BLE.cpp - Filesystem wrapper for FS (LittleFS and FATFS) on the Mbed Nano-33-BLE
  
  For MBED nRF52840-based boards such as Nano_33_BLE, Nano_33_BLE_Sense.
  Written by Khoi Hoang

  Built by Khoi Hoang https://github.com/khoih-prog/FS_Nano33BLE
  Licensed under MIT license

  Version: 1.0.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      29/08/2021 Initial coding to support MBED nRF52840-based boards such as Nano_33_BLE, etc.
*****************************************************************************************************************************/

#include "FS_Nano33BLE.h"

#ifndef _FS_LOGLEVEL_
  #define _FS_LOGLEVEL_              1
#endif
 
bool FileSystem_MBED::init()
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

bool FileSystem_MBED::mount()
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

bool FileSystem_MBED::unmount()
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


