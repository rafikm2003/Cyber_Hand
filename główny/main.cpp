#include <Arduino.h>
#include <Servo.h>
#include <zmienne.h>
#include <math.h>

void Reka::ruch(int serw, int pozycja)
{
  Servo* s;// = ktore_serwa(serw);
  if(s==0) return;
  ostatniaPozycja[serw] = pozycja;
  s -> write(pozycja + kalibracja[serw]);

}
void Reka::neutralna_pozycja()
{
  for(int i = 1; i <= 6; i++) ruch(i, neutralna[i]);
}
void Reka::ster(int tab[])
{
  if(abs(pos1 - ostatniaPozycja[1]) > 2) ruch(1, pos1);
  if(abs(pos2 - ostatniaPozycja[2]) > 2) ruch(2, pos2);
  if(abs(pos3 - ostatniaPozycja[3]) > 2) ruch(3, pos3);
  if(abs(pos4 - ostatniaPozycja[4]) > 2) ruch(4, pos4);
  if(abs(pos5 - ostatniaPozycja[5]) > 2) ruch(5, pos5);
  if(abs(pos6 - ostatniaPozycja[6]) > 2) ruch(6, pos6);

}
void Reka::ruch_palcow(int k)
{

}