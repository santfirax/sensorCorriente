#include "Ubidots.h"

Ubidots::Ubidots(const char *token)
{
    _token = token;
}

void Ubidots::wifiConnect(const char *ssid, const char *password)
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Conectando a WiFi...");
    }
    Serial.println("Conectado a WiFi");
}

bool Ubidots::send(const char *variable_label, float value)
{
    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;
        String url = String(_server) + "test";
        http.begin(url);
        http.addHeader("X-Auth-Token", _token);
        http.addHeader("Content-Type", "application/json");

        String payload = "{\"" + String(variable_label) + "\": " + String(value) + "}";
        int httpResponseCode = http.POST(payload);
        String response = http.getString();
        Serial.println(httpResponseCode);
        Serial.println(response);
        http.end();
        handleHttpStatusCode(httpResponseCode);
    }
    return false;
}
void Ubidots::handleHttpStatusCode(int statusCode)
{

    switch (statusCode / 100)
    {
    case 2:
        switch (statusCode)
        {
        case 201:
            Serial.println("Se guardo exitosamente en ubidots");
            break;

        default:
            Serial.println("Respuesta exitosa pero algo raro paso");
            break;
        }
        break;
    case 4:
        switch (statusCode)
        {
        case 400:
            Serial.println("Bad request");
            break;
        case 404:
            Serial.println("Not found");
            break;
        }
        break;
    case 5:
        Serial.println("Error interno de Ubidots");
    }
}