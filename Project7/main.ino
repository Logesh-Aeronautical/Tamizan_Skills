#include <DHT.h>
#include <Wire.h>
#include <MPU6050.h>

#define DHTPIN 4
#define DHTTYPE DHT22
#define PULSE_PIN 34
#define LED_PIN 2

DHT dht(DHTPIN, DHTTYPE);
MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  dht.begin();
  Wire.begin();

  pinMode(LED_PIN, OUTPUT);

  mpu.initialize();
  Serial.println("Health Monitoring System Started");
}

void loop() {
  // -------- Temperature --------
  float temp = dht.readTemperature();

  // -------- Heart Rate (Simulated) --------
  int pulseValue = analogRead(PULSE_PIN);
  int heartRate = map(pulseValue, 0, 4095, 50, 130);

  // -------- Fall Detection --------
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  float accel = sqrt(ax*ax + ay*ay + az*az) / 16384.0;

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" °C | Heart Rate: ");
  Serial.print(heartRate);
  Serial.print(" BPM | Accel: ");
  Serial.println(accel);

  bool alert = false;

  if (temp > 38) {
    Serial.println("⚠ High Temperature Alert");
    alert = true;
  }

  if (heartRate > 110) {
    Serial.println("⚠ High Heart Rate Alert");
    alert = true;
  }

  if (accel > 2.5) {
    Serial.println("⚠ Fall Detected");
    alert = true;
  }

  digitalWrite(LED_PIN, alert ? HIGH : LOW);

  if (alert) {
    Serial.println("🚨 Emergency Alert Sent");
  }

  Serial.println("------------------------");
  delay(2000);
}
