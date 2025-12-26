#define GAS_PIN 34
#define LED_PIN 26
#define BUZZER_PIN 27

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  int gasValue = analogRead(GAS_PIN);

  Serial.print("Gas Level: ");
  Serial.println(gasValue);

  if (gasValue > 2000) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("🔥 FIRE DETECTED");
    Serial.println("Alert Sent");
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("Status Normal");
  }

  Serial.println("---------------------");
  delay(2000);
}
