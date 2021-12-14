int dataPins[] = {15,13,2,0,4,5,12,14};

char message[] = "Hello, World";

void setup() {
  // put your setup code here, to run once:
  delay(1000);
  for(int i = 0; i < 8; i++) {
    pinMode(dataPins[i],OUTPUT);
  }
  
  Serial.begin(9600);

  // write STX Start of Text
  for(int i = 0; i < 8; i++) {
    digitalWrite(dataPins[i], bitRead(2, i));
  }

  delay(1000);
  
  for(int i = 0; i < sizeof(message); i++) {
    Serial.print(message[i]);
    for(int j = 7; j >= 0; j--) {
      digitalWrite(dataPins[j], bitRead(message[i],j));
      Serial.print(bitRead(message[i],j));
    }
    
    delay(1000);
  }

  // write ETX End of Text
  for(int i = 0; i < 8; i++) {
    digitalWrite(dataPins[i], bitRead(3, i));
  }
  delay(1000);
  for(int i = 0; i < 8; i++) {
    digitalWrite(dataPins[i], LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  
}
