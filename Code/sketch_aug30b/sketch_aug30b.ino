//Segment#1 
const int  buttonPin = A0;   
const int ledPin2 = 5;
const int ledPin3 = 6;
const int ledPin4 = 3;
const int ledPin5 = 11; 
const int ledPin6 = 10; 
const int ledPin7 = 8;
const int ledPin8 = 7;

//Power for Segments
const int SegmentPower = 4;
const int SegmentPower2 = 9;

//1st Button Counter
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;


void setup() {
  // put your setup code here, to run once:
//1st button
  pinMode(buttonPin, INPUT_PULLUP);
  // initialize the LED as an output:
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);

    pinMode(SegmentPower,OUTPUT);
  digitalWrite (SegmentPower,HIGH); 
}

void loop() {
  // put your main code here, to run repeatedly:


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




}
