//bicycle
int Wheelspin = A8;

int WheelspinCounter = 0;
int WheelspinState = 0;
int lastWheelspinState = 0;
int Spinlow = 0;
int Spinhigh = 0;
int printcounter = 0;

void setup() {
pinMode (Wheelspin,INPUT_PULLUP);
Serial.begin (9600);
  
  // put your setup code here, to run once:

}

void loop() {
 int WheelspinState = digitalRead (Wheelspin);
  // put your main code here, to run repeatedly:
  if (WheelspinState != lastWheelspinState) {
    // if the state has changed, increment the counter
    if (WheelspinState == LOW) {
      // if the current state is LOW then the button went from off to on:
      WheelspinCounter++;
      Serial.println("on");
      Serial.print("number of Spin: ");
      Serial.println(WheelspinCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
   
  }
  // save the current state as the last state, for next time through the loop

  
if (WheelspinCounter > 10){
  (WheelspinCounter--);
  }
  
if (WheelspinState != lastWheelspinState){
  if (WheelspinState == LOW) 
  Spinlow = millis();
  
  }
 if (WheelspinState != lastWheelspinState)
  if (WheelspinState == HIGH){ 
  Spinhigh = millis();
  Serial.println (Spinlow - Spinhigh);}
    
    lastWheelspinState = WheelspinState;
  
}





