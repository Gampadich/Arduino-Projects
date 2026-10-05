// Pin allocations for LEDs, button, and buzzer
#define RED_LED_PIN 11       // Pin for Red LED
#define YELLOW_LED_PIN 10    // Pin for Yellow LED
#define GREEN_LED_PIN 9      // Pin for Green LED
#define BUTTON_PIN 12        // Pin for pedestrian call button (INPUT_PULLUP)
#define BUZZER_PIN 8         // Pin for piezoelectric buzzer
#define BRIGHTNESS 255       // Max PWM brightness level for LEDs

/**
 * Handles the blinking phase for the Green LED before turning off.
 * Emits audio beeps and logs remaining time to the Serial Monitor.
 */
void flickering() {
  for (int i = 4; i > 0; i--) {
    analogWrite(GREEN_LED_PIN, BRIGHTNESS);
    delay(500);
    analogWrite(GREEN_LED_PIN, 0);

    // Skip delay on specific iteration to adjust timing sequence
    if (i != 3) {
      delay(500);
    }

    // Calculate and log display time
    int timer = i + 3;
    Serial.println(timer);

    // Emit a 2000Hz audio signal for 100ms
    tone(BUZZER_PIN, 2000, 100);
  }
}

/**
 * Custom countdown timer function.
 * @param seconds Duration of the timer in seconds.
 * @param type Sequence offset identifier (1 for green phase, 0 for red phase).
 */
void timer(int seconds, bool type) {
  for (int i = seconds; i > 0; i--) {
    delay(1000);
    if (type == 1) {
      int time = i + 7;
      Serial.println(time);
    } else if (type == 0) {
      int time = i + 2;
      Serial.println(time);
    }
  }
}

void setup() {
  // Initialize Serial Communication at 9600 baud rate for live data output
  Serial.begin(9600);

  // Configure output pins for traffic light indicators and audio output
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Configure button input using internal pull-up resistor
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // Read state of the pedestrian call button (LOW when pressed due to PULLUP)
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {
    // Phase 1: Green light remains ON for a short countdown (3 seconds)
    analogWrite(GREEN_LED_PIN, BRIGHTNESS);
    timer(3, 1);
    analogWrite(GREEN_LED_PIN, 0);

    // Phase 2: Green light flashes with audio alerts
    flickering();

    // Phase 3: Yellow light phase before stopping traffic
    analogWrite(YELLOW_LED_PIN, BRIGHTNESS);
    delay(3000);
    analogWrite(YELLOW_LED_PIN, 0);

    // Phase 4: Red light turns ON for pedestrian crossing (12 seconds)
    analogWrite(RED_LED_PIN, BRIGHTNESS);
    timer(12, 0);

    // Phase 5: Transition phase - Yellow light with Red
    analogWrite(YELLOW_LED_PIN, BRIGHTNESS);
    delay(3000);

    // Reset state: Turn off Red and Yellow LEDs
    analogWrite(YELLOW_LED_PIN, 0);
    analogWrite(RED_LED_PIN, 0);

  } else {
    // Default state: Keep Green light ON for traffic flow
    analogWrite(GREEN_LED_PIN, BRIGHTNESS);
  }
}
