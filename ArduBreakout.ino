#include <Tiny4kOLED.h>

uint8_t width = 128;
uint8_t height = 64;
uint8_t ball_x = 8, ball_y = 0;
uint8_t ball_dir_x = 1, ball_dir_y = 1;



/**
 * Made with Marlin Bitmap Converter
 * https://marlinfw.org/tools/u8glib/converter.html
 *
 * This bitmap from the file 'tesst.jpg'
 */
/**
 * Made with Marlin Bitmap Converter
 * https://marlinfw.org/tools/u8glib/converter.html
 *
 * This bitmap from the file 'note.bmp'
 */
/**
 * Made with Marlin Bitmap Converter
 * https://marlinfw.org/tools/u8glib/converter.html
 *
 * This bitmap from the file 'do.bmp'
 */

const unsigned char bitma[] PROGMEM = {
// 'tesst', 128x8px
0x00, 0x7e, 0x42, 0x44, 0x48, 0x52, 0x66, 0x4a, 0x12, 0x22, 0x42, 0x46, 0x4c, 0x78, 0x00, 0xff, 
0x00, 0x7e, 0x12, 0x14, 0x6c, 0x00, 0x00, 0x7c, 0x52, 0x56, 0x72, 0x56, 0x52, 0x00, 0x00, 0xff, 
0x00, 0x7e, 0x7c, 0x08, 0x10, 0x08, 0x7e, 0x00, 0x0c, 0x48, 0x7a, 0x48, 0x0c, 0x00, 0x00, 0xff, 
0x00, 0x7e, 0x12, 0x52, 0x02, 0x7e, 0x7e, 0x12, 0x7e, 0x06, 0x62, 0x0a, 0x7e, 0x00, 0x00, 0x00, 
0xff, 0x00, 0x48, 0x56, 0x72, 0x40, 0x40, 0x00, 0x7c, 0x44, 0x42, 0x78, 0x00, 0x7c, 0x60, 0x00, 
0xff, 0x00, 0x00, 0x7e, 0x40, 0x40, 0x58, 0x34, 0x62, 0x74, 0x38, 0x7c, 0x00, 0x00, 0x00, 0x00, 
0xff, 0x00, 0x00, 0x20, 0x40, 0x48, 0x54, 0x62, 0x44, 0x00, 0x04, 0x72, 0x04, 0x00, 0x00, 0x00, 
0xff, 0x00, 0x00, 0x00, 0x7e, 0x44, 0x28, 0x10, 0x03, 0x0c, 0x51, 0x50, 0x51, 0x0c, 0x03, 0x00
};


#include "5x5_font.h"
const DCfont *currentFont = FONT5X5;
void setup() {
  oled.begin(width, height, sizeof(tiny4koled_init_128x64br), tiny4koled_init_128x64br);
  oled.setFont(currentFont);
  oled.off();
  delay(500);
  oled.on();
  oled.clear();
  oled.bitmap(0,0,128,1,bitma);
}

void loop() {
        
        uint8_t new_x = ball_x + ball_dir_x;
        uint8_t new_y = ball_y + ball_dir_y;

        // Check if we hit the vertical walls
        if(new_x == 0 || new_x == 128) {
            ball_dir_x = -ball_dir_x;
            new_x += ball_dir_x + ball_dir_x;
        }

        // Check if we hit the horizontal walls.
        if(new_y <= 0 || new_y >= 8) {
            ball_dir_y = -ball_dir_y;
            new_y += ball_dir_y + ball_dir_y;
        }
        oled.setCursor(ball_x, ball_y );
        oled.startData();
        oled.sendData(0x00000000);
        oled.endData();
        oled.setCursor(new_x, new_y );
        oled.startData();
        oled.sendData(0x6);
        oled.endData();
        oled.setCursor(31,31);
        oled.print(new_y);
        ball_x = new_x;
        ball_y = new_y;
       
}
