# Arduino Single-Digit 7-Segment Clicker

A simple, interactive Arduino Uno project that acts as a physical counter. Every button press increments a number from 0 to 9, displaying the current digit on a single-digit 7-segment display.

## 🚀 Features
- **Direct Segment Control:** Manages individual segments (A-G) using standard digital output pins.
- **Internal Pull-Up Input:** Uses `INPUT_PULLUP` for reliable button reading without requiring external resistors.
- **Serial Feedback:** Outputs current counter values to the Arduino Serial Monitor in real-time.
- **Anti-Ghosting Logic:** Automatically clears previous segment states before rendering new digits to prevent overlapping artifacts.

---

## 🛠️ Hardware Requirements
- Arduino Uno (or compatible microcontroller)
- Single-digit 7-segment display
- Push button switch
- Breadboard and jumper wires

---

## 📌 Pin Mapping

| Component / Segment | Arduino Pin |
|---------------------|-------------|
| Segment A           | Pin 12      |
| Segment B           | Pin 11      |
| Segment C           | Pin 8       |
| Segment D           | Pin 9       |
| Segment E           | Pin 10      |
| Segment F           | Pin 13      |
| Segment G           | Pin 7       |
| Decimal Point (DP)  | Pin 5       |
| Push Button         | Pin 6       |

---

## 💻 How to Use
1. Wire up the circuit on your breadboard according to the pin mapping table above.
2. Connect your Arduino Uno to your computer via USB.
3. Open the Arduino IDE, paste the code, select your board/port, and upload it.
4. Open the **Serial Monitor** (set to `9600 baud`) and start clicking the button to watch numbers cycle from 0 to 9!
