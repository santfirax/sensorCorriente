#include <Arduino.h>
#include "CurrentSensor.h"
#include <Ubidots.h>
#include <Relay.h>

// Configura el pin y parámetros del sensor ACS748
const int sensorPin = 32;        // Pin analógico donde está conectado el OUT del ACS748
const float sensibilidad = 0.66; // Sensibilidad en V/A para ACS748
const float offset = 2.35;       // Voltaje a 0A (ajusta según tu sensor)

const int relayPin = 35;
int contador = 0;

const char *UBIDOTS_TOKEN = "BBUS-kRB4YEU0JFRYrndNaMADcyf0xf4rL6";
// const char* WIFI_SSID = "iPhone de Jose Santiago";
// const char* WIFI_PASS = "Mola123.";
const char *WIFI_SSID = "UPBWiFi";
const char *WIFI_PASS = "";
CurrentSensor currentSensor(sensorPin, sensibilidad, offset);
Ubidots ubidots(UBIDOTS_TOKEN);
Relay relay(relay);

void setup()
{
    Serial.begin(115200); // Inicializa la comunicación serial
    ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
    relay.begin();
}

void loop()
{
    float corriente = currentSensor.readCurrent(); // Lee el valor de corriente
    Serial.print("Corriente: ");
    Serial.print(corriente);
    Serial.println(" A");
    ubidots.send("Corriente", corriente);
    Serial.print("Contador");
        Serial.println(contador);
    if (contador == 3)
    {
        Serial.println("Se debe activar el rele");
        relay.deactivate();
    }
    contador++;

    delay(1000); // Espera 1 segundo antes de la siguiente lectura
}