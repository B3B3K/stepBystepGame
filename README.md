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
