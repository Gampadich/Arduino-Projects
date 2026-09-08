#define redLedPin 11
#define yellowLedPin 10
#define greenLedPin 9
#define button 12
#define buzzerPin 8
#define bright 255

void flickering(){
  for (int i = 4; i > 0; i--){
    analogWrite(greenLedPin, bright);
    delay(500);
    analogWrite(greenLedPin, 0);
    if (i != 3){
      delay(500);
    }
    int timer = i + 3;
    Serial.println(timer);
    tone(buzzerPin, 2000, 100);
  }
}

void timer(int seconds, bool type){
  for (int i = seconds; i > 0; i--){
    delay(1000);
    if (type == 1){
      int time = i + 7;
      Serial.println(time);
    } else if (type == 0){
      int time = i + 2;
      Serial.println(time);
    }
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(button);

  if (buttonState == LOW){
    analogWrite(greenLedPin, bright);
    timer(3, 1);
    analogWrite(greenLedPin, 0);
    flickering();
    analogWrite(yellowLedPin, bright);
    delay(3000);
    analogWrite(yellowLedPin, 0);
    analogWrite(redLedPin, bright);
    timer(12, 0);
    analogWrite(yellowLedPin, bright);
    delay(3000);
    analogWrite(yellowLedPin, 0);
    analogWrite(redLedPin, 0);
    
  } else {
    analogWrite(greenLedPin, bright);
  }
}
