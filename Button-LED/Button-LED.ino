#define LED_PIN 21
#define BTN_PIN 23

int buttonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(BTN_PIN);
  Serial.println(buttonState);

  if (buttonState == LOW){
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

}
