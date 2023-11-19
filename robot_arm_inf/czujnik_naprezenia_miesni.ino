/*
muscle sensor led test code

 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the sensor:
int  sensorValue = analogRead(A0);
Serial.println(sensorValue);
  // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, 680, 620, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, 0, 255);

  // fade the LED using the calibrated value:
  analogWrite(13, sensorValue);

   delay(100);        // delay in between reads for stability
}
