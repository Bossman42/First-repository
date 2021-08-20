//ChannelandLengthInput
int Wheelspin = A8;

int WheelspinCounter = 0;

int lastWheelspinState = 0;

unsigned long Spinlow = 0;
unsigned long Spinhigh = 0;


int Green0R1 = 2;
int Green1R1 = 3;
int Green2R1 = 4;
int Green3R1 = 5;
int Green4R1 = 6;
int Green5R1 = 7;
int Green6R1 = 8;
int Green7R1 = 9;
int Green8R1 = 10;
int Green9R1 = 11;
int Green0R2 = 12;
int Green1R2 = 13;
int Green2R2 = 14;
int Green3R2 = 15;
int Green4R2 = 16;
int Green5R2 = 17;
int Green6R2 = 18;
int Green7R2 = 19;
int Green8R2 = 20;
int Green9R2 = 21;

int Red0R1 = 22;
int Red1R1 = 23;
int Red2R1 = 24;
int Red3R1 = 25;
int Red4R1 = 26;
int Red5R1 = 27;
int Red6R1 = 28;
int Red7R1 = 29;
int Red8R1 = 30;
int Red9R1 = 31;
int Red0R2 = 32;
int Red1R2 = 33;
int Red2R2 = 34;
int Red3R2 = 35;
int Red4R2 = 36;
int Red5R2 = 37;
int Red6R2 = 38;
int Red7R2 = 39;
int Red8R2 = 40;
int Red9R2 = 41;

int Trigger = A0;
int Pump = A1;


int LastLedGreen0R1 = 0;
int LastLedGreen1R1 = 0;
int LastLedGreen2R1 = 0;
int LastLedGreen3R1 = 0;
int LastLedGreen4R1 = 0;
int LastLedGreen5R1 = 0;
int LastLedGreen6R1 = 0;
int LastLedGreen7R1 = 0;
int LastLedGreen8R1 = 0;
int LastLedGreen9R1 = 0;
int LastLedGreen0R2 = 0;
int LastLedGreen1R2 = 0;
int LastLedGreen2R2 = 0;
int LastLedGreen3R2 = 0;
int LastLedGreen4R2 = 0;
int LastLedGreen5R2 = 0;
int LastLedGreen6R2 = 0;
int LastLedGreen7R2 = 0;
int LastLedGreen8R2 = 0;
int LastLedGreen9R2 = 0;

int LastLedRed0R1 = 0;
int LastLedRed1R1 = 0;
int LastLedRed2R1 = 0;
int LastLedRed3R1 = 0;
int LastLedRed4R1 = 0;
int LastLedRed5R1 = 0;
int LastLedRed6R1 = 0;
int LastLedRed7R1 = 0;
int LastLedRed8R1 = 0;
int LastLedRed9R1 = 0;
int LastLedRed0R2 = 0;
int LastLedRed1R2 = 0;
int LastLedRed2R2 = 0;
int LastLedRed3R2 = 0;
int LastLedRed4R2 = 0;
int LastLedRed5R2 = 0;
int LastLedRed6R2 = 0;
int LastLedRed7R2 = 0;
int LastLedRed8R2 = 0;
int LastLedRed9R2 = 0;


void setup() {
  // put your setup code here, to run once:
pinMode (Green0R1, INPUT_PULLUP);
pinMode (Green1R1, INPUT_PULLUP);
pinMode (Green2R1, INPUT_PULLUP);
pinMode (Green3R1, INPUT_PULLUP);
pinMode (Green4R1, INPUT_PULLUP);
pinMode (Green5R1, INPUT_PULLUP);
pinMode (Green6R1, INPUT_PULLUP);
pinMode (Green7R1, INPUT_PULLUP);
pinMode (Green8R1, INPUT_PULLUP);
pinMode (Green9R1, INPUT_PULLUP);
pinMode (Green0R2, INPUT_PULLUP);
pinMode (Green1R2, INPUT_PULLUP);
pinMode (Green2R2, INPUT_PULLUP);
pinMode (Green3R2, INPUT_PULLUP);
pinMode (Green4R2, INPUT_PULLUP);
pinMode (Green5R2, INPUT_PULLUP);
pinMode (Green6R2, INPUT_PULLUP);
pinMode (Green7R2, INPUT_PULLUP);
pinMode (Green8R2, INPUT_PULLUP);
pinMode (Green9R2, INPUT_PULLUP);

pinMode (Red0R1, INPUT_PULLUP);
pinMode (Red1R1, INPUT_PULLUP);
pinMode (Red2R1, INPUT_PULLUP);
pinMode (Red3R1, INPUT_PULLUP);
pinMode (Red4R1, INPUT_PULLUP);
pinMode (Red5R1, INPUT_PULLUP);
pinMode (Red6R1, INPUT_PULLUP);
pinMode (Red7R1, INPUT_PULLUP);
pinMode (Red8R1, INPUT_PULLUP);
pinMode (Red9R1, INPUT_PULLUP);
pinMode (Red0R2, INPUT_PULLUP);
pinMode (Red1R2, INPUT_PULLUP);
pinMode (Red2R2, INPUT_PULLUP);
pinMode (Red3R2, INPUT_PULLUP);
pinMode (Red4R2, INPUT_PULLUP);
pinMode (Red5R2, INPUT_PULLUP);
pinMode (Red6R2, INPUT_PULLUP);
pinMode (Red7R2, INPUT_PULLUP);
pinMode (Red8R2, INPUT_PULLUP);
pinMode (Red9R2, INPUT_PULLUP);

pinMode (Trigger, OUTPUT);
digitalWrite (Trigger, HIGH);
pinMode (Pump, OUTPUT);

pinMode (Wheelspin,INPUT_PULLUP);
Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int LedGreen0R1 = digitalRead (Green0R1);
int LedGreen1R1 = digitalRead (Green1R1);
int LedGreen2R1 = digitalRead (Green2R1);
int LedGreen3R1 = digitalRead (Green3R1);
int LedGreen4R1 = digitalRead (Green4R1);
int LedGreen5R1 = digitalRead (Green5R1);
int LedGreen6R1 = digitalRead (Green6R1);
int LedGreen7R1 = digitalRead (Green7R1);
int LedGreen8R1 = digitalRead (Green8R1);
int LedGreen9R1 = digitalRead (Green9R1);
int LedGreen0R2 = digitalRead (Green0R2);
int LedGreen1R2 = digitalRead (Green1R2);
int LedGreen2R2 = digitalRead (Green2R2);
int LedGreen3R2 = digitalRead (Green3R2);
int LedGreen4R2 = digitalRead (Green4R2);
int LedGreen5R2 = digitalRead (Green5R2);
int LedGreen6R2 = digitalRead (Green6R2);
int LedGreen7R2 = digitalRead (Green7R2);
int LedGreen8R2 = digitalRead (Green8R2);
int LedGreen9R2 = digitalRead (Green9R2);
int LedRed0R1 = digitalRead (Red0R1);
int LedRed1R1 = digitalRead (Red1R1);
int LedRed2R1 = digitalRead (Red2R1);
int LedRed3R1 = digitalRead (Red3R1);
int LedRed4R1 = digitalRead (Red4R1);
int LedRed5R1 = digitalRead (Red5R1);
int LedRed6R1 = digitalRead (Red6R1);
int LedRed7R1 = digitalRead (Red7R1);
int LedRed8R1 = digitalRead (Red8R1);
int LedRed9R1 = digitalRead (Red9R1);
int LedRed0R2 = digitalRead (Red0R2);
int LedRed1R2 = digitalRead (Red1R2);
int LedRed2R2 = digitalRead (Red2R2);
int LedRed3R2 = digitalRead (Red3R2);
int LedRed4R2 = digitalRead (Red4R2);
int LedRed5R2 = digitalRead (Red5R2);
int LedRed6R2 = digitalRead (Red6R2);
int LedRed7R2 = digitalRead (Red7R2);
int LedRed8R2 = digitalRead (Red8R2);
int LedRed9R2 = digitalRead (Red9R2);


if (LedGreen0R1 != LastLedGreen0R1){
  if (LedGreen0R1 == LOW){
Serial.print ("Green 0 __");
Serial.println (LedGreen0R1);
  }
  else
  Serial.println ("off");
}


LastLedGreen0R1 = LedGreen0R1;

if (LedGreen0R1 == LOW && 
    LedGreen1R1 == HIGH && 
    LedGreen2R1 == HIGH && 
    LedGreen3R1 == HIGH && 
    LedGreen4R1 == HIGH && 
    LedGreen5R1 == HIGH && 
    LedGreen6R1 == HIGH && 
    LedGreen7R1 == HIGH && 
    LedGreen8R1 == HIGH && 
    LedGreen9R1 == HIGH &&  
    LedGreen0R2 == LOW && 
    LedGreen1R2 == HIGH && 
    LedGreen2R2 == HIGH && 
    LedGreen3R2 == HIGH && 
    LedGreen4R2 == HIGH && 
    LedGreen5R2 == HIGH && 
    LedGreen6R2 == HIGH && 
    LedGreen7R2 == HIGH && 
    LedGreen8R2 == HIGH && 
    LedGreen9R2 == HIGH &&  

    LedRed0R1 == LOW && 
    LedRed1R1 == HIGH && 
    LedRed2R1 == HIGH && 
    LedRed3R1 == HIGH && 
    LedRed4R1 == HIGH && 
    LedRed5R1 == HIGH && 
    LedRed6R1 == HIGH && 
    LedRed7R1 == HIGH && 
    LedRed8R1 == HIGH && 
    LedRed9R1 == HIGH &&  
    LedRed0R2 == LOW && 
    LedRed1R2 == HIGH && 
    LedRed2R2 == HIGH && 
    LedRed3R2 == HIGH && 
    LedRed4R2 == HIGH && 
    LedRed5R2 == HIGH && 
    LedRed6R2 == HIGH && 
    LedRed7R2 == HIGH && 
    LedRed8R2 == HIGH && 
    LedRed9R2 == HIGH )
    {
    digitalWrite (Trigger, LOW);
    }
    else digitalWrite (Trigger, HIGH);
    
 
  




 int WheelspinState = digitalRead (Wheelspin);
 
  if (WheelspinState != lastWheelspinState) {
    // if the state has changed, increment the counter
    if (WheelspinState == LOW) {
      // if the current state is LOW then the button went from off to on:
      WheelspinCounter++;
      Serial.println("on");
      Serial.print("number of Spin: ");
      Serial.println(WheelspinCounter);
      Serial.println (Spinlow - Spinhigh);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
   delay (50); // Delay a little bit to avoid bouncing
   
  }
  // save the current state as the last state, for next time through the loop

  

  

     Spinlow = millis();
  
 if (WheelspinCounter == 10 ){ 
  Spinhigh = millis();
  Serial.println (Spinlow - Spinhigh);
  WheelspinCounter = 0;}
  if ((Spinlow - Spinhigh) < 2000){
  Serial.println ("Relay turned on");
  digitalWrite (Pump,LOW);
  delay (2000);
  digitalWrite (Pump,HIGH);
  Serial.println ("Relay turned off");
  }

    
    lastWheelspinState = WheelspinState;
  
}

    

 






