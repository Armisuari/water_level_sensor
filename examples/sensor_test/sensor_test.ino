#include "water_level_sensor.h"

#define PIN_SENSOR 34
#define MAX_ADC_VALUE 2000

WaterLevel sensor(PIN_SENSOR, MAX_ADC_VALUE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.printf("Water level (%) = %d\n", sensor.readPercent());
  delay(100);
}