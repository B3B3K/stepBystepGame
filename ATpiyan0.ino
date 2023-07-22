#include <Tiny4kOLED.h>

uint8_t width = 64;
uint8_t height = 32;
uint8_t ball_x = 8, ball_y = 2;
uint8_t ball_dir_x = 1, ball_dir_y = 1;


#include <TinyWireM.h>
#define TINY4KOLED_QUICK_BEGIN
int state_b;
int buzzer = 4;

const unsigned char bitma[] PROGMEM = {

  // 'notes32', 64x8px
  0x00, 0x3f, 0x21, 0x21, 0x3e, 0x28, 0x38, 0x00, 0x3e, 0x09, 0x3d, 0x27, 0x25, 0x25, 0x20, 0x00,
  0x3f, 0x02, 0x04, 0x02, 0x3f, 0x38, 0x3a, 0x00, 0x3f, 0x09, 0x01, 0x02, 0x3e, 0x16, 0x3c, 0x00,
  0x27, 0x25, 0x25, 0x3d, 0x24, 0x3c, 0x3f, 0x00, 0x3f, 0x20, 0x20, 0x38, 0x28, 0x38, 0x3c, 0x00,
  0x27, 0x25, 0x25, 0x3d, 0x3c, 0x3d, 0x00, 0x00, 0x3f, 0x21, 0x21, 0x21, 0x3e, 0x28, 0x38, 0x00
};

int new_y, new_x;
void setup() {
  oled.begin(width, height, sizeof(tiny4koled_init_64x32br), tiny4koled_init_64x32br);
  oled.off();
  delay(500);
  oled.on();
  oled.clear();
  oled.bitmap(0, 0, 64, 1, bitma);
  int stat = 1;
  pinMode(3, INPUT);
  pinMode(4,OUTPUT);
  randomSeed(analogRead(1));
}

void loop() {
  uint8_t new_x = ball_x + ball_dir_x; uint8_t new_y = ball_y + ball_dir_y;
  state_b = digitalRead(3);
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
  oled.repeatData(0b10000000, width);
  oled.endData();
  if (state_b == HIGH) {
    
    if(new_x >0 and new_x < 9){
      tone(buzzer,300,100);      
      }
    if(new_x >8 and new_x < 17){
      tone(buzzer,400,100);      
      }
    if(new_x >16 and new_x < 25){
      tone(buzzer,500,100);     
      }
    if(new_x >24 and new_x < 33){
      tone(buzzer,600,100);      
      }

    if(new_x >32 and new_x < 41){
      tone(buzzer,700,100);     
      }
    if(new_x >40 and new_x < 49){
      tone(buzzer,800,100);      
      }
    if(new_x >48 and new_x < 57){
      tone(buzzer,900,100);     
      }
    if(new_x >56 and new_x < 65){
      tone(buzzer,1000,100);     
      }

    int rNbrr = random(2); // Will return 0 or 1
    if (rNbrr == 0) yY();
    if (rNbrr == 1) xX();
    
  }

  
  ball_x = new_x; ball_y = new_y;
}
void yY(){
  ball_dir_y = -ball_dir_y;
  new_y += ball_dir_y + ball_dir_y;
  }
void xX (){
  ball_dir_x = -ball_dir_x;
  new_x += ball_dir_x + ball_dir_x;
  }
