/*
  State change detection (edge detection)

  Often, you don't need to know the state of a digital input all the time, but
  you just need to know when the input changes from one state to another.
  For example, you want to know when a button goes from OFF to ON. This is called
  state change detection, or edge detection.

  This example shows how to detect when a button or button changes from off to on
  and on to off.

  The circuit:
  - pushbutton attached to pin 2 from +5V
  - 10 kilohm resistor attached to pin 2 from ground
  - LED attached from pin 13 to ground (or use the built-in LED on most
    Arduino boards)

  created  27 Sep 2005
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ButtonStateChange
*/

// this constant won't change:
const int freqPos1 = 2;
const int freqPos2 = 9;
const int freqPos3 = 7;
const int freqPos4 = 4;

const int  buttonPin = A0;    // the pin that the pushbutton is attached to
const int ledPin2 = 2;
const int ledPin3 = 3;
const int ledPin4 = 4;
const int ledPin5 = 5; 
const int ledPin6 = 6; 
const int ledPin7 = 7;
const int ledPin8 = 8;// the pin that the LED is attached to

const int  buttonPin2 = A1;    // the pin that the pushbutton is attached to
const int ledPin22 = 22;
const int ledPin23 = 23;
const int ledPin24 = 24;
const int ledPin25 = 25; 
const int ledPin26 = 26; 
const int ledPin27 = 27;
const int ledPin28 = 28;// the pin that the LED is attached to
// Variables will change:

const int  buttonPin3 = A2;    // the pin that the pushbutton is attached to
const int ledPin29 = 29;
const int ledPin30 = 30;
const int ledPin31 = 31;
const int ledPin32 = 32; 
const int ledPin33 = 33; 
const int ledPin34 = 34;
const int ledPin35 = 35;// the pin that the LED is attached to


const int  buttonPin4 = A3;    // the pin that the pushbutton is attached to
const int ledPin36 = 36;
const int ledPin37 = 37;
const int ledPin38 = 38;
const int ledPin39 = 39; 
const int ledPin40 = 40; 
const int ledPin41 = 41;
const int ledPin42 = 42;// the pin that the LED is attached to
// Variables will change:

const int Trigger = 52;
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;
//2nd Button
int buttonPushCounter2 = 0;   // counter for the number of button presses
int buttonState2 = 0;         // current state of the button
int lastButtonState2 = 0;// previous state of the button
//3rd button
int buttonPushCounter3 = 0;   // counter for the number of button presses
int buttonState3 = 0;         // current state of the button
int lastButtonState3 = 0;// previous state of the button
//4th button
int buttonPushCounter4 = 0;   // counter for the number of button presses
int buttonState4 = 0;         // current state of the button
int lastButtonState4 = 0;// previous state of the button


void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT_PULLUP);
  // initialize the LED as an output:
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);

  //2nd Button
    pinMode(buttonPin2, INPUT_PULLUP);
  // initialize the LED as an output:
  pinMode(ledPin22, OUTPUT);
  pinMode(ledPin23, OUTPUT);
  pinMode(ledPin24, OUTPUT);
  pinMode(ledPin25, OUTPUT);
  pinMode(ledPin26, OUTPUT);
  pinMode(ledPin27, OUTPUT);
  pinMode(ledPin28, OUTPUT);
 

  //3rd Button
    pinMode(buttonPin3, INPUT_PULLUP);
  // initialize the LED as an output:
  pinMode(ledPin29, OUTPUT);
  pinMode(ledPin30, OUTPUT);
  pinMode(ledPin31, OUTPUT);
  pinMode(ledPin32, OUTPUT);
  pinMode(ledPin33, OUTPUT);
  pinMode(ledPin34, OUTPUT);
  pinMode(ledPin35, OUTPUT);
 

  
  //4th Button
    pinMode(buttonPin4, INPUT_PULLUP);
  // initialize the LED as an output:
  pinMode(ledPin36, OUTPUT);
  pinMode(ledPin37, OUTPUT);
  pinMode(ledPin38, OUTPUT);
  pinMode(ledPin39, OUTPUT);
  pinMode(ledPin40, OUTPUT);
  pinMode(ledPin41, OUTPUT);
  pinMode(ledPin42, OUTPUT);
  pinMode(Trigger, OUTPUT);
  
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
   //1st Button 
  
  
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);
  
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == LOW) {
      // if the current state is LOW then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
if (buttonPushCounter > 9){
  (buttonPushCounter = 0);}

  // turns on the LED every four button pushes by checking the modulo of the
  // button push counter. the modulo function gives you the remainder of the
  // division of two numbers:





//#0
  
   if (buttonPushCounter == 0) {
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
  } else {
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
  }

// #1
  
  if (buttonPushCounter == 1) {
    digitalWrite(ledPin8, LOW);
    digitalWrite(ledPin4, LOW);
  } else {
    digitalWrite(ledPin8, HIGH);
    digitalWrite(ledPin4, HIGH);
  }
//#2
  
   if (buttonPushCounter == 2) {
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
  } else {
   digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
  }

//#3
  
  if (buttonPushCounter == 3) {
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
  } else {
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
  }

//#4
  
    if (buttonPushCounter == 4) {
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin8, LOW);
  } else {
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin8, HIGH);
  }

//#5
  
    if (buttonPushCounter == 5) {
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
  } else {
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin7, HIGH);
  }


//#6
  
    if (buttonPushCounter == 6) {
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
  } else {
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
  }

//#7
  
    if (buttonPushCounter == 7) {
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
  } else {
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
  }

//#8
  
    if (buttonPushCounter == 8) {
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
  } else {
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
  }

//#9
  
    if (buttonPushCounter == 9) {
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
  } else {
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
  }





  

//2nd Button Loop

 // read the pushbutton input pin:
  buttonState2 = digitalRead(buttonPin2);
  
  // compare the buttonState to its previous state
  if (buttonState2 != lastButtonState2) {
    // if the state has changed, increment the counter
    if (buttonState2 == LOW) {
      // if the current state is LOW then the button went from off to on:
      buttonPushCounter2++;
      Serial.println("on");
      Serial.print("number of button2 pushes: ");
      Serial.println(buttonPushCounter2);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState2 = buttonState2;
if (buttonPushCounter2 > 9){
  (buttonPushCounter2 = 0);}

  // turns on the LED every four button pushes by checking the modulo of the
  // button push counter. the modulo function gives you the remainder of the
  // division of two numbers:





//#0
  
   if (buttonPushCounter2 == 0) {
    digitalWrite(ledPin22, LOW);
    digitalWrite(ledPin23, LOW);
    digitalWrite(ledPin24, LOW);
    digitalWrite(ledPin26, LOW);
    digitalWrite(ledPin27, LOW);
    digitalWrite(ledPin28, LOW);
  } else {
    digitalWrite(ledPin22, HIGH);
    digitalWrite(ledPin23, HIGH);
    digitalWrite(ledPin24, HIGH);
    digitalWrite(ledPin26, HIGH);
    digitalWrite(ledPin27, HIGH);
    digitalWrite(ledPin28, HIGH);
  }

// #1
  
  if (buttonPushCounter2 == 1) {
    digitalWrite(ledPin28, LOW);
    digitalWrite(ledPin24, LOW);
  } else {
    digitalWrite(ledPin28, HIGH);
    digitalWrite(ledPin24, HIGH);
  }
//#2
  
   if (buttonPushCounter2 == 2) {
    digitalWrite(ledPin22, LOW);
    digitalWrite(ledPin23, LOW);
    digitalWrite(ledPin25, LOW);
    digitalWrite(ledPin27, LOW);
    digitalWrite(ledPin28, LOW);
  } else {
    digitalWrite(ledPin22, HIGH);
    digitalWrite(ledPin23, HIGH);
    digitalWrite(ledPin25, HIGH);
    digitalWrite(ledPin27, HIGH);
    digitalWrite(ledPin28, HIGH);
  }

//#3
  
  if (buttonPushCounter2 == 3) {
    digitalWrite(ledPin22, LOW);
    digitalWrite(ledPin24, LOW);
    digitalWrite(ledPin25, LOW);
    digitalWrite(ledPin27, LOW);
    digitalWrite(ledPin28, LOW);
  } else {
    digitalWrite(ledPin22, HIGH);
    digitalWrite(ledPin24, HIGH);
    digitalWrite(ledPin25, HIGH);
    digitalWrite(ledPin27, HIGH);
    digitalWrite(ledPin28, HIGH);
  }

//#4
  
    if (buttonPushCounter2 == 4) {
    digitalWrite(ledPin24, LOW);
    digitalWrite(ledPin25, LOW);
    digitalWrite(ledPin26, LOW);
    digitalWrite(ledPin28, LOW);
  } else {
    digitalWrite(ledPin24, HIGH);
    digitalWrite(ledPin25, HIGH);
    digitalWrite(ledPin26, HIGH);
    digitalWrite(ledPin28, HIGH);
  }

//#5
  
    if (buttonPushCounter2 == 5) {
    digitalWrite(ledPin22, LOW);
    digitalWrite(ledPin24, LOW);
    digitalWrite(ledPin25, LOW);
    digitalWrite(ledPin26, LOW);
    digitalWrite(ledPin27, LOW);
  } else {
    digitalWrite(ledPin22, HIGH);
    digitalWrite(ledPin24, HIGH);
    digitalWrite(ledPin25, HIGH);
    digitalWrite(ledPin26, HIGH);
    digitalWrite(ledPin27, HIGH);
  }


//#6
  
    if (buttonPushCounter2 == 6) {
    digitalWrite(ledPin22, LOW);
    digitalWrite(ledPin23, LOW);
    digitalWrite(ledPin24, LOW);
    digitalWrite(ledPin25, LOW);
    digitalWrite(ledPin26, LOW);
  } else {
    digitalWrite(ledPin22, HIGH);
    digitalWrite(ledPin23, HIGH);
    digitalWrite(ledPin24, HIGH);
    digitalWrite(ledPin25, HIGH);
    digitalWrite(ledPin26, HIGH);
  }

//#7
  
    if (buttonPushCounter2 == 7) {
    digitalWrite(ledPin24, LOW);
    digitalWrite(ledPin27, LOW);
    digitalWrite(ledPin28, LOW);
  } else {
    digitalWrite(ledPin24, HIGH);
    digitalWrite(ledPin27, HIGH);
    digitalWrite(ledPin28, HIGH);
  }

//#8
  
    if (buttonPushCounter2 == 8) {
    digitalWrite(ledPin22, LOW);
    digitalWrite(ledPin23, LOW);
    digitalWrite(ledPin24, LOW);
    digitalWrite(ledPin25, LOW);
    digitalWrite(ledPin26, LOW);
    digitalWrite(ledPin27, LOW);
    digitalWrite(ledPin28, LOW);
  } else {
    digitalWrite(ledPin22, HIGH);
    digitalWrite(ledPin23, HIGH);
    digitalWrite(ledPin24, HIGH);
    digitalWrite(ledPin25, HIGH);
    digitalWrite(ledPin26, HIGH);
    digitalWrite(ledPin27, HIGH);
    digitalWrite(ledPin28, HIGH);
  }

//#9
  
    if (buttonPushCounter2 == 9) {
    digitalWrite(ledPin24, LOW);
    digitalWrite(ledPin25, LOW);
    digitalWrite(ledPin26, LOW);
    digitalWrite(ledPin27, LOW);
    digitalWrite(ledPin28, LOW);
  } else {
    digitalWrite(ledPin24, HIGH);
    digitalWrite(ledPin25, HIGH);
    digitalWrite(ledPin26, HIGH);
    digitalWrite(ledPin27, HIGH);
    digitalWrite(ledPin28, HIGH);
  }






  //3rd Button Loop

 // read the pushbutton input pin:
  buttonState3 = digitalRead(buttonPin3);
  
  // compare the buttonState to its previous state
  if (buttonState3 != lastButtonState3) {
    // if the state has changed, increment the counter
    if (buttonState3 == LOW) {
      // if the current state is LOW then the button went from off to on:
      buttonPushCounter3++;
      Serial.println("on");
      Serial.print("number of button3 pushes: ");
      Serial.println(buttonPushCounter3);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState3 = buttonState3;
if (buttonPushCounter3 > 9){
  (buttonPushCounter3 = 0);}

  // turns on the LED every four button pushes by checking the modulo of the
  // button push counter. the modulo function gives you the remainder of the
  // division of two numbers:





//#0
  
   if (buttonPushCounter3 == 0) {
    digitalWrite(ledPin29, LOW);
    digitalWrite(ledPin30, LOW);
    digitalWrite(ledPin31, LOW);
    digitalWrite(ledPin33, HIGH);
    digitalWrite(ledPin34, HIGH);
    digitalWrite(ledPin35, HIGH);
  } else {
    digitalWrite(ledPin29, LOW);
    digitalWrite(ledPin30, LOW);
    digitalWrite(ledPin31, LOW);
    digitalWrite(ledPin33, LOW);
    digitalWrite(ledPin34, LOW);
    digitalWrite(ledPin35, LOW);
  }

// #1
  
  if (buttonPushCounter3 == 1) {
    digitalWrite(ledPin35, LOW);
    digitalWrite(ledPin31, LOW);
  } else {
    digitalWrite(ledPin35, HIGH);
    digitalWrite(ledPin31, HIGH);
  }
//#2
  
   if (buttonPushCounter3 == 2) {
    digitalWrite(ledPin29, LOW);
    digitalWrite(ledPin30, LOW);
    digitalWrite(ledPin32, LOW);
    digitalWrite(ledPin34, LOW);
    digitalWrite(ledPin35, LOW);
  } else {
    digitalWrite(ledPin29, HIGH);
    digitalWrite(ledPin30, HIGH);
    digitalWrite(ledPin32, HIGH);
    digitalWrite(ledPin34, HIGH);
    digitalWrite(ledPin35, HIGH);
  }

//#3
  
  if (buttonPushCounter3 == 3) {
    digitalWrite(ledPin29, LOW);
    digitalWrite(ledPin31, LOW);
    digitalWrite(ledPin32, LOW);
    digitalWrite(ledPin34, LOW);
    digitalWrite(ledPin35, LOW);
  } else {
    digitalWrite(ledPin29, HIGH);
    digitalWrite(ledPin31, HIGH);
    digitalWrite(ledPin32, HIGH);
    digitalWrite(ledPin34, HIGH);
    digitalWrite(ledPin35, HIGH);
  }

//#4
  
    if (buttonPushCounter3 == 4) {
    digitalWrite(ledPin31, LOW);
    digitalWrite(ledPin32, LOW);
    digitalWrite(ledPin33, LOW);
    digitalWrite(ledPin35, LOW);
  } else {
    digitalWrite(ledPin31, HIGH);
    digitalWrite(ledPin32, HIGH);
    digitalWrite(ledPin26, HIGH);
    digitalWrite(ledPin35, HIGH);
  }

//#5
  
    if (buttonPushCounter3 == 5) {
    digitalWrite(ledPin29, LOW);
    digitalWrite(ledPin31, LOW);
    digitalWrite(ledPin32, LOW);
    digitalWrite(ledPin33, LOW);
    digitalWrite(ledPin34, LOW);
  } else {
    digitalWrite(ledPin29, HIGH);
    digitalWrite(ledPin31, HIGH);
    digitalWrite(ledPin32, HIGH);
    digitalWrite(ledPin33, HIGH);
    digitalWrite(ledPin34, HIGH);
  }


//#6
  
    if (buttonPushCounter3 == 6) {
    digitalWrite(ledPin29, LOW);
    digitalWrite(ledPin30, LOW);
    digitalWrite(ledPin31, LOW);
    digitalWrite(ledPin32, LOW);
    digitalWrite(ledPin33, LOW);
  } else {
    digitalWrite(ledPin29, HIGH);
    digitalWrite(ledPin30, HIGH);
    digitalWrite(ledPin31, HIGH);
    digitalWrite(ledPin32, HIGH);
    digitalWrite(ledPin33, HIGH);
  }

//#7
  
    if (buttonPushCounter3 == 7) {
    digitalWrite(ledPin31, LOW);
    digitalWrite(ledPin34, LOW);
    digitalWrite(ledPin35, LOW);
  } else {
    digitalWrite(ledPin31, HIGH);
    digitalWrite(ledPin34, HIGH);
    digitalWrite(ledPin35, HIGH);

//#8
  
    if (buttonPushCounter3 == 8) {
    digitalWrite(ledPin29, LOW);
    digitalWrite(ledPin30, LOW);
    digitalWrite(ledPin31, LOW);
    digitalWrite(ledPin32, LOW);
    digitalWrite(ledPin33, LOW);
    digitalWrite(ledPin34, LOW);
    digitalWrite(ledPin35, LOW);
  } else {
    digitalWrite(ledPin29, HIGH);
    digitalWrite(ledPin30, HIGH);
    digitalWrite(ledPin31, HIGH);
    digitalWrite(ledPin32, HIGH);
    digitalWrite(ledPin33, HIGH);
    digitalWrite(ledPin34, HIGH);
    digitalWrite(ledPin35, HIGH);
  }

//#9
  
    if (buttonPushCounter3 == 9) {
    digitalWrite(ledPin31, LOW);
    digitalWrite(ledPin32, LOW);
    digitalWrite(ledPin33, LOW);
    digitalWrite(ledPin34, LOW);
    digitalWrite(ledPin35, LOW);
  } else {
    digitalWrite(ledPin31, HIGH);
    digitalWrite(ledPin32, HIGH);
    digitalWrite(ledPin33, HIGH);
    digitalWrite(ledPin34, HIGH);
    digitalWrite(ledPin35, HIGH);
  }





   //4rd Button Loop

 // read the pushbutton input pin:
  buttonState4 = digitalRead(buttonPin4);
  
  // compare the buttonState to its previous state
  if (buttonState4 != lastButtonState4) {
    // if the state has changed, increment the counter
    if (buttonState4 == LOW) {
      // if the current state is LOW then the button went from off to on:
      buttonPushCounter4++;
      Serial.println("on");
      Serial.print("number of button4 pushes: ");
      Serial.println(buttonPushCounter4);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState4 = buttonState4;
if (buttonPushCounter4 > 9){
  (buttonPushCounter4 = 0);}

  // turns on the LED every four button pushes by checking the modulo of the
  // button push counter. the modulo function gives you the remainder of the
  // division of two numbers:





//#0
  
   if (buttonPushCounter4 == 0) {
    digitalWrite(ledPin36, LOW);
    digitalWrite(ledPin37, LOW);
    digitalWrite(ledPin38, LOW);
    digitalWrite(ledPin40, LOW);
    digitalWrite(ledPin41, LOW);
    digitalWrite(ledPin42, LOW);
  } else {
    digitalWrite(ledPin36, HIGH);
    digitalWrite(ledPin37, HIGH);
    digitalWrite(ledPin38, HIGH);
    digitalWrite(ledPin40, HIGH);
    digitalWrite(ledPin41, HIGH);
    digitalWrite(ledPin42, HIGH);
  }

// #1
  
  if (buttonPushCounter4 == 1) {
    digitalWrite(ledPin42, LOW);
    digitalWrite(ledPin38, LOW);
  } else {
    digitalWrite(ledPin42, HIGH);
    digitalWrite(ledPin38, HIGH);
  }
//#2
  
   if (buttonPushCounter4 == 2) {
    digitalWrite(ledPin36, LOW);
    digitalWrite(ledPin37, LOW);
    digitalWrite(ledPin39, LOW);
    digitalWrite(ledPin41, LOW);
    digitalWrite(ledPin42, LOW);
  } else {
    digitalWrite(ledPin36, HIGH);
    digitalWrite(ledPin37, HIGH);
    digitalWrite(ledPin39, HIGH);
    digitalWrite(ledPin41, HIGH);
    digitalWrite(ledPin42, HIGH);
  }

//#3
  
  if (buttonPushCounter4 == 3) {
    digitalWrite(ledPin36, LOW);
    digitalWrite(ledPin38, LOW);
    digitalWrite(ledPin39, LOW);
    digitalWrite(ledPin41, LOW);
    digitalWrite(ledPin42, LOW);
  } else {
    digitalWrite(ledPin36, HIGH);
    digitalWrite(ledPin38, HIGH);
    digitalWrite(ledPin39, HIGH);
    digitalWrite(ledPin41, HIGH);
    digitalWrite(ledPin42, HIGH);
  }

//#4
  
    if (buttonPushCounter4 == 4) {
    digitalWrite(ledPin38, LOW);
    digitalWrite(ledPin39, LOW);
    digitalWrite(ledPin40, LOW);
    digitalWrite(ledPin42, LOW);
  } else {
    digitalWrite(ledPin38, HIGH);
    digitalWrite(ledPin39, HIGH);
    digitalWrite(ledPin40, HIGH);
    digitalWrite(ledPin42, HIGH);
  }

//#5
  
    if (buttonPushCounter4 == 5) {
    digitalWrite(ledPin36, LOW);
    digitalWrite(ledPin38, LOW);
    digitalWrite(ledPin39, LOW);
    digitalWrite(ledPin40, LOW);
    digitalWrite(ledPin41, LOW);
  } else {
    digitalWrite(ledPin36, HIGH);
    digitalWrite(ledPin38, HIGH);
    digitalWrite(ledPin39, HIGH);
    digitalWrite(ledPin40, HIGH);
    digitalWrite(ledPin41, HIGH);
  }


//#6
  
    if (buttonPushCounter4 == 6) {
    digitalWrite(ledPin36, LOW);
    digitalWrite(ledPin37, LOW);
    digitalWrite(ledPin38, LOW);
    digitalWrite(ledPin39, LOW);
    digitalWrite(ledPin40, LOW);
  } else {
    digitalWrite(ledPin36, HIGH);
    digitalWrite(ledPin37, HIGH);
    digitalWrite(ledPin38, HIGH);
    digitalWrite(ledPin39, HIGH);
    digitalWrite(ledPin40, HIGH);
  }

//#7
  
    if (buttonPushCounter4 == 7) {
    digitalWrite(ledPin38, LOW);
    digitalWrite(ledPin41, LOW);
    digitalWrite(ledPin42, LOW);
  } else {
    digitalWrite(ledPin38, HIGH);
    digitalWrite(ledPin41, HIGH);
    digitalWrite(ledPin42, HIGH);
  }

//#8
  
    if (buttonPushCounter4 == 8) {
    digitalWrite(ledPin36, LOW);
    digitalWrite(ledPin37, LOW);
    digitalWrite(ledPin38, LOW);
    digitalWrite(ledPin39, LOW);
    digitalWrite(ledPin40, LOW);
    digitalWrite(ledPin41, LOW);
    digitalWrite(ledPin42, LOW);
  } else {
    digitalWrite(ledPin36, HIGH);
    digitalWrite(ledPin37, HIGH);
    digitalWrite(ledPin38, HIGH);
    digitalWrite(ledPin39, HIGH);
    digitalWrite(ledPin40, HIGH);
    digitalWrite(ledPin41, HIGH);
    digitalWrite(ledPin42, HIGH);
  }

//#9
  
    if (buttonPushCounter4 == 9) {
    digitalWrite(ledPin38, LOW);
    digitalWrite(ledPin39, LOW);
    digitalWrite(ledPin40, LOW);
    digitalWrite(ledPin41, LOW);
    digitalWrite(ledPin42, LOW);
  } else {
    digitalWrite(ledPin38, HIGH);
    digitalWrite(ledPin39, HIGH);
    digitalWrite(ledPin40, HIGH);
    digitalWrite(ledPin41, HIGH);
    digitalWrite(ledPin42, HIGH);
  }




if (buttonPushCounter == freqPos1 && buttonPushCounter2 == freqPos2 && buttonPushCounter3 == freqPos3 && buttonPushCounter4 == freqPos4)
digitalWrite (Trigger, HIGH);
else digitalWrite(Trigger, LOW);


  

  }}
