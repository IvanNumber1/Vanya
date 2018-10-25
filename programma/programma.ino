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
pinMode(A0,INPUT);
pinMode(A5,INPUT);
  Serial.begin(9600);
  Serial.println("Z-Line Sensor Test");
  Serial.println();
}
//ыыыыыыыыыыыыыыыыыыыыыыыыы
void loop(){
int val = analogRead(A0);
Serial.println(val);
int value = analogRead(A5);
Serial.println(value);
if (val > 100){
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
analogWrite(enA,170);
}
else{
  analogWrite(enA,0);
}
if (value > 100){
digitalWrite(in4,LOW);
digitalWrite(in3,HIGH);
analogWrite(enB,170);
}
else{
  analogWrite(enB,0);
}
if (val < 100 & value < 100){
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
analogWrite(enA,170);
}
}

