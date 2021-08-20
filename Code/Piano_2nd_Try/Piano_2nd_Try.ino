/*
 Input Pullup Serial

 This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a
 digital input on pin 2 and prints the results to the serial monitor.

 The circuit:
 * Momentary switch attached from pin 2 to ground
 * Built-in LED on pin 13

 Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal
 20K-ohm resistor is pulled to 5V. This configuration causes the input to
 read HIGH when the switch is open, and LOW when it is closed.

 created 14 March 2012
 by Scott Fitzgerald

 http://www.arduino.cc/en/Tutorial/InputPullupSerial

 This example code is in the public domain

 */
const int Key1 = 2;   
const int Key2 = 3;
const int Key3 = 4; 
const int Key4 = 5;
const int Key5 = 6;
const int Reset = 7;// the number of the pushbutton pin
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
const int Ledon16 =  53;
int Key1S = 1;
int Key2S = 1;
int Key3S = 1;
int Key4S = 1;
int Key5S = 1;
int ResetS = 1;
int Ledon1S = 1;
int Ledon2S = 1;
int Ledon3S = 1;
int Ledon4S = 1;
int Ledon5S = 1;
int Ledon6S = 1;
int Ledon7S = 1;
int Ledon8S = 1;
int Ledon9S = 1;
int Ledon10S = 1;
int Ledon11S = 1;
int Ledon12S = 1;
int Ledon13S = 1;
int Ledon14S = 1;
int Ledon15S = 1;
int Ledon16S = 1;



void setup() {
  //start serial connection
  Serial.begin(9600);
  Serial.println("Yep");
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);//Key 1
  pinMode(3, INPUT_PULLUP);//Key 2
  pinMode(4, INPUT_PULLUP);//Key 3
  pinMode(5, INPUT_PULLUP);//Key 4
  pinMode(6, INPUT_PULLUP);//Key 5
  pinMode(7, INPUT_PULLUP);//Reset Key
  pinMode(23, OUTPUT);// Led1
  pinMode(24, OUTPUT);// Led1 Send
  pinMode(25, OUTPUT);// Led2
  pinMode(26, OUTPUT);// Led2 Send
  pinMode(27, OUTPUT);// Led3
  pinMode(28, OUTPUT);// Led3 Send
  pinMode(29, OUTPUT);// Led4
  pinMode(30, OUTPUT);// Led4 Send
  pinMode(31, OUTPUT);// Led5
  pinMode(32, OUTPUT);// Led5 Send
  pinMode(33, OUTPUT);// Led6
  pinMode(34, OUTPUT);// Led6 Send
  pinMode(35, OUTPUT);// Led7
  pinMode(36, OUTPUT);// Led7 Send
  pinMode(37, OUTPUT);// Led8
  pinMode(38, OUTPUT);// Led8 Send
  pinMode(39, OUTPUT);// Led9
  pinMode(40, OUTPUT);// Led9 Send
  pinMode(41, OUTPUT);// Led10
  pinMode(42, OUTPUT);// Led10 Send
  pinMode(43, OUTPUT);// Led11
  pinMode(44, OUTPUT);// Led11 Send
  pinMode(45, OUTPUT);// Led12
  pinMode(46, OUTPUT);// Led12 Send
  pinMode(47, OUTPUT);// Led13
  pinMode(48, OUTPUT);// Led13 Send
  pinMode(49, OUTPUT);// Led14
  pinMode(50, OUTPUT);// Led14 Send
  pinMode(51, OUTPUT);// Led15
  pinMode(52, OUTPUT);// Led15 Send
  pinMode(53, OUTPUT);// Led16

  digitalWrite(A0, INPUT_PULLUP); //Led1 On
  digitalWrite(A1, INPUT_PULLUP); //Led2 On
  digitalWrite(A2, INPUT_PULLUP); //Led3 On
  digitalWrite(A3, INPUT_PULLUP); //Led4 On
  digitalWrite(A4, INPUT_PULLUP); //Led5 On
  digitalWrite(A5, INPUT_PULLUP); //Led6 On
  digitalWrite(A6, INPUT_PULLUP); //Led7 On
  digitalWrite(A7, INPUT_PULLUP); //Led8 On
  digitalWrite(A8, INPUT_PULLUP); //Led9 On
  digitalWrite(A9, INPUT_PULLUP); //Led10 On
  digitalWrite(A10, INPUT_PULLUP); //Led11 On
  digitalWrite(A11, INPUT_PULLUP); //Led12 On
  digitalWrite(A12, INPUT_PULLUP); //Led13 On
  digitalWrite(A13, INPUT_PULLUP); //Led14 On
  digitalWrite(A14, INPUT_PULLUP); //Led15 On
  digitalWrite(A15, INPUT_PULLUP); //Led16 On


}

void loop() {
  //read the pushbutton value into a variable
  int Key1S = digitalRead(Key1);
  int Key2S = digitalRead(Key2);
  int Key3S = digitalRead(Key3);
  int Key4S = digitalRead(Key4);
  int Key5S = digitalRead(Key5);
  int ResetS = digitalRead(Reset);
  int Ledon1S = digitalRead(Ledon1);
  int Ledon2S = digitalRead(Ledon2);
  int Ledon3S = digitalRead(Ledon3);
  int Ledon4S = digitalRead(Ledon4);
  int Ledon5S = digitalRead(Ledon5);
  int Ledon6S = digitalRead(Ledon6);
  int Ledon7S = digitalRead(Ledon7);
  int Ledon8S = digitalRead(Ledon8);
  int Ledon9S = digitalRead(Ledon9);
  int Ledon10S = digitalRead(Ledon10);
  int Ledon11S = digitalRead(Ledon11);
  int Ledon12S = digitalRead(Ledon12);
  int Ledon13S = digitalRead(Ledon13);
  int Ledon14S = digitalRead(Ledon14);
  int Ledon15S = digitalRead(Ledon15);
  int Ledon16S = digitalRead(Ledon16);
  
  
  //print out the value of the pushbutton
  Serial.println(Ledon1);
  delay(100);
  Serial.println(Ledon2);
  
  
   
  
  if (Key1S == LOW && Key2S == HIGH) 
      digitalWrite(22, LOW);digitalWrite(23,LOW);
  
  if (Key1 == HIGH && Key2 == LOW && Key3 == HIGH && Key4 == HIGH && Ledon1 == LOW && Ledon2 == HIGH) // Led 1 Light up
      {digitalWrite(24, LOW);}}
      
      
      






