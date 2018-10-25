float i;
float old;
void setup(){
  pinMode (A0,INPUT);
  Serial.begin(9600);
}
void loop(){
 i = analogRead(A0);
if ( i == old+5 || i == old-5 )
{
  
}
else{
  Serial.println(i/205);
  }
i = old;
}

