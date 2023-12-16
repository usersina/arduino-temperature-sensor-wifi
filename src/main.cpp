#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>
#include <esp8266.h>

const char* SSID = "Freenet";
const char* PASSWORD = "";
const int ONE_WIRE_BUS = D2;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor(&oneWire);
float Celsius = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.print("Connecting to WiFi");
  WiFi.begin(SSID, PASSWORD);

  int connectionAttempts = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    connectionAttempts++;
    if (connectionAttempts > 60) { // 60 * 500ms = 30 seconds
      Serial.println();
      Serial.println("Failed to connect to WiFi within a reasonable time. Stopping program.");
      while (true); // Infinite loop to stop the program
    }
  }

  Serial.println();
  Serial.println("Network connected.");
  Serial.print("IP address: " + WiFi.localIP().toString() + "\n");

  sensor.begin();
}

void loop() {
  sensor.requestTemperaturesByIndex(0);
  
  Serial.print("Temperature: ");
  Serial.print(sensor.getTempCByIndex(0));
  Serial.println(" C");

  delay(2000);
}
