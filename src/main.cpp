/*
  Titre      : Luminosite Led
  Auteur     : Crepin Vardin Fouelefack
  Date       : 22/01/2022
  Description: Faire varier l'intensite d'une led a partir d'une resistance variable
               (Potentionmetre)
  Version    : 0.0.1
*/

#include <Arduino.h>

const int ANALOG_PIN           = A1;    // Broche pour le potentionmetre
const int ANALOG_TRANSISTOR    = A5;     // Broche pour la base du transistor

//Declaration des variables
int TentionAnalog1    = 0;         // Pour contenir la tension sur la broche Analogique A1
int TentionAnalog02   = 0;         // De (118-255) Pour contenir la valeur de la broche Analog convertie

void setup() {
  // put your setup code here, to run once:
  // Serial.begin(9600);                      // Pour une bonne communication entre le uC et le moniteur serie

  pinMode(ANALOG_PIN, INPUT);                //Pour lire la tention au niveau du potentionmetre (0-1023)
  pinMode(TentionAnalog02, OUTPUT);          //Pour controler la tention sur le transistor
}

void loop() {
  // put your main code here, to run repeatedly:

  TentionAnalog1   = analogRead(ANALOG_PIN);                //De (0-1023)
  TentionAnalog02  = map(TentionAnalog1,0,1023,117,255);    //De (118-255) Suppose etre 127 mais surement a cause de la precision et fiabilite du potentionmetre
  analogWrite(ANALOG_TRANSISTOR, TentionAnalog02);          //Pour inscrire une tention au niveau de la base du transistor
   
}
