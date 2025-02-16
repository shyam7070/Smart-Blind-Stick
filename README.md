# Smart-Blind-Stick
This project is a Smart Blind Stick designed to assist visually impaired individuals by detecting obstacles, path holes, and drainage water. It also includes GPS and GSM modules for emergency alerts.

# Features
Obstacle Detection: Ultrasonic sensor detects obstacles in front of the user.
Path Hole Detection: IR sensor identifies holes or gaps on the path.
Drainage Water Detection: Soil moisture sensor detects water on roads.
Emergency Alerts: GPS module tracks location, and GSM module sends an emergency SMS with the user’s location.
Light Detection: LDR sensor detects ambient light conditions for night-time assistance.

# Components Used
Arduino Nano – Main microcontroller.
Ultrasonic Sensor (HC-SR04) – Detects obstacles.
IR Sensor – Detects path holes.
Soil Moisture Sensor – Detects water on roads.
LDR Sensor – Detects light levels.
GPS Module (Neo-6M) – Tracks user location.
GSM Module (SIM800L) – Sends emergency SMS.
Buzzer – Provides audio alerts.
Rechargeable Battery – Powers the device.

# Working
The ultrasonic sensor constantly scans for obstacles and alerts the user through a buzzer.
The IR sensor ensures the path is clear of holes or gaps.
The soil moisture sensor identifies water and alerts the user.
In emergencies, the user can press a button to send an SMS with their location via GSM and GPS modules.
LDR ensures functionality in low-light conditions.

Installation

1. Connect the components as per the circuit schematic.
2. Upload the Arduino code using the Arduino IDE.
3. Power the device using the rechargeable battery.

# Future Enhancements
Integrating voice assistance for user guidance.
Adding an AI-based object recognition system.

# Author
Narasingarao K
+917075025629
knrkondapalli123@gmail.com
