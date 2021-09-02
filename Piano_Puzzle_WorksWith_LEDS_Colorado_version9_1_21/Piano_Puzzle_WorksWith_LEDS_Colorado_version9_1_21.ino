#include "FastLED.h"


#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

byte mac[6] = { 0x90, 0xA2, 0xDA, 0xC2, 0x63, 0xB0 };  //Randomly generated

IPAddress ip(192, 168, 68, 185);
IPAddress server(192, 168, 68, 103);

String Led1_str; //see last code block below use these to convert the float that you get back from DHT to a string =str
String Led2_str;
String Led3_str;
String Led4_str;
String Led5_str;
String Led6_str;
String Correct_str;
String Press_str;
String Led_str;

char Led1[50];
char Led2[50];
char Led3[50];
char Led4[50];
char Led5[50];
char Led6[50];
char Correct[50];
char Press[50];
char Led[50];




// How many leds in your strip?
#define NUM_LEDS 256
#define DATA_PIN 9

// Define the array of leds
CRGB leds[NUM_LEDS];
int Complete = 0;
int b=10;   // Delay  for button 
unsigned int i;
int Key1 = 3;   
int Key2 = 6;
int Key3 = 2; 
int Key4 = 5; 
int Key5 = 7;
int Key6 = 8;

unsigned int LastBPressed ;

int Trigger = A3;
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

void callback(char* topic, byte* payload, unsigned int length);

EthernetClient ethClient;
PubSubClient client(server, 1883, callback, ethClient);


// Callback function
void callback(char* topic, byte* payload, unsigned int length) {

  //this is for communication from node red through mqtt if the payload is '0' and publish to the MQTT server a confirmation message
  if (payload[0] == '0'){

  Led1Counter = 0;
  Led2Counter = 0;
  Led3Counter = 0;
  Led4Counter = 0;
  Led5Counter = 0;
  Led6Counter = 0;
  CorrectCounter = 0;
  LedCounter = 0;
  PressCounter = 0;
  client.publish("outTopic", "Puzzle Reset"); 
    }

  //this is for communication from node red through mqtt if the payload is '0' and publish to the MQTT server a confirmation message
  if (payload[0] == '1'){




    Led1_str = String(Led1Counter); //converting Led1Counter (the float variable above) to a string 
    Led1_str.toCharArray(Led1, Led1_str.length() + 1); //packaging up the data to publish to mqtt whoa...

    Led2_str = String(Led2Counter); //converting Led1Counter (the float variable above) to a string 
    Led2_str.toCharArray(Led2, Led2_str.length() + 1); //packaging up the data to publish to mqtt whoa...

    Led3_str = String(Led3Counter); //converting Led1Counter (the float variable above) to a string 
    Led3_str.toCharArray(Led3, Led3_str.length() + 1); //packaging up the data to publish to mqtt whoa...

    Led4_str = String(Led4Counter); //converting Led1Counter (the float variable above) to a string 
    Led4_str.toCharArray(Led4, Led4_str.length() + 1); //packaging up the data to publish to mqtt whoa...

    Led5_str = String(Led5Counter); //converting Led1Counter (the float variable above) to a string 
    Led5_str.toCharArray(Led5, Led5_str.length() + 1); //packaging up the data to publish to mqtt whoa...

    Led6_str = String(Led6Counter); //converting Led1Counter (the float variable above) to a string 
    Led6_str.toCharArray(Led6, Led6_str.length() + 1); //packaging up the data to publish to mqtt whoa...

    Correct_str = String(CorrectCounter); //converting Led1Counter (the float variable above) to a string 
    Correct_str.toCharArray(Correct, Correct_str.length() + 1); //packaging up the data to publish to mqtt whoa...

    Press_str = String(PressCounter); //converting Led1Counter (the float variable above) to a string 
    Press_str.toCharArray(Press, Press_str.length() + 1); //packaging up the data to publish to mqtt whoa...

    Led_str = String(LedCounter); //converting Led1Counter (the float variable above) to a string 
    Led_str.toCharArray(Led, Led_str.length() + 1); //packaging up the data to publish to mqtt whoa...
    
    client.publish("outTopic", "Debug");
  
    client.publish("outTopic", Led1); //money shot
    
    client.publish("outTopic", Led2); //money shot
   
    client.publish("outTopic", Led3); //money shot
 
    client.publish("outTopic", Led4); //money shot
   
    client.publish("outTopic", Led5); //money shot
   
    client.publish("outTopic", Led6); //money shot
    client.publish("outTopic", Correct); //money shot
    
    client.publish("outTopic", Press); //money shot
    client.publish("outTopic", "LedCounter");
    client.publish("outTopic", Led); //money shot
  
    }



   
    }
 // void callback
                 

void setup() {

      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  
  pinMode(Key1, INPUT_PULLUP);//Key 1
  pinMode(Key2, INPUT_PULLUP);//Key 2
  pinMode(Key3, INPUT_PULLUP);//Key 3
  pinMode(Key4, INPUT_PULLUP);//Key 4
  pinMode(Key5, INPUT_PULLUP);//Key 5
  pinMode(Key6, INPUT_PULLUP);//Key 6  Incorrect Key

  

  Ethernet.begin(mac, ip);
  if (client.connect("arduinoClient")) {
    client.publish("outTopic","hello world");
    client.subscribe("inTopic");
  }


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
  client.publish("outTopic", "Key 1 Pressed");
  delay (b);}}
  
  Key1L = Key1S;

   if (Key2S != Key2L) 
  {if (Key2S == LOW)
  {LedCounter ++;
  Led2Counter ++;
  PressCounter ++;
  client.publish("outTopic", "Key 2 Pressed");
  delay (b);}}
  Key2L = Key2S;

    if (Key3S != Key3L) 
  {if (Key3S == LOW)
  {LedCounter ++;
  Led3Counter ++;
  PressCounter ++;
  client.publish("outTopic", "Key 3 Pressed");
  delay (b);}}
  Key3L = Key3S;

    if (Key4S != Key4L) 
  {if (Key4S == LOW)
  {LedCounter ++;
  Led4Counter ++;
  PressCounter ++;
  client.publish("outTopic", "Key 4 Pressed");
  delay (b);}}
  Key4L = Key4S;

      if (Key5S != Key5L) 
  {if (Key5S == LOW)
  {LedCounter ++;
  Led5Counter ++;
  PressCounter ++;
  client.publish("outTopic", "Key 5 Pressed");
  delay (b);}}
  Key5L = Key5S;

    if (Key6S != Key6L) 
  {if (Key6S == LOW)
  {Led6Counter ++;
  PressCounter ++;
  client.publish("outTopic", "Incorrect Key Pressed");
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


  if (CorrectCounter == 15 || LedCounter >= 15){
  Led6Counter = 4;}

  if (Led6Counter >= 3)
  {
 Led_str = String(LedCounter); //converting Led1Counter (the float variable above) to a string 
    Led_str.toCharArray(Led, Led_str.length() + 1); //packaging up the data to publish to mqtt whoa...
    
        client.publish("outTopic", "LedCounter");
    client.publish("outTopic", Led); //money shot
  Led1Counter = 0;
  Led2Counter = 0;
  Led3Counter = 0;
  Led4Counter = 0;
  Led5Counter = 0;
  Led6Counter = 0;
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
    leds[i] = CRGB::Black;                       //set the color(LED) off
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
   client.publish("outTopic", "correct 3");

   leds[6] = CRGB::Green;// 1st note
  //  FastLED.show();;}
      leds[7] = CRGB::Green;
  //  FastLED.show();;}
      leds[8] = CRGB::Green;
  //  FastLED.show();;}
      leds[9] = CRGB::Green;
  //  FastLED.show();;}
      leds[10] = CRGB::Green;
  //  FastLED.show();;}
      leds[11] = CRGB::Green;
  //  FastLED.show();;}
      leds[12] = CRGB::Green;
    FastLED.show();;}
if (CorrectCounter == 0){
  Led6Counter = 4;
}
   
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
   client.publish("outTopic", "correct 2");
   
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
if (CorrectCounter == 1){
  Led6Counter = 4;
}
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
   client.publish("outTopic", "correct 3");
   
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
    FastLED.show();;} }

if (CorrectCounter == 2){
  Led6Counter = 4;
}
   
     break;
    case 4:
            if (LedCounter == 4 &&
        Led1Counter == 2 && 
   Led2Counter == 1 &&
   Led3Counter == 1 &&
   Led4Counter == 0 &&
   Led5Counter == 0 &&
   Led6Counter <= 3 &&
   CorrectCounter == 3){
   CorrectCounter++;
   client.publish("outTopic", "correct 4");
   
   {leds[54] = CRGB::Green;
    FastLED.show();;}
      {leds[55] = CRGB::Green;
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
   }
   
if (CorrectCounter == 3){
  Led6Counter = 4;
}
   
     break;
    case 5:
          if (LedCounter == 5 &&
        Led1Counter == 2 && 
   Led2Counter == 2 &&
   Led3Counter == 1 &&
   Led4Counter == 0 &&
   Led5Counter == 0 &&
   Led6Counter <= 3 &&
   CorrectCounter == 4){
   CorrectCounter++; 
      client.publish("outTopic", "correct 5");
      {leds[69] = CRGB::Green;
    FastLED.show();;}
      {leds[70] = CRGB::Green;
    FastLED.show();;}
      {leds[73] = CRGB::Green;
    FastLED.show();;}
      {leds[74] = CRGB::Green;
    FastLED.show();;}
      {leds[75] = CRGB::Green;
    FastLED.show();;}
      {leds[76] = CRGB::Green;
    FastLED.show();;}
      {leds[77] = CRGB::Green;
    FastLED.show();;} }


   if (CorrectCounter == 4){
  Led6Counter = 4;
}
     break;
    case 6:
           if (LedCounter == 6 &&
        Led1Counter == 2 && 
   Led2Counter == 2 &&
   Led3Counter == 2 &&
   Led4Counter == 0 &&
   Led5Counter == 0 &&
   Led6Counter <= 3 &&
   CorrectCounter == 5){
   CorrectCounter++; 
client.publish("outTopic", "correct 6");
     
     {leds[84] = CRGB::Green;
    FastLED.show();;}
      {leds[85] = CRGB::Green;
    FastLED.show();;}
      {leds[90] = CRGB::Green;
    FastLED.show();;}
      {leds[91] = CRGB::Green;
    FastLED.show();;}
      {leds[92] = CRGB::Green;
    FastLED.show();;}
      {leds[93] = CRGB::Green;
    FastLED.show();;}
      {leds[94] = CRGB::Green;
    FastLED.show();;}
   }

if (CorrectCounter == 5){
  Led6Counter = 4;
}

   
     break;
    case 7:
           if (LedCounter == 7 &&
        Led1Counter == 3 && 
   Led2Counter == 2 &&
   Led3Counter == 2 &&
   Led4Counter == 0 &&
   Led5Counter == 0 &&
   Led6Counter <= 3 &&
   CorrectCounter == 6){
   CorrectCounter++;
    client.publish("outTopic", "correct 7");
    {leds[102] = CRGB::Green;
    FastLED.show();;}
      {leds[103] = CRGB::Green;
    FastLED.show();;}
      {leds[104] = CRGB::Green;
    FastLED.show();;}
      {leds[105] = CRGB::Green;
    FastLED.show();;}
      {leds[106] = CRGB::Green;
    FastLED.show();;}
      {leds[107] = CRGB::Green;
    FastLED.show();;}
      {leds[108] = CRGB::Green;
    FastLED.show();;}}
   if (CorrectCounter == 6){
  Led6Counter = 4;
}

     break;
    case 8:
           if (LedCounter == 8 &&
        Led1Counter == 3 && 
   Led2Counter == 3 &&
   Led3Counter == 2 &&
   Led4Counter == 0 &&
   Led5Counter == 0 &&
   Led6Counter <= 3 &&
   CorrectCounter == 7){
   CorrectCounter++; 
   client.publish("outTopic", "correct 8");
   
   {leds[117] = CRGB::Green;
    FastLED.show();;}
      {leds[118] = CRGB::Green;
    FastLED.show();;}
      {leds[121] = CRGB::Green;
    FastLED.show();;}
      {leds[122] = CRGB::Green;
    FastLED.show();;}
      {leds[123] = CRGB::Green;
    FastLED.show();;}
      {leds[124] = CRGB::Green;
    FastLED.show();;}
      {leds[125] = CRGB::Green;
    FastLED.show();;}}
   if (CorrectCounter == 7){
  Led6Counter = 4;
}

     break;
    case 9:
           if (LedCounter == 9 &&
        Led1Counter == 3 && 
   Led2Counter == 3 &&
   Led3Counter == 2 &&
   Led4Counter == 1 &&
   Led5Counter == 0 &&
   Led6Counter <= 3 &&
   CorrectCounter == 8){
   CorrectCounter++;
   client.publish("outTopic", "correct 9");
   {leds[131] = CRGB::Green;
    FastLED.show();;}
      {leds[132] = CRGB::Green;
    FastLED.show();;}
      {leds[139] = CRGB::Green;
    FastLED.show();;}
      {leds[140] = CRGB::Green;
    FastLED.show();;}
      {leds[141] = CRGB::Green;
    FastLED.show();;}
      {leds[142] = CRGB::Green;
    FastLED.show();;}
      {leds[143] = CRGB::Green;
    FastLED.show();;}}
   if (CorrectCounter == 8){
  Led6Counter = 4;
}


     break;
    case 10:
           if (LedCounter == 10 &&
        Led1Counter == 3 && 
   Led2Counter == 3 &&
   Led3Counter == 2 &&
   Led4Counter == 1 &&
   Led5Counter == 1 &&
   Led6Counter <= 3 &&
   CorrectCounter == 9){
   CorrectCounter++; 
     client.publish("outTopic", "correct 10");
     {leds[148] = CRGB::Green;
    FastLED.show();;}
      {leds[149] = CRGB::Green;
    FastLED.show();;}
      {leds[154] = CRGB::Green;
    FastLED.show();;}
      {leds[155] = CRGB::Green;
    FastLED.show();;}
      {leds[156] = CRGB::Green;
    FastLED.show();;}
      {leds[157] = CRGB::Green;
    FastLED.show();;}
      {leds[158] = CRGB::Green;
    FastLED.show();;}}
   if (CorrectCounter == 9){
  Led6Counter = 4;
}

     break;
    case 11:
          if (LedCounter == 11 &&
        Led1Counter == 3 && 
   Led2Counter == 3 &&
   Led3Counter == 2 &&
   Led4Counter == 2 &&
   Led5Counter == 1 &&
   Led6Counter <= 3 &&
   CorrectCounter == 10){
   CorrectCounter++; 
   client.publish("outTopic", "correct 11");
   {leds[163] = CRGB::Green;
    FastLED.show();;}
      {leds[164] = CRGB::Green;
    FastLED.show();;}
      {leds[171] = CRGB::Green;
    FastLED.show();;}
      {leds[172] = CRGB::Green;
    FastLED.show();;}
      {leds[173] = CRGB::Green;
    FastLED.show();;}
      {leds[174] = CRGB::Green;
    FastLED.show();;}
      {leds[175] = CRGB::Green;
    FastLED.show();;}}
   if (CorrectCounter == 10){
  Led6Counter = 4;
}

     break;
    case 12:
            if (LedCounter == 12 &&
        Led1Counter == 3 && 
   Led2Counter == 3 &&
   Led3Counter == 2 &&
   Led4Counter == 2 &&
   Led5Counter == 2 &&
   Led6Counter <= 3 &&
   CorrectCounter == 11){
   CorrectCounter++; 
    client.publish("outTopic", "correct 12");
    {leds[180] = CRGB::Green;
    FastLED.show();;}
      {leds[181] = CRGB::Green;
    FastLED.show();;}
      {leds[186] = CRGB::Green;
    FastLED.show();;}
      {leds[187] = CRGB::Green;
    FastLED.show();;}
      {leds[188] = CRGB::Green;
    FastLED.show();;}
      {leds[189] = CRGB::Green;
    FastLED.show();;}
      {leds[190] = CRGB::Green;
    FastLED.show();;}}
   if (CorrectCounter == 11){
  Led6Counter = 4;
}

     break;
    case 13 :
   if (LedCounter == 13 &&
   Led1Counter == 3 && 
   Led2Counter == 3 &&
   Led3Counter == 2 &&
   Led4Counter == 3 &&
   Led5Counter == 2 &&
   Led6Counter <= 3 &&
   CorrectCounter == 12){
   CorrectCounter++;
     client.publish("outTopic", "correct 13");
     {leds[195] = CRGB::Green;
    FastLED.show();;}
      {leds[196] = CRGB::Green;
    FastLED.show();;}
      {leds[203] = CRGB::Green;
    FastLED.show();;}
      {leds[204] = CRGB::Green;
    FastLED.show();;}
      {leds[205] = CRGB::Green;
    FastLED.show();;}
      {leds[206] = CRGB::Green;
    FastLED.show();;}
      {leds[207] = CRGB::Green;
    FastLED.show();;}}
       if (CorrectCounter == 12){
  Led6Counter = 4;
}


     break;
    case 14:
           if (LedCounter == 14 &&
        Led1Counter == 3 && 
   Led2Counter == 3 &&
   Led3Counter == 2 &&
   Led4Counter == 3 &&
   Led5Counter == 3 &&
   Led6Counter <= 3 &&
   CorrectCounter == 13){
   CorrectCounter++;
    client.publish("outTopic", "correct 14");
    {leds[212] = CRGB::Green;
    FastLED.show();;}
      {leds[213] = CRGB::Green;
    FastLED.show();;}
      {leds[218] = CRGB::Green;
    FastLED.show();;}
      {leds[219] = CRGB::Green;
    FastLED.show();;}
      {leds[220] = CRGB::Green;
    FastLED.show();;}
      {leds[221] = CRGB::Green;
    FastLED.show();;}
      {leds[222] = CRGB::Green;
    FastLED.show();;}}
   if (CorrectCounter == 13){
  Led6Counter = 4;
}

     break;
    case 15:
           if (LedCounter == 15 &&
        Led1Counter == 3 && 
   Led2Counter == 3 &&
   Led3Counter == 2 &&
   Led4Counter == 4 &&
   Led5Counter == 3 &&
   Led6Counter <= 3 &&
   CorrectCounter == 14){
   CorrectCounter++;
     client.publish("outTopic", "correct 15");
     {leds[227] = CRGB::Green;
    FastLED.show();;}
      {leds[228] = CRGB::Green;
    FastLED.show();;}
      {leds[235] = CRGB::Green;
    FastLED.show();;}
      {leds[236] = CRGB::Green;
    FastLED.show();;}
      {leds[237] = CRGB::Green;
    FastLED.show();;}
      {leds[238] = CRGB::Green;
    FastLED.show();;}
      {leds[239] = CRGB::Green;
    FastLED.show();;}}
   if (CorrectCounter == 14){
  Led6Counter = 4;
}

     break;
    case 16:
     if (LedCounter == 16 &&
   Led1Counter == 3 && 
   Led2Counter == 3 &&
   Led3Counter == 3 &&
   Led4Counter == 4 &&
   Led5Counter == 3 &&
   Led6Counter <= 3 &&
   CorrectCounter == 15){ 
     client.publish("outTopic", "correct 16");
     {leds[244] = CRGB::Green;
    FastLED.show();;}
      {leds[245] = CRGB::Green;
    FastLED.show();;}
      {leds[250] = CRGB::Green;
    FastLED.show();;}
      {leds[251] = CRGB::Green;
    FastLED.show();;}
      {leds[252] = CRGB::Green;
    FastLED.show();;}
      {leds[253] = CRGB::Green;
    FastLED.show();;}
      {leds[254] = CRGB::Green;
    FastLED.show();;}
     

   
   {   client.publish("outTopic", "Puzzle Solved");
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
    delay (3000);

  {Led1Counter = 0;
  Led2Counter = 0;
  Led3Counter = 0;
  Led4Counter = 0;
  Led5Counter = 0;
  Led6Counter = 0;
  CorrectCounter = 0;

  client.publish("outTopic", "Puzzle Reset");
  LedCounter = 0;
  PressCounter = 0;
 for (i = 0; i < 256; i++)                     //loop through the array
  {
    leds[i] = CRGB::Green;                       //set the color(LED) red
    FastLED.show();}
    delay (200);  
    
    for (i = 0; i < 256; i++)                     //loop through the array
  { leds[i] = CRGB::Black;                       //set the color(LED) red
    FastLED.show();}
    delay (20);  }



    
       
}}
  if (CorrectCounter == 15 || LedCounter >= 17){
  Led6Counter = 4;}
   
/* else
  {Led1Counter = 0;
  Led2Counter = 0;
  Led3Counter = 0;
  Led4Counter = 0;
  Led5Counter = 0;
  Led6Counter = 0;
  CorrectCounter = 0;
  digitalWrite(Trigger,HIGH);
  client.publish("outTopic", "Puzzle Reset");
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
    delay (20);  }}
*/
   }
   client.loop();  // refresh mqtt publish/subscribe 
    }
    
    
    
    

    


      


     


        
