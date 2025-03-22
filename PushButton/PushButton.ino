#define BUTTON_PIN 33

// Variables will change:
int lastState = LOW;  // the previous state from the input pin
int currentState;     // the current reading from the input pin

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // read the state of the switch/button:
  currentState = digitalRead(BUTTON_PIN);

  if (lastState == HIGH && currentState == LOW)
    Serial.println("The button is pressed");
  else if (lastState == LOW && currentState == HIGH)
    Serial.println("The button is released");

  // save the the last state
  lastState = currentState;
}

