#include <Servo.h>
Servo LNOGA;  // Первый сервопривод
Servo PNOGA;
Servo LBEDRO;
Servo PBEDRO;
void setup() {
  LNOGA.attach(9);   // Указваем объекту класса Servo, что серво присоединен к пину 9
  PNOGA.attach(10);  // А этот servo присоединен к 10 пину
  LBEDRO.attach(11);
  LBEDRO.attach(12);

}
void loop() {
  LNOGA.write(30); 
  delay(200);
  LNOGA.write(150); 
}
