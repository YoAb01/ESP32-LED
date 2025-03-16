#define LED_PIN1 21
#define LED_PIN2 23
#define BTN_PIN 18
#define BLINK_INTERVAL1 1000
#define BLINK_INTERVAL2 3000

int ledState1 = LOW;
int ledState2 = LOW;

int previousButtonState = LOW;
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP);

}

void loop() {
  unsigned long currentMillis = millis();

  // Change the state of the led (light it on or turn it off) based on the time diff
  if(currentMillis - previousMillis1 >= BLINK_INTERVAL1){
    ledState1 = (ledState1 == LOW) ? HIGH : LOW;
    digitalWrite(LED_PIN1, ledState1);
    previousMillis1 = currentMillis;
  }

  if(currentMillis - previousMillis2 >= BLINK_INTERVAL2){
    ledState2 = (ledState2 == LOW) ? HIGH : LOW;
    digitalWrite(LED_PIN2, ledState2);
    previousMillis2 = currentMillis;
  }

  // Read the state of the button
  int currentButtonState = digitalRead(BTN_PIN);
  if(currentButtonState != previousButtonState) {
    Serial.println(currentButtonState);
    previousButtonState = currentButtonState;
  }
  
}
