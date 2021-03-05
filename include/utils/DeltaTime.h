#ifndef DELTATIME_H
#define DELTATIME_H

#include <ctime>

class DeltaTime{
    clock_t init;       // Valor retornado por clock()
    unsigned delta;     // Valor de tempo a definir
public:
    DeltaTime (float sec = 1);
    // Converte os segundos em ticks de clock.
    void setDelta(float sec);
    void start();
    bool dttimeout();
    void wait();
};

#endif