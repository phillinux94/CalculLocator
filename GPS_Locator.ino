/*
Géolocalisation via GPS
Calcul du Locator

Copyright Philippe Labbe 2021

*/

// Chargement des bibliothèques
#include <Wire.h>
#include "rgb_lcd.h"
#include <SoftwareSerial.h>
#include <TinyGPS++.h>


// Création de l'objet LCD
rgb_lcd lcd;

// Déclaration des variables pour le GPS
char data;
double latitude;
double longitude;
double alt;
double vitesse;
unsigned long nbre_sat;

// Création de l'objet GPS
TinyGPSPlus gps;

// Déclaration des variables pour l'affichage LCD
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

// Déclaration des variables pour la liaison série  entre l'arduino et le GPS
#define RX 2
#define TX 3

// Déclaration de la variable locator
String locator;

// Création de l'objet GPS pour la liaison entre l'arduino et le GPS
SoftwareSerial GPS(RX, TX);


void setup() {
  // Initialisation de l'affichage LCD
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);

  // Message d'accueil
  lcd.setCursor(0, 0);
  lcd.print("Initialisation");

  // Initialisation connexion avec le GPS  
  GPS.begin(9600);
  
  //Temporisation (1 seconde)
  delay(1000);
  
  // Clear affichage LCD
  lcd.setCursor(0, 0);
  lcd.print("               ");
}


// Boucle de lecture
void loop() {
  while (GPS.available()) {
    data = GPS.read();
    gps.encode(data);
    if (gps.location.isUpdated())
    {
      latitude = gps.location.lat();
      longitude = gps.location.lng();
      alt = gps.altitude.meters();
      vitesse = gps.speed.kmph();
      nbre_sat = gps.satellites.value();

      lcd.setCursor(0, 0);
      lcd.print("Lat : ");
      lcd.setCursor(6, 0);
      lcd.print(latitude, 4);

      lcd.setCursor(0, 1);
      lcd.print("Lon : ");
      lcd.setCursor(6, 1);
      lcd.print(longitude, 4);      
         
      delay(4000);
      
      lcd.setCursor(0, 0);
      lcd.print("Alt : ");
      lcd.setCursor(6, 0);
      lcd.print(alt, 4);
            
      lcd.setCursor(0, 1);
      lcd.print("NbS : ");
      lcd.setCursor(6, 1);
      lcd.print("                  ");  
      lcd.setCursor(6, 1);      
      lcd.print(nbre_sat);  
      
      delay(4000);    

      lcd.setCursor(0, 0);
      lcd.print("Locator :                      ");
      lcd.setCursor(0, 1);   
      lcd.print("                             ");    
      lcd.setCursor(0, 1);    
            
      lcd.print(calcLocator(longitude, latitude)); 
      delay(4000);            
    }
     
  }
}

String calcLocator(double lng, double lat){
  
  // Calcul du locator
  locator = "";
  double Lo = (180 + lng) / 20;
  double La = (90 + lat) /10;

  int L1 = (int)Lo;
  int L2 = (int)La;
  
  locator += convertLettre(L1);
  locator += convertLettre(L2);  

  double Lo1 = (Lo - L1) * 10;
  double La1 = (La - L2) * 10;

  int L3 = (int)Lo1;
  int L4 = (int)La1;
  
  locator += L3;
  locator += L4;
   
  double Lo2 = (Lo1 - L3) * 24;
  double La2 = (La1 - L4) * 24;
  
  int L5 = (int)Lo2;
  int L6 = (int)La2;

  locator += convertLettre(L5);
  locator += convertLettre(L6);
  
  return locator;
}

char convertLettre(int x){
    
  // Conversion des chiffres en lettres
  char result;        
  if (x == 0) result = 'A';
  if (x == 1) result = 'B';
  if (x == 2) result = 'C';    
  if (x == 3) result = 'D';
  if (x == 4) result = 'E';
  if (x == 5) result = 'F';
  if (x == 6) result = 'G';
  if (x == 7) result = 'H';
  if (x == 8) result = 'I';
  if (x == 9) result = 'J';
  if (x == 10) result = 'K';
  if (x == 11) result = 'L';
  if (x == 12) result = 'M';
  if (x == 13) result = 'N';
  if (x == 14) result = 'O';
  if (x == 15) result = 'P';
  if (x == 16) result = 'Q';
  if (x == 17) result = 'R';
  if (x == 18) result = 'S';
  if (x == 19) result = 'T';
  if (x == 20) result = 'U';
  if (x == 21) result = 'V';
  if (x == 22) result = 'W';
  if (x == 23) result = 'X';
  if (x == 24) result = 'Y';
  if (x == 25) result = 'Z';
  
  return result;   
}
    