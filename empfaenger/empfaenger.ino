byte dataPins[] = {53,51,49,47,45,43,41,39};

char data[32];
byte dataCounter = 0;

void setup() {
  // put your setup code here, to run once:

  for(int i = 0; i < 8; i++) {
    pinMode(dataPins[i], INPUT_PULLUP);
  }

  Serial.begin(9600); 

}

void loop() {
  // put your main code here, to run repeatedly:
  char character;
  for(int i = 0; i < 8; i++){
    bitWrite(character, i, digitalRead(dataPins[7-i]));
  }
  if(character == 2){
    for(int i = 0; i < 8; i++){
        bitWrite(character, i, digitalRead(dataPins[7-i]));
    }
    do {
      delay(1000);
      data[dataCounter] = character;
      dataCounter++;
      Serial.print(character);
      for(int i = 0; i < 8; i++){
        bitWrite(character, i, digitalRead(dataPins[7-i]));
      }
    } while(character != 3);
    Serial.println(data);
  }
}
