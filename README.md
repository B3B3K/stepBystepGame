#TIPS:
---
1. (v2). When u converting image to byte array, ___"DRAW MODE"___ shuld be ___"verticaL 1Bit per byte"___
2. (v2). oled librarys default, gets vertical value sperated by ___default value___
>Display = 128x64 -->  64 = default_value (8) * n
>I wrote 8 to default_value cause using oled font library (5x5_font.h) haves this:
```plaintext
const DCfont TinyOLEDFont5x5 = {
  (uint8_t *)ssd1306xled_font5x5,
  6, // character width in pixels
  1, // character height in pages (8 pixels)
  32,127 // ASCII extents
  };
```
>For example if i wanna write to 32 (y), i should write it like:
```plaintext
oled.setCursor(x, 4 ); // 8 (default_value) * n (4) = 32
```
# TO DO LIST:
---
1. add side switch for controlling 
>> now works with one button
3. oled should be 64*32 (made it)
4. made targets, ball and scrolling thing 1px height 
>> now enemy and target is your time 
6. make a physics 
>> why?
8. FINISH THE GAME (made it)

#FIRST VERSION:
---
```plaintext 
void loop() {
int swL = digitalRead(PB3);int swR = digitalRead(PB4);int swM = digitalRead(PB5);
if (swM == 1){
if (swL == 1){y_axis = y_axis + 1;swL = 0;//L}
if (swR == 1){y_axis = y_axis - 1;swR = 0;//R}}

oled.setCursor(y_axis_demo,54);y_axis_demo = y_axis_demo + 1;oled.print("yo!");oled.on();delay(100);oled.clear();swM = 0;
}
```

#SECOND VERSION:
---
```plaintext

uint8_t new_x = ball_x + ball_dir_x;uint8_t new_y = ball_y + ball_dir_y;
        //check wall horizontal
if(new_x == 0 || new_x == 128) {ball_dir_x = -ball_dir_x;new_x += ball_dir_x + ball_dir_x;}
        //check wall vertical
if(new_y <= 0 || new_y >= 8) {ball_dir_y = -ball_dir_y;new_y += ball_dir_y + ball_dir_y;}
        //print 
oled.setCursor(ball_x, ball_y );oled.startData();oled.sendData(0x0);oled.endData();oled.setCursor(new_x, new_y);oled.startData();oled.sendData(0x6);oled.endData();oled.setCursor(31,31);oled.print(new_y);
        //set values for next step
ball_x = new_x;ball_y = new_y;   

```

#FORGET ABOUT project
---
bug but gold :)  
```plaintext

  uint8_t new_x = ball_x + ball_dir_x; uint8_t new_y = ball_y + ball_dir_y;
  //check

  if (new_x == 0 || new_x == 64) {
    ball_dir_x = -ball_dir_x;
    new_x += ball_dir_x + ball_dir_x;
  }
  //check
  if (new_y == 0  || new_y == 4) {
    ball_dir_y = -ball_dir_y;
    new_y += ball_dir_y + ball_dir_y;
  }
  oled.setCursor(new_x,new_y);
  oled.startData();
  oled.sendData(0b11111111);
  oled.repeatData(0b10000000, width - 2);
  oled.endData();
```
#What I Did?
---
1. 128x64.ino
>   first demo of buttons with text
3. ArduBreakout.ino
> Bitmap print with animation
4. ATpiyan0.ino
> BUG BUT GOLD!!!

