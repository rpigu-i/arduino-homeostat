#include <Wire.h>

#define UNIT_ID 1  // Change per board: 1, 2, 3, 4
#define NUM_UNITS 4
#define NEXT_UNIT_ADDR ((UNIT_ID % NUM_UNITS) + 1)
#define LED_PIN 13
#define BUTTON_PIN 2

float param = 1.0;
float input = 0.0;
float output = 0.0;
float desired = 50.0;
float threshold = 10.0;

bool stable = false;
unsigned long lastSendTime = 0;
unsigned long interval = 200;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);
  Wire.begin(UNIT_ID); // This Arduino's I2C address
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    input += random(-30, 30); // simulate external shock
  }

  output = input * param;

  // Stability check
  float error = abs(output - desired);
  stable = error < threshold;
  digitalWrite(LED_PIN, stable ? HIGH : LOW);

  // Adaptation if unstable
  if (!stable) {
    param = random(50, 150) / 100.0; // param ∈ [0.5, 1.5]
  }

  // Send output periodically to next unit
  if (millis() - lastSendTime > interval) {
    Wire.beginTransmission(NEXT_UNIT_ADDR);
    Wire.write((byte *)&output, sizeof(output));
    Wire.endTransmission();
    lastSendTime = millis();
  }

  Serial.print("Unit ");
  Serial.print(UNIT_ID);
  Serial.print(" | In: ");
  Serial.print(input);
  Serial.print(" | Out: ");
  Serial.print(output);
  Serial.print(" | Param: ");
  Serial.print(param);
  Serial.print(" | Stable: ");
  Serial.println(stable);
  delay(100);
}

void receiveEvent(int howMany) {
  if (howMany == sizeof(float)) {
    Wire.readBytes((char *)&input, sizeof(input));
  }
}

void requestEvent() {
  Wire.write((byte *)&output, sizeof(output));
}
