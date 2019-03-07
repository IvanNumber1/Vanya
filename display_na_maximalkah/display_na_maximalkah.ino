// функции даты и времени с использованием часов реального времени DS1307, подключенные по I2C. В скетче используется библиотека Wire lib
#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal_PCF8574.h>
#include "stDHT.h"
DHT sens(DHT22); // Указать датчик DHT11, DHT21, DHT22
LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display
#define Gas A3 // аналоговый выход MQ135 подключен к пину A0 Arduino
int ZnacheniyaGasa; // для аналогового значения

  int t ; // чтение датчика на пине 2
  int h ;    // чтение датчика на пине 2
int show;

int i;
RTC_DS1307 RTC;

void setup () {
  pinMode(Gas,INPUT);
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  ////////////////////
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

     } 
   else {
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

void timer(){
  for(int o=0;o<=4;o++){
    DateTime now = RTC.now();
    //lcd.clear();
    lcd.home();
    if(now.day() < 10){
      lcd.print("0");
      lcd.print(now.day(), DEC);
    }
    else{
      lcd.print(now.day(), DEC);
    }
    lcd.write("/");
    if(now.month() < 10){
      lcd.print("0");
      lcd.print(now.month(), DEC);
    }
    else{
      lcd.print(now.month(), DEC);
    }
    lcd.write("/");
    lcd.print(now.year(), DEC);
    lcd.setCursor(0,1);
    if(now.hour() < 10){
      lcd.print("0");
      lcd.print(now.hour(), DEC);
    }
    else{
      lcd.print(now.hour(), DEC);
    }
    lcd.write(":");
    if(now.minute() < 10){
      lcd.print("0");
      lcd.print(now.minute(), DEC);
    }
    else{
      lcd.print(now.minute(), DEC);
    }
    lcd.write(":");
    if(now.second() < 10){
      lcd.print("0");
      lcd.print(now.second(), DEC);
    }
    else{
      lcd.print(now.second(), DEC);
    }
    delay(1000);
  }
}
void temp_and_hum(){
  for(int o = 0;o < 2;o++){
    lcd.home();
    t = sens.readTemperature(2); // чтение датчика на пине 2
    h = sens.readHumidity(2); 
    lcd.print("Hum: ");
    lcd.print(h);
    lcd.write(" %");
    lcd.setCursor(0,1);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print(" C ");
    delay(2000);
  }
}
void gasi(){
    ZnacheniyaGasa = analogRead(Gas); 
    lcd.print("CO2");
    lcd.write(": ");
    lcd.print(ZnacheniyaGasa);
    delay(4000);
}

void loop () {
  lcd.setBacklight(1);
  temp_and_hum();
  lcd.clear();
  timer();
  lcd.clear();
  gasi();
  lcd.clear();
}
