#include <Wire.h> 
#include <ZumoShield.h> 

#define LED 13 

int duration, cm; 
int trigPin = 13; 
int echoPin = 12; 
int chislo; 
// this might need to be tuned for different lighting conditions, surfaces, etc. 
#define QTR_THRESHOLD 1500 // microseconds 

// these might need to be tuned for different motor types 
#define REVERSE_SPEED 200 // 0 is stopped, 400 is full speed 
#define TURN_SPEED 200 
#define FORWARD_SPEED 155 
#define REVERSE_DURATION 200 // ms 
int TURN_DURATION = 225; // ms 
#define RUN_SPEED 230 
ZumoBuzzer buzzer; 
ZumoMotors motors; 
Pushbutton button(ZUMO_BUTTON); // pushbutton on pin 12 

#define NUM_SENSORS 6 
unsigned int sensor_values[NUM_SENSORS]; 

ZumoReflectanceSensorArray sensors(QTR_NO_EMITTER_PIN); 

/*void waitForButtonAndCountDown() 
{ 
digitalWrite(LED, HIGH); 
button.waitForButton(); 
digitalWrite(LED, LOW); 

// play audible countdown 
for (int i = 0; i < 3; i++) 
{ 
delay(1000); 
buzzer.playNote(NOTE_G(3), 200, 15); 
} 
delay(1000); 
buzzer.playNote(NOTE_G(4), 500, 15); 
delay(1000); 
} 
*/ 
void setup() 
{ 
Serial.begin (9600); 
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
delay(100); 
pinMode(LED, HIGH); 

// play audible countdown 
for (int i = 0; i < 3; i++) 
{ 
delay(1000); 
buzzer.playNote(NOTE_G(3), 200, 15); 
} 
delay(1000); 
buzzer.playNote(NOTE_G(4), 500, 15); 
delay(1000); 

// waitForButtonAndCountDown(); 
} 

void findObject(){ 
digitalWrite(trigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH); 
delayMicroseconds(10); 
digitalWrite(trigPin, LOW); 
duration = pulseIn(echoPin, HIGH); 
cm = duration / 58.2; 
} 
void loop() 
{ 
/* if (button.isPressed()) 
{ 
// if button is pressed, stop and wait for another press to go again 
motors.setSpeeds(0, 0); 
button.waitForRelease(); 
waitForButtonAndCountDown(); 
*/ 
chislo = random(0,1000); 
//TURN_DURATION = random(400,600); 
findObject(); 
sensors.read(sensor_values); 
if(cm<0){ 

} 
else{
if (sensor_values[5] > QTR_THRESHOLD||sensor_values[0] > QTR_THRESHOLD) 
{ 
if(chislo<=500){ 
motors.setSpeeds(-REVERSE_SPEED, -REVERSE_SPEED); 
delay(REVERSE_DURATION); 
motors.setSpeeds(TURN_SPEED, -TURN_SPEED); 
delay(TURN_DURATION); 
} 


else{ 
motors.setSpeeds(-REVERSE_SPEED, -REVERSE_SPEED); 
delay(REVERSE_DURATION); 
motors.setSpeeds(-TURN_SPEED, TURN_SPEED); 
delay(TURN_DURATION); 
} 

}

else 
{
  while(cm>20){
    for(int i=1;i<250;i++){
  motors.setSpeeds(FORWARD_SPEED, FORWARD_SPEED);
  delay(1);
  findObject();
    }
    for(int i=1;i<40;i++){
delay(1);  
motors.setSpeeds(TURN_SPEED, -TURN_SPEED); 
findObject();
}
    for(int i=80;i>1;i--){
delay(1);  
motors.setSpeeds(-TURN_SPEED, TURN_SPEED); 
findObject();
}
    for(int i=1;i<40;i++){
delay(1);  
motors.setSpeeds(TURN_SPEED, -TURN_SPEED); 
findObject();
}
}
}
} 
if(cm<20){
if(chislo<=500){ 
motors.setSpeeds(-REVERSE_SPEED, -REVERSE_SPEED); 
delay(REVERSE_DURATION); 
motors.setSpeeds(TURN_SPEED, -TURN_SPEED); 
delay(TURN_DURATION); 
} 


else{
motors.setSpeeds(-REVERSE_SPEED, -REVERSE_SPEED); 
delay(REVERSE_DURATION); 
motors.setSpeeds(-TURN_SPEED, TURN_SPEED); 
delay(TURN_DURATION); 
}
if(chislo<=500){
findObject(); 
while(cm < 20){
  if(cm<0){
findObject();
}
findObject();
motors.setSpeeds(TURN_SPEED, -TURN_SPEED);
}
delay(225);
}
else{
findObject(); 
while(cm < 20){
  if(cm<0){
findObject();
}
findObject();
motors.setSpeeds(TURN_SPEED, -TURN_SPEED);
}
delay(225);
}
}
else{
  while(cm>20){
    for(int i=1;i<250;i++){
  motors.setSpeeds(FORWARD_SPEED, FORWARD_SPEED);
  delay(1);
  findObject();
    }
    for(int i=1;i<40;i++){
delay(1);  
motors.setSpeeds(TURN_SPEED, -TURN_SPEED); 
findObject();
}
    for(int i=80;i>1;i--){
delay(1);  
motors.setSpeeds(-TURN_SPEED, TURN_SPEED); 
findObject();
}
    for(int i=1;i<40;i++){
delay(1);  
motors.setSpeeds(TURN_SPEED, -TURN_SPEED); 
findObject();
}
}
}
}


