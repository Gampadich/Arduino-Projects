// Define pins for the sensor input and the LED output
#define photoPin 8
#define ledPin 9

void setup() {
  // Configure photoresistor/sensor pin as input and LED pin as output
  pinMode(photoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  // Initialize serial communication at 9600 baud rate for monitoring
  Serial.begin(9600);
  
  // Ensure the LED starts in the OFF state
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Read the digital state (HIGH/LOW -> 1/0) from the sensor module
  int photoVal = digitalRead(photoPin);

  // Control the LED based on the sensor's digital output
  if (photoVal == 1) {
    digitalWrite(ledPin, HIGH); // Turn LED on if threshold is met (HIGH)
  } else if (photoVal == 0) {
    digitalWrite(ledPin, LOW);  // Turn LED off otherwise (LOW)
}

  // Print current sensor reading to the Serial Monitor
  Serial.println(photoVal);
  
  // Wait 1 second before the next reading
  delay(1000);
}