// Pin definitions for the security system components
#define moveSensor 9  // Digital output pin from the IR obstacle/motion sensor module
#define buzzerPin 8   // Pin connected to the active/passive buzzer for sound alarms
#define ledPin 10     // Pin connected to the warning LED

void setup() {
  // Configure the sensor pin as an input to read state changes
  pinMode(moveSensor, INPUT);
  
  // Configure buzzer and LED pins as outputs to trigger the alarm signals
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the current state of the motion/obstacle sensor (LOW typically means an object/movement is detected)
  int moveVal = digitalRead(moveSensor);

  // Trigger the alarm sequence if movement or an obstacle is detected
  if (moveVal == LOW) {
    // Loop 3 times to create a pulsing siren effect
    for (int i = 0; i < 3; i++) {
      // Emit a high-pitched tone (1000 Hz) for 1 second and turn on the warning LED
      tone(buzzerPin, 1000, 1000);
      digitalWrite(ledPin, HIGH);
      delay(200); // Short pause for the pulse rhythm
      
      // Shift to a lower-pitched tone (300 Hz) for 1 second and turn off the warning LED
      tone(buzzerPin, 300, 1000);
      digitalWrite(ledPin, LOW);
      delay(200); // Short pause before the next iteration
    }
  }
}