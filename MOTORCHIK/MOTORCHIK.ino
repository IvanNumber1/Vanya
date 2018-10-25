int i;
int x;
void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
pinMode(A0,INPUT);
pinMode(9,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(13,HIGH);
 i = analogRead(A0);
Serial.println(i);
x = i/4;
analogWrite(9,x);
}
