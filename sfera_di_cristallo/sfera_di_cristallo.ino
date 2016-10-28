#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(switchPin, INPUT);
  lcd.print("Interroga");
  lcd.setCursor(0,1);
  lcd.print("la Sfera!");
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState){
    if(switchState == LOW){
      reply = random(5);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("la Sfera dice...");
      lcd.setCursor(0,1);
      switch(reply){
        case 0: lcd.print("Ricchione");
          break;
        case 1: lcd.print("Femminiello");
          break;
        case 2 : lcd.print("Gino gay");
          break;
        case 3 : lcd.print("Pergolone");
          break;
        case 4 : lcd.print("Florinda ti amo");
      }
    }
  }
  prevSwitchState = switchState;
}
