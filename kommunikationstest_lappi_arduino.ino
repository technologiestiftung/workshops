 // Dieses Beispiel testet die Kommunikation zwischen Lappi und Arduino, sonst nichts


// Uebersicht Programmteile:
// includes, Definition von Konstanten und Variablen einschliesslich TTN-Schluessel und deren Uebergabe an LMIC, eigene Globals
// void setup () wird einmal durchlaufen und konfiguriert z.B. Pinouts und die LMIC
// void loop () wird als Schleife ausgeführt


#include <lmic.h>
#include <hal/hal.h>
#include <SPI.h>

// Globals

int temperatur = 25; //Unter der Variablen "temperatur" wird später der Temperaturwert abgespeichert.



//**************************************************
// BEGINN SETUP (wird einmal durchlaufen)

void setup() {
    Serial.begin(115200);  //Im Setup beginnt die serielle Kommunikation. Über die serielle Kommunikation sendet das Board später die Messwerte über USB. In der Arduino-Software kann man unter „Werkzeuge“ den „Seriellen Monitor“ starten um die Messwerte zu sehen.
    Serial.println(F("Starting..."));
}

// ***** ENDE SETUP ********




// *** Anfang LOOP ***********

void loop() 
{
Serial.println(temperatur); // Nun wird der Wert „temperatur“ über die serielle Kommunikation an den PC gesendet. 
delay(2000); //wartet zwei Sekunden, damit man den Output lesen kann
}

// ENDE LOOP-SCHLEIFE

