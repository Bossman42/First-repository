#include "FastLED.h"
// How many leds in your strip?
#define NUM_LEDS 256
#define DATA_PIN 9

// Define the array of leds
CRGB leds[NUM_LEDS];
int Complete = 0;
int b=10;   // Delay  for button 
unsigned int i;
int Key1 = 2;   
int Key2 = 3;
int Key3 = 8; 
int Key4 = 5; 
int Key5 = 6;
int Key6 = 7;

unsigned int LastBPressed ;

int Trigger = A1;
int Key1L=1;
int Key2L=1;
int Key3L=1;
int Key4L=1;
int Key5L=1;
int Key6L=1;
unsigned int LedCounter= 0;
unsigned int Led1Counter = 0;
unsigned int Led2Counter = 0;
unsigned int Led3Counter = 0;
unsigned int Led4Counter = 0;
unsigned int Led5Counter = 0;
unsigned int Led6Counter = 0;
unsigned int CorrectCounter = 0;
unsigned int PressCounter = 0;

                 //Have to declare these before void setup

void setup() {

      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  
  pinMode(Key1, INPUT_PULLUP);//Key 1
  pinMode(Key2, INPUT_PULLUP);//Key 2
  pinMode(Key3, INPUT_PULLUP);//Key 3
  pinMode(Key4, INPUT_PULLUP);//Key 4
  pinMode(Key5, INPUT_PULLUP);//Key 5
  pinMode(Key6, INPUT_PULLUP);//Key 6



   pinMode(Trigger, OUTPUT);
               
   

digitalWrite(Trigger,HIGH);

  Serial.begin(9600);
  Serial.println("Yep");
  }


void loop() {
      FastLED.setBrightness(10);
      
  int Key1S = digitalRead(Key1);
  int Key2S = digitalRead(Key2);
  int Key3S = digitalRead(Key3);
  int Key4S = digitalRead(Key4);
  int Key5S = digitalRead(Key5);
  int Key6S = digitalRead(Key6);
  

  if (Key1S != Key1L) 
  {if (Key1S == LOW)
  {LedCounter ++;
  Led1Counter ++;
  PressCounter ++;
  delay (b);}}
  
  Key1L = Key1S;

   if (Key2S != Key2L) 
  {if (Key2S == LOW)
  {LedCounter ++;
  Led2Counter ++;
  PressCounter ++;
  delay (b);}}
  Key2L = Key2S;

    if (Key3S != Key3L) 
  {if (Key3S == LOW)
  {LedCounter ++;
  Led3Counter ++;
  PressCounter ++;
  delay (b);}}
  Key3L = Key3S;

    if (Key4S != Key4L) 
  {if (Key4S == LOW)
  {LedCounter ++;
  Led4Counter ++;
  PressCounter ++;
  delay (b);}}
  Key4L = Key4S;

      if (Key5S != Key5L) 
  {if (Key5S == LOW)
  {LedCounter ++;
  Led5Counter ++;
  PressCounter ++;
  delay (b);}}
  Key5L = Key5S;

    if (Key6S != Key6L) 
  {if (Key6S == LOW)
  {Led6Counter ++;
  PressCounter ++;
     {leds[244] = CRGB::Red;
    FastLED.show();;}
      {leds[245] = CRGB::Red;
    FastLED.show();;}
      {leds[250] = CRGB::Red;
    FastLED.show();;}
      {leds[251] = CRGB::Red;
    FastLED.show();;}
      {leds[252] = CRGB::Red;
    FastLED.show();;}
      {leds[253] = CRGB::Red;
    FastLED.show();;}
      {leds[254] = CRGB::Red;
    FastLED.show();;}
    delay (10);
      {leds[244] = CRGB::Black;
    FastLED.show();;}
      {leds[245] = CRGB::Black;
    FastLED.show();;}
      {leds[250] = CRGB::Black;
    FastLED.show();;}
      {leds[251] = CRGB::Black;
    FastLED.show();;}
      {leds[252] = CRGB::Black;
    FastLED.show();;}
      {leds[253] = CRGB::Black;
    FastLED.show();;}
      {leds[254] = CRGB::Black;
  }}}
  Key6L = Key6S;

  if (Led6Counter >= 3)
  {Led1Counter = 0;
  Led2Counter = 0;
  Led3Counter = 0;
  Led4Counter = 0;
  Led5Counter = 0;
  Led6Counter = 0;
  digitalWrite(Trigger,HIGH);
  CorrectCounter = 0;
  LedCounter = 0;
  PressCounter = 0;
 
 for (i = 0; i < 256; i++)                     //loop through the array
  {
    leds[i] = CRGB::Red;                       //set the color(LED) red
   FastLED.show();}
    delay (200);  
    
    for (i = 0; i < 256; i++)                     //loop through the array
  {
    leds[i] = CRGB::Black;                       //set the color(LED) red
    FastLED.show();}
    delay (20);  }
  
   switch (LedCounter){
      case 1:
     if (LedCounter == 1 &&
        Led1Counter == 1 && 
   Led2Counter == 0 &&
   Led3Counter == 0 &&
   Led4Counter == 0 &&
   Led5Counter == 0 &&
   Led6Counter <= 3 &&
   CorrectCounter == 0){
   CorrectCounter++; 

   {leds[6] = CRGB::Green;// 1st note
    FastLED.show();;}
      {leds[7] = CRGB::Green;
    FastLED.show();;}
      {leds[8] = CRGB::Green;
    FastLED.show();;}
      {leds[9] = CRGB::Green;
    FastLED.show();;}
      {leds[10] = CRGB::Green;
    FastLED.show();;}
      {leds[11] = CRGB::Green;
    FastLED.show();;}
      {leds[12] = CRGB::Green;
    FastLED.show();;}}
   else
   {leds[6] = CRGB::Red;// 1st note
    FastLED.show();;}
      {leds[7] = CRGB::Red;
    FastLED.show();;}
      {leds[8] = CRGB::Red;
    FastLED.show();;}
      {leds[9] = CRGB::Red;
    FastLED.show();;}
      {leds[10] = CRGB::Red;
    FastLED.show();;}
      {leds[11] = CRGB::Red;
    FastLED.show();;}
      {leds[12] = CRGB::Red;
    FastLED.show();;}

     
    //{leds[0] = CRGB::Red;
    //FastLED.show();;}
   
    break;
    case 2:
              if (LedCounter == 2 &&
        Led1Counter == 1 && 
   Led2Counter == 1 &&
   Led3Counter == 0 &&
   Led4Counter == 0 &&
   Led5Counter == 0 &&
   Led6Counter <= 3 &&
   CorrectCounter == 1){
   CorrectCounter++; 
   
   {leds[21] = CRGB::Green;
    FastLED.show();;}
      {leds[22] = CRGB::Green;
    FastLED.show();;}
      {leds[25] = CRGB::Green;
    FastLED.show();;}
      {leds[26] = CRGB::Green;
    FastLED.show();;}
      {leds[27] = CRGB::Green;
    FastLED.show();;}
      {leds[28] = CRGB::Green;
    FastLED.show();;}
      {leds[29] = CRGB::Green;
    FastLED.show();;}}
    else
      { {leds[21] = CRGB::Red;
    FastLED.show();;}
      {leds[22] = CRGB::Red;
    FastLED.show();;}
      {leds[25] = CRGB::Red;
    FastLED.show();;}
      {leds[26] = CRGB::Red;
    FastLED.show();;}
      {leds[27] = CRGB::Red;
    FastLED.show();;}
      {leds[28] = CRGB::Red;
    FastLED.show();;}
      {leds[29] = CRGB::Red;
    FastLED.show();;} }
    
    //{leds[15] = CRGB::Red;
    //FastLED.show();;}
    break;
    case 3:
    if (LedCounter == 3 &&
        Led1Counter == 1 && 
   Led2Counter == 1 &&
   Led3Counter == 1 &&
   Led4Counter == 0 &&
   Led5Counter == 0 &&
   Led6Counter <= 3 &&
   CorrectCounter == 2){
   CorrectCounter++;
   
   {leds[36] = CRGB::Green;
    FastLED.show();;}
      {leds[37] = CRGB::Green;
    FastLED.show();;}
      {leds[42] = CRGB::Green;
    FastLED.show();;}
      {leds[43] = CRGB::Green;
    FastLED.show();;}
      {leds[44] = CRGB::Green;
    FastLED.show();;}
      {leds[45] = CRGB::Green;
    FastLED.show();;}
      {leds[46] = CRGB::Green;
    FastLED.show();;}}
    else
    { {leds[36] = CRGB::Red;
    FastLED.show();;}
      {leds[37] = CRGB::Red;
    FastLED.show();;}
      {leds[42] = CRGB::Red;
    FastLED.show();;}
      {leds[43] = CRGB::Red;
    FastLED.show();;}
      {leds[44] = CRGB::Red;
    FastLED.show();;}
      {leds[45] = CRGB::Red;
    FastLED.show();;}
      {leds[46] = CRGB::Red;
    FastLED.show();;}  }

       
     //  {leds[16] = CRGB::Red;
    //FastLED.show();;} 
   
     break;
    case 4:
   {leds[54] = CRGB::White;
    FastLED.show();;}
      {leds[55] = CRGB::White;
    FastLED.show();;}
      {leds[56] = CRGB::White;
    FastLED.show();;}
      {leds[57] = CRGB::White;
    FastLED.show();;}
      {leds[58] = CRGB::White;
    FastLED.show();;}
      {leds[59] = CRGB::White;
    FastLED.show();;}
      {leds[60] = CRGB::White;
    FastLED.show();;}
          if (LedCounter == 4 &&
        Led1Counter == 2 && 
   Led2Counter == 1 &&
   Led3Counter == 1 &&
   Led4Counter == 0 &&
   Led5Counter == 0 &&
   Led6Counter <= 3 &&
   CorrectCounter == 3){
   CorrectCounter++;
   //    {leds[31] = CRGB::Red;
   // FastLED.show();;} 
   }
     break;
    case 5:
      {leds[69] = CRGB::White;
    FastLED.show();;}
      {leds[70] = CRGB::White;
    FastLED.show();;}
      {leds[73] = CRGB::White;
    FastLED.show();;}
      {leds[74] = CRGB::White;
    FastLED.show();;}
      {leds[75] = CRGB::White;
    FastLED.show();;}
      {leds[76] = CRGB::White;
    FastLED.show();;}
      {leds[77] = CRGB::White;
    FastLED.show();;} 
          if (LedCounter == 5 &&
        Led1Counter == 2 && 
   Led2Counter == 2 &&
   Led3Counter == 1 &&
   Led4Counter == 0 &&
   Led5Counter == 0 &&
   Led6Counter <= 3 &&
   CorrectCounter == 4){
   CorrectCounter++; 
   //    {leds[32] = CRGB::Red;
   // FastLED.show();;}
   }
     break;
    case 6:
     {leds[84] = CRGB::White;
    FastLED.show();;}
      {leds[85] = CRGB::White;
    FastLED.show();;}
      {leds[90] = CRGB::White;
    FastLED.show();;}
      {leds[91] = CRGB::White;
    FastLED.show();;}
      {leds[92] = CRGB::White;
    FastLED.show();;}
      {leds[93] = CRGB::White;
    FastLED.show();;}
      {leds[94] = CRGB::White;
    FastLED.show();;}
          if (LedCounter == 6 &&
        Led1Counter == 2 && 
   Led2Counter == 2 &&
   Led3Counter == 2 &&
   Led4Counter == 0 &&
   Led5Counter == 0 &&
   Led6Counter <= 3 &&
   CorrectCounter == 5){
   CorrectCounter++; 
    //   {leds[47] = CRGB::Red;
    //FastLED.show();;}
   }
     break;
    case 7:
    {leds[102] = CRGB::White;
    FastLED.show();;}
      {leds[103] = CRGB::White;
    FastLED.show();;}
      {leds[104] = CRGB::White;
    FastLED.show();;}
      {leds[105] = CRGB::White;
    FastLED.show();;}
      {leds[106] = CRGB::White;
    FastLED.show();;}
      {leds[107] = CRGB::White;
    FastLED.show();;}
      {leds[108] = CRGB::White;
    FastLED.show();;}
          if (LedCounter == 7 &&
        Led1Counter == 3 && 
   Led2Counter == 2 &&
   Led3Counter == 2 &&
   Led4Counter == 0 &&
   Led5Counter == 0 &&
   Led6Counter <= 3 &&
   CorrectCounter == 6){
   CorrectCounter++;
   //    {leds[48] = CRGB::Red;
   // FastLED.show();;} 
   }
     break;
    case 8:
   {leds[117] = CRGB::White;
    FastLED.show();;}
      {leds[118] = CRGB::White;
    FastLED.show();;}
      {leds[121] = CRGB::White;
    FastLED.show();;}
      {leds[122] = CRGB::White;
    FastLED.show();;}
      {leds[123] = CRGB::White;
    FastLED.show();;}
      {leds[124] = CRGB::White;
    FastLED.show();;}
      {leds[125] = CRGB::White;
    FastLED.show();;}
          if (LedCounter == 8 &&
        Led1Counter == 3 && 
   Led2Counter == 3 &&
   Led3Counter == 2 &&
   Led4Counter == 0 &&
   Led5Counter == 0 &&
   Led6Counter <= 3 &&
   CorrectCounter == 7){
   CorrectCounter++; 
  //     {leds[63] = CRGB::Red;
  //  FastLED.show();;}
   }
     break;
    case 9:
   {leds[131] = CRGB::White;
    FastLED.show();;}
      {leds[132] = CRGB::White;
    FastLED.show();;}
      {leds[139] = CRGB::White;
    FastLED.show();;}
      {leds[140] = CRGB::White;
    FastLED.show();;}
      {leds[141] = CRGB::White;
    FastLED.show();;}
      {leds[142] = CRGB::White;
    FastLED.show();;}
      {leds[143] = CRGB::White;
    FastLED.show();;}
          if (LedCounter == 9 &&
        Led1Counter == 3 && 
   Led2Counter == 3 &&
   Led3Counter == 2 &&
   Led4Counter == 1 &&
   Led5Counter == 0 &&
   Led6Counter <= 3 &&
   CorrectCounter == 8){
   CorrectCounter++;
   //    {leds[64] = CRGB::Red;
   // FastLED.show();;} 
   }

     break;
    case 10:
     {leds[148] = CRGB::White;
    FastLED.show();;}
      {leds[149] = CRGB::White;
    FastLED.show();;}
      {leds[154] = CRGB::White;
    FastLED.show();;}
      {leds[155] = CRGB::White;
    FastLED.show();;}
      {leds[156] = CRGB::White;
    FastLED.show();;}
      {leds[157] = CRGB::White;
    FastLED.show();;}
      {leds[158] = CRGB::White;
    FastLED.show();;}
          if (LedCounter == 10 &&
        Led1Counter == 3 && 
   Led2Counter == 3 &&
   Led3Counter == 2 &&
   Led4Counter == 1 &&
   Led5Counter == 1 &&
   Led6Counter <= 3 &&
   CorrectCounter == 9){
   CorrectCounter++; 
   //    {leds[79] = CRGB::Red;
   // FastLED.show();;}
   }
     break;
    case 11:
   {leds[163] = CRGB::White;
    FastLED.show();;}
      {leds[164] = CRGB::White;
    FastLED.show();;}
      {leds[171] = CRGB::White;
    FastLED.show();;}
      {leds[172] = CRGB::White;
    FastLED.show();;}
      {leds[173] = CRGB::White;
    FastLED.show();;}
      {leds[174] = CRGB::White;
    FastLED.show();;}
      {leds[175] = CRGB::White;
    FastLED.show();;}
          if (LedCounter == 11 &&
        Led1Counter == 3 && 
   Led2Counter == 3 &&
   Led3Counter == 2 &&
   Led4Counter == 2 &&
   Led5Counter == 1 &&
   Led6Counter <= 3 &&
   CorrectCounter == 10){
   CorrectCounter++; 
   //    {leds[80] = CRGB::Red;
   // FastLED.show();;}
   }
     break;
    case 12:
    {leds[180] = CRGB::White;
    FastLED.show();;}
      {leds[181] = CRGB::White;
    FastLED.show();;}
      {leds[186] = CRGB::White;
    FastLED.show();;}
      {leds[187] = CRGB::White;
    FastLED.show();;}
      {leds[188] = CRGB::White;
    FastLED.show();;}
      {leds[189] = CRGB::White;
    FastLED.show();;}
      {leds[190] = CRGB::White;
    FastLED.show();;}
          if (LedCounter == 12 &&
        Led1Counter == 3 && 
   Led2Counter == 3 &&
   Led3Counter == 2 &&
   Led4Counter == 2 &&
   Led5Counter == 2 &&
   Led6Counter <= 3 &&
   CorrectCounter == 11){
   CorrectCounter++; 
   //    {leds[95] = CRGB::Red;
   // FastLED.show();;}
   }
     break;
    case 13 :
     {leds[195] = CRGB::White;
    FastLED.show();;}
      {leds[196] = CRGB::White;
    FastLED.show();;}
      {leds[203] = CRGB::White;
    FastLED.show();;}
      {leds[204] = CRGB::White;
    FastLED.show();;}
      {leds[205] = CRGB::White;
    FastLED.show();;}
      {leds[206] = CRGB::White;
    FastLED.show();;}
      {leds[207] = CRGB::White;
    FastLED.show();;}
          if (LedCounter == 13 &&
        Led1Counter == 3 && 
   Led2Counter == 3 &&
   Led3Counter == 2 &&
   Led4Counter == 3 &&
   Led5Counter == 2 &&
   Led6Counter <= 3 &&
   CorrectCounter == 12){
   CorrectCounter++;
   //    {leds[96] = CRGB::Red;
   // FastLED.show();;} 
   }
     break;
    case 14:
    {leds[212] = CRGB::White;
    FastLED.show();;}
      {leds[213] = CRGB::White;
    FastLED.show();;}
      {leds[218] = CRGB::White;
    FastLED.show();;}
      {leds[219] = CRGB::White;
    FastLED.show();;}
      {leds[220] = CRGB::White;
    FastLED.show();;}
      {leds[221] = CRGB::White;
    FastLED.show();;}
      {leds[222] = CRGB::White;
    FastLED.show();;}
          if (LedCounter == 14 &&
        Led1Counter == 3 && 
   Led2Counter == 3 &&
   Led3Counter == 2 &&
   Led4Counter == 3 &&
   Led5Counter == 3 &&
   Led6Counter <= 3 &&
   CorrectCounter == 13){
   CorrectCounter++;
    //   {leds[111] = CRGB::Red;
   // FastLED.show();;} 
   }
     break;
    case 15:
     {leds[227] = CRGB::White;
    FastLED.show();;}
      {leds[228] = CRGB::White;
    FastLED.show();;}
      {leds[235] = CRGB::White;
    FastLED.show();;}
      {leds[236] = CRGB::White;
    FastLED.show();;}
      {leds[237] = CRGB::White;
    FastLED.show();;}
      {leds[238] = CRGB::White;
    FastLED.show();;}
      {leds[239] = CRGB::White;
    FastLED.show();;}
          if (LedCounter == 15 &&
        Led1Counter == 3 && 
   Led2Counter == 3 &&
   Led3Counter == 2 &&
   Led4Counter == 4 &&
   Led5Counter == 3 &&
   Led6Counter <= 3 &&
   CorrectCounter == 14){
   CorrectCounter++;
   // {leds[112] = CRGB::Red;
   // FastLED.show();;} 
   }
     break;
    case 16:
   
     
     {leds[244] = CRGB::White;
    FastLED.show();;}
      {leds[245] = CRGB::White;
    FastLED.show();;}
      {leds[250] = CRGB::White;
    FastLED.show();;}
      {leds[251] = CRGB::White;
    FastLED.show();;}
      {leds[252] = CRGB::White;
    FastLED.show();;}
      {leds[253] = CRGB::White;
    FastLED.show();;}
      {leds[254] = CRGB::White;
    FastLED.show();;}
    
   if (LedCounter == 16 &&
   Led1Counter == 3 && 
   Led2Counter == 3 &&
   Led3Counter == 3 &&
   Led4Counter == 4 &&
   Led5Counter == 3 &&
   Led6Counter <= 3 &&
   CorrectCounter == 15)
   
   {digitalWrite (Trigger,LOW);
    for (i = 0; i < 256; i++)                     //loop through the array
  { leds[i] = CRGB::Black;                       //set the color(LED) red
    FastLED.show();}
    {leds[35] = CRGB::Green;
    FastLED.show();;}
    {leds[36] = CRGB::Green;
    FastLED.show();;}
    {leds[42] = CRGB::Green;
    FastLED.show();;}
    {leds[43] = CRGB::Green;
    FastLED.show();;}
    {leds[44] = CRGB::Green;
    FastLED.show();;}
    {leds[45] = CRGB::Green;
    FastLED.show();;}
    {leds[49] = CRGB::Green;
    FastLED.show();;}
    {leds[50] = CRGB::Green;
    FastLED.show();;}
    {leds[51] = CRGB::Green;
    FastLED.show();;}
    {leds[52] = CRGB::Green;
    FastLED.show();;}
    {leds[53] = CRGB::Green;
    FastLED.show();;}
    {leds[54] = CRGB::Green;
    FastLED.show();;}
    {leds[56] = CRGB::Green;
    FastLED.show();;}
    {leds[57] = CRGB::Green;
    FastLED.show();;}
    {leds[58] = CRGB::Green;
    FastLED.show();;}
    {leds[59] = CRGB::Green;
    FastLED.show();;}
    {leds[60] = CRGB::Green;
    FastLED.show();;}
    {leds[61] = CRGB::Green;
    FastLED.show();;}
    {leds[62] = CRGB::Green;
    FastLED.show();;}
    {leds[63] = CRGB::Green;
    FastLED.show();;}
    {leds[65] = CRGB::Green;
    FastLED.show();;}
    {leds[66] = CRGB::Green;
    FastLED.show();;}
    {leds[67] = CRGB::Green;
    FastLED.show();;}
    {leds[68] = CRGB::Green;
    FastLED.show();;}
    {leds[69] = CRGB::Green;
    FastLED.show();;}
    {leds[70] = CRGB::Green;
    FastLED.show();;}
    {leds[74] = CRGB::Green;
    FastLED.show();;}
    {leds[75] = CRGB::Green;
    FastLED.show();;}
    {leds[76] = CRGB::Green;
    FastLED.show();;}
    {leds[77] = CRGB::Green;
    FastLED.show();;}
    {leds[84] = CRGB::Green;
    FastLED.show();;}
    {leds[83] = CRGB::Green;
    FastLED.show();;}
    {leds[91] = CRGB::Green;
    FastLED.show();;}
    {leds[92] = CRGB::Green;
    FastLED.show();;}
    {leds[100] = CRGB::Green;
    FastLED.show();;}
    {leds[99] = CRGB::Green;
    FastLED.show();;}
    {leds[107] = CRGB::Green;
    FastLED.show();;}
    {leds[108] = CRGB::Green;
    FastLED.show();;}
    {leds[115] = CRGB::Green;
    FastLED.show();;}
    {leds[116] = CRGB::Green;
    FastLED.show();;}
    {leds[123] = CRGB::Green;
    FastLED.show();;}
    {leds[124] = CRGB::Green;
    FastLED.show();;}
    {leds[132] = CRGB::Green;
    FastLED.show();;}
    {leds[131] = CRGB::Green;
    FastLED.show();;}
    {leds[139] = CRGB::Green;
    FastLED.show();;}
    {leds[140] = CRGB::Green;
    FastLED.show();;}
    {leds[145] = CRGB::Green;
    FastLED.show();;}
    {leds[146] = CRGB::Green;
    FastLED.show();;}
    {leds[147] = CRGB::Green;
    FastLED.show();;}
    {leds[148] = CRGB::Green;
    FastLED.show();;}
    {leds[155] = CRGB::Green;
    FastLED.show();;}
    {leds[156] = CRGB::Green;
    FastLED.show();;}
    {leds[164] = CRGB::Green;
    FastLED.show();;}
    {leds[163] = CRGB::Green;
    FastLED.show();;}
    {leds[162] = CRGB::Green;
    FastLED.show();;}
    {leds[161] = CRGB::Green;
    FastLED.show();;}
    {leds[171] = CRGB::Green;
    FastLED.show();;}
    {leds[172] = CRGB::Green;
    FastLED.show();;}
    {leds[180] = CRGB::Green;
    FastLED.show();;}
    {leds[179] = CRGB::Green;
    FastLED.show();;}
    {leds[178] = CRGB::Green;
    FastLED.show();;}
    {leds[187] = CRGB::Green;
    FastLED.show();;}
    {leds[188] = CRGB::Green;
    FastLED.show();;}
    
       
}
   
else
  {Led1Counter = 0;
  Led2Counter = 0;
  Led3Counter = 0;
  Led4Counter = 0;
  Led5Counter = 0;
  Led6Counter = 0;
  CorrectCounter = 0;
  digitalWrite(Trigger,HIGH);
  LedCounter = 0;
  PressCounter = 0;
 for (i = 0; i < 256; i++)                     //loop through the array
  {
    leds[i] = CRGB::Red;                       //set the color(LED) red
    FastLED.show();}
    delay (200);  
    
    for (i = 0; i < 256; i++)                     //loop through the array
  { leds[i] = CRGB::Black;                       //set the color(LED) red
    FastLED.show();}
    delay (20);  }}}
    


      


     


        
