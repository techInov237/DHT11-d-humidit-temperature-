// pour les connexions des broches; connecter la broche SDA au pin analogique A4 et la broche SCL au pin A5!    
// les broches VCC et GND serons connectées normalement aux pin 5V et GND

#include <Wire.h> 
#include <LiquidCrystal_I2C.h> // inclusion de la bibliothèque du LCD 

#include <SimpleDHT.h >// inclusion de la bibliothèque du DHT11

const int pinDHT11 = 8; // initialiser la broche 8 pour le pin du DHT11
SimpleDHT11 dht11;  //creer un objet dht11

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  pinMode(6, OUTPUT);  //initialise la broche 6 en sortie
  digitalWrite(6, LOW);
 
}


void loop()
{

  byte temperature = 0;// creer les variables temperature et humidité
  byte humidity = 0;

  int err = 0; // initialiser une variable erreur à la valleur 0 
   if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != 0) 
  {
    lcd.print(" erreur");
  }
  else
  {

    
    // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print((int)temperature);
  lcd.print(" DEGRES C");
  lcd.setCursor(1,1);
  lcd.print((int)humidity);
  lcd.print(" % HUMIDITE");
  }

  if (humidity > 70)// si le tau d'humidité est > 70% , la led clignote
  {
    digitalWrite(6, HIGH);
    delay(200);
    digitalWrite(6, LOW);
    delay(200);
    digitalWrite(6, HIGH);
    delay(200);
    digitalWrite(6, LOW);
    delay(200);
    digitalWrite(6, HIGH);
    delay(200);
    digitalWrite(6, LOW);
    delay(200);
  }
  else
  {
    delay(1200);
  }

}
