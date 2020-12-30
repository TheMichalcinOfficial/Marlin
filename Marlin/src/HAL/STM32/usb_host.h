/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

<<<<<<< HEAD:Marlin/src/module/thermistor/thermistor_503.h
// Zonestar (Z8XM2) Heated Bed thermistor. Added By AvanOsch
// These are taken from the Zonestar settings in original Repetier firmware: Z8XM2_ZRIB_LCD12864_V51.zip
const temp_entry_t temptable_503[] PROGMEM = {
   { OV(  12), 300 },
   { OV(  27), 270 },
   { OV(  47), 250 },
   { OV(  68), 230 },
   { OV(  99), 210 },
   { OV( 120), 200 },
   { OV( 141), 190 },
   { OV( 171), 180 },
   { OV( 201), 170 },
   { OV( 261), 160 },
   { OV( 321), 150 },
   { OV( 401), 140 },
   { OV( 451), 130 },
   { OV( 551), 120 },
   { OV( 596), 110 },
   { OV( 626), 105 },
   { OV( 666), 100 },
   { OV( 697), 90 },
   { OV( 717), 85 },
   { OV( 798), 69 },
   { OV( 819), 65 },
   { OV( 870), 55 },
   { OV( 891), 51 },
   { OV( 922), 39 },
   { OV( 968), 28 },
   { OV( 980), 23 },
   { OV( 991), 17 },
   { OV( 1001), 9 },
   { OV(1021), -27 },
   { OV(1023), -200}
};
=======
#include <stdint.h>

typedef enum {
  USB_STATE_INIT,
  USB_STATE_ERROR,
  USB_STATE_RUNNING,
} usb_state_t;

class USBHost {
public:
  bool start();
  void Task();
  uint8_t getUsbTaskState();
  void setUsbTaskState(uint8_t state);
  uint8_t regRd(uint8_t reg) { return 0x0; };
  uint8_t usb_task_state = USB_STATE_INIT;
  uint8_t lun = 0;
  uint32_t capacity = 0;
  uint16_t block_size = 0;
  uint32_t block_count = 0;
};

class BulkStorage {
public:
  BulkStorage(USBHost *usb) : usb(usb) {};

  bool LUNIsGood(uint8_t t);
  uint32_t GetCapacity(uint8_t lun);
  uint16_t GetSectorSize(uint8_t lun);
  uint8_t Read(uint8_t lun, uint32_t addr, uint16_t bsize, uint8_t blocks, uint8_t *buf);
  uint8_t Write(uint8_t lun, uint32_t addr, uint16_t bsize, uint8_t blocks, const uint8_t * buf);

  USBHost *usb;
};

extern USBHost usb;
extern BulkStorage bulk;
>>>>>>> 4ad633bae235f0a47972d6d7873e614b8286d914:Marlin/src/HAL/STM32/usb_host.h
