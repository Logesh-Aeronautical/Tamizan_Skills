#define TRIG 9
#define ECHO 10

#define LED_LOW 2
#define LED_MID 3
#define LED_FULL 4

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(LED_LOW, OUTPUT);
  pinMode(LED_MID, OUTPUT);
  pinMode(LED_FULL, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);
  int distance = duration * 0.034 / 2;

  Serial.print("Water Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 25) {
    digitalWrite(LED_LOW, HIGH);
    digitalWrite(LED_MID, LOW);
    digitalWrite(LED_FULL, LOW);
    Serial.println("Water Level: LOW");
  }
  else if (distance > 10) {
    digitalWrite(LED_LOW, LOW);
    digitalWrite(LED_MID, HIGH);
    digitalWrite(LED_FULL, LOW);
    Serial.println("Water Level: MEDIUM");
  }
  else {
    digitalWrite(LED_LOW, LOW);
    digitalWrite(LED_MID, LOW);
    digitalWrite(LED_FULL, HIGH);
    Serial.println("Water Level: FULL");
  }

  delay(1000);
}
