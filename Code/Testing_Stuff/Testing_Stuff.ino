int Leds [6] = {2,3,4,5,6,7};
int LedCount = 6;
int timer = 100;
int Button = 8;
int LastButtonState = HIGH;
int ButtonCount = 0;

void setup() {
  // put your setup code here, to run once:
for( int Led = 0; Led < LedCount; Led++){
  pinMode (Leds [Led],OUTPUT);
} 
pinMode (Button,INPUT_PULLUP);
Serial.begin (9600);
Serial.println ("hey");
}

void loop() {
  int CurrentButtonState = digitalRead (Button);
 
Serial.println (ButtonCount);
delay (timer);

if (CurrentButtonState == LOW && LastButtonState == HIGH){
  digitalWrite (Leds[0],HIGH);
  ButtonCount++;
  delay (timer);
  LastButtonState = CurrentButtonState;}
  else LastButtonState = HIGH;
 
   
   

}



  
  
  
