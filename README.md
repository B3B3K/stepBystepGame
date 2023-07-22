# TO DO LIST:
---
1. add side switch for controlling
2. oled should be 64*32
3. made targets, ball and scrolling thing 1px height
4. make a physics
5. FINISH THE GAME

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
