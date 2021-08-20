/*
  Showing number 0-9 on a Common Anode 7-segment LED display
  Displays the numbers 0-9 on the display, with one second inbetween.
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
  This example code is in the public domain.
 */
 
// Pin 2-8 is connected to the 7 segments of the display.
// this constant won't change:
const int freqPos1 = 2;
const int freqPos2 = 9;
const int freqPos3 = 7;
const int freqPos4 = 4;

const int  buttonPin = A0;    // the pin that the pushbutton is attached to
const int  buttonPin2 = A1;
const int  buttonPin3 = A2;
const int  buttonPin4 = A3;

const int  delayTime = 5;  // DIgit refresh time

const int Trigger = A4;
const int Trigger2 = A5;

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


int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;
int Delay =100;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);  
  

    pinMode(buttonPin, INPUT_PULLUP);
pinMode(buttonPin2, INPUT_PULLUP);
   pinMode(buttonPin3, INPUT_PULLUP);
 pinMode(buttonPin4, INPUT_PULLUP);
     pinMode(Trigger, OUTPUT);
digitalWrite (Trigger,HIGH);
digitalWrite (Trigger2,HIGH);
Serial.begin(9600);

// the loop routine runs over and over again forever:
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

//4th Button Loop

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

//#0
  switch (buttonPushCounter){

  case 0:
 digitalWrite(D1, LOW);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);
    delay(delayTime);
  break;
  case 1:
   digitalWrite(D1, LOW);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
    delay(delayTime);
     break;

  case 2:
   digitalWrite(D1, LOW);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;

  case 3:
 digitalWrite(D1, LOW);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;

  case 4:
 digitalWrite(D1, LOW);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;
  case 5:
 digitalWrite(D1, LOW);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;
 case 6:
 digitalWrite(D1, LOW);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;
      case 7:
 digitalWrite(D1, LOW);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
    delay(delayTime);
     break;
      case 8:
 digitalWrite(D1, LOW);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;

      case 9:
 digitalWrite(D1, LOW);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;





  

}



// Digit #2



 switch (buttonPushCounter2){

   case 0:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, LOW);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);
    delay(delayTime);
  break;
  case 1:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, LOW);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
    delay(delayTime);
     break;

  case 2:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, LOW);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;

  case 3:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, LOW);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;

  case 4:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, LOW);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;
  case 5:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, LOW);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;
 case 6:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, LOW);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;
      case 7:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, LOW);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
    delay(delayTime);
     break;
      case 8:
  digitalWrite(D1, HIGH);
 digitalWrite(D2, LOW);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;

      case 9:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, LOW);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;

}



// Digit #3
 switch (buttonPushCounter3){

   case 0:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, LOW);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);
    delay(delayTime);
  break;
  case 1:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, LOW);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
    delay(delayTime);
     break;

  case 2:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, LOW);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;

  case 3:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, LOW);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;

  case 4:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, LOW);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;
  case 5:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, LOW);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;
 case 6:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, LOW);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;
      case 7:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, LOW);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
    delay(delayTime);
     break;
      case 8:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, LOW);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;

      case 9:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, LOW);
 digitalWrite(D4, HIGH);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;


 }



//Digit #4

switch (buttonPushCounter4){

   case 0:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, LOW);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);
    delay(delayTime);
  break;
  case 1:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, LOW);
 
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
    delay(delayTime);
     break;

  case 2:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, LOW);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;

  case 3:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, LOW);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;

  case 4:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, LOW);
 
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;
  case 5:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, LOW);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;
 case 6:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, LOW);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;
      case 7:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, LOW);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
    delay(delayTime);
     break;
      case 8:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, LOW);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;

      case 9:
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 digitalWrite(D4, LOW);
 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
    delay(delayTime);
     break;


 }


if (buttonPushCounter == freqPos1 && buttonPushCounter2 == freqPos2 && buttonPushCounter3 == freqPos3 && buttonPushCounter4 == freqPos4) {
  digitalWrite (Trigger,LOW);
  digitalWrite (Trigger2,LOW);}
  else digitalWrite (Trigger,HIGH);
  digitalWrite (Trigger2,HIGH);


 

}
