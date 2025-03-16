#define LED_PIN 18
#define FADE_PERIOD 5000  // Total fade-in + fade-out time in milliseconds

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  unsigned long progress = millis() % FADE_PERIOD;  // Keeps cycling

  // First half: Fade in (0 → 255)
  if (progress <= FADE_PERIOD / 2) {
    int brightness = map(progress, 0, FADE_PERIOD / 2, 0, 255);
    analogWrite(LED_PIN, brightness);
  } 
  // Second half: Fade out (255 → 0)
  else {
    int brightness = map(progress, FADE_PERIOD / 2, FADE_PERIOD, 255, 0);
    analogWrite(LED_PIN, brightness);
  }
}