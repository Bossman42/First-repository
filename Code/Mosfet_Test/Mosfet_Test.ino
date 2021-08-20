int Button1 = 2;
int Button2 = 3;
int Button3 = 4;
int Button4 = 5;
int Button5 = 6;
int Mosfet1 = 22;
int Mosfet2 = 23;
int Mosfet3 = 24;
int Mosfet4 = 25;
int Mosfet5 = 26;


void setup() {
  // put your setup code here, to run once:
pinMode (Button1, INPUT_PULLUP);
pinMode (Button2, INPUT_PULLUP);
pinMode (Button3, INPUT_PULLUP);
pinMode (Button4, INPUT_PULLUP);
pinMode (Button5, INPUT_PULLUP);
pinMode (Mosfet1, OUTPUT);
pinMode (Mosfet2, OUTPUT);
pinMode (Mosfet3, OUTPUT);
pinMode (Mosfet4, OUTPUT);
pinMode (Mosfet5, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int ButtonS1 = digitalRead (Button1);
int ButtonS2 = digitalRead (Button2);
int ButtonS3 = digitalRead (Button3);
int ButtonS4 = digitalRead (Button4);
int ButtonS5 = digitalRead (Button5);

if (ButtonS1 == LOW){
digitalWrite (Mosfet1, LOW);}
else digitalWrite (Mosfet1, HIGH);

if (ButtonS2 == LOW){
digitalWrite (Mosfet2, LOW);}
else digitalWrite (Mosfet2, HIGH);

if (ButtonS3 == LOW){
digitalWrite (Mosfet3, LOW);}
else digitalWrite (Mosfet3, HIGH);


if (ButtonS4 == LOW){
digitalWrite (Mosfet4, LOW);}
else digitalWrite (Mosfet4, HIGH);

if (ButtonS5 == LOW){
digitalWrite (Mosfet5, LOW);}
else digitalWrite (Mosfet5, HIGH);





}
