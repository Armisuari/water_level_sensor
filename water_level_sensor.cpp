#include "water_level_sensor.h"

WaterLevel::WaterLevel(size_t pin, int16_t MAX_ADC)
  : _pin(pin), _MAX_ADC(MAX_ADC) {
}

uint16_t WaterLevel::readPercent() {
  return map(readADC(), 0, _MAX_ADC, 0, 100);
}

void WaterLevel::readWaterLevel(setCondition kosong, setCondition rendah, setCondition sedang, setCondition tinggi, setCondition banjir) {
  if (readPercent() <= kosong._lValue) {
    flag = ConditionType::kosong;
  } else if (readPercent() > rendah._lValue && readPercent() <= rendah._hValue) {
    flag = ConditionType::rendah;
  } else if (readPercent() > sedang._lValue && readPercent() <= sedang._hValue) {
    flag = ConditionType::sedang;
  } else if (readPercent() > tinggi._lValue && readPercent() <= tinggi._hValue) {
    flag = ConditionType::tinggi;
  } else if (readPercent() >= banjir._lValue) {
    flag = ConditionType::banjir;
  }
}

uint16_t WaterLevel::readADC() {
  return analogRead(_pin);
}
