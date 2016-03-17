//Sensor de Luz
#include <SoftwareSerial.h>


const int SensorPin = A0;  // pin with the photoresistor with the red gel
int Value = 0; // value to write to the red LED
int SensorValue = 0; // variable to hold the value from the red sensor
SoftwareSerial XBee(8, 9); // RX, TX

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  XBee.begin(9600);
  Serial.println("Start!!");

}

void loop() {
  // Read the sensors first:

  SensorValue = analogRead(SensorPin);

  delay(5);

  

  XBee.print("L");
  XBee.println(SensorValue);
  Serial.print ("L");
  Serial.println(SensorValue);
  delay(15000);


}

