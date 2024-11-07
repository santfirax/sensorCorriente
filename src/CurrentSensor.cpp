#include "CurrentSensor.h"

CurrentSensor::CurrentSensor(int pin, float sensitivity, float offset)
    : _pin(pin), _sensitivity(sensitivity), _offset(offset) {}

float CurrentSensor::readCurrent() {
    int valorADC = analogRead(_pin); // Lee el valor del ADC
    float voltaje = (valorADC / 4095.0) * 3.3; // Convierte a voltaje
    float corriente = (voltaje - _offset) / _sensitivity; // Calcula la corriente

    return corriente; // Devuelve el valor de corriente
}