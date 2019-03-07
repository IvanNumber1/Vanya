// функции даты и времени с использованием часов реального времени DS1307, подключенные по I2C. В скетче используется библиотека Wire lib
#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int show;
int i;
RTC_DS1307 RTC;

void setup () {
  int error;
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
Serial.begin(57600);

RTC.begin();

if (! RTC.isrunning()) {

Serial.println("RTC is NOT running!");

// строка ниже используется для настройки даты и времени часов

RTC.adjust(DateTime(__DATE__, __TIME__));

}

}

void loop () {

DateTime now = RTC.now();

lcd.setBacklight(1);
lcd.clear();
lcd.print(now.day(), DEC);
lcd.write("/");
lcd.print(now.month(), DEC);
lcd.write("/");
lcd.print(now.year(), DEC);
lcd.setCursor(0,1);
lcd.print(now.hour(), DEC);
lcd.write(":");
lcd.print(now.minute(), DEC);
lcd.write(":");
lcd.print(now.second(), DEC);

delay(1000);
Serial.print(now.day(), DEC);
Serial.print("/");
Serial.print(now.month(), DEC);
Serial.print("/");
Serial.print(now.year(), DEC);
Serial.println();
Serial.print(now.hour(), DEC);
Serial.print(":");
Serial.print(now.minute(), DEC);
Serial.print(":");
Serial.println(now.second(), DEC);
}
