int switchPin = 13;              // switch is connected to pin 2
int led1Pin = 7;

int val;                        // variable for reading the pin status
int val2;                       // variable for reading the delayed/debounced status
int buttonState;                // variable to hold the button state

int lightMode = 0;              // Is the light on or off?

int x;
int y;
int o;
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(13,INPUT);
pinMode(7,OUTPUT);
Serial.begin(9600);

pinMode(switchPin, INPUT);    // Set the switch pin as input
  pinMode(led1Pin, OUTPUT);
  buttonState = digitalRead(switchPin);   // read the initial state
}
bool ButtonDo(){
  val = digitalRead(switchPin);      // read input value and store it in val
  delay(10);                         // 10 milliseconds is a good amount of time
  val2 = digitalRead(switchPin);     // read the input again to check for bounces
  if (val == val2) {                 // make sure we got 2 consistant readings!
    if (val != buttonState) {          // the button state has changed!
      if (val == LOW) {                // check if the button is pressed
        if (lightMode == 0) {          // is the light off?
          lightMode = 1;               // turn light on!
          digitalWrite(led1Pin, HIGH);
        } else {
          lightMode = 0;               // turn light off!
          digitalWrite(led1Pin, LOW);
        }
      }
    }
    buttonState = val;                 // save the new state in our variable
  }
}

void loop() {
  // put your main code here, to run repeatedly:
 x=analogRead(A0);
 y=analogRead(A1);
  o=digitalRead(13);
/*  if (x>520||x<500){
Serial.println(x);
digitalWrite(7,HIGH);
}
else{
  digitalWrite(7,LOW);
}*/
  if (y>520||y<500){
Serial.println(y);
digitalWrite(13,HIGH);
}
else{
  digitalWrite(7,LOW);
}

Serial.println(o);
//ButtonDo();

}

