# 🚦 Arduino Traffic Light

An Arduino-based traffic light project that simulates a real traffic light sequence using three LEDs, a push button, and a buzzer.

The project starts in the normal green-light state. When the button is pressed, the traffic light runs through a complete sequence with countdowns, green-light flashing, and buzzer notifications.

## 📋 Project Overview

This project demonstrates how to control multiple LEDs, read a push button, generate sounds with a buzzer, and implement timed sequences using Arduino.

The traffic light has three LEDs:

* 🔴 **Red** — stop
* 🟡 **Yellow** — warning / transition
* 🟢 **Green** — go

A button is used to start the traffic light sequence.

A buzzer provides an audible signal during the green-light flashing stage.

## 🔧 Components

| Component          | Quantity |
| ------------------ | :------: |
| Arduino board      |     1    |
| Red LED            |     1    |
| Yellow LED         |     1    |
| Green LED          |     1    |
| Push button        |     1    |
| Buzzer             |     1    |
| Resistors for LEDs |     3    |
| Breadboard         |     1    |
| Jumper wires       |  Several |

## 🔌 Pin Configuration

| Component     | Arduino Pin |
| ------------- | :---------: |
| 🔴 Red LED    |     `11`    |
| 🟡 Yellow LED |     `10`    |
| 🟢 Green LED  |     `9`     |
| 🔘 Button     |     `12`    |
| 🔊 Buzzer     |     `8`     |

The LED brightness is set to the maximum PWM value:

```cpp
#define bright 255
```

## ⚙️ How It Works

### 🟢 Default State

When the button is not pressed, the green LED remains turned on.

```cpp
analogWrite(greenLedPin, bright);
```

This represents the normal **GO** state.

### 🔘 Button Press

The button uses the Arduino's internal pull-up resistor:

```cpp
pinMode(button, INPUT_PULLUP);
```

Because of this configuration, the button is considered pressed when `digitalRead()` returns `LOW`.

```cpp
if (buttonState == LOW)
```

When the button is pressed, the traffic light sequence begins.

## 🚦 Traffic Light Sequence

The complete sequence works as follows:

### 1. 🟢 Green Light

The green LED turns on and a short countdown begins:

```cpp
timer(3, 1);
```

The countdown lasts approximately 3 seconds.

### 2. 🟢 Green Light Flashing

The green LED turns off and starts flashing.

During this stage, the buzzer produces short sounds at **2000 Hz**:

```cpp
tone(buzzerPin, 2000, 100);
```

The `flickering()` function is responsible for this warning sequence.

### 3. 🟡 Yellow Light

After the green light finishes flashing, the yellow LED turns on for 3 seconds:

```cpp
analogWrite(yellowLedPin, bright);
delay(3000);
```

This indicates that the traffic light is changing.

### 4. 🔴 Red Light

The yellow LED turns off and the red LED turns on:

```cpp
analogWrite(redLedPin, bright);
```

A 12-second countdown then starts:

```cpp
timer(12, 0);
```

The red light represents the **STOP** state.

### 5. 🟡 Warning Before Green

After the red-light countdown, the yellow LED turns on for another 3 seconds.

This indicates that the traffic light is about to return to green.

### 6. 🟢 Return to Green

Finally, the yellow and red LEDs turn off.

The program returns to its default state, where the green LED is turned on.

## ⏱️ Countdown

The project uses the `timer()` function to create countdowns.

```cpp
void timer(int seconds, bool type)
```

The `seconds` parameter determines how long the timer runs.

The `type` parameter determines which values are printed to the Serial Monitor.

For example:

```cpp
timer(3, 1);
```

is used during the green-light countdown, while:

```cpp
timer(12, 0);
```

is used during the red-light countdown.

## 🔊 Buzzer

The buzzer is connected to pin `8`.

During the green LED flashing sequence, the buzzer generates a short 2000 Hz tone:

```cpp
tone(buzzerPin, 2000, 100);
```

This provides an audible warning in addition to the visual flashing LED.

## 💻 Serial Monitor

The project uses the Serial Monitor to display timer values.

Serial communication is initialized at:

```cpp
Serial.begin(9600);
```

To view the countdown:

1. Upload the program to the Arduino.
2. Open the **Serial Monitor** in the Arduino IDE.
3. Set the baud rate to **9600**.
4. Press the button.

The countdown values will be displayed in the Serial Monitor.

## 🧩 Main Functions

### `flickering()`

Controls the green LED flashing and buzzer sounds before the traffic light changes to yellow.

```cpp
void flickering()
```

### `timer()`

Creates a countdown and sends its values to the Serial Monitor.

```cpp
void timer(int seconds, bool type)
```

### `setup()`

Initializes:

* Serial communication
* LED pins
* Button input
* Buzzer pin

### `loop()`

Continuously checks the button state and controls the entire traffic light sequence.

## 📐 Circuit Connections

Basic connection layout:

```text
                 Arduino
              ┌───────────┐
              │           │
 Red LED  ────┤ Pin 11    │
 Yellow LED ──┤ Pin 10    │
 Green LED ───┤ Pin 9     │
 Button ──────┤ Pin 12    │
 Buzzer ──────┤ Pin 8     │
              │           │
              └───────────┘
```

Each LED should be connected through an appropriate resistor.

The button is configured with `INPUT_PULLUP`, so an external pull-up resistor is not required.

## 🚀 Installation

1. Assemble the circuit according to the pin configuration.
2. Connect the Arduino board to your computer.
3. Open the project in **Arduino IDE**.
4. Select your Arduino board.
5. Select the correct COM/serial port.
6. Upload the code.
7. Open the Serial Monitor at **9600 baud**.
8. Press the button to start the traffic light sequence.

## 🛠️ Customization

You can easily change the pins by modifying the definitions at the beginning of the program:

```cpp
#define redLedPin 11
#define yellowLedPin 10
#define greenLedPin 9
#define button 12
#define buzzerPin 8
```

You can also change the LED brightness:

```cpp
#define bright 255
```

For example, a lower value will make the LEDs dimmer.

The timing of the traffic light can be changed by modifying:

```cpp
timer(3, 1);
```

and:

```cpp
timer(12, 0);
```

The yellow-light duration can also be changed by modifying:

```cpp
delay(3000);
```

## 📚 What This Project Demonstrates

This project is useful for learning:

* Arduino digital inputs and outputs
* PWM LED control with `analogWrite()`
* Push-button input
* Internal pull-up resistors
* Delays and timing
* Functions and parameters
* `for` loops
* Conditional statements
* Serial communication
* Buzzer control with `tone()`

## 📄 License

This project is intended for educational and personal use. You are free to modify and improve the code for your own Arduino projects.
