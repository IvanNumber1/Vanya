#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int show;

void setup()
{
  int error;

  Serial.begin(9600);
  Serial.println("LCD...");

  while (! Serial);

  Serial.println("Dose: check for LCD");

  // See http://playground.arduino.cc/Main/I2cScanner
  Wire.begin();
  Wire.beginTransmission(0x27);
  error = Wire.endTransmission();
  Serial.print("Error: ");
  Serial.print(error);

  if (error == 0) {
    Serial.println(": LCD found.");

  } else {
    Serial.println(": LCD not found.");
  } // if

  lcd.begin(16, 2); // initialize the lcd
  show = 0;
  lcd.home();
} // setup()

void loop() {
  // put your main code here, to run repeatedly:
lcd.clear();  
lcd.print("dark");
lcd.setBacklight(0);
for(int i=0;i<16;i++){
lcd.scrollDisplayRight();
delay(250);
}
lcd.clear();  
lcd.setCursor(11,1);
lcd.print("light");
lcd.setBacklight(1);
for(int i=16;i>0;i--){
lcd.scrollDisplayLeft();
delay(250);
}
}
