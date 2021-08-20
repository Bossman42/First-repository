int button=2;
int led=13;
int lastbuttonState = 1;
int buttonState = 1;

void setup() {
  // put your setup code here, to run once:
pinMode (button,INPUT_PULLUP);
pinMode (led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(button);

  if (buttonState != lastbuttonState) {
    buttonState = lastbuttonState;
    digitalWrite (led, LOW);
    delay(1000);
   

     }
else
digitalWrite (led,HIGH);
}
