# Arduino Digital Sensor & LED Controller

A simple Arduino project that reads digital signals from a sensor module (such as a photoresistor with an LM393 comparator board) and controls an LED based on the sensor's threshold state.

## Features

- **Digital Signal Processing**: Reads clean HIGH/LOW (`1` / `0`) digital states from the sensor module.
- **Hardware Feedback**: Automatically toggles an LED indicator depending on environmental changes (e.g., light/dark threshold).
- **Serial Monitoring**: Outputs real-time sensor states to the Arduino Serial Monitor for debugging.

## Components Used

- Arduino Board (e.g., Uno / Nano)
- Sensor module with LM393 comparator (e.g., photoresistor module)
- LED
- Jumper wires (Male-to-Male / Male-to-Female)

## Wiring / Pinout Diagram

| Component Pin | Arduino Pin | Description |
| ------------- | ----------- | ----------- |
| **DO** (Digital Out) | Pin `8` (`photoPin`) | Connects sensor digital output |
| **LED Positive (+)** | Pin `9` (`ledPin`) | Connects LED control pin |
| **VCC** | 5V | Power supply |
| **GND** | GND | Ground |

*Note: You can adjust the hardware triggering threshold by turning the onboard blue potentiometer (trimmer) on the sensor module.*

## Usage

1. Connect the hardware according to the pinout table above.
2. Open the project sketch in **Arduino IDE**.
3. Select your board and COM port via **Device Manager**.
4. Upload the code to your Arduino board and open the **Serial Monitor** (9600 baud) to view live states.
