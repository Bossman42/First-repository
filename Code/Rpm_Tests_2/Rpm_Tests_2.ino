

void setup() {
  // put your setup code here, to run once:
pinMode (A0,INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
 int sig = analogRead(A0);
 Serial.println (sig);
 delay (500);
}
