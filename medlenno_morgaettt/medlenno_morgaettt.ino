int x=0;
void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.read() == '1'){
for(x=0;x<100;x++){
digitalWrite(13,HIGH);
delay(x);
digitalWrite(13,LOW);
delay(x);
}
}
  if(Serial.read() == '2'){
for(x=100;x>10;x--){
digitalWrite(13,HIGH);
delay(x);
digitalWrite(13,LOW);
delay(x);
}
}
}
