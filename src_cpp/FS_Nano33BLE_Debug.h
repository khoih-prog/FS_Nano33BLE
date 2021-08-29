/****************************************************************************************************************************
  FS_Nano33BLE_Debug.h - Filesystem wrapper for FS (LittleFS and FATFS) on the Mbed Nano-33-BLE
  
  For MBED nRF52840-based boards such as Nano_33_BLE, Nano_33_BLE_Sense.
  Written by Khoi Hoang

  Built by Khoi Hoang https://github.com/khoih-prog/FS_Nano33BLE
  Licensed under MIT license

  Version: 1.0.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      29/08/2021 Initial coding to support MBED nRF52840-based boards such as Nano_33_BLE, etc.
*****************************************************************************************************************************/  

#ifndef FS_NANO33BLE_Debug_h
#define FS_NANO33BLE_Debug_h

#ifdef FS_DEBUG_OUTPUT
  #define DBG_PORT_FS       FS_DEBUG_OUTPUT
#else
  #define DBG_PORT_FS       Serial
#endif

// Change _FS_LOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational (default)
// 4: DEBUG: errors, warnings, informational and debug

#ifndef _FS_LOGLEVEL_
  #define _FS_LOGLEVEL_       0
#endif

//////////////////////////////////////////

const char FS_MARK[] = "[FS] ";

#define FS_PRINT_MARK    DBG_PORT_FS.print(FS_MARK)

#define FS_PRINT         DBG_PORT_FS.print
#define FS_PRINTLN       DBG_PORT_FS.println
#define FS_FLUSH         DBG_PORT_FS.flush

//////////////////////////////////////////

#define FS_LOGERROR0(x)        if(_FS_LOGLEVEL_>0) { FS_PRINT(x); }
#define FS_LOGERROR(x)         if(_FS_LOGLEVEL_>0) { FS_PRINT_MARK; FS_PRINTLN(x); }
#define FS_LOGERROR1(x,y)      if(_FS_LOGLEVEL_>0) { FS_PRINT_MARK; FS_PRINT(x); FS_PRINTLN(y); }
#define FS_HEXLOGERROR1(x,y)   if(_FS_LOGLEVEL_>0) { FS_PRINT_MARK; FS_PRINT(x); FS_PRINTLN(y, HEX); }
#define FS_LOGERROR2(x,y,z)    if(_FS_LOGLEVEL_>0) { FS_PRINT_MARK; FS_PRINT(x); FS_PRINT(y); FS_PRINTLN(z); }
#define FS_LOGERROR3(x,y,z,w)  if(_FS_LOGLEVEL_>0) { FS_PRINT_MARK; FS_PRINT(x); FS_PRINT(y); FS_PRINT(z); FS_PRINTLN(w); }
#define FS_HEXLOGERROR3(x,y,z,w)     if(_FS_LOGLEVEL_>0) { FS_PRINT_MARK; FS_PRINT(x); FS_PRINT(y, HEX); FS_PRINT(z); FS_PRINTLN(w, HEX); }
#define FS_LOGERROR5(x,y,z,w,xx,yy)  if(_FS_LOGLEVEL_>0) { FS_PRINT_MARK; FS_PRINT(x); FS_PRINT(y); FS_PRINT(z); FS_PRINT(w); FS_PRINT(xx); FS_PRINTLN(yy); }

//////////////////////////////////////////

#define FS_LOGWARN0(x)     if(_FS_LOGLEVEL_>1) { FS_PRINT(x); }
#define FS_LOGWARN(x)      if(_FS_LOGLEVEL_>1) { FS_PRINT_MARK; FS_PRINTLN(x); }
#define FS_LOGWARN1(x,y)   if(_FS_LOGLEVEL_>1) { FS_PRINT_MARK; FS_PRINT(x); FS_PRINTLN(y); }
#define FS_LOGWARN2(x,y,z) if(_FS_LOGLEVEL_>1) { FS_PRINT_MARK; FS_PRINT(x); FS_PRINT(y); FS_PRINTLN(z); }
#define FS_LOGWARN3(x,y,z,w) if(_FS_LOGLEVEL_>1) { FS_PRINT_MARK; FS_PRINT(x); FS_PRINT(y); FS_PRINT(z); FS_PRINTLN(w); }
#define FS_LOGWARN5(x,y,z,w,xx,yy) if(_FS_LOGLEVEL_>1) { FS_PRINT_MARK; FS_PRINT(x); FS_PRINT(y); FS_PRINT(z); FS_PRINT(w); FS_PRINT(xx); FS_PRINTLN(yy); }

//////////////////////////////////////////

#define FS_LOGINFO0(x)     if(_FS_LOGLEVEL_>2) { FS_PRINT(x); }
#define FS_LOGINFO(x)      if(_FS_LOGLEVEL_>2) { FS_PRINT_MARK; FS_PRINTLN(x); }
#define FS_LOGINFO1(x,y)   if(_FS_LOGLEVEL_>2) { FS_PRINT_MARK; FS_PRINT(x); FS_PRINTLN(y); }
#define FS_LOGINFO2(x,y,z) if(_FS_LOGLEVEL_>3) { FS_PRINT_MARK; FS_PRINT(x); FS_PRINT(y); FS_PRINTLN(z); }
#define FS_LOGINFO3(x,y,z,w) if(_FS_LOGLEVEL_>3) { FS_PRINT_MARK; FS_PRINT(x); FS_PRINT(y); FS_PRINT(z); FS_PRINTLN(w); }
#define FS_LOGINFO5(x,y,z,w,xx,yy) if(_FS_LOGLEVEL_>2) { FS_PRINT_MARK; FS_PRINT(x); FS_PRINT(y); FS_PRINT(z); FS_PRINT(w); FS_PRINT(xx); FS_PRINTLN(yy); }

//////////////////////////////////////////

#define FS_LOGDEBUG0(x)     if(_FS_LOGLEVEL_>3) { FS_PRINT(x); }
#define FS_LOGDEBUG(x)      if(_FS_LOGLEVEL_>3) { FS_PRINT_MARK; FS_PRINTLN(x); }
#define FS_LOGDEBUG1(x,y)   if(_FS_LOGLEVEL_>3) { FS_PRINT_MARK; FS_PRINT(x); FS_PRINTLN(y); }
#define FS_LOGDEBUG2(x,y,z) if(_FS_LOGLEVEL_>3) { FS_PRINT_MARK; FS_PRINT(x); FS_PRINT(y); FS_PRINTLN(z); }
#define FS_LOGDEBUG3(x,y,z,w) if(_FS_LOGLEVEL_>3) { FS_PRINT_MARK; FS_PRINT(x); FS_PRINT(y); FS_PRINT(z); FS_PRINTLN(w); }
#define FS_LOGDEBUG5(x,y,z,w,xx,yy) if(_FS_LOGLEVEL_>3) { FS_PRINT_MARK; FS_PRINT(x); FS_PRINT(y); FS_PRINT(z); FS_PRINT(w); FS_PRINT(xx); FS_PRINTLN(yy); }

//////////////////////////////////////////

#endif    //FS_NANO33BLE_Debug_h
