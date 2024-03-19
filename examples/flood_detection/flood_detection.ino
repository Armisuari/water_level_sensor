#include "water_level_sensor.h"

#define PIN_SENSOR 34
#define MAX_ADC_VALUE 2000

setCondition kosong(0, 0);
setCondition rendah(0, 30);
setCondition sedang(30, 60);
setCondition tinggi(60, 80);
setCondition banjir(80, 100);

WaterLevel sensor(PIN_SENSOR, MAX_ADC_VALUE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.printf("Water level (%) = %d\n", sensor.readPercent());
  sensor.readWaterLevel(kosong, rendah, sedang, tinggi, banjir);
  Serial.printf("result = %d\n", sensor.flag);

  switch (sensor.flag) {
    case 0:
      Serial.println("Kondisi air : kosong");
      break;
    case 1:
      Serial.println("Kondisi air : rendah");
      break;
    case 2:
      Serial.println("Kondisi air : sedang");
      break;
    case 3:
      Serial.println("Kondisi air : tinggi");
      break;
    case 4:
      Serial.println("Kondisi air : banjir");
      break;
  }

  delay(100);
}
