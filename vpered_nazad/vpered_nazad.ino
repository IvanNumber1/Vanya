int i;
int x=5;
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
}
//ыыыыыыыыыыыыыыыыыыыыыыыыы
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
analogWrite(enA,200);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
analogWrite(enB,200);
delay(500);
digitalWrite(in1,LOW);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,LOW);
delay(2000);
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
analogWrite(enA,200);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
analogWrite(enB,200);
delay(500);
digitalWrite(in1,LOW);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,LOW);
delay(2000);
}
