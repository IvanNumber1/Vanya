const int analogPin=0;
const int analogPin1=1;
int i;
int x=1;
//левый двигатель
int enA = 9;
int in1 = 7;
int in2 = 6;
//правый двигатель
int enB = 3;
int in3 = 5;
int in4 = 4;
void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(9,OUTPUT);
  Serial.begin(9600);
  Serial.println("Z-Line Sensor Test");
  Serial.println();
}
//ыыыыыыыыыыыыыыыыыыыыыыыыы
void demoOne(){
int analogValue = analogRead(analogPin);
Serial.println(analogValue);
int analogValue1 = analogRead(analogPin1);
Serial.println(analogValue1);
if (analogValue > 100){
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
analogWrite(enA,150);
}
else{
  analogWrite(enA,0);
}
if (analogValue1 > 100){
digitalWrite(in4,LOW);
digitalWrite(in3,HIGH);
analogWrite(enB,150);
}
else{
  analogWrite(enB,0);
}
}
void loop(){
demoOne();
}
