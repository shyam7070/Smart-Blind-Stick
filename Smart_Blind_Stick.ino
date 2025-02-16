
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Pin definitions
const int trigPin = 9;
const int echoPin = 8;
const int irPin = 7;
const int soilPin = A0;
const int ldrPin = A1;
const int buzzerPin = 6;
const int emergencyButton = 5;

SoftwareSerial gsm(10, 11); // RX, TX for GSM
TinyGPSPlus gps;

// Variables
long duration;
int distance;
int waterLevel;
int lightLevel;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(irPin, INPUT);
  pinMode(soilPin, INPUT);
  pinMode(ldrPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(emergencyButton, INPUT_PULLUP);
  
  Serial.begin(9600);
  gsm.begin(9600);
  Serial.println("Smart Blind Stick Initialized");
}

void loop() {
  // Ultrasonic Sensor for obstacle detection
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance < 50) {
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
  }

  // IR Sensor for path holes detection
  if (digitalRead(irPin) == LOW) {
    digitalWrite(buzzerPin, HIGH);
    delay(300);
    digitalWrite(buzzerPin, LOW);
  }

  // Soil Moisture Sensor for water detection
  waterLevel = analogRead(soilPin);
  if (waterLevel < 500) {
    digitalWrite(buzzerPin, HIGH);
    delay(700);
    digitalWrite(buzzerPin, LOW);
  }

  // LDR Sensor for light detection
  lightLevel = analogRead(ldrPin);
  if (lightLevel < 300) {
    Serial.println("Low Light Detected");
  }

  // Emergency button to send SMS
  if (digitalRead(emergencyButton) == LOW) {
    sendEmergencySMS();
  }

  // GPS data
  while (Serial.available() > 0) {
    gps.encode(Serial.read());
  }

  delay(500);
}

void sendEmergencySMS() {
  gsm.println("AT+CMGF=1"); // Set SMS mode
  delay(1000);
  gsm.println("AT+CMGS="+91xxxxxxxxxx""); // Replace with phone number
  delay(1000);
  gsm.print("Emergency! Location: ");
  gsm.print("Lat: "); gsm.print(gps.location.lat(), 6);
  gsm.print(", Lng: "); gsm.println(gps.location.lng(), 6);
  delay(1000);
  gsm.write(26); // End SMS
  delay(1000);
  Serial.println("Emergency SMS Sent!");
}
