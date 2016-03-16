//DHT22
#include <SoftwareSerial.h>
#include "DHT.h"

#define DHTPIN 4 

const int SensorPin = A0; 
int Value = 0; 
int SensorValue = 0; 
SoftwareSerial XBee(8, 9); // RX, TX
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  XBee.begin(9600);
  //Serial.println("Start!!");
  delay(2000);
}

void loop() {
  // Read the sensors first:

   float t = dht.readTemperature();

   if (isnan(t)) {
    //Serial.println("Failed to read from DHT sensor!");
    return;
  }
  else
  {
  XBee.print("T");
  XBee.println(t);
  //Serial.print ("T");
  Serial.println(t);
  
  delay(15000);
  }

}

