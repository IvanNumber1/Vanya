int A[100];
double sum;
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sum = 0;
 for (int i = 0; i <= 100; i++){
digitalWrite(A0,HIGH);
A[i] = analogRead(A0);
//Serial.print(i);
//Serial.print(") ");
//Serial.println(A[i]);
sum = sum + A[i];
//Serial.println(sum);
}
Serial.print("crednee chislo ");
Serial.println(sum/100);
}
