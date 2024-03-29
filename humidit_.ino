/* THONAIN
 *  CAPTEUR T° ET HUMIDITE DHT11 + AFFICHAGE SUR ECRAN LCD
 *  AVEC LED ALARME HUMIDITE
 */
#include <SimpleDHT.h >
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int pinDHT11 = 8;
SimpleDHT11 dht11;
void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
 analogWrite(6, LOW);
 analogWrite(7, LOW); 
}
void loop() {
  byte temperature = 0;
  byte humidity = 0;
 lcd.setCursor(0, 0);
 int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) 
  {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  Serial.print("Lecture OK: ");
  Serial.print(" TEMPERATURE  "); Serial.print((int)temperature); Serial.print(" °C, "); 
  Serial.print(" HUMIDITE  "); Serial.print((int)humidity); Serial.println(" %");
 if ( humidity > 40)
  {
    analogWrite(6, 255);
    analogWrite(7, LOW);
  }
 else
  {
    analogWrite(6, LOW);
    analogWrite(7, 255);
  }
  lcd.print((int)temperature);
  lcd.print(" DEGRES C");
  lcd.setCursor(0, 1);
  lcd.print((int)humidity);
  lcd.print(" % HUMIDITE");
  delay(1500);
}
