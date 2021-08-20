int buttonPin = 4 ;    // the pin that the pushbutton is attached to
int ledPin = 6    ;       // the pin that the LED is attached to
        

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
Serial.begin(9600);
Serial.print ("hello");
}


void loop() {
int  buttonState = digitalRead(buttonPin);
delay(50);
  
  if (buttonState = LOW) {
    Serial.println("LOW");
   digitalWrite(ledPin, HIGH);
  }
 if (buttonState = HIGH) {
    Serial.println("HIGH");
    digitalWrite(ledPin, LOW);        
  }



//digitalWrite(ledPin,HIGH);
//delay(1000);
//digitalWrite(ledPin,LOW);
//delay(1000);
}
