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
  void demoOne(){
  //назад
  for (i=0;i<200;i=x+i){
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
analogWrite(enA,i);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
analogWrite(enB,i);
delay(100);}
for (i=200;i>0;i=i-x){
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
analogWrite(enA,i);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
analogWrite(enB,i);
delay(100);}
delay(2000);
//вперед
for (i=0;i<200;i=x+i){
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
analogWrite(enA,i);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
analogWrite(enB,i);
delay(100);}
for (i=200;i>0;i=i-x){
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
analogWrite(enA,i);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
analogWrite(enB,i);
delay(100);}
delay(2000);
}

void loop() { 
demoOne();
}

