// функции даты и времени с использованием часов реального времени DS1307, подключенные по I2C. В скетче используется библиотека Wire lib
#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal_PCF8574.h>
#include "stDHT.h"
DHT sens(DHT22); // Указать датчик DHT11, DHT21, DHT22
LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display
#define Gas A3 // аналоговый выход MQ135 подключен к пину A0 Arduino


int flag = 0;
int o = 0;
int ZnacheniyaGasa; // для аналогового значения
  int i = 1;
  int t ; // чтение датчика на пине 2
  int h ;    // чтение датчика на пине 2
int show;
int clk = A2;
int dt = A1;
int sw = 10;
int button;
int DT;
int CLK;


int switchPin = sw;              // switch is connected to pin 2
int led1Pin = 13;

int val;                        // variable for reading the pin status
int val2;                       // variable for reading the delayed/debounced status
int buttonState;                // variable to hold the button state

int lightMode = 0; 
RTC_DS1307 RTC;

void setup () {
  pinMode(clk,INPUT);
  pinMode(dt,INPUT);
  pinMode(sw,INPUT_PULLUP);
  pinMode(Gas,INPUT);
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  pinMode(switchPin, INPUT);    // Set the switch pin as input
  pinMode(led1Pin, OUTPUT);
  buttonState = digitalRead(switchPin); 
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
  Serial.begin(9600);

  RTC.begin();

  if (! RTC.isrunning()) {

    Serial.println("RTC is NOT running!");

    // строка ниже используется для настройки даты и времени часов

    RTC.adjust(DateTime(__DATE__, __TIME__));

   }

 }

void timer(){
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
}
void temp_and_hum(){
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
}
void gasi(){
    ZnacheniyaGasa = analogRead(Gas); 
    lcd.print("CO2");
    lcd.write(": ");
    if (ZnacheniyaGasa < 100){
      lcd.print("0");
    }
    lcd.print(ZnacheniyaGasa);
    lcd.home();
}

void loop () {
    while(1){
  if(CLK < 50 && DT < 50){
  
}
if(DT < 50){
  while(DT < 50 || CLK < 50){
    DT = analogRead(dt);
    CLK = analogRead(clk);   
    delay(5);
    lcd.clear();
  }
  i++;
  Serial.println("Left");
}
if(CLK < 50){
  while(DT < 50 || CLK < 50){
    DT = analogRead(dt);
    CLK = analogRead(clk);
    delay(5);
    lcd.clear();
  }
  i--;
  Serial.println("Right");
}
if(CLK > 50 && DT > 50){
  lcd.setBacklight(lightMode);
  DT = analogRead(dt);
  CLK = analogRead(clk);
  if(i%3 == 1 || i%3 == -1){
  temp_and_hum();
  }
  if(i%3 == 2 || i%3 == -2){
  timer();
  }
  if(i%3 == 0){
  gasi();
  delay(1);
  }
}
///////////////////////
 val = digitalRead(switchPin);      // read input value and store it in val
  delay(10);                         // 10 milliseconds is a good amount of time
  val2 = digitalRead(switchPin);     // read the input again to check for bounces
  if (val == val2) {                 // make sure we got 2 consistant readings!
    if (val != buttonState) {          // the button state has changed!
      if (val == LOW) {                // check if the button is pressed
        if (lightMode == 0) {         // is the light off?
          lightMode = 1;               // turn light on!
        } else {
          lightMode = 0;               // turn light off!
        }
      }
    }
    buttonState = val;         
  }
///////////////////////
}
}
