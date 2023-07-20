#include "TinyWireM.h"
#include "Tiny4kOLED.h"

#include "5x5_font.h"
int y_axis = 0;
int y_axis_demo = 0;
const DCfont *currentFont = FONT5X5;
uint8_t width = 128;
uint8_t height = 64;
uint8_t currentCharacter;
int button_state = LOW;
void setup() {
  oled.begin(width, height, sizeof(tiny4koled_init_128x64br), tiny4koled_init_128x64br);
  oled.setFont(currentFont);
  pinMode(PB3, INPUT);pinMode(PB4, INPUT);pinMode(PB5, INPUT);
  oled.on();
}

void loop() {
int swL = digitalRead(PB3);
int swR = digitalRead(PB4);
int swM = digitalRead(PB5);
if (swM == 1)
{
if (swL == 1)
{
  y_axis = y_axis + 1;
  swL = 0;

  //L
}

if (swR == 1)
{
  y_axis = y_axis - 1;
  swR = 0;
  //R
}

}
oled.setCursor(y_axis_demo,54);
y_axis_demo = y_axis_demo + 1;
oled.print("yo!");
oled.on();
delay(100);
oled.clear();
swM = 0;
}
