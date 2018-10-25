int WORD;
void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
  WORD=Serial.read();
 if (WORD == '1'){
 digitalWrite(13,HIGH);
 Serial.println("GORIT");
}
if (WORD == '2'){
  digitalWrite(13,LOW);
  Serial.println("NE GORIT");
}
}
}
