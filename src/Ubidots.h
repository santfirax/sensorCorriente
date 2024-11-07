#ifndef UBIDOTS_H
#define UBIDOTS_H

#include <WiFi.h>
#include <HTTPClient.h>

class Ubidots {
public:
    Ubidots(const char* token);
    void wifiConnect(const char* ssid, const char* password);
    bool send(const char* variable_label, float value);
    void handleHttpStatusCode(int statusCode);
    
private:
    const char* _token;
    const char* _server = "http://industrial.api.ubidots.com/api/v1.6/devices/";
};

#endif // UBIDOTS_H