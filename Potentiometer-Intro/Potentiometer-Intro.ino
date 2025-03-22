#define GPIO 36
#define VOLTAGE 3.3

// Linear interpolation function to float map [0, 4096] => [0, 3.3]
float floatMap(float analogVal, float min_1, float max_1, float min_2, float max_2) {
  return min_2 + (analogVal - min_1) * (max_2 - min_2) / (max_1 - min_1);
}

void setup() {
  Serial.begin(9600);
  analogSetAttenuation(ADC_11db);  // Up to 3.3V input

}

void loop() {
  int analogValue = analogRead(GPIO);     // Read on ANALOG_PIN_36
  float voltage = floatMap(analogValue, 0, 4095, 0, VOLTAGE);
  Serial.print("Value: ");
  Serial.print(analogValue);
  Serial.print(", Voltage: ");
  Serial.println(voltage);

}
