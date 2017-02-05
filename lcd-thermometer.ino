#include <LiquidCrystal.h>
#include "DHT/DHT.h"

// Thermometer data input pn
int DHT22_PIN = 7;

// thermometer object
DHT dht(DHT22_PIN, DHT22);
// LCD object
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  delay(1000);
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  lcd.clear();
  // print temperature to LCD display
  lcd.setCursor(0 ,0);
  lcd.print("Temp:");
  lcd.setCursor(9, 0);
  lcd.print(temperature);
  lcd.setCursor(14, 0);
  lcd.print((char)223); // print degree symbol
  lcd.setCursor(15, 0);
  lcd.print("C");
  // print humidity to LCD display
  lcd.setCursor(0, 1);
  lcd.print("Humidity:");
  lcd.setCursor(10, 1);
  lcd.print(humidity);
  lcd.setCursor(15, 1);
  lcd.print("%");
}
