# CalculLocator

# Calcul du Locator par Géolocalisation


Le matériel requis est le suivant :
  - Arduino Uno : https://www.lextronic.fr/carte-arduino-uno-dip-rev3-A000066-2474.html
  - Platine Grove Base Shield : https://www.lextronic.fr/platine-grove-base-shield-v2-103030000-14174.html?fast_search=fs
  - Module Grove GPS : https://www.lextronic.fr/module-grove-gps-air530-109020022-61889.html?fast_search=fs
  - Module Grove Afficheur LCD 2 * 16 : https://www.lextronic.fr/grove-afficheur-lcd-2x16-noir-rouge-104020112-39823.html?fast_search=fs
  - Adaptateur pile 9V : https://www.lextronic.fr/adaptateur-pile-9v-pour-arduino-15978.html


Le logiciel calcule et affiche les informations suivantes :
  - Longitude du lieu
  - Latitude du lieu
  - Altitude du lieu
  - Nombre de   satellites (GPS) utilisés
  - Locator du lieu


# Montage

  - Connecter le shield Grove à l'arduino Uno.
  - Connecter le module LCD à un port I2C du shield
  - Connecter le module GPS au port D2 du shield



Installer Arduino IDE : https://www.arduino.cc/en/software

Le projet requiert les bibliothèques Tiny GPS++ et rgb_lcd. Les installer à partir des sources fournis.
Cf photo jointe au projet.
