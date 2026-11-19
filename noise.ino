#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

// WiFi Credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Topic ID
const char* topic = "YOUR_TOPIC_ID";

// KY-038 Sound Sensor
#define SOUND_PIN A0

// Example threshold (adjust after testing)
const int NOISE_THRESHOLD = 500;

// KiwisIoT object
KiwisIoT kiwisiot(ssid, pass, topic);

unsigned long previousMillis = 0;
const unsigned long interval = 2000;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("================================");
  Serial.println("IoT Noise Pollution Monitoring");
  Serial.println("================================");

  pinMode(SOUND_PIN, INPUT);

  Serial.println("KY-038 Sensor Initialized");
  Serial.println("Starting KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialization returned");
}

void loop() {

  // Maintain KiwisIoT connection
  kiwisiot.run();

  if (millis() - previousMillis >= interval) {
    previousMil