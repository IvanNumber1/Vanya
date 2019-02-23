#include <Wire.h> 
#include <ZumoShield.h> 
 
int duration, cm; 
int trigPin = 13; 
int echoPin = 12; 
int chislo;
int TURN_DURATION; // ms
int S = 35;//length to object

#define LED 13
#define QTR_THRESHOLD 1500 // microseconds  
#define REVERSE_SPEED 200 // 0 is stopped, 400 is full speed 
#define TURN_SPEED 200 
#define MINI_TURN_SPEED 155 
#define MINI_TURN_DURATION 110 
#define MINI_TURN_DURATIONN 70
#define FORWARD_SPEED 125 
#define REVERSE_DURATION 200 // ms 
#define RUN_SPEED 230 
#define NUM_SENSORS 6 

ZumoBuzzer buzzer; 
ZumoMotors motors; 
Pushbutton button(ZUMO_BUTTON); // pushbutton on pin 12 


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

    void go_back(){
      motors.setSpeeds(-REVERSE_SPEED, -REVERSE_SPEED); 
      delay(REVERSE_DURATION);
    }
    void turn_right(){
      motors.setSpeeds(TURN_SPEED, -TURN_SPEED); 
      delay(MINI_TURN_DURATION); 
    }
    void turn_left(){
      motors.setSpeeds(-TURN_SPEED, TURN_SPEED); 
      delay(MINI_TURN_DURATION);
    } 
    void run_forward(){
      motors.setSpeeds(RUN_SPEED, RUN_SPEED); 
    }
    void turn_right_and_search(){
           while(cm > S){
          if(cm < 0){ 
             findObject(); 
           } 
           findObject(); 
           motors.setSpeeds(MINI_TURN_SPEED, -MINI_TURN_SPEED); 
       }  
    }
    void turn_left_and_search(){
        while(cm > S){
             if(cm < 0){ 
               findObject(); 
             } 
           findObject(); 
           motors.setSpeeds(-MINI_TURN_SPEED, MINI_TURN_SPEED); 
        } 
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
        
        go_back();
        
        turn_right();
         
        findObject(); 
        
        turn_right_and_search(); 
        
        delay(MINI_TURN_DURATIONN);
      } 

    else{ 
      
     go_back(); 
     
     turn_left(); 
     
     findObject(); 
     
     turn_left_and_search(); 
     
       delay(MINI_TURN_DURATIONN);
    }

  } 

   else 
   { 
    if(chislo <= 500){ 
        findObject(); 
        
        turn_right_and_search();
        
    } 

       else{ 
         findObject(); 
         
           turn_left_and_search(); 
           
       }
  }
 
   if(cm < S){
    
    run_forward();
     
     } 
   }
 }
