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
const int  buttonPin = 9;    // the pin that the pushbutton is attached to
const int ledPin2 = 2;
const int ledPin3 = 3;
const int ledPin4 = 4;
const int ledPin5 = 5; 
const int ledPin6 = 6; 
const int ledPin7 = 7;
const int ledPin8 = 8;// the pin that the LED is attached to

const int  buttonPin2 = 10;    // the pin that the pushbutton is attached to
const int ledPin22 = 22;
const int ledPin23 = 23;
const int ledPin24 = 24;
const int ledPin25 = 25; 
const int ledPin26 = 26; 
const int ledPin27 = 27;
const int ledPin28 = 28;// the pin that the LED is attached to
// Variables will change:

const int Trigger = 52;
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;
//2nd Button
int buttonPushCounter2 = 0;   // counter for the number of button presses
int buttonState2 = 0;         // current state of the button
int lastButtonState2 = 0;// previous state of the button

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
  pinMode(Trigger, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
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
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
  } else {
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
  }

// #1
  
  if (buttonPushCounter == 1) {
    digitalWrite(ledPin8, HIGH);
    digitalWrite(ledPin4, HIGH);
  } else {
    digitalWrite(ledPin8, LOW);
    digitalWrite(ledPin4, LOW);
  }
//#2
  
   if (buttonPushCounter == 2) {
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
  } else {
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
  }

//#3
  
  if (buttonPushCounter == 3) {
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
  } else {
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
  }

//#4
  
    if (buttonPushCounter == 4) {
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin8, HIGH);
  } else {
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin8, LOW);
  }

//#5
  
    if (buttonPushCounter == 5) {
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin7, HIGH);
  } else {
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
  }


//#6
  
    if (buttonPushCounter == 6) {
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
  } else {
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
  }

//#7
  
    if (buttonPushCounter == 7) {
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
  } else {
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
  }

//#8
  
    if (buttonPushCounter == 8) {
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
  } else {
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
  }

//#9
  
    if (buttonPushCounter == 9) {
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
  } else {
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
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
    digitalWrite(ledPin22, HIGH);
    digitalWrite(ledPin23, HIGH);
    digitalWrite(ledPin24, HIGH);
    digitalWrite(ledPin26, HIGH);
    digitalWrite(ledPin27, HIGH);
    digitalWrite(ledPin28, HIGH);
  } else {
    digitalWrite(ledPin22, LOW);
    digitalWrite(ledPin23, LOW);
    digitalWrite(ledPin24, LOW);
    digitalWrite(ledPin26, LOW);
    digitalWrite(ledPin27, LOW);
    digitalWrite(ledPin28, LOW);
  }

// #1
  
  if (buttonPushCounter2 == 1) {
    digitalWrite(ledPin28, HIGH);
    digitalWrite(ledPin24, HIGH);
  } else {
    digitalWrite(ledPin28, LOW);
    digitalWrite(ledPin24, LOW);
  }
//#2
  
   if (buttonPushCounter2 == 2) {
    digitalWrite(ledPin22, HIGH);
    digitalWrite(ledPin23, HIGH);
    digitalWrite(ledPin25, HIGH);
    digitalWrite(ledPin27, HIGH);
    digitalWrite(ledPin28, HIGH);
  } else {
    digitalWrite(ledPin22, LOW);
    digitalWrite(ledPin23, LOW);
    digitalWrite(ledPin25, LOW);
    digitalWrite(ledPin27, LOW);
    digitalWrite(ledPin28, LOW);
  }

//#3
  
  if (buttonPushCounter2 == 3) {
    digitalWrite(ledPin22, HIGH);
    digitalWrite(ledPin24, HIGH);
    digitalWrite(ledPin25, HIGH);
    digitalWrite(ledPin27, HIGH);
    digitalWrite(ledPin28, HIGH);
  } else {
    digitalWrite(ledPin22, LOW);
    digitalWrite(ledPin24, LOW);
    digitalWrite(ledPin25, LOW);
    digitalWrite(ledPin27, LOW);
    digitalWrite(ledPin28, LOW);
  }

//#4
  
    if (buttonPushCounter2 == 4) {
    digitalWrite(ledPin24, HIGH);
    digitalWrite(ledPin25, HIGH);
    digitalWrite(ledPin26, HIGH);
    digitalWrite(ledPin28, HIGH);
  } else {
    digitalWrite(ledPin24, LOW);
    digitalWrite(ledPin25, LOW);
    digitalWrite(ledPin26, LOW);
    digitalWrite(ledPin28, LOW);
  }

//#5
  
    if (buttonPushCounter2 == 5) {
    digitalWrite(ledPin22, HIGH);
    digitalWrite(ledPin24, HIGH);
    digitalWrite(ledPin25, HIGH);
    digitalWrite(ledPin26, HIGH);
    digitalWrite(ledPin27, HIGH);
  } else {
    digitalWrite(ledPin22, LOW);
    digitalWrite(ledPin24, LOW);
    digitalWrite(ledPin25, LOW);
    digitalWrite(ledPin26, LOW);
    digitalWrite(ledPin27, LOW);
  }


//#6
  
    if (buttonPushCounter2 == 6) {
    digitalWrite(ledPin22, HIGH);
    digitalWrite(ledPin23, HIGH);
    digitalWrite(ledPin24, HIGH);
    digitalWrite(ledPin25, HIGH);
    digitalWrite(ledPin26, HIGH);
  } else {
    digitalWrite(ledPin22, LOW);
    digitalWrite(ledPin23, LOW);
    digitalWrite(ledPin24, LOW);
    digitalWrite(ledPin25, LOW);
    digitalWrite(ledPin26, LOW);
  }

//#7
  
    if (buttonPushCounter2 == 7) {
    digitalWrite(ledPin24, HIGH);
    digitalWrite(ledPin27, HIGH);
    digitalWrite(ledPin28, HIGH);
  } else {
    digitalWrite(ledPin24, LOW);
    digitalWrite(ledPin27, LOW);
    digitalWrite(ledPin28, LOW);
  }

//#8
  
    if (buttonPushCounter2 == 8) {
    digitalWrite(ledPin22, HIGH);
    digitalWrite(ledPin23, HIGH);
    digitalWrite(ledPin24, HIGH);
    digitalWrite(ledPin25, HIGH);
    digitalWrite(ledPin26, HIGH);
    digitalWrite(ledPin27, HIGH);
    digitalWrite(ledPin28, HIGH);
  } else {
    digitalWrite(ledPin22, LOW);
    digitalWrite(ledPin23, LOW);
    digitalWrite(ledPin24, LOW);
    digitalWrite(ledPin25, LOW);
    digitalWrite(ledPin26, LOW);
    digitalWrite(ledPin27, LOW);
    digitalWrite(ledPin28, LOW);
  }

//#9
  
    if (buttonPushCounter2 == 9) {
    digitalWrite(ledPin24, HIGH);
    digitalWrite(ledPin25, HIGH);
    digitalWrite(ledPin26, HIGH);
    digitalWrite(ledPin27, HIGH);
    digitalWrite(ledPin28, HIGH);
  } else {
    digitalWrite(ledPin24, LOW);
    digitalWrite(ledPin25, LOW);
    digitalWrite(ledPin26, LOW);
    digitalWrite(ledPin27, LOW);
    digitalWrite(ledPin28, LOW);
  }


if (buttonPushCounter == 2 && buttonPushCounter2 == 9)
digitalWrite (Trigger, HIGH);
else digitalWrite(Trigger, LOW);


  

}
