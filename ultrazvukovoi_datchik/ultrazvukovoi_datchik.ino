
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13,OUTPUT);
pinMode(A0,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:\
analogRead(A0);
Serial.println(analogRead(A0));
   for (int i=0; i <= 255; i++)
      analogWrite(13, i);
      delay(100);
   }



