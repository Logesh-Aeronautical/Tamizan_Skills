#include <DHT.h>

#define DHTPIN 15
#define DHTTYPE DHT22
#define SOIL_PIN 34

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int soilValue = analogRead(SOIL_PIN);

  Serial.println("---- Smart Agriculture Monitoring ----");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Soil Moisture Value: ");
  Serial.println(soilValue);

  if (soilValue < 1500) {
    Serial.println("Soil Status: WET");
  } else {
    Serial.println("Soil Status: DRY");
  }

  Serial.println("Data sent to IoT Dashboard");
  Serial.println("-------------------------------------");

  delay(2000);
}

