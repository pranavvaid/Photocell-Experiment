#include <LiquidCrystal.h>
LiquidCrystal lcd(3, 2, 4, 5, 6, 7); //Define the pins for the LCD
int threshold1 = 11;
int threshold2 = 60;
int background;
void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  delay(30);
  analogWrite(9,255);
  analogWrite(10,255);
  analogWrite(11,255);
  delay(100);
  for(int i=1;i<30;i++){
    if(i == 1){
      int sum = 0;
    }
    int tem = analogRead(A0);
    Serial.print("Reading: ");
    Serial.println(tem);
    int sum = sum + tem;
    background = sum/i;
    Serial.println(background);
    delay(50);
  }
  
  Serial.println("done");
}

void loop() {  
  
  int value = analogRead(A0);
  Serial.print("Val: ");
  Serial.println(value);
  if(value>threshold1 + background && value<threshold2 +background){
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("A thing is near  ");
    delay(100);
  }
  if(value>threshold2 +background){
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("It's here...   ");
    delay(100);
  }
  if(value<threshold1+background){
    lcd.setCursor(0,0);
    lcd.print("It's all ok... ");
  }
  delay(50);
}
