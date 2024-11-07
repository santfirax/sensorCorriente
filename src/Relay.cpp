#include "Relay.h"
#include <Arduino.h>

Relay::Relay(int pin) : relayPin(pin) {
   relayPin=pin;
}

void Relay::begin() {
    pinMode(relayPin, OUTPUT); // Configura el pin como salida
    activate(); 
}

void Relay::activate() {
    digitalWrite(relayPin, HIGH); // Activa el relé (HIGH)
}

void Relay::deactivate() {
    digitalWrite(relayPin, LOW); // Desactiva el relé (LOW)
}