# Motion Sensor LED System (Arduino C++)

## 📌 Project Overview

This mini project uses an Arduino board, a motion sensor, and an LED to create a simple motion-activated lighting system.

When the motion sensor detects movement, the LED turns on for 5 seconds and then turns off. If no movement is detected, the LED remains off.

This project is a great introduction to digital input/output, motion detection, and basic Arduino programming.

## 🛠️ Components

- Arduino Uno or compatible board
- PIR motion sensor (or a compatible digital motion sensor)
- LED
- 220Ω resistor for the LED
- Breadboard
- Jumper wires
- USB cable for programming the Arduino

## 🔌 Pin Configuration

| Component | Arduino Pin | Mode |
|---|---|---|
| Motion Sensor | 9 | INPUT |
| LED | 8 | OUTPUT |

**Note:** The code assumes that the sensor outputs `LOW` when motion is detected. Many PIR sensors output `HIGH` when motion is detected, so check your sensor's documentation and adjust the condition if necessary.

## ⚙️ How It Works

1. The Arduino configures pin 9 as an input and pin 8 as an output.
2. The program reads the digital signal from the motion sensor.
3. When the sensor outputs `LOW`, the LED turns on.
4. The LED stays on for 5 seconds.
5. After the delay, the LED turns off.
6. If the sensor output is `HIGH`, the LED remains off.

## 💻 Code Features

- Digital sensor input using `digitalRead()`
- LED control using `digitalWrite()`
- Conditional logic with `if/else`
- Time delay using `delay()`
- Simple motion-activated lighting behavior

## 🚀 Applications

- Basic motion-activated lighting
- Arduino learning projects
- Simple security and automation prototypes
- Introduction to sensor-based systems

## 📚 Technologies

- **Language:** Arduino C++
- **Platform:** Arduino IDE
- **Microcontroller:** Arduino Uno or compatible board

## 📄 License

This project is intended for educational and personal use.
