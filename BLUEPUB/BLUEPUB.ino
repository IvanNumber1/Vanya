int in1 = 13;
int in2 = 12;
int in3 = 11;
int in4 = 10;
void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
Serial.begin(9600);
}

void loop() {
 String string;
 if(Serial.available()>0){
   string = Serial.readString();
   Serial.println(string);
   }
   
  if(string=="vpered"){
    vpered(in1,in2,in3,in4);
  }
  if(string=="nazad"){
    nazad(in1,in2,in3,in4);
  }
   if(string=="stop"){
    stopp(in1,in2,in3,in4);
  }
   if(string=="left"){
    left(in1,in2,in3,in4);
    delay(410);
    stopp(in1,in2,in3,in4);
  }
  if(string=="right"){
    right(in1,in2,in3,in4);
    delay(410);
    stopp(in1,in2,in3,in4);
  }
}
void stopp(int i1, int i2,int i3, int i4){
  digitalWrite(i1,LOW);
   digitalWrite(i2,LOW);
    digitalWrite(i3,LOW);
     digitalWrite(i4,LOW);
}
void nazad(int i1, int i2, int i3, int i4){
  digitalWrite(i1,HIGH);
   digitalWrite(i2,LOW);
    digitalWrite(i3,0);
     digitalWrite(i4,1);
      
}
void vpered(int i1, int i2,int i3, int i4){
  digitalWrite(i1,0);
   digitalWrite(i2,1);
    digitalWrite(i3,1);
     digitalWrite(i4,0);
      
}
void right(int i1, int i2,int i3, int i4){
  digitalWrite(i1,1);
   digitalWrite(i2,0);
    digitalWrite(i3,1);
     digitalWrite(i4,0);
      
}
void left(int i1, int i2,int i3, int i4){
  digitalWrite(i1,0);
   digitalWrite(i2,1);
    digitalWrite(i3,0);
     digitalWrite(i4,1);
      
}
