
#define moveSensor 9  // Digital pin connected to the motion sensor
#define ledPin 8      // Digital pin connected to the LED

void setup() {
  // Configure the motion sensor pin as an input
  pinMode(moveSensor, INPUT);

  // Configure the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the current digital signal from the motion sensor
  int moveVal = digitalRead(moveSensor);

  // Check whether the sensor output is LOW
  // This code assumes that LOW indicates detected motion
  if (moveVal == LOW) {
    // Turn the LED on
    digitalWrite(ledPin, HIGH);

    // Keep the LED on for 5 seconds
    delay(5000);

    // Turn the LED off after the delay
    digitalWrite(ledPin, LOW);
  } else {
    // Keep the LED off when the sensor output is HIGH
    digitalWrite(ledPin, LOW);
  }
}
