// Pin definitions for sensors and actuators
#define SOIL_MOISTURE_PIN A0  // Analog pin connected to the moisture sensor output
#define GREEN_LED_PIN 8       // Digital pin for the green LED (optimal moisture)
#define RED_LED_PIN 9         // Digital pin for the red LED (dry soil warning)

void setup() {
  // Initialize serial communication at 9600 baud rate for data logging
  Serial.begin(9600);
  
  // Configure pin modes
  pinMode(SOIL_MOISTURE_PIN, INPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
}

void loop() {
  // Read the raw analog value from the soil moisture sensor (0 - 1023)
  int moistureValue = analogRead(SOIL_MOISTURE_PIN);

  // Reset LED states before evaluating condition
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);

  // Print current sensor value to Serial Monitor for debugging and monitoring
  Serial.println(moistureValue);

  // Evaluate moisture levels based on the defined threshold (800)
  // Higher analog readings indicate drier soil (higher resistance)
  if (moistureValue >= 800) {
    // Soil is dry: Turn on the Red LED to indicate watering is needed
    digitalWrite(RED_LED_PIN, HIGH);
  } else {
    // Soil has sufficient moisture: Turn on the Green LED
    digitalWrite(GREEN_LED_PIN, HIGH);
  }

  // Delay for 1 second between readings to stabilize output
  delay(1000);
}
