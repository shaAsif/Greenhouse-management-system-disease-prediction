#include <DHT.h>

#define DHTPIN D5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

#define SOIL_PIN A0
#define LDR_PIN D0
#define PUMP_PIN D6
#define FAN_PIN D7

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(PUMP_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);

  // Pump and fan OFF initially (HIGH = Off for relay modules)
  digitalWrite(PUMP_PIN, HIGH);
  digitalWrite(FAN_PIN, HIGH);

  Serial.println("Smart Greenhouse System Started");
}

void loop() {

  // Soil Moisture Reading
  int soil = analogRead(SOIL_PIN);
  Serial.print("Soil Moisture: ");
  Serial.println(soil);

  // LDR Light Reading
  int lightState = digitalRead(LDR_PIN);
  Serial.print("Light: ");
  Serial.println(lightState == HIGH ? "Bright" : "Dark");

  // DHT11 Sensor Reading
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print("  Humidity: ");
  Serial.println(h);

  // Water Pump Logic
  if (soil < 400) {  // Dry soil
    digitalWrite(PUMP_PIN, LOW);  // ON
    Serial.println("PUMP: ON");
  } else {
    digitalWrite(PUMP_PIN, HIGH); // OFF
    Serial.println("PUMP: OFF");
  }

  // Fan Logic
  if (t > 30) {
    digitalWrite(FAN_PIN, LOW);  // ON
    Serial.println("FAN: ON");
  } else {
    digitalWrite(FAN_PIN, HIGH); // OFF
    Serial.println("FAN: OFF");
  }

  Serial.println("-------------------------");
  delay(2000);
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
