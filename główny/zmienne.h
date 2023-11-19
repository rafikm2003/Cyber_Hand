#ifndef ZMIENNE_H
#define ZMIENNE_H
#include <Arduino.h>
#include <Servo.h>
#include <math.h>

class Reka
{
public:
    int ostatniaPozycja[7] = {0,0,0,0,0,0,0};
    int kalibracja[7] = {0, 0, -20, -12, 0, 0, 0};
    int neutralna[7] = {0, 93, 121, 37, 80, 86, 80};
    Servo s[8];

    void neutralna_pozycja();
    void ruch(int serw, int pozycja);
    void ruch_palcow(int k);
    void ster(int tab[]);
};
#endif