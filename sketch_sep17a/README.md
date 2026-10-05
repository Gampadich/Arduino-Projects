# 🌿 Smart Soil Moisture Monitoring System (Arduino C++)

## 📌 Project Overview

This project is an automated hardware-software prototype designed to monitor soil moisture levels in real time using an **Arduino Uno** and an analog **Soil Moisture Sensor**.

The system evaluates soil moisture levels and provides immediate visual feedback via LED indicators while logging raw analog data to the Serial Monitor.

It serves as a foundational module for:

* 🌱 Smart agriculture systems
* 💧 Automated plant watering setups
* 📊 IoT-driven environmental monitoring

---

## 🛠️ Hardware Components

| Component           | Description                                                      |
| ------------------- | ---------------------------------------------------------------- |
| **Microcontroller** | Arduino Uno (ATmega328P)                                         |
| **Sensor**          | YL-69 / HW-080 Soil Moisture Sensor with LM393 Comparator Module |
| **Red LED**         | Dry soil warning                                                 |
| **Green LED**       | Sufficient moisture indicator                                    |
| **Resistors**       | 220Ω current-limiting resistors                                  |
| **Prototyping**     | Breadboard and DuPont jumper wires                               |

---

## ⚡ Circuit Schematic & Pin Layout

| Component Pin               | Arduino Pin  | Function                             |
| --------------------------- | ------------ | ------------------------------------ |
| Sensor Analog Output (`AO`) | **A0**       | Analog soil moisture reading         |
| Red LED (Anode)             | **D9**       | High threshold indicator — dry soil  |
| Green LED (Anode)           | **D8**       | Low threshold indicator — moist soil |
| VCC / GND                   | **5V / GND** | Module power supply                  |

### 🔌 Pin Summary

```text
Soil Moisture Sensor
├── AO  → A0
├── VCC → 5V
└── GND → GND

Red LED
└── Anode → D9

Green LED
└── Anode → D8
```

> ⚠️ Always use a current-limiting resistor (e.g. **220Ω**) when connecting LEDs to Arduino pins.

---

## 🔍 System Logic & How It Works

### 1. Data Acquisition

The soil moisture sensor measures the electrical conductivity/resistance of the soil and outputs an analog signal through pin `A0`.

The Arduino reads this signal using its built-in **10-bit ADC**, producing a value between:

```text
0 – 1023
```

---

### 2. Threshold Logic

The system uses a threshold value of **800** to determine the soil condition.

| Sensor Value | Soil Condition | LED             |
| ------------ | -------------- | --------------- |
| `wet > 800`  | 🌵 Dry soil    | 🔴 Red LED ON   |
| `wet < 800`  | 💧 Moist soil  | 🟢 Green LED ON |

When the sensor reading exceeds the threshold, the system considers the soil dry and activates the **Red LED**.

When the reading is below the threshold, the system considers the soil sufficiently moist and activates the **Green LED**.

> 💡 The exact threshold depends on the sensor, soil type, and environmental conditions. Calibration is recommended for reliable measurements.

---

### 3. Serial Monitor Telemetry

Raw ADC readings are sent to the Arduino Serial Monitor at **9600 baud**.

Example output:

```text
742
765
801
824
798
```

This allows the user to monitor changes in soil moisture and helps with system calibration and debugging.

---

## 🚀 Potential Future Enhancements

### 📊 Data Calibration

Convert raw ADC readings into a more understandable percentage scale:

```cpp
int moisturePercent = map(wet, 1023, 0, 0, 100);
```

This would allow the system to display moisture approximately as:

```text
0%   → Very Dry
50%  → Moderate Moisture
100% → Very Wet
```

> The mapping should be calibrated using actual dry and wet soil measurements for better accuracy.

### 💧 Automated Watering

Add a **5V relay module** and a small water pump to automatically irrigate the plant when the soil becomes too dry.

Possible logic:

```text
Soil moisture
      │
      ▼
  Read sensor
      │
      ▼
 Is soil dry?
   /       \
 YES       NO
  │         │
  ▼         ▼
Pump ON   Pump OFF
```

### 🌐 IoT Integration

The project could also be expanded with an ESP8266, ESP32, or another network-enabled controller to provide:

* 📱 Remote monitoring
* ☁️ Cloud data storage
* 📈 Moisture history and charts
* 🔔 Low-moisture notifications
* 💧 Remote irrigation control

---

## 📂 Project Structure

A possible project structure:

```text
smart-soil-moisture-monitor/
│
├── smart-soil-moisture-monitor.ino
├── README.md
└── LICENSE
```

---

## 📋 Requirements

### Software

* [Arduino IDE](https://www.arduino.cc/en/software)
* Arduino Uno board support

### Hardware

* Arduino Uno
* YL-69 / HW-080 soil moisture sensor
* Red LED
* Green LED
* 2 × 220Ω resistors
* Breadboard
* Jumper wires
* USB cable

---

## ⚙️ Configuration

The main threshold can be adjusted in the Arduino code:

```cpp
#define MOISTURE_THRESHOLD 800
```

Lower or higher values can be tested depending on the sensor and soil conditions.

For accurate results, measure the sensor output in both:

1. Completely dry soil
2. Properly watered soil

Then select an appropriate threshold between those values.

---

## 📝 Notes

* The YL-69 sensor probes can corrode over time when continuously powered.
* For long-term projects, consider powering the sensor only when a measurement is required.
* Sensor readings can vary depending on soil composition, temperature, and moisture distribution.
* The `800` threshold is an example and should be calibrated for the specific setup.

---

## 📄 License

This project is open-source and can be modified or extended for educational and personal projects.
