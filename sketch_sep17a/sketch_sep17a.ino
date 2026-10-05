#define soilMissurePIN A0
#define greenPin 8
#define redPin 9

void setup(){
  Serial.begin(9600);
  pinMode(soilMissurePIN, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop(){
  int wet = analogRead(soilMissurePIN);

  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);

  if (wet > 800){
    Serial.println(wet);
    digitalWrite(redPin, HIGH);
    delay(1000);
  } else if (wet < 800){
    Serial.println(wet);
    digitalWrite(greenPin, HIGH);
    delay(1000);
  }
}
