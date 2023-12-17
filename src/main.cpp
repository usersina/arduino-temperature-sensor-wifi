#include <DallasTemperature.h>
#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>
#include <OneWire.h>
#include <esp8266.h>
#include <secrets.h>

#include "addons/TokenHelper.h"

// Firebase configuration
FirebaseData firebaseData;
FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPreviousMillis = 0;  // the last time the data was sent
bool signupOk = false;

// Define the variables for temperature sensor
const int ONE_WIRE_BUS = D2;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor(&oneWire);
float temperatureCelcius = 0;

void setup() {
    Serial.begin(115200);
    while (!Serial) {
        // Waiting for the serial port to connect
    }

    // ==================== WiFi ====================
    Serial.print("Connecting to WiFi");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    int connectionAttempts = 0;
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        connectionAttempts++;
        if (connectionAttempts > 60) {  // 60 * 500ms = 30 seconds
            Serial.println();
            Serial.println("Failed to connect to WiFi within a reasonable time. Stopping program.");
            while (true)
                ;  // Infinite loop to stop the program
        }
    }

    Serial.println();
    Serial.println("Network connected.");
    Serial.print("IP address: " + WiFi.localIP().toString() + "\n");

    // ==================== Firebase ====================
    config.api_key = FIREBASE_API_KEY;
    config.host = FIREBASE_HOST;
    if (Firebase.signUp(&config, &auth, "", "")) {
        Serial.println("Sign up succeeded");
        signupOk = true;
    } else {
        Serial.println("Sign up failed");
        Serial.printf("Reason: %s\n", config.signer.signupError.message.c_str());
    }
    config.token_status_callback = tokenStatusCallback;
    Firebase.begin(&config, &auth);
    Firebase.reconnectNetwork(true);

    // ==================== Temperature Sensor ====================
    sensor.begin();
}

void loop() {
    if (Firebase.ready() && signupOk &&
        (millis() - sendDataPreviousMillis > 5000 ||
         sendDataPreviousMillis == 0)) {
        sendDataPreviousMillis = millis();

        sensor.requestTemperaturesByIndex(0);
        temperatureCelcius = sensor.getTempCByIndex(0);

        Serial.print("Temperature: ");
        Serial.print(temperatureCelcius);
        Serial.println(" C");

        if (Firebase.RTDB.setFloat(&firebaseData, "Sensor/temperature", temperatureCelcius)) {
            Serial.print(temperatureCelcius);
            Serial.print(" C sent to Firebase at path" + firebaseData.dataPath());
            Serial.println(" (" + firebaseData.dataType() + ")");
        } else {
            Serial.println("FAILED: " + firebaseData.errorReason());
        }
    }
}
