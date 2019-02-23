int trigPin = 11;   
int echoPin = 12;    
long duration, mm;
void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}
void loop()
{
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
mm = (duration/2) / 2.91;
Serial.print(mm);
Serial.print("mm");
Serial.println();
delay(250);
}
