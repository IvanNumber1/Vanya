#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int show;
int i;
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
lcd.clear();
lcd.setBacklight(1);
i = 0;
lcd.setCursor(0,i);
lcd.print("menu");
i = 1;
lcd.setCursor(0,i);
lcd.print("exit");
delay(1000);
lcd.clear();
i = 0;
lcd.setCursor(0,i);
lcd.print("exit");
i = 1;
lcd.setCursor(0,i);
lcd.print("help");
delay(1000);
}
