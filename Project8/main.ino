#define TRIG_PIN 5
#define ECHO_PIN 18
#define LED_PIN  2

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("Garbage Level Monitoring System Started");
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo time
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 10) {
    Serial.println("STATUS: BIN FULL");
    digitalWrite(LED_PIN, HIGH);
  }
  else if (distance < 20) {
    Serial.println("STATUS: BIN HALF");
    digitalWrite(LED_PIN, LOW);
  }
  else {
    Serial.println("STATUS: BIN EMPTY");
    digitalWrite(LED_PIN, LOW);
  }

  Serial.println("-----------------------");
  delay(1500);
}
