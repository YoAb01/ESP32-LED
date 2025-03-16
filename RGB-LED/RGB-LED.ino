#define PIN_RED 21
#define PIN_GREEN 22
#define PIN_BLUE 23


void setup() {
  Serial.begin(9600);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);

}

void loop() {
  setColor(255, 0, 0);
  delay(500);
  setColor(255, 64, 0);
  delay(500);
  setColor(255, 255, 0);
  delay(500);
  setColor(64, 255, 0);
  delay(500);
  setColor(0, 255, 128);
  delay(500);
  setColor(0, 64, 255);
  delay(500);
  setColor(128, 0, 255);
  delay(500);
  setColor(255, 0, 255);
  delay(500);
  setColor(255, 0, 128);
  delay(500);

}

void setColor(int R, int G, int B) {
  analogWrite(PIN_RED, R);
  analogWrite(PIN_GREEN, G);
  analogWrite(PIN_BLUE, B);
}
