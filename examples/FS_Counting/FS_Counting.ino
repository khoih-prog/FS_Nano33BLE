/****************************************************************************************************************************
  FS_Counting.ino - Filesystem wrapper for FS (LittleFS and FATFS) on the Mbed Nano-33-BLE

  For MBED nRF52840-based boards such as Nano_33_BLE, Nano_33_BLE_Sense.
  Written by Khoi Hoang

  Built by Khoi Hoang https://github.com/khoih-prog/FS_Nano33BLE
  Licensed under MIT license
*****************************************************************************************************************************/

#define FS_NANO33BLE_VERSION_MIN_TARGET      "FS_Nano33BLE v1.2.1"
#define FS_NANO33BLE_VERSION_MIN             1002001

#define _FS_LOGLEVEL_               1

// Min NANO33BLE_FS_SIZE_KB must be  64KB. If defined smalller => auto adjust to  64KB
// Max NANO33BLE_FS_SIZE_KB must be 512KB. If defined larger   => auto adjust to 512KB
#define NANO33BLE_FS_SIZE_KB        256

#define FORCE_REFORMAT              false

// Default USING_LITTLEFS. Uncomment to not USING_LITTLEFS => USING_FATFS.
// It's advisable not to use FATFS, as the NANO33BLE_FS_SIZE_KB must be auto-adjusted to 512KB
//#define USING_LITTLEFS              false

#include <FS_Nano33BLE.h>

#define START_COUNT_OVER            false

FileSystem_MBED *myFS;

void setup()
{
  Serial.begin(115200);

  while (!Serial && millis() < 5000);

  delay(1000);

  Serial.print("\nStart FS_Counting on ");
  Serial.println(BOARD_NAME);
  Serial.println(FS_NANO33BLE_VERSION);

#if defined(FS_NANO33BLE_VERSION_MIN)

  if (FS_NANO33BLE_VERSION_INT < FS_NANO33BLE_VERSION_MIN)
  {
    Serial.print("Warning. Must use this example on Version equal or later than : ");
    Serial.println(FS_NANO33BLE_VERSION_MIN_TARGET);
  }

#endif

  Serial.print("FS_size (KB) = ");
  Serial.println(NANO33BLE_FS_SIZE_KB);
  Serial.print("FS_ Start Address = 0x");
  Serial.println(NANO33BLE_FS_START, HEX);

  myFS = new FileSystem_MBED();

  if (!myFS->init())
  {
    Serial.println("FS Mount Failed");

    return;
  }

  char fileName[] = MBED_FS_FILE_PREFIX "/counts.txt";

#define BUF_SIZE      32

  char buff[BUF_SIZE];
  int count = 1;

#if  START_COUNT_OVER
  Serial.print("Deleting file: ");
  Serial.print(fileName);

  if (remove(fileName) == 0)
  {
    Serial.println(" => OK");
  }
  else
  {
    Serial.println(" => Failed");
  }

#endif

  FILE *file = fopen(fileName, "r");

  if (file)
  {
    Serial.println(" => Open to read OK");

    bzero(buff, BUF_SIZE);

    uint32_t numRead = fread((uint8_t *) buff, BUF_SIZE - 1, 1, file);

    if ( numRead )
    {
      sscanf(buff, "%d", &count);
      //Serial.print("Times have been run = "); Serial.println(count);
    }

    fclose(file);
  }

  Serial.print("Times have been run = ");
  Serial.println(count);

  sprintf(buff, "%d\n", ++count);

  file = fopen(fileName, "w");

  if (file)
  {
    Serial.println(" => Open to write OK");

    fwrite((uint8_t *) buff, 1, BUF_SIZE - 1, file) ;
    fclose(file);
  }
}

void loop()
{
}
