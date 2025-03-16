#define LED_PIN 18

unsigned int brightness = 0;
unsigned int fadeAmount = 5;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  analogWrite(LED_PIN, brightness);
  brightness = brightness + fadeAmount;

  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  Serial.print("Brightness: ");
  Serial.println(brightness);

  delay(30);
}
