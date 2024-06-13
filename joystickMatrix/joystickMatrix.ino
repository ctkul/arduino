#include <LiquidCrystal.h>
#include <DHT.h>

const int DHTTYPE = DHT11; 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DHT dht(8, DHT11);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  lcd.clear();
}

void loop() {
lcd.setCursor(0, 0); 
  lcd.print("Temp: ");
  lcd.print(dht.readTemperature());
  lcd.print((char)223); 
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Vlaga: ");
  lcd.print(dht.readHumidity());
  lcd.print("%");

  delay(5000);
}