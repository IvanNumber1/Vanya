int y = 100;
int i;
int Infa = A0;
int LED = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
pinMode(Infa,INPUT);
Serial.begin(9600);
for(i = 0; i<=y;i++){
delay(100);
Serial.print(analogRead(Infa));
Serial.print(" ");
Serial.println(i);
}
 for(int x = 0;x<1;x++){
if(i=y){
  Serial.print("Schitano");
  Serial.print(" ");
   Serial.print(y);
    Serial.print(" ");
     Serial.println("znacheniy");
}
}
}

void loop() {
  // put your main code here, to run repeatedly:
  analogRead(Infa);
 
}
