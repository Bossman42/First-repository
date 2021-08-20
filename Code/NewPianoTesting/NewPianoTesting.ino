int Debounce= 10; // Debounce Delay time
int MI = 2; // Alloable Mistakes when playing the song
int Complete = 0;  // They played the correct song



int Key1=2;
int Key2=3;
int Key3=4;
int Key4=5;
int Key5=6;
int Key6=7;
int Key7=8;
int Key8=9;
int Key9=10;
int Key10=11;
int Key11=12;
int Key12=13;
int Key13=14;
int Key14=15;
int Key15=16;
int Key16=17;
int Key17=18;
int Key18=19;
int Key19=20;
int Key20=21;
int Key21=22;
int Key22=23;
int Key23=24;
int KeyReset=25;

int Key1C=0;  // Counter for each Key
int Key2C=0;
int Key3C=0;
int Key4C=0;
int Key5C=0;
int Key6C=0;
int Key7C=0;
int Key8C=0;
int Key9C=0;
int Key10C=0;
int Key11C=0;
int Key12C=0;
int Key13C=0;
int Key14C=0;
int Key15C=0;
int Key16C=0;
int Key17C=0;
int Key18C=0;
int Key19C=0;
int Key20C=0;
int Key21C=0;
int Key22C=0;
int Key23C=0;
int KeyResetC=0;

int TotalC = 0;

int Key1L=0;// Last Key State
int Key2L=0;
int Key3L=0;
int Key4L=0;
int Key5L=0;
int Key6L=0;
int Key7L=0;
int Key8L=0;
int Key9L=0;
int Key10L=0;
int Key11L=0;
int Key12L=0;
int Key13L=0;
int Key14L=0;
int Key15L=0;
int Key16L=0;
int Key17L=0;
int Key18L=0;
int Key19L=0;
int Key20L=0;
int Key21L=0;
int Key22L=0;
int Key23L=0;
int KeyResetL=0;




void setup() {
  // put your setup code here, to run once:
pinMode (2,INPUT_PULLUP);
pinMode (3,INPUT_PULLUP);
pinMode (4,INPUT_PULLUP);
pinMode (5,INPUT_PULLUP);
pinMode (6,INPUT_PULLUP);
pinMode (7,INPUT_PULLUP);
pinMode (8,INPUT_PULLUP);
pinMode (9,INPUT_PULLUP);
pinMode (10,INPUT_PULLUP);
pinMode (11,INPUT_PULLUP);
pinMode (12,INPUT_PULLUP);
pinMode (13,INPUT_PULLUP);
pinMode (14,INPUT_PULLUP);
pinMode (15,INPUT_PULLUP);
pinMode (16,INPUT_PULLUP);
pinMode (17,INPUT_PULLUP);
pinMode (18,INPUT_PULLUP);
pinMode (19,INPUT_PULLUP);
pinMode (20,INPUT_PULLUP);
pinMode (21,INPUT_PULLUP);
pinMode (22,INPUT_PULLUP);
pinMode (23,INPUT_PULLUP);
pinMode (24,INPUT_PULLUP);
pinMode (25,INPUT_PULLUP);

Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:


int Key1S= digitalRead(Key1);
int Key2S= digitalRead(Key2);
int Key3S= digitalRead(Key3);
int Key4S= digitalRead(Key4);
int Key5S= digitalRead(Key5);
int Key6S= digitalRead(Key6);
int Key7S= digitalRead(Key7);
int Key8S= digitalRead(Key8);
int Key9S= digitalRead(Key9);
int Key10S= digitalRead(Key10);
int Key11S= digitalRead(Key11);
int Key12S= digitalRead(Key12);
int Key13S= digitalRead(Key13);
int Key14S= digitalRead(Key14);
int Key15S= digitalRead(Key15);
int Key16S= digitalRead(Key16);
int Key17S= digitalRead(Key17);
int Key18S= digitalRead(Key18);
int Key19S= digitalRead(Key19);
int Key20S= digitalRead(Key20);
int Key21S= digitalRead(Key21);
int Key22S= digitalRead(Key22);
int Key23S= digitalRead(Key23);
int KeyResetS= digitalRead(KeyReset);

if (Key1S != Key1L)
{if (Key1S == LOW)
{ Key1C++;
TotalC++;
Serial.print ("Key 1 Pressed  ");
Serial.println (Key1C);
Serial.println ("");}}
Key1L=Key1S;
delay (Debounce);

if (Key2S != Key2L)
{if (Key2S == LOW)
{ Key2C++;
TotalC++;
Serial.print ("Key 2 Pressed  ");
Serial.println (Key2C);
Serial.println ("");}}
Key2L=Key2S;
delay (Debounce);

if (Key3S != Key3L)
{if (Key3S == LOW)
{ Key3C++;
TotalC++;
Serial.print ("Key 3 Pressed  ");
Serial.println (Key3C);
Serial.println ("");}}
Key3L=Key3S;
delay (Debounce);

if (Key4S != Key4L)
{if (Key4S == LOW)
{ Key4C++;
TotalC++;
Serial.print ("Key 4 Pressed  ");
Serial.println (Key4C);
Serial.println ("");}}
Key4L=Key4S;
delay (Debounce);

if (Key5S != Key5L)
{if (Key5S == LOW)
{ Key5C++;
TotalC++;
Serial.print ("Key 5 Pressed  ");
Serial.println (Key5C);
Serial.println ("");}}
Key5L=Key5S;
delay (Debounce);

if (Key6S != Key6L)
{if (Key6S == LOW)
{ Key6C++;
TotalC++;
Serial.print ("Key 6 Pressed  ");
Serial.println (Key6C);
Serial.println ("");}}
Key6L=Key6S;
delay (Debounce);

if (Key7S != Key7L)
{if (Key7S == LOW)
{ Key7C++;
TotalC++;
Serial.print ("Key 7 Pressed  ");
Serial.println (Key7C);
Serial.println ("");}}
Key7L=Key7S;
delay (Debounce);

if (Key8S != Key8L)
{if (Key8S == LOW)
{ Key8C++;
TotalC++;
Serial.print ("Key 8 Pressed  ");
Serial.println (Key8C);
Serial.println ("");}}
Key8L=Key8S;
delay (Debounce);

if (Key9S != Key9L)
{if (Key9S == LOW)
{ Key9C++;
TotalC++;
Serial.print ("Key 9 Pressed  ");
Serial.println (Key9C);
Serial.println ("");}}
Key9L=Key9S;
delay (Debounce);

if (Key10S != Key10L)
{if (Key10S == LOW)
{ Key10C++;
TotalC++;
Serial.print ("Key 10 Pressed  ");
Serial.println (Key10C);
Serial.println ("");}}
Key10L=Key10S;
delay (Debounce);

if (Key11S != Key11L)
{if (Key11S == LOW)
{ Key11C++;
TotalC++;
Serial.print ("Key 11 Pressed  ");
Serial.println (Key11C);
Serial.println ("");}}
Key11L=Key11S;
delay (Debounce);

if (Key12S != Key12L)
{if (Key12S == LOW)
{ Key12C++;
TotalC++;
Serial.print ("Key 12 Pressed  ");
Serial.println (Key12C);
Serial.println ("");}}
Key12L=Key12S;
delay (Debounce);


if (Key13S != Key13L)
{if (Key13S == LOW)
{ Key13C++;
TotalC++;
Serial.print ("Key 13 Pressed  ");
Serial.println (Key13C);
Serial.println ("");}}
Key13L=Key13S;
delay (Debounce);

if (Key14S != Key14L)
{if (Key14S == LOW)
{ Key14C++;
TotalC++;
Serial.print ("Key 14 Pressed  ");
Serial.println (Key14C);
Serial.println ("");}}
Key14L=Key14S;
delay (Debounce);

if (Key15S != Key15L)
{if (Key15S == LOW)
{ Key15C++;
TotalC++;
Serial.print ("Key 15 Pressed  ");
Serial.println (Key15C);
Serial.println ("");}}
Key15L=Key15S;
delay (Debounce);

if (Key16S != Key16L)
{if (Key16S == LOW)
{ Key16C++;
TotalC++;
Serial.print ("Key 16 Pressed  ");
Serial.println (Key16C);
Serial.println ("");}}
Key16L=Key16S;
delay (Debounce);

if (Key17S != Key17L)
{if (Key17S == LOW)
{ Key17C++;
TotalC++;
Serial.print ("Key 17 Pressed  ");
Serial.println (Key17C);
Serial.println ("");}}
Key17L=Key17S;
delay (Debounce);

if (Key18S != Key18L)
{if (Key18S == LOW)
{ Key18C++;
TotalC++;
Serial.print ("Key 18 Pressed  ");
Serial.println (Key18C);
Serial.println ("");}}
Key18L=Key18S;
delay (Debounce);

if (Key19S != Key19L)
{if (Key19S == LOW)
{ Key19C++;
TotalC++;
Serial.print ("Key 19 Pressed  ");
Serial.println (Key19C);
Serial.println ("");}}
Key19L=Key19S;
delay (Debounce);

if (Key20S != Key20L)
{if (Key20S == LOW)
{ Key20C++;
TotalC++;
Serial.print ("Key 20 Pressed  ");
Serial.println (Key20C);
Serial.println ("");}}
Key20L=Key20S;
delay (Debounce);

if (Key21S != Key21L)
{if (Key21S == LOW)
{ Key21C++;
TotalC++;
Serial.print ("Key 21 Pressed  ");
Serial.println (Key21C);
Serial.println ("");}}
Key21L=Key21S;
delay (Debounce);

if (Key22S != Key22L)
{if (Key22S == LOW)
{ Key22C++;
TotalC++;
Serial.print ("Key 22 Pressed  ");
Serial.println (Key22C);
Serial.println ("");}}
Key22L=Key22S;
delay (Debounce);

if (Key23S != Key23L)
{if (Key23S == LOW)
{ Key23C++;
TotalC++;
Serial.print ("Key 23 Pressed  ");
Serial.println (Key23C);
Serial.println ("");
Serial.print ("Total ");
Serial.println (TotalC);
Serial.print ("");
Serial.println("");}}
Key23L=Key23S;
delay (Debounce);

if (KeyResetS != KeyResetL)
{if (KeyResetS == LOW)
{ Key1C = 0;
  Key2C = 0;
  Key3C = 0;
  Key4C = 0;
  Key5C = 0;
  Key6C = 0;
  Key7C = 0;
  Key8C = 0;
  Key9C = 0;
  Key10C = 0;
  Key11C = 0;
  Key12C = 0;
  Key13C = 0;
  Key14C = 0;
  Key15C = 0;
  Key16C = 0;
  Key17C = 0;
  Key18C = 0;
  Key19C = 0;
  Key20C = 0;
  Key21C = 0;
  Key22C = 0;
  Key23C = 0;
  TotalC=0;
Serial.print ("Key Reset Pressed  ");
Serial.print (KeyResetC);
Serial.print ("");
Serial.print ("Total reset on all keys");}}
KeyResetL=KeyResetS;
delay (Debounce);



if (Key1C == MI or Key2C == MI or Key3C == MI 
or Key4C == MI or Key6C == MI or Key7C == MI 
or Key9C == MI or Key10C == MI or Key11C == MI 
or Key12C == MI or Key13C == MI or Key14C == MI 
or Key15C == MI or Key17C == MI or Key18C == MI 
or Key19C == MI or Key22C == MI or Key23C == MI ){
  Serial.println ("Reset to 0");
  Serial.println ("");
  Key1C = 0;
  Key2C = 0;
  Key3C = 0;
  Key4C = 0;
  Key5C = 0;
  Key6C = 0;
  Key7C = 0;
  Key8C = 0;
  Key9C = 0;
  Key10C = 0;
  Key11C = 0;
  Key12C = 0;
  Key13C = 0;
  Key14C = 0;
  Key15C = 0;
  Key16C = 0;
  Key17C = 0;
  Key18C = 0;
  Key19C = 0;
  Key20C = 0;
  Key21C = 0;
  Key22C = 0;
  Key23C = 0;
  }
  if (Key5C == 3 && Key8C == 3 && Key16C == 3 
  && Key20C == 4 && Key21C == 3){
    Serial.println ("Release the Golden Egg");
    Complete++;
  Key1C = 0;
  Key2C = 0;
  Key3C = 0;
  Key4C = 0;
  Key5C = 0;
  Key6C = 0;
  Key7C = 0;
  Key8C = 0;
  Key9C = 0;
  Key10C = 0;
  Key11C = 0;
  Key12C = 0;
  Key13C = 0;
  Key14C = 0;
  Key15C = 0;
  Key16C = 0;
  Key17C = 0;
  Key18C = 0;
  Key19C = 0;
  Key20C = 0;
  Key21C = 0;
  Key22C = 0;
  Key23C = 0;
    delay (Debounce);
  }
if (Complete == 1 && TotalC >= 16){
  Serial.println ("Quack Quack Quack Quack");
  Complete++;
}
if (Complete == 0 && TotalC >= 22){
  Serial.println ("Quack");
  TotalC = 0;
  Key1C = 0;
  Key2C = 0;
  Key3C = 0;
  Key4C = 0;
  Key5C = 0;
  Key6C = 0;
  Key7C = 0;
  Key8C = 0;
  Key9C = 0;
  Key10C = 0;
  Key11C = 0;
  Key12C = 0;
  Key13C = 0;
  Key14C = 0;
  Key15C = 0;
  Key16C = 0;
  Key17C = 0;
  Key18C = 0;
  Key19C = 0;
  Key20C = 0;
  Key21C = 0;
  Key22C = 0;
  Key23C = 0;}
   

}
