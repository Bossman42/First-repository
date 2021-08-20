int led = 9;
int switchPin = 2;
int val;
int buttonCount = 0;

void setup () {

pinMode (led, OUTPUT);
pinMode (switchPin, INPUT_PULLUP);
}

void loop () {

val = digitalRead(switchPin);

if (val == LOW && buttonCount == 0);
    buttonCount++ && digitalWrite (led, LOW);
  }
  else {
     delay(500);
    digitalWrite(led, HIGH);
  }
}
else {
  buttonCount = 0; 
}
}



  
