#include "RTClib.h"
#include <LiquidCrystal_PCF8574.h>
#include "stDHT.h"
#define Gas A3 // аналоговый выход MQ135 подключен к пину A3 Arduino

DHT sens(DHT22); // Указать датчик DHT11, DHT21, DHT22
LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display
RTC_DS1307 RTC;

int clk = A2;
int dt = A1;
int sw = 10;
int led1Pin = 13;


  int flag = 0;
  int ZnacheniyaGasa; // для аналогового значения
  int i = 1;
  int t ; // чтение датчика на пине 2
  int h ;    // чтение датчика на пине 2
  int w = 1;
  int show;
  int button;
  int DT;
  int CLK;

  int switchPin = sw;              // switch is connected to pin 2

  int val;                        // variable for reading the pin status
  int val2;                       // variable for reading the delayed/debounced status
  int buttonState;                // variable to hold the button state

  int lightMode = 1; 

const int buttonPin=10;// вывод кнопки 0 нажата 1 нет
uint32_t last_millis; // переменные: последний  millis

uint8_t botton(){
  if (digitalRead(buttonPin) == 1){   
     last_millis = millis();
     return 0;
     }
     delay(5);
     while (digitalRead(buttonPin) == 0);
     delay(5);
   if (last_millis+65 > millis()){ // ложное срабатывание
        last_millis = millis();
     return 0;
   }
   if (last_millis+500 > millis()){ // короткое нажатие меньше 0.50 сек
     last_millis = millis();
     return 1;
   }
   last_millis = millis(); // длинное нажатие больше 0.50 сек
   return 2;
}


void setup () {
  Serial.begin(9600);
  RTC.begin();
  lcd.begin(16, 2); // initialize the lcd
  
  pinMode(clk,INPUT);
  pinMode(dt,INPUT);
  pinMode(sw,INPUT_PULLUP);
  pinMode(Gas,INPUT);
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  pinMode(switchPin, INPUT);    // Set the switch pin as input
  pinMode(led1Pin, OUTPUT);
   pinMode(buttonPin, INPUT_PULLUP); // вывод на ввод с подтягивающим резистром 
  last_millis = millis();  
  buttonState = digitalRead(switchPin); 
  
  show = 0;
  lcd.home();
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
    delay(5);
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
   /////////////////////
   if(CLK > 50 && DT > 50){///////////////////////////////////////
    ////////////////////
      lcd.setBacklight(lightMode);
      DT = analogRead(dt);
      CLK = analogRead(clk);
     if(w == 0){
      if(i%2 == 1||i%2 == -1){
        lcd.home();
        lcd.write("*");
        lcd.print("BYDILbNIK");
        lcd.setCursor(0,1);
        lcd.print("BblNTN");    
      }
      if(i%2 == 0){
        lcd.home();
        lcd.print("BYDILbNIK");
        lcd.setCursor(0,1);
        lcd.write("*");
        lcd.print("EXIT");
      switch (botton()) {
       case 1:  
          w = 1;
         lcd.clear();
        break;
      }
   }
    }
     else{
      if(i%3 == 1 || i%3 == -1){
        temp_and_hum();
      }
      if(i%3 == 2 || i%3 == -2){
        timer();
      }
      if(i%3 == 0){
        gasi();
      }
 }
///////////////////////
  switch (botton()) {
      case 1:  
      w = 1;
         lcd.clear();
         if (lightMode == 0) {       // is the light off?
           lightMode = 1;               // turn light on!
        } 
         else {
           lightMode = 0;               // turn light off!
        }
         break;
      case 2:
         w = 0;
         lcd.clear();
       break;
   }
///////////////////////
}
}
}
