#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h> 

RF24 wyslij(7, 8);

const byte address[6] = "00004";
unsigned long k = 0;
unsigned long l= 0;

struct Paczka
{
  byte emg_1;
  byte emg_2;
  byte emg_3;
  //drugi sposób
  // byte tab[3];
};
Paczka data;

void setup() {
  Serial.begin(9600);
  wyslij.begin();
  wyslij.openWritingPipe(address);
  wyslij.setAutoAck(false);
  wyslij.setDataRate(RF24_250KBPS);
  wyslij.setPALevel(RF24_PA_LOW);
  wyslij.stopListening();
}

void loop() {
 // Serial.println(data.emg_1);

  data.emg_1 = map(analogRead(A2), 0, 1023, 0, 255);
  data.emg_2 = map(analogRead(A1), 0, 1023, 0, 255);
  data.emg_3 = map(analogRead(A0), 0, 1023, 0, 255);
  wyslij.write(&data, sizeof(Paczka));
}
