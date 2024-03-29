/*

  Bitmap.pde
  
  Show simple bitmap

  >>> Before compiling: Please remove comment from the constructor of the 
  >>> connected graphics display (see below).

  Universal 8bit Graphics Library, https://github.com/olikraus/u8glib/
  
  Copyright (c) 2011, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
  
*/


#include "U8glib.h"

// setup u8g object, please remove comment from one of the following constructor calls
// IMPORTANT NOTE: The following list is incomplete. The complete list of supported 
// devices with all constructor calls is here: https://github.com/olikraus/u8glib/wiki/device
//U8GLIB_NHD27OLED_BW u8g(13, 11, 10, 9);  // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_NHD27OLED_2X_BW u8g(13, 11, 10, 9);  // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_NHD27OLED_GR u8g(13, 11, 10, 9); // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_NHD27OLED_2X_GR u8g(13, 11, 10, 9);  // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_NHD31OLED_BW u8g(13, 11, 10, 9); // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_NHD31OLED_2X_BW u8g(13, 11, 10, 9);  // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_NHD31OLED_GR u8g(13, 11, 10, 9); // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_NHD31OLED_2X_GR u8g(13, 11, 10, 9);  // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_DOGS102 u8g(13, 11, 10, 9, 8);   // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_DOGM132 u8g(13, 11, 10, 9);    // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_DOGM128 u8g(13, 11, 10, 9);    // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_DOGM128_2X u8g(13, 11, 10, 9);   // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_ST7920_128X64_1X u8g(8, 9, 10, 11, 4, 5, 6, 7, 18, 17, 16);   // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, di=17,rw=16
//U8GLIB_ST7920_128X64_4X u8g(8, 9, 10, 11, 4, 5, 6, 7, 18, 17, 16);   // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, di=17,rw=16
//U8GLIB_ST7920_128X64_1X u8g(18, 16, 17);  // SPI Com: SCK = en = 18, MOSI = rw = 16, CS = di = 17
//U8GLIB_ST7920_128X64_4X u8g(18, 16, 17);  // SPI Com: SCK = en = 18, MOSI = rw = 16, CS = di = 17
//U8GLIB_ST7920_192X32_1X u8g(8, 9, 10, 11, 4, 5, 6, 7, 18, 17, 16);   // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, di=17,rw=16
//U8GLIB_ST7920_192X32_4X u8g(8, 9, 10, 11, 4, 5, 6, 7, 18, 17, 16);   // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, di=17,rw=16
//U8GLIB_ST7920_192X32_1X u8g(18, 16, 17);  // SPI Com: SCK = en = 18, MOSI = rw = 16, CS = di = 17
//U8GLIB_ST7920_192X32_4X u8g(18, 16, 17);  // SPI Com: SCK = en = 18, MOSI = rw = 16, CS = di = 17
//U8GLIB_ST7920_192X32_1X u8g(13, 11, 10);  // SPI Com: SCK = en = 13, MOSI = rw = 11, CS = di = 10
//U8GLIB_ST7920_192X32_4X u8g(10);    // SPI Com: SCK = en = 13, MOSI = rw = 11, CS = di = 10, HW SPI
//U8GLIB_ST7920_202X32_1X u8g(8, 9, 10, 11, 4, 5, 6, 7, 18, 17, 16);   // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, di=17,rw=16
//U8GLIB_ST7920_202X32_4X u8g(8, 9, 10, 11, 4, 5, 6, 7, 18, 17, 16);   // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, di=17,rw=16
//U8GLIB_ST7920_202X32_1X u8g(18, 16, 17);  // SPI Com: SCK = en = 18, MOSI = rw = 16, CS = di = 17
//U8GLIB_ST7920_202X32_4X u8g(18, 16, 17);  // SPI Com: SCK = en = 18, MOSI = rw = 16, CS = di = 17
//U8GLIB_LM6059 u8g(13, 11, 10, 9);   // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_LM6063 u8g(13, 11, 10, 9);   // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_DOGXL160_BW u8g(10, 9);    // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_DOGXL160_GR u8g(13, 11, 10, 9);  // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_DOGXL160_2X_BW u8g(13, 11, 10, 9); // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_DOGXL160_2X_GR u8g(13, 11, 10, 9); // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_PCD8544 u8g(13, 11, 10, 9, 8);   // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, Reset = 8
//U8GLIB_PCF8812 u8g(13, 11, 10, 9, 8);   // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, Reset = 8
//U8GLIB_KS0108_128 u8g(8, 9, 10, 11, 4, 5, 6, 7, 18, 14, 15, 17, 16);    // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, cs1=14, cs2=15,di=17,rw=16
//U8GLIB_LC7981_160X80 u8g(8, 9, 10, 11, 4, 5, 6, 7,  18, 14, 15, 17, 16);  // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, cs=14 ,di=15,rw=17, reset = 16
//U8GLIB_LC7981_240X64 u8g(8, 9, 10, 11, 4, 5, 6, 7,  18, 14, 15, 17, 16);  // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, cs=14 ,di=15,rw=17, reset = 16
//U8GLIB_LC7981_240X128 u8g(8, 9, 10, 11, 4, 5, 6, 7,  18, 14, 15, 17, 16);   // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, cs=14 ,di=15,rw=17, reset = 16
//U8GLIB_ILI9325D_320x240 u8g(18,17,19,U8G_PIN_NONE,16 );       // 8Bit Com: D0..D7: 0,1,2,3,4,5,6,7 en=wr=18, cs=17, rs=19, rd=U8G_PIN_NONE, reset = 16
//U8GLIB_SBN1661_122X32 u8g(8,9,10,11,4,5,6,7,14,15, 17, U8G_PIN_NONE, 16);   // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 cs1=14, cs2=15,di=17,rw=16,reset = 16
//U8GLIB_SSD1306_128X64 u8g(13, 11, 10, 9); // SW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_SSD1306_128X64 u8g(4, 5, 6, 7);  // SW SPI Com: SCK = 4, MOSI = 5, CS = 6, A0 = 7 (new white HalTec OLED)
//U8GLIB_SSD1306_128X64 u8g(10, 9);   // HW SPI Com: CS = 10, A0 = 9 (Hardware Pins are  SCK = 13 and MOSI = 11)
//U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);  // I2C / TWI 
//U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_DEV_0|U8G_I2C_OPT_NO_ACK|U8G_I2C_OPT_FAST); // Fast I2C / TWI 
//U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);  // Display which does not send AC
//U8GLIB_SSD1306_ADAFRUIT_128X64 u8g(13, 11, 10, 9);  // SW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_SSD1306_ADAFRUIT_128X64 u8g(10, 9);    // HW SPI Com: CS = 10, A0 = 9 (Hardware Pins are  SCK = 13 and MOSI = 11)
//U8GLIB_SSD1306_128X32 u8g(13, 11, 10, 9); // SW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_SSD1306_128X32 u8g(10, 9);             // HW SPI Com: CS = 10, A0 = 9 (Hardware Pins are  SCK = 13 and MOSI = 11)
//U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_NONE);  // I2C / TWI 
//U8GLIB_SSD1306_64X48 u8g(13, 11, 10, 9);  // SW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_SSD1306_64X48 u8g(10, 9);             // HW SPI Com: CS = 10, A0 = 9 (Hardware Pins are  SCK = 13 and MOSI = 11)
//U8GLIB_SSD1306_64X48 u8g(U8G_I2C_OPT_NONE); // I2C / TWI 
//U8GLIB_SH1106_128X64 u8g(13, 11, 10, 9);  // SW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_SH1106_128X64 u8g(4, 5, 6, 7); // SW SPI Com: SCK = 4, MOSI = 5, CS = 6, A0 = 7 (new blue HalTec OLED)
//U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE); // I2C / TWI 
//U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_DEV_0|U8G_I2C_OPT_FAST); // Dev 0, Fast I2C / TWI
//U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NO_ACK); // Display which does not send ACK
//U8GLIB_SSD1309_128X64 u8g(13, 11, 10, 9); // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_SSD1327_96X96_GR u8g(U8G_I2C_OPT_NONE);  // I2C
//U8GLIB_SSD1327_96X96_2X_GR u8g(U8G_I2C_OPT_NONE); // I2C
//U8GLIB_UC1611_DOGM240 u8g(U8G_I2C_OPT_NONE);  // I2C
//U8GLIB_UC1611_DOGM240 u8g(13, 11, 10, 9); // SW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_UC1611_DOGM240 u8g(10, 9);   // HW SPI Com: CS = 10, A0 = 9 (Hardware Pins are  SCK = 13 and MOSI = 11)
//U8GLIB_UC1611_DOGM240 u8g(10, 9);   // HW SPI Com: CS = 10, A0 = 9 (Hardware Pins are  SCK = 13 and MOSI = 11)
//U8GLIB_UC1611_DOGM240 u8g(8, 9, 10, 11, 4, 5, 6, 7, 18, 3, 17, 16);   // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, cs=3, di/a0=17,rw=16
//U8GLIB_UC1611_DOGXL240 u8g(U8G_I2C_OPT_NONE); // I2C
//U8GLIB_UC1611_DOGXL240 u8g(13, 11, 10, 9);  // SW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_UC1611_DOGXL240 u8g(10, 9);    // HW SPI Com: CS = 10, A0 = 9 (Hardware Pins are  SCK = 13 and MOSI = 11)
//U8GLIB_UC1611_DOGXL240 u8g(8, 9, 10, 11, 4, 5, 6, 7, 18, 3, 17, 16);   // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, cs=3, di/a0=17,rw=16
//U8GLIB_NHD_C12864 u8g(13, 11, 10, 9, 8);  // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, RST = 8
//U8GLIB_NHD_C12832 u8g(13, 11, 10, 9, 8);  // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, RST = 8
//U8GLIB_LD7032_60x32 u8g(13, 11, 10, 9, 8);  // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, RST = 8
//U8GLIB_LD7032_60x32 u8g(11, 12, 9, 10, 8);  // SPI Com: SCK = 11, MOSI = 12, CS = 9, A0 = 10, RST = 8  (SW SPI Nano Board)
//U8GLIB_UC1608_240X64 u8g(13, 11, 10, 9, 8); // SW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, RST = 8
//U8GLIB_UC1608_240X64_2X u8g(13, 11, 10, 9, 8);  // SW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, RST = 8
//U8GLIB_UC1608_240X64 u8g(10, 9, 8); // HW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, RST = 8
//U8GLIB_UC1608_240X64_2X u8g(10, 9, 8);  // HW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, RST = 8
//U8GLIB_UC1608_240X u8g(13, 11, 10, 9, 8); // SW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, RST = 8
//U8GLIB_UC1608_240X64_2X u8g(13, 11, 10, 9, 8);  // SW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, RST = 8
//U8GLIB_UC1608_240X64 u8g(10, 9, 8); // HW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, RST = 8
//U8GLIB_UC1608_240X64_2X u8g(10, 9, 8);  // HW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, RST = 8
//U8GLIB_T6963_240X128 u8g(8, 9, 10, 11, 4, 5, 6, 7, 14, 15, 17, 18, 16); // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7, cs=14, a0=15, wr=17, rd=18, reset=16
//U8GLIB_T6963_128X128 u8g(8, 9, 10, 11, 4, 5, 6, 7, 14, 15, 17, 18, 16); // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7, cs=14, a0=15, wr=17, rd=18, reset=16
//U8GLIB_T6963_240X64 u8g(8, 9, 10, 11, 4, 5, 6, 7, 14, 15, 17, 18, 16); // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7, cs=14, a0=15, wr=17, rd=18, reset=16
//U8GLIB_T6963_128X64 u8g(8, 9, 10, 11, 4, 5, 6, 7, 14, 15, 17, 18, 16); // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7, cs=14, a0=15, wr=17, rd=18, reset=16
//U8GLIB_HT1632_24X16 u8g(3, 2, 4);   // WR = 3, DATA = 2, CS = 4
//U8GLIB_SSD1351_128X128_332 u8g(13, 11, 8, 9, 7); // Arduino UNO: SW SPI Com: SCK = 13, MOSI = 11, CS = 8, A0 = 9, RESET = 7 (http://electronics.ilsoft.co.uk/ArduinoShield.aspx)
//U8GLIB_SSD1351_128X128_332 u8g(76, 75, 8, 9, 7); // Arduino DUE: SW SPI Com: SCK = 13, MOSI = 11, CS = 8, A0 = 9, RESET = 7 (http://electronics.ilsoft.co.uk/ArduinoShield.aspx)
//U8GLIB_SSD1351_128X128_332 u8g(8, 9, 7); // Arduino: HW SPI Com: SCK = 13, MOSI = 11, CS = 8, A0 = 9, RESET = 7 (http://electronics.ilsoft.co.uk/ArduinoShield.aspx)
//U8GLIB_SSD1351_128X128_HICOLOR u8g(76, 75, 8, 9, 7); // Arduino DUE, SW SPI Com: SCK = 76, MOSI = 75, CS = 8, A0 = 9, RESET = 7 (http://electronics.ilsoft.co.uk/ArduinoShield.aspx)
//U8GLIB_SSD1351_128X128_HICOLOR u8g(8, 9, 7); // Arduino, HW SPI Com: SCK = 76, MOSI = 75, CS = 8, A0 = 9, RESET = 7 (http://electronics.ilsoft.co.uk/ArduinoShield.aspx)
//U8GLIB_SSD1351_128X128GH_332 u8g(8, 9, 7); // Arduino, HW SPI Com: SCK = 76, MOSI = 75, CS = 8, A0 = 9, RESET = 7 (Freetronics OLED)
//U8GLIB_SSD1351_128X128GH_HICOLOR u8g(8, 9, 7); // Arduino, HW SPI Com: SCK = 76, MOSI = 75, CS = 8, A0 = 9, RESET = 7 (Freetronics OLED)
U8GLIB_SH1106_128X64 u8g(13, 11, 10, 9, 8);
const uint8_t rook_bitmap[] PROGMEM = {
  0x00,0x00,0x00,0x00,0x0a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x05,0xf0,0x00,0xf8,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x02,0xaa,0xfa,0xff,0xfe,0xe0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x10,0x7f,0xff,0xff,0xfd,0x00,0x00,0x00,
  0x00,0x00,0x00,0x08,0xaa,0xbf,0xff,0xff,0xfe,0x80,0x00,0x00,
  0x00,0x00,0x00,0x00,0x1e,0x7f,0xff,0xff,0xff,0xc0,0x00,0x00,
  0x00,0x00,0x00,0x0a,0xbe,0xff,0xff,0xff,0xff,0xf8,0x00,0x00,
  0x00,0x00,0x01,0x1f,0xff,0xff,0xff,0xff,0xff,0xfc,0x00,0x00,
  0x00,0x00,0x07,0xfe,0xea,0xff,0xff,0xff,0xff,0xfe,0x00,0x00,
  0x00,0x00,0x1f,0xd4,0x40,0x0f,0xff,0xff,0xff,0xff,0x80,0x00,
  0x00,0x00,0x3e,0xaa,0xa0,0x02,0xbf,0xff,0xff,0xff,0x80,0x00,
  0x00,0x01,0xff,0xf5,0x00,0x00,0x01,0xff,0xff,0xff,0xe0,0x00,
  0x00,0x03,0xfe,0xaa,0xa8,0x08,0x88,0xaf,0xff,0xff,0xe8,0x00,
  0x00,0xdf,0xff,0xfd,0x40,0x00,0x00,0x07,0xff,0xff,0xfc,0x00,
  0x02,0xbf,0xff,0xaa,0xa0,0x00,0xaa,0x02,0xbf,0xff,0xfe,0x00,
  0x55,0xff,0xff,0xd7,0x40,0x00,0x77,0x00,0x3f,0xff,0xff,0x00,
  0xaa,0xfe,0xae,0xaa,0xa8,0x00,0xea,0x80,0xaf,0xff,0xfe,0x80,
  0x5f,0xff,0xdf,0xdd,0xc0,0x00,0x7f,0xc0,0xaf,0xff,0xff,0xc0,
  0xaf,0xfa,0xaa,0xaa,0xa8,0x02,0xfb,0xa0,0x2f,0xff,0xff,0x80,
  0x7f,0xfc,0x7f,0xff,0xf0,0x01,0xff,0xc0,0x07,0xff,0xff,0xc0,
  0xbf,0xea,0xaa,0xfe,0xe8,0x0a,0xeb,0xe0,0x0b,0xff,0xff,0xe0,
  0xff,0xd0,0x55,0xff,0xfc,0x07,0xff,0xc0,0x01,0xff,0xff,0xf0,
  0xff,0xea,0xaa,0xff,0xba,0x0a,0xfb,0xe0,0x03,0xff,0xff,0xf0,
  0xff,0xe1,0x41,0xff,0xfc,0x07,0xff,0xe0,0x01,0xff,0xff,0xf0,
  0xff,0xea,0xa8,0xfa,0xae,0x8a,0xff,0xe0,0x82,0xff,0xff,0xf0,
  0xff,0xc1,0xd0,0x7d,0xfc,0x07,0xff,0xc0,0x01,0xff,0xff,0xff,
  0xff,0xea,0xa8,0x3a,0xb8,0xaa,0xbf,0xe0,0x22,0xff,0xff,0xf8,
  0xff,0xf1,0xf0,0x1d,0xf0,0x07,0xff,0xc0,0x01,0xff,0xff,0xf8,
  0xff,0xea,0xe8,0x3e,0xf8,0x8a,0xff,0x80,0x8a,0xff,0xff,0xf8,
  0xff,0xf1,0xf0,0x1d,0xf8,0x07,0xff,0xc0,0x01,0xff,0xff,0xf8,
  0xff,0xea,0xe0,0x3b,0xfa,0x02,0xff,0x80,0x22,0xff,0xff,0xf8,
  0xff,0xf1,0xe0,0x1f,0xf0,0x01,0x7f,0x00,0x01,0xff,0xff,0xf8,
  0xff,0xea,0xe8,0x3b,0xe8,0x00,0xaa,0x80,0x8a,0xff,0xff,0xf8,
  0xff,0xc1,0xe0,0x7f,0xfc,0x00,0x1c,0x00,0x01,0xff,0xff,0xf8,
  0xff,0xab,0xe0,0x3b,0xf8,0x00,0xaa,0xa0,0x22,0xff,0xff,0xf8,
  0xff,0xd1,0xf0,0x7f,0xf0,0x00,0xac,0x00,0x01,0xff,0xff,0xf0,
  0xff,0xaa,0xc8,0x3b,0xf8,0xaa,0xaa,0x88,0x8a,0xff,0xff,0xe0,
  0xff,0xc7,0xf0,0x7f,0xf0,0x03,0xfc,0x00,0x00,0xff,0xff,0xf0,
  0xff,0xaa,0xaa,0x3b,0xea,0xab,0xfe,0x82,0x22,0xbf,0xff,0xe0,
  0xff,0xd5,0x75,0xff,0xf0,0x17,0xff,0x00,0x01,0x7f,0xff,0xe0,
  0xff,0xea,0xab,0xfa,0xea,0xaf,0xfe,0x88,0x8a,0xbf,0xff,0xe0,
  0xff,0xf5,0xdf,0xfc,0xf0,0x0f,0xff,0x00,0x00,0xff,0xff,0xe0,
  0xff,0xfa,0xab,0xfa,0xaa,0xaa,0xff,0x80,0x22,0xff,0xff,0xe0,
  0xff,0xff,0xff,0xfd,0xf0,0x1f,0xff,0x80,0x01,0xff,0xff,0xc0,
  0xff,0xfe,0xef,0xfe,0xe8,0xbf,0xef,0x88,0x8a,0xff,0xff,0x80,
  0xff,0xff,0xff,0xff,0xc0,0x0f,0xff,0xc0,0x01,0xff,0xff,0xc0,
  0xbf,0xff,0xfb,0xaa,0xa0,0x3b,0xaf,0xa2,0xaa,0xff,0xff,0x80,
  0x7f,0xff,0xff,0xff,0x40,0x1f,0xff,0x80,0x01,0xff,0xff,0x00,
  0xab,0xff,0xfe,0xea,0x80,0xcf,0xef,0x8a,0xaa,0xff,0xfe,0x80,
  0xdd,0xff,0xff,0xfc,0x00,0x1f,0xdf,0x00,0x07,0xff,0xff,0x00,
  0xaa,0xff,0xfa,0xaa,0xa0,0x2f,0xae,0xaa,0xab,0xff,0xf4,0x00,
  0x55,0x7f,0xff,0xfd,0x00,0x1f,0xff,0x00,0x17,0xff,0xff,0x00,
  0xaa,0xaf,0xfe,0xea,0x88,0xae,0xbe,0xaa,0xaf,0xff,0xfe,0x00,
  0xb5,0x51,0xff,0xfd,0x00,0x0f,0xfc,0x45,0xff,0xff,0xfc,0x00,
  0x2a,0x00,0xff,0xaa,0xaa,0xaa,0xfa,0xab,0xff,0xff,0xf8,0x00,
  0x40,0x00,0x17,0xff,0x41,0x57,0xff,0xff,0xff,0xff,0xf0,0x00,
  0x00,0x00,0x00,0xfe,0xea,0xff,0xff,0xff,0xff,0xfe,0xe0,0x00,
  0x00,0x00,0x01,0x5f,0xff,0xff,0xff,0xff,0xff,0xfc,0x00,0x00,
  0x00,0x00,0x02,0xaa,0xaf,0xff,0xff,0xff,0xff,0xf8,0x00,0x00,
  0x00,0x00,0x00,0x07,0xff,0xff,0xff,0xff,0xff,0xf0,0x00,0x00,
  0x00,0x00,0x00,0x00,0xef,0xff,0xff,0xff,0xff,0xe0,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xfc,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x98,0x00,0x00,0x00
};

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.drawBitmapP( 0, 0, 12, 63, rook_bitmap);
}

void setup(void) {
}

void loop(void) {
  // picture loop
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(1000);
}
