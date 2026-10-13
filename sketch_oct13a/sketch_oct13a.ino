// Define pins for the push button and 7-segment display segments (A-G and DP)
#define buttonPin 6
#define sectorA 12
#define sectorB 11
#define sectorC 8
#define sectorD 9
#define sectorE 10
#define sectorF 13
#define sectorG 7
#define sectorDP 5

void setup() {
  // Configure the button pin with an internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Configure all 7-segment display pins as outputs
  pinMode(sectorA, OUTPUT);
  pinMode(sectorB, OUTPUT);
  pinMode(sectorC, OUTPUT);
  pinMode(sectorD, OUTPUT);
  pinMode(sectorE, OUTPUT);
  pinMode(sectorF, OUTPUT);
  pinMode(sectorG, OUTPUT);
  pinMode(sectorDP, OUTPUT);
  
  // Initialize Serial communication for debugging at 9600 baud
  Serial.begin(9600);

  // Turn on the decimal point by default as an indicator
  digitalWrite(sectorDP, HIGH);
}

// Global counter variable to track current digit (0-9)
int num = 0;

void loop() {
  // Read the button state (LOW when pressed due to INPUT_PULLUP)
  bool click = digitalRead(buttonPin);

  // Check if the button is pressed
  if (click == 0){
    num++; // Increment the counter value

    // Clear all segments (turn them OFF) before rendering the next digit to prevent overlapping
    digitalWrite(sectorA, LOW);
    digitalWrite(sectorB, LOW);
    digitalWrite(sectorC, LOW);
    digitalWrite(sectorD, LOW);
    digitalWrite(sectorE, LOW);
    digitalWrite(sectorF, LOW);
    digitalWrite(sectorG, LOW);
    
    // Print the current counter value to the Serial Monitor
    Serial.println(num);

    // Simple delay for debounce and to control click speed
    delay(200);
  }

  // Display logic for numbers 0 through 9
  if (num == 1){
    digitalWrite(sectorB, HIGH);
    digitalWrite(sectorC, HIGH);
  } else if (num == 2){
    digitalWrite(sectorA, HIGH);
    digitalWrite(sectorB, HIGH);
    digitalWrite(sectorG, HIGH);
    digitalWrite(sectorE, HIGH);
    digitalWrite(sectorD, HIGH);
  } else if (num == 3){
    digitalWrite(sectorA, HIGH);
    digitalWrite(sectorB, HIGH);
    digitalWrite(sectorG, HIGH);
    digitalWrite(sectorC, HIGH);
    digitalWrite(sectorD, HIGH);
  } else if (num == 4){
    digitalWrite(sectorF, HIGH);
    digitalWrite(sectorG, HIGH);
    digitalWrite(sectorB, HIGH);
    digitalWrite(sectorC, HIGH);
  } else if (num == 5){
    digitalWrite(sectorA, HIGH);
    digitalWrite(sectorF, HIGH);
    digitalWrite(sectorG, HIGH);
    digitalWrite(sectorC, HIGH);
    digitalWrite(sectorD, HIGH);
  } else if (num == 6){
    digitalWrite(sectorA, HIGH);
    digitalWrite(sectorF, HIGH);
    digitalWrite(sectorG, HIGH);
    digitalWrite(sectorE, HIGH);
    digitalWrite(sectorD, HIGH);
    digitalWrite(sectorC, HIGH);
  } else if (num == 7){
    digitalWrite(sectorA, HIGH);
    digitalWrite(sectorB, HIGH);
    digitalWrite(sectorC, HIGH);
  } else if (num == 8){
    digitalWrite(sectorA, HIGH);
    digitalWrite(sectorB, HIGH);
    digitalWrite(sectorC, HIGH);
    digitalWrite(sectorD, HIGH);
    digitalWrite(sectorE, HIGH);
    digitalWrite(sectorF, HIGH);
    digitalWrite(sectorG, HIGH);
  } else if (num == 9){
    digitalWrite(sectorA, HIGH);
    digitalWrite(sectorB, HIGH);
    digitalWrite(sectorC, HIGH);
    digitalWrite(sectorD, HIGH);
    digitalWrite(sectorF, HIGH);
    digitalWrite(sectorG, HIGH);
  } else if (num > 9){
    num = 0; // Reset counter back to 0 when it exceeds 9

    // Default display state for 0 reset
    digitalWrite(sectorA, HIGH);
    digitalWrite(sectorB, HIGH);
    digitalWrite(sectorC, HIGH);
    digitalWrite(sectorD, HIGH);
    digitalWrite(sectorF, HIGH);
    digitalWrite(sectorE, HIGH);
  }
}
