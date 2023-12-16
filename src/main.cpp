#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// #define ONE_WIRE_BUS 8 // for arduino uno

// GPIO where the DS18B20 is connected
const int ONE_WIRE_BUS = 4;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor(&oneWire);
float Celsius = 0;

void setup() {
  Serial.begin(9600);
  
  sensor.begin();
}

void loop() {
  sensor.requestTemperaturesByIndex(0);
  
  Serial.print("Temperature: ");
  Serial.print(sensor.getTempCByIndex(0));
  Serial.println(" C");

  delay(2000);
}
