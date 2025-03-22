#define GPIO 36
#define VOLTAGE 3.3
#define LED_PIN 27

unsigned int threshold_led = 127;
int buttonState = LOW;

// Linear interpolation function to float map [0, 4096] => [0, 3.3]
float floatMap(float analogVal, float min_1, float max_1, float min_2, float max_2) {
  return min_2 + (analogVal - min_1) * (max_2 - min_2) / (max_1 - min_1);
}

void setup() {
  Serial.begin(9600);
  analogSetAttenuation(ADC_11db);  // Up to 3.3V input
  pinMode(LED_PIN, OUTPUT);

}

void loop() {
  int analogValue = analogRead(GPIO);     // Read on ANALOG_PIN_36
  float led = floatMap(analogValue, 0, 4095, 0, 255);
  int ledVal = (int)led;

  buttonState = (led >= threshold_led) ? HIGH : LOW;
  digitalWrite(LED_PIN, buttonState);

}