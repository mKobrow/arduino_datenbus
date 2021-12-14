int clockPin = 16;
int dataPins[] = {15,13,2,0,4,5,12,14};

int myClock = 0;
char message[] = "Hello, World";

void setup() {
  // put your setup code here, to run once:
  delay(1000);
  for(int i = 0; i < 8; i++) {
    pinMode(dataPins[i],OUTPUT);
  }

  pinMode(clockPin,OUTPUT);

  Serial.begin(9600);

  for(int i = 0; i < sizeof(message); i++) {
    Serial.print(message[i]);
    for(int j = 7; j >= 0; j--) {
      digitalWrite(dataPins[j], bitRead(message[i],j));
      Serial.print(bitRead(message[i],j));
    }

    myClock = !myClock;
    digitalWrite(clockPin, myClock);
    Serial.print(" ");
    Serial.println(myClock);
    delay(1000);
  }
  for(int i = 0; i < 8; i++) {
    digitalWrite(dataPins[i],LOW);
  }
  digitalWrite(clockPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  
}
