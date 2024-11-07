#include <Arduino.h>
#include "CurrentSensor.h"

// Configura el pin y parámetros del sensor ACS748
const int sensorPin = 25; // Pin analógico donde está conectado el OUT del ACS748
const float sensibilidad = 0.185; // Sensibilidad en V/A para ACS748
const float offset = 2.5; // Voltaje a 0A (ajusta según tu sensor)

CurrentSensor currentSensor(sensorPin, sensibilidad, offset);

void setup() {
    Serial.begin(115200); // Inicializa la comunicación serial
}

void loop() {
    float corriente = currentSensor.readCurrent(); // Lee el valor de corriente

    Serial.print("Corriente: ");
    Serial.print(corriente);
    Serial.println(" A");

    delay(1000); // Espera 1 segundo antes de la siguiente lectura
}