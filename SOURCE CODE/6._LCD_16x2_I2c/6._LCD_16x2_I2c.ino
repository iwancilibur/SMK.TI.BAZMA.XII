#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
 Serial.begin(115200);
 lcd.begin();
}

void loop() { 
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("HALLO ^_^");
  lcd.setCursor(0,1);lcd.print("IWAN CILIBUR");
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("HALLO ^_^");
  lcd.setCursor(0,1);lcd.print("ROBOTIKA");
  delay(1000);
}
