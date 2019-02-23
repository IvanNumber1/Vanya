#include <Servo.h> //используем библиотеку для работы с сервоприводом
#include"timer-api.h"
Servo servo; //объявляем переменную servo типа Servo
int i;
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
for(i=0;i<180;i++){
servo.write(i); 
radar(); 
}
for(i=180;i>0;i--){
servo.write(i); 
radar(); 
}
if(distance<10){
  Serial.println(distance);
  servo.write(i);
}
}
