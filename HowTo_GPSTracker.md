<img align="right" width="260" src="images/citylab-logo-2160x550.jpg">

&nbsp;
# Bauanleitung GPS-Tracker

<img align="top" width="100%" src="images/GPSTracker/Header_GPSTracker_new.jpg">

Der Arduino Uno (https://store.arduino.cc/arduino-uno-rev3) ist ein Mini-Computer, der sich Dank der Arduino-Umgebung sehr leicht programmieren lässt. Es gibt verschiedene Ausführungen der Arduinos, wobei sich diese in den Anschlüssen, Pins, Baugröße, der Prozessorleistung uvm. unterscheiden. In dieser Bauanleitung haben wir den Arduino Uno bzw. den Arduino Nano mit Hilfe eines GPS-Moduls, eines LCD bzw. OLED-Displays und mit Hilfe eines LoRa-Shields ein wenig Leben eingehaucht. Dabei haben wir insgesamt zwei Versionen des GPS-Trackers gebaut:
* **Version 1:** Arduino Nano + NEO 6M GPS-Modul mit Antenne + 0.96" I2C OLED-Display (keine Übertragung ins LoRaWan)
* **Version 2:** Arduino Uno + aufgstecktes LoRa/GPS-Shield mit Xbee und GPS-Modul (Datenübertragung über LoRaWan möglich)

Nachfolgend soll das Setup von Version 1 beschrieben werden.

## Version 1: GPS-Tracker mit kleinem OLED-Display

<img align="right" width="400px" src="images/GPSTracker/ArduinoUno_smOLED.jpg">

#### Hardware
Welche Hardware man für diese Version benötigt:
* Arduino Nano à 20€ (https://store.arduino.cc/arduino-nano)
* NEO 6M GPS-Modul à 8€ (https://www.az-delivery.de/products/neo-6m-gps-modul?ls=de&cache=false)
* 0.96" I2C OLED-Display  à 5€ (https://www.az-delivery.de/products/0-96zolldisplay?_pos=3&_sid=10138dee5&_ss=r&ls=de)
* ein paar Kabel à 3€ (https://www.az-delivery.de/products/3er-set-40-stk-jumper-wire-m2m-f2m-f2f?_pos=1&_sid=88ced2339&_ss=r&ls=de)

Der Gesamtpreis für die Hardware für GPS-Tracker Version 1 liegt damit bei **36 Euro**. Möchte man ein paar Euros sparen, kann man auch den Arduino Nano inkl. Mini-USB Kabel (benötigt man, um das Setch auf das Board zu übertragen) auch "nicht original" für nur 5 Euro bestellen (https://www.az-delivery.de/products/nano-v3-0-pro?ls=de). Funktioniert für uns genau so gut.

#### Verkabelung
Die einzelnen Hardware-Komponenten müssen wie folgt miteinander verkabelt werden. Für die Stromversorgung haben wir uns in unserem Schaltplan für eine 9V Batterie entschieden, das Board kann aber auch ohne Probleme mit dem Mini-USB-Kabel per Computer versorgt werden.

<img align="right" width="100%" src="images/GPSTracker_Nano_Schaltplan.png">

#### Libraries
Jedes einzelne Modul bzw. jede einzelne Hardware-Komponente, wie bspw. Display, GPS-Sensor etc., muss natürlich irgendwie über den Arduino angesteuert werden. Demnach benötogt man für bestimmte Module auch bestimmte Libraries, die in den Programmcode in den Präprozessor (also ganz am Anfang des Codes) durch das Schlüsselwort #include eingebunden werden müssen. Für diese Version haben wir 3 zusützliche Libraries eingebunden, die nicht per default über Arduino bereitgestellt werden. Das sind:
* https://github.com/adafruit/Adafruit-GFX-Library
* https://github.com/adafruit/Adafruit_SSD1306
* https://github.com/mikalhart/TinyGPSPlus (im Ordner src)



Untder dem nachfolgendem Link, findet ihr eine ähnliche Bauanleitung mit gleichen Hardware-Komponenten. Der Autor hat in diesem Fall mit das Display sehr gut mit Hilfe der dtostrf-Funktion gestaltet: https://robotzero.one/arduino-neo-gps-oled/
Die dtostrf-Funktion erklärt: https://www.mikrocontroller.net/topic/86391

## First things first: das OLED-Display erklärt

Das OLED-Display wird über die Adafruit GFX Grpahics Library angesteuert und kann dadurch beliebig strukturiert und gestaltet werden. Dabei sind der Kreativität keine Grenzen gesetzt.

<img align="right" height="280px" src="images/GPSTracker/OLED_Triangle.jpg">
<img position="inline" height="280px" src="images/GPSTracker/OLED_Stripes.jpg">

Ausführliches Erläuterungen zu den einzelen Funktionen der Library findet Ihr hier: [im offiziellen Library Guide](https://learn.adafruit.com/adafruit-gfx-graphics-library?view=all). Darin wird u.a. erklärt, wie man Schriftfarbe, -Größe, und -Anordnung definiert und wie die Funktionen und deren Parameterübergabe prinzipiell genutzt werden können. 

Möchte man eine Custom Font benutzen, kann man sich diese ebenso in den Präprozessor mit einer .h-Datei einbinden. Ein Auswahl der Custom-Fonts könnt Ihr euch [hier](https://learn.adafruit.com/pages/6656/elements/2002817/download) herunterladen.
Für unseren GPS-Tracker haben wir kein Farbdisplay, sondern ein simples SW-Display genutzt.

<img align="right" width="300" src="images/GPSTracker/oled_arduino_verkabelung.jpg">

Wer erst einmal nur mit dem Display warm werden möchte, der kann dieses auch einzeln an den Arduino anschließen. Eine asuwführliche Beschreibung wie das Display mit dem Arduino verkabelt werden muss, findet ihr hier: https://randomnerdtutorials.com/guide-for-oled-display-with-arduino/. Gut zu wissen: SCL (Serial Clock) transportiert das Taktsignal , während SDA (Serial Data) die Datenbits überträgt. Durch die Verwendung von einem I2C-Bus kann man das Display über nur (genau diesen) zwei Pins ansteuern.


## Version 2: GPS-Tracker mit LoRa-Funktion

Welche Hardware man für diese version benötigt:
* Arduino Nano Rev3 à 20€ (https://store.arduino.cc/arduino-uno-rev3)
* Dragino LoRa/GPS-Shield mit LoRa Bee à 34€(https://www.exp-tech.de/module/wireless/funk/7767/dragino-lora/gps-shield-915)
* ein paar Kabel à 3€ (https://www.az-delivery.de/products/3er-set-40-stk-jumper-wire-m2m-f2m-f2f?_pos=1&_sid=88ced2339&_ss=r&ls=de)

Der Gesamtpreis für die Hardware für GPS-Tracker Version 1 liegt damit bei **57 Euro**. Zugegeben, das klingt jetzt erst mal nach viel Geld. Für einen einfach, frustrfreien Einstieg in die LoRaWan-Tehmatik ist das Shield von Dragino jedoch sehr gut geeignet. Es kombiniert GPS-Modul + Antenne (sandfarbener Würfel) und LoRa Bee + Antenne (weißer Stab) und wird einfach auf den Arduino Uno aufsgeteckt. Man kann das Shield natürlich auch für weniger Geld aus den Eizelteilen nachbauen oedr gar LoRa-Modul und GPS-Modul einzeln mit den Arduino verkabeln. Diese Vorgehensweise beleuchten wir allerdings nicht.

Zur Verkabelung mit dem Arduino Uno benötigen wir lediglich zwei Kabel. **WICHTIG**: die Jumper von RX (Receive) und TX (Transmitter) müssen entfernt werden, damit ein Signal übertragen werden kann.


