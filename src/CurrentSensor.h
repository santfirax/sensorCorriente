#ifndef CURRENT_SENSOR_H
#define CURRENT_SENSOR_H

#include <Arduino.h>

class CurrentSensor {
public:
    CurrentSensor(int pin, float sensitivity, float offset);
    float readCurrent();

private:
    int _pin;           // pin analogico donde está conectado el OUT del ACS748
    float _sensitivity; // sensibilidad en V/A para ACS748
    float _offset;      // voltaje a 0A (ajusta según tu sensor)
};

#endif 