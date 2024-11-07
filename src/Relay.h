#ifndef RELAY_H
#define RELAY_H

class Relay {
public:
    Relay(int pin); // Constructor que recibe el pin del relé
    void begin();   // Inicializa el pin del relé
    void activate(); // Activa el relé
    void deactivate(); // Desactiva el relé

private:
    int relayPin; // Almacena el número del pin del relé
};

#endif // RELAY_H