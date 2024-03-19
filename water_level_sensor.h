#ifndef WATER_LEVEL_SENSOR_H
#define WATER_LEVEL_SENSOR_H

#include <Arduino.h>

class setCondition
{
  public:
    int _lValue, _hValue;
    setCondition(int lValue, int hValue) : _lValue(lValue), _hValue(hValue)
    {

    }
};

class WaterLevel
{
  public:
    WaterLevel(size_t pin, int16_t MAX_ADC);
    uint16_t readPercent();
    void readWaterLevel(setCondition kosong, setCondition rendah, setCondition sedang, setCondition tinggi, setCondition banjir);

    enum ConditionType
    {
      kosong,
      rendah,
      sedang,
      tinggi,
      banjir,
    };

    ConditionType flag;

  private:
    uint16_t readADC();
    size_t _pin;
    int16_t _MAX_ADC;
};

#endif
