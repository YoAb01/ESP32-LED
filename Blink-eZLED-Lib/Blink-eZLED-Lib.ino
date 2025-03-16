#include <ezLED.h>

#define NUM_LED 3

#define PIN_LED_1 16
#define PIN_LED_2 17
#define PIN_LED_3 18

ezLED ledArr[NUM_LED] = {
  ezLED(PIN_LED_1),
  ezLED(PIN_LED_2),
  ezLED(PIN_LED_3)
};

void setup() {
  Serial.begin(9600);

  ledArr[0].blink(500, 500);
  ledArr[1].blink(300, 700);
  ledArr[2].blink(100, 100);

}

void loop() {
  for (int led=0; led < NUM_LED; led++){
    ledArr[led].loop();
  }

}
