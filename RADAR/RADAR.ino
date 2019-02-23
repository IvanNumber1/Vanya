#include <Servo.h> //используем библиотеку для работы с сервоприводом
Servo servo; //объявляем переменную servo типа Servo
int trigPin = 8; 
int echoPin = 11;  
int duration, distance;
void setup() //процедура setup
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
servo.attach(10); //привязываем привод к порту 10
}
void radar()
{
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH); 
  distance = duration / 58;
}
void loop() //процедура loop
{
servo.write(0); //ставим вал под 0
delay(2000); //ждем 2 секунды
radar();
while(distance<0){
  radar();
}
Serial.println(distance);
servo.write(180); //ставим вал под 180
delay(2000); //ждем 2 секунды
radar();
while(distance<0){
  radar();
}
Serial.println(distance);
}
