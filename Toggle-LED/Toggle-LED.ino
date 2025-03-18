#define LED_PIN 21
#define BTN_PIN 23

int buttonState;
int lastButtonState;
int ledState = LOW;


void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP);
  buttonState = digitalRead(BTN_PIN); // Store the initial button state
}


void loop() {
  lastButtonState = buttonState;         // Store the latest state
  buttonState = digitalRead(BTN_PIN);    // Read it
  if(lastButtonState == LOW && buttonState == HIGH) {   // If btn state change, change the led state
    Serial.println("The button is pressed");
    Serial.println("Changing led to: " + String(!ledState));
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
  }
}