int x=5;
int i;
void setup() {
  // put your setup code here, to run once:
pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for (i=0;i<255;i=i+x){
analogWrite(11,i);
delay(1000);
}
for (i=255;i>=0;i=i-x){
analogWrite(11,i);
delay(1000);
}
}
