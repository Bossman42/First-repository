int button1 = 30 ;        
int button2 = 31 ;
int button3 = 32 ;
int button4 = 33 ;
int button5 = 34 ;
int button6 = 35 ;
int button7 = 36 ;
int button8 = 37 ;
int button9 = 38 ;
int button10 = 39 ;
int button11 = 40 ;
int button12 = 41 ;

int opendelay = 300;

int activate = 13;
int completed = 0;
int donecounter = 0;
int led1 = 42 ;
int led2 = 44 ;
int led3 = 46;
int led4 = 45 ;
int led5 = 47 ;
int led6 = 43 ;
int led7 = 48 ;
int led8 = 49 ;
int led9 = 50 ;
int led10 = 51 ;
int led11 = 53 ;
int led12 = 52 ;

int step1 = 0;
int step2 = 0;
int step3 = 0;
int step4 = 0;
int step5 = 0;

int resetdelay = 300;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////Button   Led    //////////////////////////////////////////////////////////////////////////
//////////////////Button   Led    ///////////////////////////////////////////Button   Led    //////////////////////////////////////////////////////////////
/////////////////////////////////////////////////Button 7  Led 48   //////////////////////////////////////////////////////////////////////////
//////////////////Button   Led    ///////////////////////////////////////////Button 8  Led 49   //////////////////////////////////////////////////////////////
/////////////////////////////////////////////////Button 5  Led 47   //////////////////////////////////////////////////////////////////////////
//////////////////Button 3  Led 46   ///////////////////////////////////////////Button 4  Led 45   //////////////////////////////////////////////////////////////
//////////////////////////////////////////////////Button 2  Led 44   /////////////////////////////////////////////////////////////////////////
///////////////////Button 1  Led 42   //////////////////////////////////////////Button 6 Led  43  //////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int lastButton1S = 0;
int lastButton2S = 0;
int lastButton3S = 0;
int lastButton4S = 0;
int lastButton5S = 0;
int lastButton6S = 0;
int lastButton7S = 0;
int lastButton8S = 0;
int lastButton9S = 0;
int lastButton10S = 0;
int lastButton11S = 0;
int lastButton12S = 0;


int buttonPushCounter1 = 1;
int buttonPushCounter2 = 1;
int buttonPushCounter3 = 1;
int buttonPushCounter4 = 1;
int buttonPushCounter5 = 1;
int buttonPushCounter6 = 1;
int buttonPushCounter7 = 1;
int buttonPushCounter8 = 1;
int buttonPushCounter9 = 1;
int buttonPushCounter10 = 1;
int buttonPushCounter11 = 1;
int buttonPushCounter12 = 1;




int led1S = 0;
int led2S = 0;
int led3S = 0;
int led4S = 0;
int led5S = 0;
int led6S = 0;
int led7S = 0;
int led8S = 0;
int led9S = 0;
int led10S = 0;
int led11S = 0;
int led12S = 0;

unsigned long lastDebounceTime1 = 0;  // the last time the output pin was toggled
unsigned long lastDebounceTime2 = 0;
unsigned long lastDebounceTime3 = 0;
unsigned long lastDebounceTime4 = 0;
unsigned long lastDebounceTime5 = 0;
unsigned long lastDebounceTime6 = 0;
unsigned long lastDebounceTime7 = 0;
unsigned long lastDebounceTime8 = 0;
unsigned long lastDebounceTime9 = 0;
unsigned long lastDebounceTime10 = 0;
unsigned long lastDebounceTime11 = 0;
unsigned long lastDebounceTime12 = 0;



int activation = 0;

unsigned long debounceDelay = 20;    // the debounce time; increase if the output flickers

void setup() {
  // put your setup code here, to run once:

pinMode (button1,INPUT_PULLUP);
pinMode (button2,INPUT_PULLUP);
pinMode (button3,INPUT_PULLUP);
pinMode (button4,INPUT_PULLUP);
pinMode (button5,INPUT_PULLUP);
pinMode (button6,INPUT_PULLUP);
pinMode (button7,INPUT_PULLUP);
pinMode (button8,INPUT_PULLUP);
pinMode (button9,INPUT_PULLUP);
pinMode (button10,INPUT_PULLUP);
pinMode (button11,INPUT_PULLUP);
pinMode (button12,INPUT_PULLUP);
pinMode (activate,INPUT_PULLUP);

pinMode (led1,OUTPUT);
pinMode (led2,OUTPUT);
pinMode (led3,OUTPUT);
pinMode (led4,OUTPUT);
pinMode (led5,OUTPUT);
pinMode (led6,OUTPUT);
pinMode (led7,OUTPUT);
pinMode (led8,OUTPUT);
pinMode (led9,OUTPUT);
pinMode (led10,OUTPUT);
pinMode (led11,OUTPUT);
pinMode (led12,OUTPUT);




Serial.begin(9600);



}

void loop(){
  int activateS = digitalRead(activate);
  if (activateS == LOW){
    activation = 1;
  }
    if(activation == 1){
      game();
    }
  
}

void game() {
  // put your main code here, to run repeatedly:

int button1S = digitalRead(button1);
int button2S = digitalRead(button2);
int button3S = digitalRead(button3);
int button4S = digitalRead(button4);
int button5S = digitalRead(button5);
int button6S = digitalRead(button6);
int button7S = digitalRead(button7);
int button8S = digitalRead(button8);
int button9S = digitalRead(button9);
int button10S = digitalRead(button10);
int button11S = digitalRead(button11);
int button12S = digitalRead(button12);

unsigned long debounce1 = millis() - lastDebounceTime1;
unsigned long debounce2 = millis() - lastDebounceTime2;
unsigned long debounce3 = millis() - lastDebounceTime3;
unsigned long debounce4 = millis() - lastDebounceTime4;
unsigned long debounce5 = millis() - lastDebounceTime5;
unsigned long debounce6 = millis() - lastDebounceTime6;
unsigned long debounce7 = millis() - lastDebounceTime7;
unsigned long debounce8 = millis() - lastDebounceTime8;
unsigned long debounce9 = millis() - lastDebounceTime9;
unsigned long debounce10 = millis() - lastDebounceTime10;
unsigned long debounce11 = millis() - lastDebounceTime11;
unsigned long debounce12 = millis() - lastDebounceTime12;

//////////////////////////////////////////////  Button and Led 1  ///////////////////////////////////////////

if (button1S != lastButton1S){
  lastDebounceTime1 = millis();
}

if (debounce1 > debounceDelay  && button1S != lastButton1S  && button1S == LOW) {    // if the state has changed, increment the counter                                     
      buttonPushCounter1++;      // if the current state is HIGH then the button went from off to on:                               
    }
  if (buttonPushCounter1 % 2 == 0) {              // turns on the LED every four button pushes by checking the modulo of the
    digitalWrite(led1, HIGH);                     // button push counter. the modulo function gives you the remainder of the
    led1S = 1;      // division of two numbers:
  } else {
    digitalWrite(led1, LOW);
    led1S = 0;
  }
 lastButton1S = button1S ;      // save the current state as the last state, for next time through the loop



//////////////////////////////////////////////  Button and Led 2  ///////////////////////////////////////////

if (button2S != lastButton2S){
  lastDebounceTime2 = millis();
}

if (debounce2 > debounceDelay  && button2S != lastButton2S  && button2S == LOW) {    // if the state has changed, increment the counter                                     
      buttonPushCounter2++;      // if the current state is HIGH then the button went from off to on:                               
    }
  if (buttonPushCounter2 % 2 == 0) {              // turns on the LED every four button pushes by checking the modulo of the
    digitalWrite(led2, HIGH);                     // button push counter. the modulo function gives you the remainder of the
    led2S = 1;                                    // division of two numbers:
  } else {
    digitalWrite(led2, LOW);
    led2S = 0;
  }
 lastButton2S = button2S ;      // save the current state as the last state, for next time through the loop



//////////////////////////////////////////////  Button and Led 3  ///////////////////////////////////////////

if (button3S != lastButton3S){
  lastDebounceTime3 = millis();
}

if (debounce3 > debounceDelay  && button3S != lastButton3S  && button3S == LOW) {    // if the state has changed, increment the counter                                     
      buttonPushCounter3++;      // if the current state is HIGH then the button went from off to on:                               
    }
  if (buttonPushCounter3 % 2 == 0) {              // turns on the LED every four button pushes by checking the modulo of the
    digitalWrite(led3, HIGH);                     // button push counter. the modulo function gives you the remainder of the
    led3S = 1;                                    // division of two numbers:
  } else {
    digitalWrite(led3, LOW);
    led3S = 0;
  }
 lastButton3S = button3S ;      // save the current state as the last state, for next time through the loop



//////////////////////////////////////////////  Button and Led 4  ///////////////////////////////////////////

if (button4S != lastButton4S){
  lastDebounceTime4 = millis();
}

if (debounce4 > debounceDelay  && button4S != lastButton4S  && button4S == LOW) {    // if the state has changed, increment the counter                                     
      buttonPushCounter4++;      // if the current state is HIGH then the button went from off to on:                               
    }
  if (buttonPushCounter4 % 2 == 0) {              // turns on the LED every four button pushes by checking the modulo of the
    digitalWrite(led4, HIGH);                     // button push counter. the modulo function gives you the remainder of the
    led4S = 1;                                    // division of two numbers:
  } else {
    digitalWrite(led4, LOW);
    led4S = 0;
  }
 lastButton4S = button4S ;      // save the current state as the last state, for next time through the loop


//////////////////////////////////////////////  Button and Led 5  ///////////////////////////////////////////

if (button5S != lastButton5S){
  lastDebounceTime5 = millis();
}

if (debounce5 > debounceDelay  && button5S != lastButton5S  && button5S == LOW) {    // if the state has changed, increment the counter                                     
      buttonPushCounter5++;      // if the current state is HIGH then the button went from off to on:                               
    }
  if (buttonPushCounter5 % 2 == 0) {              // turns on the LED every four button pushes by checking the modulo of the
    digitalWrite(led5, HIGH);                     // button push counter. the modulo function gives you the remainder of the
    led5S = 1;                                    // division of two numbers:
  } else {
    digitalWrite(led5, LOW);
    led5S = 0;
  }
 lastButton5S = button5S ;      // save the current state as the last state, for next time through the loop


//////////////////////////////////////////////  Button and Led 6  ///////////////////////////////////////////

if (button6S != lastButton6S){
  lastDebounceTime6 = millis();
}

if (debounce6 > debounceDelay  && button6S != lastButton6S  && button6S == LOW) {    // if the state has changed, increment the counter                                     
      buttonPushCounter6++;      // if the current state is HIGH then the button went from off to on:                               
    }
  if (buttonPushCounter6 % 2 == 0) {              // turns on the LED every four button pushes by checking the modulo of the
    digitalWrite(led6, HIGH);                     // button push counter. the modulo function gives you the remainder of the
    led6S = 1;                                    // division of two numbers:
  } else {
    digitalWrite(led6, LOW);
    led6S = 0;
  }
 lastButton6S = button6S ;      // save the current state as the last state, for next time through the loop


//////////////////////////////////////////////  Button and Led 7  ///////////////////////////////////////////

if (button7S != lastButton7S){
  lastDebounceTime7 = millis();
}

if (debounce7 > debounceDelay  && button7S != lastButton7S  && button7S == LOW) {    // if the state has changed, increment the counter                                     
      buttonPushCounter7++;      // if the current state is HIGH then the button went from off to on:                               
    }
  if (buttonPushCounter7 % 2 == 0) {              // turns on the LED every four button pushes by checking the modulo of the
    digitalWrite(led7, HIGH);                     // button push counter. the modulo function gives you the remainder of the
    led7S = 1;                                    // division of two numbers:
  } else {
    digitalWrite(led7, LOW);
    led7S = 0;
  }
 lastButton7S = button7S ;      // save the current state as the last state, for next time through the loop


//////////////////////////////////////////////  Button and Led 8  ///////////////////////////////////////////

if (button8S != lastButton8S){
  lastDebounceTime8 = millis();
}

if (debounce8 > debounceDelay  && button8S != lastButton8S  && button8S == LOW) {    // if the state has changed, increment the counter                                     
      buttonPushCounter8++;      // if the current state is HIGH then the button went from off to on:                               
    }
  if (buttonPushCounter8 % 2 == 0) {              // turns on the LED every four button pushes by checking the modulo of the
    digitalWrite(led8, HIGH);                     // button push counter. the modulo function gives you the remainder of the
    led8S = 1;                                    // division of two numbers:
  } else {
    digitalWrite(led8, LOW);
    led8S = 0;
  }
 lastButton8S = button8S ;      // save the current state as the last state, for next time through the loop


//////////////////////////////////////////////  Button and Led 9  ///////////////////////////////////////////

if (button9S != lastButton9S){
  lastDebounceTime9 = millis();
}

if (debounce9 > debounceDelay  && button9S != lastButton9S  && button9S == LOW) {    // if the state has changed, increment the counter                                     
      buttonPushCounter9++;      // if the current state is HIGH then the button went from off to on:                               
    }
  if (buttonPushCounter9 % 2 == 0) {              // turns on the LED every four button pushes by checking the modulo of the
    digitalWrite(led9, HIGH);                     // button push counter. the modulo function gives you the remainder of the
    led9S = 1;                                    // division of two numbers:
  } else {
    digitalWrite(led9, LOW);
    led9S = 0;
  }
 lastButton9S = button9S ;      // save the current state as the last state, for next time through the loop


//////////////////////////////////////////////  Button and Led 10  ///////////////////////////////////////////

if (button10S != lastButton10S){
  lastDebounceTime10 = millis();
}

if (debounce10 > debounceDelay  && button10S != lastButton10S  && button10S == LOW) {    // if the state has changed, increment the counter                                     
      buttonPushCounter10++;      // if the current state is HIGH then the button went from off to on:                               
    }
  if (buttonPushCounter10 % 2 == 0) {              // turns on the LED every four button pushes by checking the modulo of the
    digitalWrite(led10, HIGH);                     // button push counter. the modulo function gives you the remainder of the
    led10S = 1;                                    // division of two numbers:
  } else {
    digitalWrite(led10, LOW);
    led10S = 0;
  }
 lastButton10S = button10S ;      // save the current state as the last state, for next time through the loop


//////////////////////////////////////////////  Button and Led 11  ///////////////////////////////////////////

if (button11S != lastButton11S){
  lastDebounceTime11 = millis();
}

if (debounce11 > debounceDelay  && button11S != lastButton11S  && button11S == LOW) {    // if the state has changed, increment the counter                                     
      buttonPushCounter11++;      // if the current state is HIGH then the button went from off to on:                               
    }
  if (buttonPushCounter11 % 2 == 0) {              // turns on the LED every four button pushes by checking the modulo of the
    digitalWrite(led11, HIGH);                     // button push counter. the modulo function gives you the remainder of the
    led11S = 1;                                    // division of two numbers:
  } else {
    digitalWrite(led11, LOW);
    led11S = 0;
  }
 lastButton11S = button11S ;      // save the current state as the last state, for next time through the loop



//////////////////////////////////////////////  Button and Led 12  ///////////////////////////////////////////

if (button12S != lastButton12S){
  lastDebounceTime12 = millis();
}

if (debounce12 > debounceDelay  && button12S != lastButton12S  && button12S == LOW) {    // if the state has changed, increment the counter                                     
      buttonPushCounter12++;      // if the current state is HIGH then the button went from off to on:                               
    }
  if (buttonPushCounter12 % 2 == 0) {              // turns on the LED every four button pushes by checking the modulo of the
    digitalWrite(led12, HIGH);                     // button push counter. the modulo function gives you the remainder of the
    led12S = 1;                                    // division of two numbers:
  } else {
    digitalWrite(led12, LOW);
    led12S = 0;
  }
 lastButton12S = button12S ;      // save the current state as the last state, for next time through the loop



if ( led1S == 1 && led2S == 0 && led3S == 0 && led4S == 0 && led5S == 0 && led6S == 0 && led7S == 0 && led8S == 0 
&& led9S == 0 && led10S == 0 && led11S == 0 && led12S == 0 && step2 == 0 && step3 == 0 && step4 == 0 && step5 == 0 ){
    step1 = 1;
    }
if ( led1S == 1 && led2S == 1 && led3S == 0 && led4S == 0 && led5S == 0 && led6S == 0 && led7S == 0 && led8S == 0 
&& led9S == 0 && led10S == 0 && led11S == 0 && led12S == 0 && step1 == 1 && step3 == 0 && step4 == 0 && step5 == 0){
    step2 = 1;
    }
if ( led1S == 1 && led2S == 1 && led3S == 1 && led4S == 0 && led5S == 0 && led6S == 0 && led7S == 0 && led8S == 0 
&& led9S == 0 && led10S == 0 && led11S == 0 && led12S == 0 && step1 == 1 && step2 == 1 && step4 == 0 && step5 == 0){
    step3 = 1;
    }
if ( led1S == 1 && led2S == 1 && led3S == 1 && led4S == 1 && led5S == 0 && led6S == 0 && led7S == 0 && led8S == 0 
&& led9S == 0 && led10S == 0 && led11S == 0 && led12S == 0 && step1 == 1 && step2 == 1 && step3 == 1 && step5 == 0){
    step4 = 1;
    }
if ( led1S == 1 && led2S == 1 && led3S == 1 && led4S == 1 && led5S == 1 && led6S == 0 && led7S == 0 && led8S == 0 
&& led9S == 0 && led10S == 0 && led11S == 0 && led12S == 0 && step1 == 1 && step2 == 1 && step3 == 1 && step4 == 1){
    step5 = 1;
    }        

if ( led1S == 0 && led2S == 0 && led3S == 0 && led4S == 0 && led5S == 0 && led6S == 0 && led7S == 0 && led8S == 0 
&& led9S == 0 && led10S == 0 && led11S == 0 && led12S == 0 ){
    step1 = 0;
    step2 = 0;
    step3 = 0;
    step4 = 0;
    step5 = 0;
    }        



if (step1 == 1 && step2 == 1 && step3 == 1 && step4 == 1 && step5 == 1){
  completed = 1;
}


if (completed == 1 && donecounter <3){

  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  digitalWrite(led6,LOW);
  digitalWrite(led7,LOW);
  digitalWrite(led8,LOW);
  digitalWrite(led9,LOW);
  digitalWrite(led10,LOW);
  digitalWrite(led11,LOW);
  digitalWrite(led12,LOW);
  
delay(opendelay);
    digitalWrite(led1,HIGH);
    delay(opendelay);
  digitalWrite(led2,HIGH);
  delay(opendelay);
  digitalWrite(led3,HIGH);
  delay(opendelay);
  digitalWrite(led4,HIGH);
  delay(opendelay);
  digitalWrite(led5,HIGH);
  delay(opendelay);
  digitalWrite(led6,HIGH);
  delay(opendelay);
  digitalWrite(led7,HIGH);
  delay(opendelay);
  digitalWrite(led8,HIGH);
  delay(opendelay);
  digitalWrite(led9,HIGH);
  delay(opendelay);
  digitalWrite(led10,HIGH);
  delay(opendelay);
  digitalWrite(led11,HIGH);
  delay(opendelay);
  digitalWrite(led12,HIGH);
  donecounter++;
}
if (donecounter >=3){
      digitalWrite(led1,HIGH);
    delay(opendelay);
  digitalWrite(led2,HIGH);
  delay(opendelay);
  digitalWrite(led3,HIGH);
  delay(opendelay);
  digitalWrite(led4,HIGH);
  delay(opendelay);
  digitalWrite(led5,HIGH);
  delay(opendelay);
  digitalWrite(led6,HIGH);
  delay(opendelay);
  digitalWrite(led7,HIGH);
  delay(opendelay);
  digitalWrite(led8,HIGH);
  delay(opendelay);
  digitalWrite(led9,HIGH);
  delay(opendelay);
  digitalWrite(led10,HIGH);
  delay(opendelay);
  digitalWrite(led11,HIGH);
  delay(opendelay);
  digitalWrite(led12,HIGH);
  donecounter++;
}





//////////////////////////////   After 5 button press will reset lights   //////////////////////////////////////////

if( led1S + led2S + led3S + led4S + led5S + led6S + led7S + led8S + led9S + led10S + led11S + led12S >= 6){
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,HIGH);
  digitalWrite(led6,HIGH);
  digitalWrite(led7,HIGH);
  digitalWrite(led8,HIGH);
  digitalWrite(led9,HIGH);
  digitalWrite(led10,HIGH);
  digitalWrite(led11,HIGH);
  digitalWrite(led12,HIGH);
  
  delay(resetdelay);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  digitalWrite(led6,LOW);
  digitalWrite(led7,LOW);
  digitalWrite(led8,LOW);
  digitalWrite(led9,LOW);
  digitalWrite(led10,LOW);
  digitalWrite(led11,LOW);
  digitalWrite(led12,LOW);
  delay(resetdelay); 
     digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,HIGH);
  digitalWrite(led6,HIGH);
  digitalWrite(led7,HIGH);
  digitalWrite(led8,HIGH);
  digitalWrite(led9,HIGH);
  digitalWrite(led10,HIGH);
  digitalWrite(led11,HIGH);
  digitalWrite(led12,HIGH);
  delay(resetdelay);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  digitalWrite(led6,LOW);
  digitalWrite(led7,LOW);
  digitalWrite(led8,LOW);
  digitalWrite(led9,LOW);
  digitalWrite(led10,LOW);
  digitalWrite(led11,LOW);
  digitalWrite(led12,LOW);
  delay(resetdelay); 
     digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,HIGH);
  digitalWrite(led6,HIGH);
  digitalWrite(led7,HIGH);
  digitalWrite(led8,HIGH);
  digitalWrite(led9,HIGH);
  digitalWrite(led10,HIGH);
  digitalWrite(led11,HIGH);
  digitalWrite(led12,HIGH);
  delay(resetdelay);
  
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
digitalWrite(led4,LOW);
digitalWrite(led5,LOW);
digitalWrite(led6,LOW);
digitalWrite(led7,LOW);
digitalWrite(led8,LOW);
digitalWrite(led9,LOW);
digitalWrite(led10,LOW);
digitalWrite(led11,LOW);
digitalWrite(led12,LOW);

button1S = 0;
button2S = 0;
button3S = 0;
button4S = 0;
button5S = 0;
button6S = 0;
button7S = 0;
button8S = 0;
button9S = 0;
button10S = 0;
button11S = 0;
button12S = 0;

 led1S = 0;
 led2S = 0;
 led3S = 0;
 led4S = 0;
 led5S = 0;
 led6S = 0;
 led7S = 0;
 led8S = 0;
 led9S = 0;
 led10S = 0;
 led11S = 0;
 led12S = 0;

 buttonPushCounter1 = 1;
 buttonPushCounter2 = 1;
 buttonPushCounter3 = 1;
 buttonPushCounter4 = 1;
 buttonPushCounter5 = 1;
 buttonPushCounter6 = 1;
 buttonPushCounter7 = 1;
 buttonPushCounter8 = 1;
 buttonPushCounter9 = 1;
 buttonPushCounter10 = 1;
 buttonPushCounter11 = 1;
 buttonPushCounter12 = 1;

 step1 = 0;
 step2 = 0;
 step3 = 0;
 step4 = 0;
 step5 = 0;
 
}





 ////////////////////////////////////////////   Serial Debuging /////////////////////////////////////////////////////////////////


Serial.print ("  Leds  ");
Serial.print (led1S);
Serial.print (" ");
Serial.print (led2S);
Serial.print (" ");
Serial.print (led3S);
Serial.print (" ");
Serial.print (led4S);
Serial.print (" ");
Serial.print (led5S);
Serial.print (" ");
Serial.print (led6S);
Serial.print (" ");
Serial.print (led7S);
Serial.print (" ");
Serial.print (led8S);
Serial.print (" ");
Serial.print (led9S);
Serial.print (" ");
Serial.print (led10S);
Serial.print (" ");
Serial.print (led11S);
Serial.print (" ");
Serial.print (led12S);
Serial.print ("       ");
Serial.print ("steps ");
Serial.print (step1);
Serial.print (" ");
Serial.print (step2);
Serial.print (" ");
Serial.print (step3);
Serial.print (" ");
Serial.print (step4);
Serial.print (" ");
Serial.print (step5);
Serial.println (" ");



//Serial.print ("   lastDebounceTime ");
//Serial.print (lastDebounceTime1);
//Serial.print ("   buttonpushcounter1  ");
//Serial.print (buttonPushCounter1);
//Serial.print ("   button1S ");
//Serial.print (button1S);
//Serial.print ("   time-debounce ");
//Serial.println (debounce1);





}
