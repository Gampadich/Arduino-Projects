#define moveSensor 9
#define ledPin 8

void setup() {
  pinMode(moveSensor, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int moveVal = digitalRead(moveSensor);

  if (moveVal == LOW){
    digitalWrite(ledPin, HIGH);
    delay(5000);
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
