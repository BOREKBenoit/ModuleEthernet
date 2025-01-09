/*
Code créer par Benoit BOREK
Mis à jour le 09/01/2025

IDE : Visual Studio Code ver 1.96.2

Constituants :

Arduino Mega 2560
Module ethernet WIZ811MJ


Lien de la doc technique du module : https://docs.wiznet.io/img/products/wiz811mj/WIZ811MJ_DS_V120E.pdf
*/



#include <SPI.h>
#include <Ethernet.h>
#include <DHT.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,20);
IPAddress myDns(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);




void setup() {

  

  Serial.begin(9600);
  Ethernet.init(10);
  Serial.println("Initialisation Ethernet...");

  // Initialisation de l'Ethernet en utilisant la pin 53 pour CS
  Ethernet.begin(mac, ip, myDns, gateway, subnet);

  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Le module Ethernet est introuvable.");
    while (true);
  }
  
  /*if (Ethernet.begin(mac) == 0) {
    Serial.println("Échec de l'initialisation Ethernet avec DHCP");
    while (true); // Bloque ici
  }
  */
  Serial.print("Adresse IP obtenue via DHCP : ");
  Serial.println(Ethernet.localIP());
}

void loop() {}
