/*
Nom du programme : WIZ811MJ ethernet
Par Mathis Benoit
Editeur : Visual Studio Code v1.96.2
IDE : PlatformIO v3.3.4

Dernière modification : 16/01/2025

Matériel : 
  - Module ethernet WIZ811MJ
  - Carte Arduino Mega 

Câblage Module Arduino --> Module ethernet : 
  - 3.3V --> 3V3D (J1:12)
  - GND --> GND (J1:11)
  - 50 (MISO) --> MISO (J1:2)
  - 51 (MOSI) --> MOSI (J1:1)
  - 52 (SCLK) --> SCLK (J2:3)
  - 53 (CS) --> /SCS (J2:4)
*/

#include <Arduino.h>    //Appel des librairies 
#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

#define   UDPMessagingPort    9999          // Selection du port UDP

EthernetUDP Udp;

void setup(){
  Serial.begin(9600);                     //Initialise le moniteur série à 9600 Bauds.
  
  byte mac[] = { 0x0a, 0x00, 0x27, 0x00, 0x00, 0x10 };    //Adresse MAC du PC  (sur mon partage de connection)
  byte ip[] = { 10, 186, 203, 64 };                       //Adresse IP du PC 

  while (!Serial) {
    ; // Met en pause le programme le temps que la connection série soit établie 
  }

  // Vérifie si le module est bien connecté 
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Le module ethernet n'a pas été trouvé ");
    while (true) {
      delay(1); // ne fait rien, bloque le programme dans une boucle 
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Pas de câble ethernet trouvé");
  }
  
  Ethernet.begin(mac,ip);                    // Initialise l'ethernet avec l'adresse IP et l'adresse MAC définient.
  while(!Udp.begin(UDPMessagingPort)){}      // Initialise l'UDP
  delay(100);                                // On attend un petit peu pour être sûr que tout au eu le temps de démarrer 

  Serial.print("connecté à : ");
  IPAddress remote = Udp.remoteIP();
    for (int i=0; i < 4; i++) {
      Serial.print(remote[i], DEC);
      if (i < 3) {
        Serial.print(".");
      }
    }
  Serial.println();


}

void loop() {

}
