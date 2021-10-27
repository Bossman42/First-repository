/*
 * Write digits 0-3 into a 4-digit LED module using the TM1637 chip, set the
 * brightness, then render it by flushing the data bits to the TM1637 controller
 * using the SimpleTmiInterface class from the AceTMI library.
 */

#include <Arduino.h>
#include <AceTMI.h> // SimpleTmiInterface
#include <AceSegment.h> // Tm1637Module

using ace_tmi::SimpleTmiInterface;
using ace_segment::LedModule;
using ace_segment::Tm1637Module;
int holder = 8;
// Replace these with the PIN numbers of your dev board.
const uint8_t CLK_PIN = A0;
const uint8_t DIO_PIN = A1;
const uint8_t NUM_DIGITS = 4;

// Many TM1637 LED modules contain 10 nF capacitors on their DIO and CLK lines
// which are unreasonably high. This forces a 100 microsecond delay between
// bit transitions. If you remove those capacitors, you can set this as low as
// 1-5 micros.
const uint8_t DELAY_MICROS = 100;

using TmiInterface = SimpleTmiInterface;
TmiInterface tmiInterface(DIO_PIN, CLK_PIN, DELAY_MICROS);
Tm1637Module<TmiInterface, NUM_DIGITS> ledModule(tmiInterface);



int button1 = 2;
int button2 = 3;
int button3 = 4;
int button4 = 5;

int button1LS = 0;
int button2LS = 0;
int button3LS = 0;
int button4LS = 0;


int frequency = 0;
int thousand = 0;
int hundred = 0;
int ten = 0;
int one = 0;

int thousandS = 0;
int hundredS = 0;
int tenS = 0;
int oneS = 0;
int hold = 10;

int previousfrequency = 0;






// LED segment patterns.
const uint8_t NUM_PATTERNS = 10;
const uint8_t PATTERNS[NUM_PATTERNS] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111, // 9
};

void setup() {
  delay(1000);

pinMode (button1,INPUT_PULLUP);
pinMode (button2,INPUT_PULLUP);
pinMode (button3,INPUT_PULLUP);
pinMode (button4,INPUT_PULLUP);


Serial.begin(9600);
Serial.println ("Frequency Arduino Online");
delay (2000);
Serial.println ("a = +1000");
delay (2000);
Serial.println ("b = +100");
delay (2000);
Serial.println ("c = +10");
delay (2000);
Serial.println ("d = +1");
delay (2000);
Serial.println ("e = reset");

// a = +1000
// b = +100
// c = +10
// d = +1
// e = reset




  tmiInterface.begin();
  ledModule.begin();

 // ledModule.setPatternAt(0, PATTERNS[holder]);
 // ledModule.setPatternAt(1, PATTERNS[1]);
 // ledModule.setPatternAt(2, PATTERNS[2]);
 // ledModule.setPatternAt(3, PATTERNS[3]);

  ledModule.setBrightness(2);

  ledModule.flush();
}


void loop() {
  
  handleSerial();

int button1S = digitalRead (button1);
int button2S = digitalRead (button2);
int button3S = digitalRead (button3);
int button4S = digitalRead (button4);




if (button1S != button1LS) {
    if (button1S == LOW) {
      thousand += 1000;
      thousandS += 1; 
      }
  button1LS = button1S;
    }


if (button2S != button2LS) {
    if (button2S == LOW) {
      hundred += 100;
      hundredS += 1; 
      }
  button2LS = button2S;
    }



if (button3S != button3LS) {
    if (button3S == LOW) {
      ten += 10;
      tenS += 1;
      }
  button3LS = button3S;
    }



if (button4S != button4LS) {
    if (button4S == LOW) {
      one += 1 ;
      oneS += 1;
      }
  button4LS = button4S;
    }

    
if (thousand > 9001){
  thousand = 0;}
  
if (thousandS > 9){
  thousandS = 0;}
  

if (hundred > 900){
  hundred = 0;}

if (hundredS > 9){
  hundredS = 0;}
  
if (ten > 90){
  ten = 0;  }

if (tenS > 9){
  tenS = 0;  }  

if (one > 9){
  one = 0;    }

if (oneS > 9){
  oneS = 0;    }

  

  {frequency = thousand + hundred + ten + one;}

if (frequency != previousfrequency){
  Serial.println(frequency);
  previousfrequency = frequency; 
}
if (frequency == 0){
 ledModule.setBrightness(0);}
else {    ledModule.setBrightness(2);}

  //sevseg.refreshDisplay(); // Must run repeatedly



  
  
  
  
  
  
  
  
  
  
  
  ledModule.setPatternAt(0, PATTERNS[thousandS]);
  ledModule.setPatternAt(1, PATTERNS[hundredS]);
  ledModule.setPatternAt(2, PATTERNS[tenS]);
  ledModule.setPatternAt(3, PATTERNS[oneS]);
  
  
  ledModule.flush();
  
  }

void handleSerial(){
  while (Serial.available()>0){
    char incomingCharacter = Serial.read();
    switch (incomingCharacter) {
        case 'a':
      thousand += 1000 ;
      thousandS += 1 ;
      Serial.println ("Frequency + 1000");
      break;  
        
      case 'b':
      hundred += 100;
      hundredS += 1;
      Serial.println ("Frequency + 100");
      break;      
           
      case 'c':
      ten += 10;
      tenS += 1;
      Serial.println ("Frequency + 10");
      break;

      case 'd':
      one += 1;
      oneS += 1;
      
      Serial.println ("Frequency + 1");
      break;

      case 'e':
      thousand = 0;
      hundred = 0;
      ten = 0;
      one = 0;
       thousandS = 0;
      hundredS = 0;
      tenS = 0;
      oneS = 0;
      Serial.println ("Frequency reset");
      break;

      case 'f':
     
      Serial.println ("Not Used");
      break;

      case 'g':
    
      Serial.println ("Not Used");
      break;

// a = +1000
// b = +100
// c = +10
// d = +1
// e = reset




      
      
    }
  }
}

/// END ///

  
