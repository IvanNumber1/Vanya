
int arra = digitalRead(9);
void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
pinMode(9,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalRead(9);
if (arra == HIGH){
digitalWrite(13,HIGH);
}
else{
  digitalWrite(13,LOW);
}
}
