#define LIGHT 26
#define FAN 27

void setup() {
  Serial.begin(9600);
  pinMode(LIGHT, OUTPUT);
  pinMode(FAN, OUTPUT);

  Serial.println("Home Automation System Ready");
  Serial.println("Commands: ON1 OFF1 ON2 OFF2");
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "ON1") {
      digitalWrite(LIGHT, HIGH);
      Serial.println("Light ON");
    } 
    else if (command == "OFF1") {
      digitalWrite(LIGHT, LOW);
      Serial.println("Light OFF");
    }
    else if (command == "ON2") {
      digitalWrite(FAN, HIGH);
      Serial.println("Fan ON");
    }
    else if (command == "OFF2") {
      digitalWrite(FAN, LOW);
      Serial.println("Fan OFF");
    }
    else {
      Serial.println("Invalid Command");
    }
  }
}
