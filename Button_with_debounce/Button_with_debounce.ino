int switchPin = 12;              // switch is connected to pin 2
int led1Pin = 13;

int val;                        // variable for reading the pin status
int val2;                       // variable for reading the delayed/debounced status
int buttonState;                // variable to hold the button state

int lightMode = 0;              // Is the light on or off?

void setup() {
  pinMode(switchPin, INPUT);    // Set the switch pin as input
  pinMode(led1Pin, OUTPUT);
  buttonState = digitalRead(switchPin);   // read the initial state
}

void loop(){
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
