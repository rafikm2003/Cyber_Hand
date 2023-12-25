# Cyber Hand

## **Project assumptions:**
The system's task is to collect information about the position of the hand and its individual fingers by appropriately placing EKG electrodes on the hand. It then utilizes this information to change the position of a cybernetic hand using servomechanisms, ensuring that its position corresponds to that of our hand.


### **Program code:**
To create the program, we used the C++ language on the Arduino platform. The code includes all necessary functions for determining the hand's position calculationally and for communication. The program can be divided into two parts:
- Nadawca.ino: Transmitter, retrieves data from EKG electrodes and sends it to the second part of the program.
- Odbiorca.ino: Receiver, using the data obtained from the Transmitter, performs necessary calculations and then transmits this data to servomechanisms that determine the position of the cybernetic hand.

When creating the Transmitter part of the program, the following libraries were used:
- SPI.h: for communication with the NRF2401 radio module.
- RF24.h: for handling the radio module.

Functions used in the Transmitter part of the program:
- struct Paczka: a structural function defining variables that store sensor measurements.
- void setup(): a void function responsible for initiating communication with the radio module.
- void loop(): a void function tasked with reading, mapping, and subsequently sending sensor data to the radio module.

The following libraries were used in the Receiver part of the program:
- Servo.h: for controlling the servomechanisms.
- Math.h: importing necessary mathematical functions for calculations.

The Receiver also contains functions:
- void neutralna_pozycja(): a void function that controls the static position of the hand. In simple terms, if the sensors don't detect any movement, this function keeps the cybernetic hand in the last known position. Otherwise, involuntary changes in the cybernetic hand's position might occur.
- void Ruch(): a void function taking two arguments:
    1) int serw: an integer variable describing the servo where actions will be performed.
    2) int pozycja: an integer variable that, based on the previous position, determines the next one.

## **Device construction

### Circuitry
The entire setup comprises the following components:
- główny.kicad_sch: The device incorporates separate power for servomechanisms using the popular mc34063 circuit, functioning as a configurable STEPDOWN switching regulator. A 5V voltage is required to power the servomechanisms.
- nadawca.kicad_sch: This part includes the NRF2401 radio module, an Arduino MEGA 2560, and its purpose is to send measurements from EMG sensors.
- emg_sensor.kicad_sch: This circuit's task involves amplifying the voltage difference of the EMG signal.

### Casing and EKG Electrodes
The entirety is neatly enclosed using a plastic hand created via a 3D printer.
im1
The second part of the project is essentially our cyber-arm. It includes crucial devices such as the previously mentioned measurement amplifier and a band-pass filter (active), which amplifies the signal and isolates the appropriate frequency.
im2
It's worth mentioning the EKG electrodes at the end. The placement of each electrode is crucial for the correct interpretation of values responsible for controlling individual fingers. Below is the specific placement:
im3
The task of the remaining electrodes is to read values responsible for the movement of the entire arm. Their placement depends on the user, which is a drawback of the device, necessitating calibration to the individual user.


