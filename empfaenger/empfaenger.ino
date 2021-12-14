byte dataPins[] = {53,51,49,47,45,43,41,39};
byte clockPin = 23;

char data[32];
byte dataCounter = 0;
byte lastClock = 0;

void setup() {
  // put your setup code here, to run once:

  for(int i = 0; i < 8; i++) {
    pinMode(dataPins[i], INPUT_PULLUP);
  }
  pinMode(clockPin, INPUT_PULLUP);

  Serial.begin(9600); 

}

void loop() {
  // put your main code here, to run repeatedly:
  byte myClock = digitalRead(clockPin);
  if(myClock != lastClock){
    lastClock = myClock;
    char character;

    for(int i = 0; i < 8; i++){
      bitWrite(character, i, digitalRead(dataPins[7-i]));
    }

    Serial.println(dataCounter);
    if(dataCounter == 31){
      dataCounter = 0;
    }
    data[dataCounter] = character;
    dataCounter++;
    Serial.println(data);
    delay(1000);
  }
}
