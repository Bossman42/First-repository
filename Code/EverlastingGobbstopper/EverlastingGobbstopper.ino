int ChocolateBar = 2;
int GoldenEgg = 3;
int FizzyLiftingDrink = 4;
int ButtonLed = 5;
int StartButton = 6;
int GobstopperRelease = 7;
int MachineStuff = 8;
int OneTimeUse = 0;


void setup() {
pinMode (ChocolateBar, INPUT_PULLUP);
pinMode (GoldenEgg, INPUT_PULLUP);
pinMode (FizzyLiftingDrink, INPUT_PULLUP);
pinMode (ButtonLed, OUTPUT);
pinMode (StartButton, INPUT_PULLUP);
pinMode (GobstopperRelease, OUTPUT);
pinMode (MachineStuff, OUTPUT);

digitalWrite (ButtonLed, LOW);
digitalWrite (GobstopperRelease, HIGH);
digitalWrite (MachineStuff, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
int ChocolateBarS = digitalRead(ChocolateBar);
int GoldenEggS = digitalRead(GoldenEgg);
int FizzyLiftingDrinkS = digitalRead(FizzyLiftingDrink);
int StartButtonS = digitalRead(StartButton);

if (ChocolateBarS == LOW && GoldenEggS == LOW && FizzyLiftingDrinkS == LOW){
  digitalWrite (ButtonLed,HIGH);}
  else digitalWrite (ButtonLed,LOW);
if (ChocolateBarS == LOW && GoldenEggS == LOW && FizzyLiftingDrinkS == LOW && StartButtonS == LOW){
  OneTimeUse++;}
if (OneTimeUse == 1)  {
digitalWrite (ButtonLed,HIGH);
digitalWrite (MachineStuff,LOW);
delay (15000);
digitalWrite (GobstopperRelease, LOW);
delay (1000);
digitalWrite (GobstopperRelease, HIGH);
digitalWrite (MachineStuff, HIGH);
OneTimeUse++;
}
}


