#include <SimpleDHT.h >
const int pinDHT11 = 8; // initialiser la broche 8 pour le pin du DHT11
SimpleDHT11 dht11; //creer un objet dht11

void setup() {
  Serial.begin(115200); //initialise le moniteur serie
}

void loop() {
  byte temperature = 0; // creer les variables temperature et humidité
  byte humidity = 0;

  int err = 0;// initialiser une variable erreur à la valleur 0 
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != 0) // lorsque la fonction "dht11.read" renvoie 0, celle signifie que la mesure a bien été prise
  {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
   
  }
  else
  {
  Serial.print("Lecture OK: ");
  Serial.print(" TEMPERATURE  "); Serial.print((int)temperature); Serial.print(" °C, "); 
  Serial.print(" HUMIDITE  "); Serial.print((int)humidity); Serial.println(" %");
  }
delay(1200);
}
