#define SLOT1_BTN 2
#define SLOT2_BTN 3

#define SLOT1_LED 8
#define SLOT2_LED 9

void setup() {
  pinMode(SLOT1_BTN, INPUT_PULLUP);
  pinMode(SLOT2_BTN, INPUT_PULLUP);

  pinMode(SLOT1_LED, OUTPUT);
  pinMode(SLOT2_LED, OUTPUT);

  Serial.begin(9600);
  Serial.println("Smart Parking System Started");
}

void loop() {
  int slot1 = digitalRead(SLOT1_BTN);
  int slot2 = digitalRead(SLOT2_BTN);

  // SLOT 1
  if (slot1 == LOW) {   // button pressed
    digitalWrite(SLOT1_LED, HIGH);
    Serial.println("Slot 1: OCCUPIED");
  } else {
    digitalWrite(SLOT1_LED, LOW);
    Serial.println("Slot 1: EMPTY");
  }

  // SLOT 2
  if (slot2 == LOW) {
    digitalWrite(SLOT2_LED, HIGH);
    Serial.println("Slot 2: OCCUPIED");
  } else {
    digitalWrite(SLOT2_LED, LOW);
    Serial.println("Slot 2: EMPTY");
  }

  delay(1000);
}
