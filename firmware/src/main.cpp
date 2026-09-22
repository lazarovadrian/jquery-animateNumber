#include <Arduino.h>

// Светодиод платы. -1, пока не известно, на каком GPIO он сидит.
// На многих DevKit ESP32-C3 это GPIO 8. На Super Mini часто другой.
static constexpr int LED_PIN = -1;

// Пины драйвера моторов намеренно не заданы.
// Сначала заполнить docs/wiring.md, потом завести константы сюда.

static const char *PROJECT = "esp32c3-rc-car";

void setup() {
  Serial.begin(115200);
  delay(200);
  Serial.println();
  Serial.print(PROJECT);
  Serial.println(" boot");
  Serial.print("chip: ");
  Serial.println(ESP.getChipModel());

  if (LED_PIN >= 0) {
    pinMode(LED_PIN, OUTPUT);
  }
}

void loop() {
  if (LED_PIN >= 0) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }

  Serial.print(PROJECT);
  Serial.print(" uptime_ms=");
  Serial.println(millis());
  delay(1000);
}
