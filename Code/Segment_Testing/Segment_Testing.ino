int A = 2;
int B = 2;
int C = 2;
int B1 = 8;
int B2 = 9;
int B3 = 10;


void setup() {
  // put your setup code here, to run once:
pinMode (A, OUTPUT);
pinMode (B, OUTPUT);
pinMode (C, OUTPUT);
pinMode (B1, INPUT_PULLUP);
pinMode (B2, INPUT_PULLUP);
pinMode (B3, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly
  int B1Press = digitalRead (B1);
  int B2Press = digitalRead (B2);
  int B3Press = digitalRead (B3);
  if (B1Press == LOW)
  digitalWrite (A,LOW);}
  
  
  
