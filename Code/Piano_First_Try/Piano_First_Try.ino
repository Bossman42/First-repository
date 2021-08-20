/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to
// set pin numbers:
const int Key1 = 2;   
const int Key2 = 3;
const int Key3 = 4; 
const int Key4 = 5;
const int Key5 = 6;// the number of the pushbutton pin
const int Led1 =  22;
const int Led2 =  24;
const int Led3 =  26;   
const int Led4 =  28;   
const int Led5 =  30;   
const int Led6 =  32;   
const int Led7 =  34;   
const int Led8 =  36;   
const int Led9 =  38;   
const int Led10 =  40;   
const int Led11 =  42;   
const int Led12 =  44;   
const int Led13 =  46;   
const int Led14 =  48;
const int Led15 =  50;
const int Led16 =  52;  
const int Ledon1 =  23;
const int Ledon2 =  25;
const int Ledon3 =  27;   
const int Ledon4 =  29;   
const int Ledon5 =  31;   
const int Ledon6 =  33;   
const int Ledon7 =  35;   
const int Ledon8 =  37;   
const int Ledon9 =  39;   
const int Ledon10 =  41;   
const int Ledon11 =  43;   
const int Ledon12 =  45;   
const int Ledon13 =  47;   
const int Ledon14 =  49;
const int Ledon15 =  51;
const int Ledon16 =  53; // the number of the LED pin

// variables will change:
int Key1State = 0;
int Key2State = 0;
int Key3State = 0;
int Key4State = 0;
int Key5State = 0;
int Ledon1State = 0;
int Ledon2State = 0;
int Ledon3State = 0;
int Ledon4State = 0;
int Ledon5State = 0;
int Ledon6State = 0;
int Ledon7State = 0;
int Ledon8State = 0;
int Ledon9State = 0;
int Ledon10State = 0;
int Ledon11State = 0;
int Ledon12State = 0;
int Ledon13State = 0;
int Ledon14State = 0;
int Ledon15State = 0;
int Ledon16State = 0;
int prevState = 0;
;// variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  pinMode(Led5, OUTPUT);
  pinMode(Led6, OUTPUT);
  pinMode(Led7, OUTPUT);
  pinMode(Led8, OUTPUT);
  pinMode(Led9, OUTPUT);
  pinMode(Led10, OUTPUT);
  pinMode(Led11, OUTPUT);
  pinMode(Led12, OUTPUT);
  pinMode(Led13, OUTPUT);
  pinMode(Led14, OUTPUT);
  pinMode(Led15, OUTPUT);
  pinMode(Led16, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(Key1, INPUT);
  pinMode(Key2, INPUT);
  pinMode(Key3, INPUT);
  pinMode(Key4, INPUT);
  pinMode(Key5, INPUT);
  pinMode(Ledon1, INPUT);
  pinMode(Ledon2, INPUT);
  pinMode(Ledon3, INPUT);
  pinMode(Ledon4, INPUT);
  pinMode(Ledon5, INPUT);
  pinMode(Ledon6, INPUT);
  pinMode(Ledon7, INPUT);
  pinMode(Ledon8, INPUT);
  pinMode(Ledon9, INPUT);
  pinMode(Ledon10, INPUT);
  pinMode(Ledon11, INPUT);
  pinMode(Ledon12, INPUT);
  pinMode(Ledon13, INPUT);
  pinMode(Ledon14, INPUT);
  pinMode(Ledon15, INPUT);
  pinMode(Ledon16, INPUT);
 
}

void loop() { 

  Key1State = digitalRead(Key1);
  Key2State = digitalRead(Key2);
  Key3State = digitalRead(Key3);
  Key4State = digitalRead(Key4);
  Key5State = digitalRead(Key5);
  Ledon1State = digitalRead(Ledon1);
  Ledon2State = digitalRead(Ledon2);
  Ledon3State = digitalRead(Ledon3);

  
  if (Key1State == HIGH and Key2State == LOW and Key3State == LOW and Key4State == LOW and Key5State == LOW and Ledon1State == LOW and Ledon2State == LOW and Ledon3State == LOW) {
    delay(100);
    digitalWrite(Led1, HIGH);
  }
  
  if (Key1State == LOW and Key2State == HIGH and Key3State == LOW and Key4State == LOW and Key5State == LOW and Ledon1State == LOW and Ledon2State == LOW and Ledon3State == LOW) {
    delay(100);
    digitalWrite(Led2, HIGH);
  }

  if (Key1State == LOW and Key2State == LOW and Key3State == HIGH and Key4State == LOW and Key5State == LOW and Ledon1State == HIGH and Ledon2State == HIGH and Ledon3State == LOW) {
    delay(100);
    digitalWrite(Led3, HIGH);
    
  if (Key1State == HIGH and Key2State == LOW and Key3State == LOW and Key4State == LOW and Key5State == LOW and Ledon1State == HIGH and Ledon2State == HIGH and Ledon3State == HIGH) {
    delay(100);
    digitalWrite(Led4, HIGH);
  }

    }
  
  if (Key5State == HIGH ) {
    delay(100);
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, LOW);
    digitalWrite(Led4, LOW);
    }  }
  



  
