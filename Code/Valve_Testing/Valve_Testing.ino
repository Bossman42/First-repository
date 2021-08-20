int ValveSounds = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(ValveSounds, OUTPUT);//ValveSound2
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite (ValveSounds,HIGH);
delay (5000);
digitalWrite (ValveSounds,LOW);
delay (5000);
}
