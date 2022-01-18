// Ausgangspins (most significant to least significant)
int dataPins[] = {15,13,2,0,4,5,12,14};

char message[] = "Hello, World! This may be too long";

void setup() {
  // delay für Entprellung des Reset Tasters
  delay(1000);
  // Ausgangspins initialisieren
  for(int i = 0; i < 8; i++) {
    pinMode(dataPins[i],OUTPUT);
  }

  // schreibe STX (start of text)
  for(int i = 0; i < 8; i++) {
    digitalWrite(dataPins[i], bitRead(2, i));
  }

  delay(1000);
  
  // Schleife über Buchstaben der Nachricht
  for(int i = 0; i < sizeof(message); i++) {
    // Schleife über Bits der Buchstaben
    for(int j = 7; j >= 0; j--) {
      digitalWrite(dataPins[j], bitRead(message[i],j));
    }
    delay(1000);
  }

  // schreibe ETX (end of text)
  for(int i = 0; i < 8; i++) {
    digitalWrite(dataPins[i], bitRead(3, i));
  }
  delay(1000);
  // alle Pins low damit die LEDs nicht dauerhaft leuchten
  for(int i = 0; i < 8; i++) {
    digitalWrite(dataPins[i], LOW);
  }
}

void loop() {
  // wird nicht benoetigt
}
