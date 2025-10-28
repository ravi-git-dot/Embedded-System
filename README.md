🛰️ Mini Satellite & Smart System Projects using Raspberry Pi Pico
🌍 Project Overview

This repository shares the complete journey of building a mini satellite, starting from simple electronic experiments to the final working model.

It includes learning activities like series and parallel connections, load control, and working with basic electronic components such as transistors, switches, LEDs, diodes, voltage regulators, potentiometers, and motors.

You’ll also find exciting hands-on projects using the Raspberry Pi Pico, including:

1. Smart Irrigation System – automates watering using a moisture sensor and IC control

2. Logic Gates & Conditional Statements – helps understand basic electronics and coding logic

3. LDR Sensor Module – part of the Smart Blind Stick project that reacts to light levels

4 Mini Satellite Project – collects real-world data using multiple sensors

🧠 What I learn from the course

1.Basics of electronic circuits (series/parallel connections)

2.Using microcontrollers like Raspberry Pi Pico

3.Reading and storing data from sensors

4.Interfacing multiple modules in one system

Understanding real-world applications like smart farming and satellite data collection

#Components Used

Raspberry Pi Pico (microcontroller)

MQ2 – Gas & air quality sensor

MPU6050 – Gyroscope and accelerometer

BMP280 – Pressure and temperature sensor

Moisture Sensor – For smart irrigation system

LDR Sensor – For light detection (smart blind stick)

SD Card Module – For data logging

Transistors, LEDs, Diodes, Potentiometers, Motors, Switches

🚀 Getting Started
1. 🧩 Hardware Setup

Connect the sensors to the Raspberry Pi Pico using I2C or analog/digital pins as shown in your wiring diagrams.

Ensure all sensors share a common ground.

Use a breadboard or PCB for neat connections.

2. 💻 Software Setup

Install Thonny IDE on your computer.

Connect your Raspberry Pi Pico via USB.

Open the .py files from this repository in Thonny.

Make sure to install or copy required libraries (e.g., chittiSat folder) to the Pico.

3. ▶️ Run the Code

Upload the code file (e.g., main.py) to the Pico.

Open the Shell window in Thonny to view sensor readings.

For the satellite project, readings will be saved automatically to the SD card.

📊 Output Example

BMP280 → Temperature, Pressure, Altitude

MPU6050 → Acceleration, Gyroscope, Motion detection

MQ2 → Air quality or gas concentration

SD Card → Saves sensor data for analysis
