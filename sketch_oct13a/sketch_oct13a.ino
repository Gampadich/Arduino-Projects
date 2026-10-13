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
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(sectorA, OUTPUT);
  pinMode(sectorB, OUTPUT);
  pinMode(sectorC, OUTPUT);
  pinMode(sectorD, OUTPUT);
  pinMode(sectorE, OUTPUT);
  pinMode(sectorF, OUTPUT);
  pinMode(sectorG, OUTPUT);
  pinMode(sectorDP, OUTPUT);
  Serial.begin(9600);

  digitalWrite(sectorDP, HIGH);
}

int num = 0;

void loop() {
  bool click = digitalRead(buttonPin);

  if (click == 0){
    num++;

    digitalWrite(sectorA, LOW);
    digitalWrite(sectorB, LOW);
    digitalWrite(sectorC, LOW);
    digitalWrite(sectorD, LOW);
    digitalWrite(sectorE, LOW);
    digitalWrite(sectorF, LOW);
    digitalWrite(sectorG, LOW);
    Serial.println(num);

    delay(200);
  }

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
    num = 0;

    digitalWrite(sectorA, HIGH);
    digitalWrite(sectorB, HIGH);
    digitalWrite(sectorC, HIGH);
    digitalWrite(sectorD, HIGH);
    digitalWrite(sectorF, HIGH);
    digitalWrite(sectorE, HIGH);
  }
}
