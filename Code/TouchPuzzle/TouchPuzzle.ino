int Led1 = 22;
int Led2 = 23;
int Led3 = 24;
int Led4 = 25;
int Led5 = 26;
int Led6 = 27;
int Led7 = 28;
int Led8 = 29;
int Led9 = 30;
int Led10 = 31;
int Led11 = 32;
int Led12 = 33;
int Led13 = 34;
int Led14 = 35;
int Led15 = 36;
int Led16 = 37;
int Led17 = 38;
int Led18 = 39;
int Led19 = 40;
int Led20 = 41;

int Touch = 2;

long Delay = 500;

void setup() {
  // put your setup code here, to run once:
pinMode (Led1, OUTPUT);
pinMode (Led2, OUTPUT);
pinMode (Led3, OUTPUT);
pinMode (Led4, OUTPUT);
pinMode (Led5, OUTPUT);
pinMode (Led6, OUTPUT);
pinMode (Led7, OUTPUT);
pinMode (Led8, OUTPUT);
pinMode (Led9, OUTPUT);
pinMode (Led10, OUTPUT);
pinMode (Led11, OUTPUT);
pinMode (Led12, OUTPUT);
pinMode (Led13, OUTPUT);
pinMode (Led14, OUTPUT);
pinMode (Led15, OUTPUT);
pinMode (Led16, OUTPUT);
pinMode (Led17, OUTPUT);
pinMode (Led18, OUTPUT);
pinMode (Led19, OUTPUT);
pinMode (Led20, OUTPUT);

pinMode (Touch, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
int TouchS = digitalRead(Touch);
if (TouchS == LOW)

    digitalWrite (Led1, LOW),
    delay(Delay),
    digitalWrite (Led2, LOW),
    delay(Delay),
    digitalWrite (Led3, LOW),
    delay(Delay),
    digitalWrite (Led4, LOW);
        delay(Delay),
    digitalWrite (Led5, LOW);
        delay(Delay),
    digitalWrite (Led6, LOW);
        delay(Delay),
    digitalWrite (Led7, LOW);
        delay(Delay),
    digitalWrite (Led8, LOW);
        delay(Delay),
    digitalWrite (Led9, LOW);
        delay(Delay),
    digitalWrite (Led10, LOW);
        delay(Delay),
    digitalWrite (Led11, LOW);
        delay(Delay),
    digitalWrite (Led12, LOW);
        delay(Delay),
    digitalWrite (Led13, LOW);
        delay(Delay),
    digitalWrite (Led14, LOW);
        delay(Delay),
    digitalWrite (Led15, LOW);
        delay(Delay),
    digitalWrite (Led16, LOW);
        delay(Delay),
    digitalWrite (Led17, LOW);
        delay(Delay),
    digitalWrite (Led18, LOW);
        delay(Delay),
    digitalWrite (Led19, LOW);
        delay(Delay),
    digitalWrite (Led20, LOW);
        delay(Delay),
    else digitalWrite (Led1,HIGH),
    digitalWrite(Led2, HIGH),
    digitalWrite (Led3,HIGH),
    digitalWrite (Led4,HIGH);
}
