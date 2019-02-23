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
#define MINI_TURN_SPEED 155 
#define MINI_TURN_DURATION 80 
#define FORWARD_SPEED 125 
#define REVERSE_DURATION 200 // ms 
int TURN_DURATION; // ms 
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

void findObject(){ 
digitalWrite(trigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH); 
delayMicroseconds(10); 
digitalWrite(trigPin, LOW); 
duration = pulseIn(echoPin, HIGH); 
cm = duration / 58; 
} 

void setup() 
{ 
Serial.begin (9600); 
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(3, OUTPUT); 
delay(100); 

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
//TURN_DURATION = random(400,800); 
//findObject(); 
sensors.read(sensor_values); 
if(cm<0){ 
findObject(); 
} 
else{ 
if (sensor_values[5] > QTR_THRESHOLD||sensor_values[0] > QTR_THRESHOLD) 
{ 
if(chislo<=500){ 
motors.setSpeeds(-REVERSE_SPEED, -REVERSE_SPEED); 
delay(REVERSE_DURATION); 
motors.setSpeeds(TURN_SPEED, -TURN_SPEED); 
delay(MINI_TURN_DURATION); 
findObject(); 
while(cm>35){ 
findObject(); 
motors.setSpeeds(MINI_TURN_SPEED, -MINI_TURN_SPEED); 
} 
} 

else{ 
motors.setSpeeds(-REVERSE_SPEED, -REVERSE_SPEED); 
delay(REVERSE_DURATION); 
motors.setSpeeds(-TURN_SPEED, TURN_SPEED); 
delay(MINI_TURN_DURATION); 
findObject(); 
while(cm>35){ 
findObject(); 
motors.setSpeeds(-MINI_TURN_SPEED, MINI_TURN_SPEED); 
} 
} 

} 

else 
{ 
if(chislo<=500){ 
findObject(); 
while(cm>35){ 

findObject(); 
motors.setSpeeds(MINI_TURN_SPEED, -MINI_TURN_SPEED); 
} 
} 

else{ 
findObject(); 
while(cm>35){ 
findObject(); 
motors.setSpeeds(-MINI_TURN_SPEED, MINI_TURN_SPEED); 
} 
} 
} 


if(cm < 35){ 
motors.setSpeeds(RUN_SPEED, RUN_SPEED); 
} 
} 
}
