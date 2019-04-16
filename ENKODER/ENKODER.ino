int clk = A2;
int dt = A1;
int sw = 10;
int button;
int DT;
int CLK;
void setup() {
  // put your setup code here, to run once:
pinMode(clk,INPUT);
pinMode(dt,INPUT);
pinMode(sw,INPUT_PULLUP);
Serial.begin(9600);
}

void loop() {
  while(1){
  // put your main code here, to run repeatedly:
  button = digitalRead(sw);
 // Serial.println(button);
  DT = analogRead(dt);
///  Serial.println(DT);
 
  CLK = analogRead(clk);
 // Serial.println(CLK);
 
 // Serial.println("");
  if(CLK < 50 && DT < 50){
  
}
if(DT < 50){
  while(DT < 50 || CLK < 50){
    DT = analogRead(dt);
    CLK = analogRead(clk);   
    delay(5);
  }
  Serial.println("Left");
}
if(CLK < 50){
  while(DT < 50 || CLK < 50){
    DT = analogRead(dt);
    CLK = analogRead(clk);
    delay(5);
  }
  Serial.println("Right");
}
if(CLK > 50 && DT > 50){
  
}
if(button == 0){
  Serial.println("Button is pressed");
  while(button == 0){
  button = digitalRead(sw);
  delay(25);
  }
}
}
}
