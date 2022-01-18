// Einbinden der nötigen Bibliotheken für LCD Display und Initialiserung
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Festlegen der Eingangspins (most significant to least significant)
byte dataPins[] = {53,51,49,47,45,43,41,39};

byte dataCounter = 0;

void setup() {
  // Initialisierung des Displays
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Waiting...");

  // Einstellen des Pullup Wiederstandes fuer die Eingangspins
  for(int i = 0; i < 8; i++) {
    pinMode(dataPins[i], INPUT_PULLUP);
  }
}

void loop() {  
  // lese alle Sekunde ein Zeichen von den Pins
  char character;
  character = readPins();
  delay(1000);

  // wenn Zeichen STX (start of text)
  if(character == 2){
    // leere das Display und lese das nächste Zeichen
    character = readPins();
    lcd.clear();
    do {
      // schreibe das Zeichen auf das Display, isPrintable faengt Fehler ab
      if(isPrintable(character)) {
        print_lcd(lcd, character, dataCounter);
      }
      // warte, lese naechstes Zeichen
      delay(1000);
      dataCounter++;
      character = readPins();
    } while(character != 3);
    dataCounter = 0;
  }
}

// Funktion zum Lesen eines char von den Eingangspins
char readPins () {
  char c;
  for(int i = 0; i < 8; i++){
    bitWrite(c, i, digitalRead(dataPins[7-i]));
  }
  return c;
}

// schreibt auf LCD und beachtet die maximale LCD laenge
void print_lcd (LiquidCrystal_I2C lcd, char c, byte counter) {
  if (counter < 16) {
    lcd.setCursor(counter, 0);
  } else {
    lcd.setCursor(counter-16, 1);
  }

  lcd.print(c);
}