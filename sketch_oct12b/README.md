# Motion Sensor Alarm System (Arduino C++)

## 📌 Project Overview

This mini project is a simple motion-activated alarm system built with an Arduino board, a motion sensor, a buzzer, and an LED.

When the motion sensor detects movement, the system activates an audible and visual alarm. The buzzer alternates between two tones while the LED flashes three times, providing a basic warning signal.

This project introduces the fundamentals of sensor-based security systems and Arduino digital input/output.

## 🛠️ Components

- Arduino Uno or compatible board
- PIR motion sensor or compatible digital motion sensor
- Active or passive buzzer
- LED
- 220Ω current-limiting resistor for the LED
- Breadboard
- Jumper wires
- USB cable for programming the Arduino

## 🔌 Pin Configuration

| Component | Arduino Pin | Mode |
|---|---|---|
| Motion Sensor | 9 | INPUT |
| Buzzer | 8 | OUTPUT |
| LED | 10 | OUTPUT |

## ⚙️ How It Works

1. The Arduino initializes the motion sensor, buzzer, and LED pins.
2. The program continuously reads the digital output of the motion sensor.
3. When the sensor output becomes `LOW`, the alarm sequence starts.
4. The buzzer alternates between two frequencies: 1000 Hz and 300 Hz.
5. The LED flashes in synchronization with the alternating tones.
6. The alarm sequence repeats three times for each detection event.
7. After the sequence finishes, the program continues monitoring the sensor.

## 💻 Code Features

- Motion detection using `digitalRead()`
- Audible alerts using `tone()`
- Visual alerts using an LED
- Repeating alarm sequence with a `for` loop
- Conditional logic using `if`
- Timing control using `delay()`

## 🚀 Applications

- Educational security system prototypes
- Motion-triggered warning devices
- Basic home security demonstrations
- Arduino electronics and programming practice
- Introduction to sound and visual alert systems

## 📚 Technologies

- **Programming Language:** Arduino C++
- **Development Environment:** Arduino IDE
- **Microcontroller:** Arduino Uno or compatible board

## ⚠️ Notes

- The code assumes that the motion sensor outputs `LOW` when motion is detected. Some sensors, including the HC-SR501 PIR module, typically output `HIGH` when motion is detected. Adjust the condition if necessary.
- The alarm sequence runs three times whenever the `if` condition is entered.
- The program uses blocking delays, so the Arduino cannot check the sensor continuously while the alarm sequence is running.
- This is an educational prototype, not a complete or certified security system.

## 📄 License

This project is intended for educational and personal use.
