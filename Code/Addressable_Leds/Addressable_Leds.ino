#include "FastLED.h"
int Delay = 1000;
// How many leds in your strip?
#define NUM_LEDS 150
int Peddle = 1;
int Button = 4;
int Combo = 5;
int LedPosition = 0;

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 3
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  pinMode (Button,INPUT_PULLUP);
  pinMode (Combo,INPUT_PULLUP);
      // Uncomment/edit one of the following lines for your leds arrangement.
      // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
      // FastLED.addLeds<APA104, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<GW6205, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<GW6205_400, DATA_PIN, RGB>(leds, NUM_LEDS);
      
      // FastLED.addLeds<WS2801, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<P9813, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<APA102, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<DOTSTAR, RGB>(leds, NUM_LEDS);

      // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
int  Delay = (300);   // delay for leds to turn on while pedaling
int  Delay2 = (500); // delay for leds to turn off when not peddaling
int  Delay3 = (500); // flashing leds when combo is entered correctly


int  ButtonS = digitalRead (Button);
int  ComboS = digitalRead (Combo);
 // Number 2
if (ButtonS == LOW){
Peddle = 0;}
else Peddle = 1; 


if (ComboS == LOW){
  
if (LedPosition == 0){
    {leds[25] = CRGB::White;
    FastLED.show();;}
    {leds[26] = CRGB::White;
    FastLED.show();;}
    {leds[27] = CRGB::White;
    FastLED.show();;}
    {leds[28] = CRGB::White;
    FastLED.show();;}
    {leds[29] = CRGB::White;
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
    {leds[85] = CRGB::White;
    FastLED.show();;}
    {leds[86] = CRGB::White;
    FastLED.show();;}
    {leds[87] = CRGB::White;
    FastLED.show();;}
    {leds[88] = CRGB::White;
    FastLED.show();;}
    {leds[89] = CRGB::White;
    FastLED.show();;}
    {leds[115] = CRGB::White;
    FastLED.show();;}
    {leds[116] = CRGB::White;
    FastLED.show();;}
    {leds[117] = CRGB::White;
    FastLED.show();;}
    {leds[118] = CRGB::White;
    FastLED.show();;}
    {leds[119] = CRGB::White;
    FastLED.show();;}
delay (Delay3);
    {leds[25] = CRGB::Black;
    FastLED.show();;}
    {leds[26] = CRGB::Black;
    FastLED.show();;}
    {leds[27] = CRGB::Black;
    FastLED.show();;}
    {leds[28] = CRGB::Black;
    FastLED.show();;}
    {leds[29] = CRGB::Black;
    FastLED.show();;}
    {leds[55] = CRGB::Black;
    FastLED.show();;}
    {leds[56] = CRGB::Black;
    FastLED.show();;}
    {leds[57] = CRGB::Black;
    FastLED.show();;}
    {leds[58] = CRGB::Black;
    FastLED.show();;}
    {leds[59] = CRGB::Black;
    FastLED.show();;}
    {leds[85] = CRGB::Black;
    FastLED.show();;}
    {leds[86] = CRGB::Black;
    FastLED.show();;}
    {leds[87] = CRGB::Black;
    FastLED.show();;}
    {leds[88] = CRGB::Black;
    FastLED.show();;}
    {leds[89] = CRGB::Black;
    FastLED.show();;}
    {leds[115] = CRGB::Black;
    FastLED.show();;}
    {leds[116] = CRGB::Black;
    FastLED.show();;}
    {leds[117] = CRGB::Black;
    FastLED.show();;}
    {leds[118] = CRGB::Black;
    FastLED.show();;}
    {leds[119] = CRGB::Black;
    FastLED.show();;}
delay (Delay3);}
else

    {leds[25] = CRGB::White;
    FastLED.show();;}
    {leds[26] = CRGB::White;
    FastLED.show();;}
    {leds[27] = CRGB::White;
    FastLED.show();;}
    {leds[28] = CRGB::White;
    FastLED.show();;}
    {leds[29] = CRGB::White;
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
    {leds[85] = CRGB::White;
    FastLED.show();;}
    {leds[86] = CRGB::White;
    FastLED.show();;}
    {leds[87] = CRGB::White;
    FastLED.show();;}
    {leds[88] = CRGB::White;
    FastLED.show();;}
    {leds[89] = CRGB::White;
    FastLED.show();;}
    {leds[115] = CRGB::White;
    FastLED.show();;}
    {leds[116] = CRGB::White;
    FastLED.show();;}
    {leds[117] = CRGB::White;
    FastLED.show();;}
    {leds[118] = CRGB::White;
    FastLED.show();;}
    {leds[119] = CRGB::White;
    FastLED.show();;}




//  NUMBER  2
   
  if (Peddle == 0 && LedPosition == 0)
  {leds[120] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else 
  if (Peddle == 0 && LedPosition == 1)
  {leds[121] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else 
  if (Peddle == 0 && LedPosition == 2)
  {leds[122] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 3)
  {leds[123] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else 
  if (Peddle == 0 && LedPosition == 4)
  {leds[124] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else 
  if (Peddle == 0 && LedPosition == 5)
  {leds[125] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 6)
  {leds[109] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else 
  if (Peddle == 0 && LedPosition == 7)
  {leds[65] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else 
  if (Peddle == 0 && LedPosition == 8)
  {leds[64] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 9)
  {leds[63] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else 
  if (Peddle == 0 && LedPosition == 10)
  {leds[62] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else 
  if (Peddle == 0 && LedPosition == 11)
  {leds[61] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 12)
  {leds[60] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else 
  if (Peddle == 0 && LedPosition == 13)
  {leds[54] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else 
  if (Peddle == 0 && LedPosition == 14)
  {leds[0] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 15)
  {leds[1] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else 
  if (Peddle == 0 && LedPosition == 16)
  {leds[1] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else 
  if (Peddle == 0 && LedPosition == 17)
  {leds[2] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 18)
  {leds[3] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else 
  if (Peddle == 0 && LedPosition == 19)
  {leds[4] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else 
  if (Peddle == 0 && LedPosition == 20)
  {leds[5] = CRGB::Blue;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}


// NUMBER 9

  
else
  if (Peddle == 0 && LedPosition == 21)
  {leds[11] = CRGB::Green;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 22)
  {leds[43] = CRGB::Green;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 23)
  {leds[71] = CRGB::Green;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 24)
  {leds[103] = CRGB::Green;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 25)
  {leds[131] = CRGB::Green;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 26)
  {leds[130] = CRGB::Green;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 27)
  {leds[129] = CRGB::Green;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 28)
  {leds[128] = CRGB::Green;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 29)
  {leds[127] = CRGB::Green;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 30)
  {leds[126] = CRGB::Green;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 31)
  {leds[108] = CRGB::Green;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 32)
  {leds[66] = CRGB::Green;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 33)
  {leds[67] = CRGB::Green;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 34)
  {leds[68] = CRGB::Green;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 35)
  {leds[69] = CRGB::Green;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 36)
  {leds[70] = CRGB::Green;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}

// NUMBER 7


else
  if (Peddle == 0 && LedPosition == 37)
  {leds[17] = CRGB::White;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 38)
  {leds[37] = CRGB::White;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 39)
  {leds[77] = CRGB::White;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 40)
  {leds[97] = CRGB::White;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 41)
  {leds[137] = CRGB::White;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 42)
  {leds[136] = CRGB::White;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 43)
  {leds[135] = CRGB::White;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 44)
  {leds[134] = CRGB::White;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 45)
  {leds[133] = CRGB::White;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 46)
  {leds[132] = CRGB::White;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}

// NUMBER 4

else
  if (Peddle == 0 && LedPosition == 47)
  {leds[23] = CRGB::Red;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 48)
  {leds[31] = CRGB::Red;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 49)
  {leds[83] = CRGB::Red;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 50)
  {leds[91] = CRGB::Red;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 51)
  {leds[143] = CRGB::Red;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 52)
  {leds[138] = CRGB::Red;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 53)
  {leds[96] = CRGB::Red;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 54)
  {leds[78] = CRGB::Red;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 55)
  {leds[79] = CRGB::Red;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 56)
  {leds[80] = CRGB::Red;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 57)
  {leds[81] = CRGB::Red;
  FastLED.show();;
  LedPosition++;
  delay (Delay);}
else
  if (Peddle == 0 && LedPosition == 58)
  {leds[82] = CRGB::Red;
  FastLED.show();;
 
  delay (Delay);}

























//DOWN


  if (Peddle == 1 && LedPosition == 58)
  {leds[82] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 57)
  {leds[81] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 56)
  {leds[80] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 55)
  {leds[79] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 54)
  {leds[78] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 53)
  {leds[96] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 52)
  {leds[138] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 51)
  {leds[143] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 50)
  {leds[91] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 49)
  {leds[83] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 48)
  {leds[31] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 47)
  {leds[23] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 46)
  {leds[132] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 45)
  {leds[133] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 44)
  {leds[134] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 43)
  {leds[135] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 42)
  {leds[136] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 41)
  {leds[137] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 40)
  {leds[97] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 39)
  {leds[77] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 38)
  {leds[37] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 37)
  {leds[17] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 36)
  {leds[70] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 35)
  {leds[69] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 34)
  {leds[68] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 33)
  {leds[67] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 32)
  {leds[66] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 31)
  {leds[66] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 30)
  {leds[108] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 29)
  {leds[126] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 28)
  {leds[127] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 27)
  {leds[128] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 26)
  {leds[129] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 25)
  {leds[130] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 24)
  {leds[131] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 23)
  {leds[103] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 22)
  {leds[71] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 21)
  {leds[43] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 20)
  {leds[11] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 

  if (Peddle == 1 && LedPosition == 19)
  {leds[5] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 18)
  {leds[4] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 17)
  {leds[3] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 16)
  {leds[2] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 15)
  {leds[1] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 14)
  {leds[0] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 13)
  {leds[54] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 12)
  {leds[60] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 11)
  {leds[61] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 10)
  {leds[62] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 9)
  {leds[63] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 8)
  {leds[64] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 7)
  {leds[65] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 6)
  {leds[109] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 5)
  {leds[125] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 4)
  {leds[124] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 3)
  {leds[123] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 2)
  {leds[122] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 1)
  {leds[121] = CRGB::Black;
  FastLED.show();;
  LedPosition--;
  delay (Delay2);}
else 
  if (Peddle == 1 && LedPosition == 0)
  {leds[120] = CRGB::Black;
  FastLED.show();;
  delay (Delay2);}
  
}
else
{  LedPosition = 0;

  {leds[0] = CRGB::Black;
  FastLED.show();;}
  {leds[1] = CRGB::Black;
  FastLED.show();;}
  {leds[2] = CRGB::Black;
  FastLED.show();;}
  {leds[3] = CRGB::Black;
  FastLED.show();;}
  {leds[4] = CRGB::Black;
  FastLED.show();;}
  {leds[5] = CRGB::Black;
  FastLED.show();;}
  {leds[6] = CRGB::Black;
  FastLED.show();;}
  {leds[7] = CRGB::Black;
  FastLED.show();;}
  {leds[8] = CRGB::Black;
  FastLED.show();;}
  {leds[9] = CRGB::Black;
  FastLED.show();;}
  {leds[10] = CRGB::Black;
  FastLED.show();;}
  {leds[11] = CRGB::Black;
  FastLED.show();;}
  {leds[12] = CRGB::Black;
  FastLED.show();;}
  {leds[13] = CRGB::Black;
  FastLED.show();;}
  {leds[14] = CRGB::Black;
  FastLED.show();;}
  {leds[15] = CRGB::Black;
  FastLED.show();;}
  {leds[16] = CRGB::Black;
  FastLED.show();;}
  {leds[17] = CRGB::Black;
  FastLED.show();;}
  {leds[18] = CRGB::Black;
  FastLED.show();;}
  {leds[19] = CRGB::Black;
  FastLED.show();;}
  {leds[20] = CRGB::Black;
  FastLED.show();;}
  {leds[21] = CRGB::Black;
  FastLED.show();;}
  {leds[22] = CRGB::Black;
  FastLED.show();;}
  {leds[23] = CRGB::Black;
  FastLED.show();;}
  {leds[24] = CRGB::Black;
  FastLED.show();;}
  {leds[25] = CRGB::Black;
  FastLED.show();;}
  {leds[26] = CRGB::Black;
  FastLED.show();;}
  {leds[27] = CRGB::Black;
  FastLED.show();;}
  {leds[28] = CRGB::Black;
  FastLED.show();;}
  {leds[29] = CRGB::Black;
  FastLED.show();;}
  {leds[30] = CRGB::Black;
  FastLED.show();;}
  {leds[31] = CRGB::Black;
  FastLED.show();;}
  {leds[32] = CRGB::Black;
  FastLED.show();;}
  {leds[33] = CRGB::Black;
  FastLED.show();;}
  {leds[34] = CRGB::Black;
  FastLED.show();;}
  {leds[35] = CRGB::Black;
  FastLED.show();;}
  {leds[36] = CRGB::Black;
  FastLED.show();;}
  {leds[37] = CRGB::Black;
  FastLED.show();;}
  {leds[38] = CRGB::Black;
  FastLED.show();;}
  {leds[39] = CRGB::Black;
  FastLED.show();;}
  {leds[40] = CRGB::Black;
  FastLED.show();;}
  {leds[41] = CRGB::Black;
  FastLED.show();;}
  {leds[42] = CRGB::Black;
  FastLED.show();;}
  {leds[43] = CRGB::Black;
  FastLED.show();;}
  {leds[44] = CRGB::Black;
  FastLED.show();;}
  {leds[45] = CRGB::Black;
  FastLED.show();;}
  {leds[46] = CRGB::Black;
  FastLED.show();;}
  {leds[47] = CRGB::Black;
  FastLED.show();;}
  {leds[48] = CRGB::Black;
  FastLED.show();;}
  {leds[49] = CRGB::Black;
  FastLED.show();;}
  {leds[50] = CRGB::Black;
  FastLED.show();;}
  {leds[51] = CRGB::Black;
  FastLED.show();;}
  {leds[52] = CRGB::Black;
  FastLED.show();;}
  {leds[53] = CRGB::Black;
  FastLED.show();;}
  {leds[54] = CRGB::Black;
  FastLED.show();;}
  {leds[55] = CRGB::Black;
  FastLED.show();;}
  {leds[56] = CRGB::Black;
  FastLED.show();;}
  {leds[57] = CRGB::Black;
  FastLED.show();;}
  {leds[58] = CRGB::Black;
  FastLED.show();;}
  {leds[59] = CRGB::Black;
  FastLED.show();;}
  {leds[60] = CRGB::Black;
  FastLED.show();;}
  {leds[61] = CRGB::Black;
  FastLED.show();;}
  {leds[62] = CRGB::Black;
  FastLED.show();;}
  {leds[63] = CRGB::Black;
  FastLED.show();;}
  {leds[64] = CRGB::Black;
  FastLED.show();;}
  {leds[65] = CRGB::Black;
  FastLED.show();;}
  {leds[66] = CRGB::Black;
  FastLED.show();;}
  {leds[67] = CRGB::Black;
  FastLED.show();;}
  {leds[68] = CRGB::Black;
  FastLED.show();;}
  {leds[69] = CRGB::Black;
  FastLED.show();;}
  {leds[70] = CRGB::Black;
  FastLED.show();;}
  {leds[71] = CRGB::Black;
  FastLED.show();;}
  {leds[72] = CRGB::Black;
  FastLED.show();;}
  {leds[73] = CRGB::Black;
  FastLED.show();;}
  {leds[74] = CRGB::Black;
  FastLED.show();;}
  {leds[75] = CRGB::Black;
  FastLED.show();;}
  {leds[76] = CRGB::Black;
  FastLED.show();;}
  {leds[77] = CRGB::Black;
  FastLED.show();;}
  {leds[78] = CRGB::Black;
  FastLED.show();;}
  {leds[79] = CRGB::Black;
  FastLED.show();;}
  {leds[80] = CRGB::Black;
  FastLED.show();;}
  {leds[81] = CRGB::Black;
  FastLED.show();;}
  {leds[82] = CRGB::Black;
  FastLED.show();;}
  {leds[83] = CRGB::Black;
  FastLED.show();;}
  {leds[84] = CRGB::Black;
  FastLED.show();;}
  {leds[85] = CRGB::Black;
  FastLED.show();;}
  {leds[86] = CRGB::Black;
  FastLED.show();;}
  {leds[87] = CRGB::Black;
  FastLED.show();;}
  {leds[88] = CRGB::Black;
  FastLED.show();;}
  {leds[89] = CRGB::Black;
  FastLED.show();;}
  {leds[90] = CRGB::Black;
  FastLED.show();;}
  {leds[91] = CRGB::Black;
  FastLED.show();;}
  {leds[92] = CRGB::Black;
  FastLED.show();;}
  {leds[93] = CRGB::Black;
  FastLED.show();;}
  {leds[94] = CRGB::Black;
  FastLED.show();;}
  {leds[95] = CRGB::Black;
  FastLED.show();;}
  {leds[96] = CRGB::Black;
  FastLED.show();;}
  {leds[97] = CRGB::Black;
  FastLED.show();;}
  {leds[98] = CRGB::Black;
  FastLED.show();;}
  {leds[99] = CRGB::Black;
  FastLED.show();;}
  {leds[100] = CRGB::Black;
  FastLED.show();;}
  {leds[101] = CRGB::Black;
  FastLED.show();;}
  {leds[102] = CRGB::Black;
  FastLED.show();;}
  {leds[103] = CRGB::Black;
  FastLED.show();;}
  {leds[104] = CRGB::Black;
  FastLED.show();;}
  {leds[105] = CRGB::Black;
  FastLED.show();;}
  {leds[106] = CRGB::Black;
  FastLED.show();;}
  {leds[107] = CRGB::Black;
  FastLED.show();;}
  {leds[108] = CRGB::Black;
  FastLED.show();;}
  {leds[109] = CRGB::Black;
  FastLED.show();;}
  {leds[110] = CRGB::Black;
  FastLED.show();;}
  {leds[111] = CRGB::Black;
  FastLED.show();;}
  {leds[112] = CRGB::Black;
  FastLED.show();;}
  {leds[113] = CRGB::Black;
  FastLED.show();;}
  {leds[114] = CRGB::Black;
  FastLED.show();;}
  {leds[115] = CRGB::Black;
  FastLED.show();;}
  {leds[116] = CRGB::Black;
  FastLED.show();;}
  {leds[117] = CRGB::Black;
  FastLED.show();;}
  {leds[118] = CRGB::Black;
  FastLED.show();;}
  {leds[119] = CRGB::Black;
  FastLED.show();;}
  {leds[120] = CRGB::Black;
  FastLED.show();;}
  {leds[121] = CRGB::Black;
  FastLED.show();;}
  {leds[120] = CRGB::Black;
  FastLED.show();;}
  {leds[121] = CRGB::Black;
  FastLED.show();;}
  {leds[122] = CRGB::Black;
  FastLED.show();;}
  {leds[123] = CRGB::Black;
  FastLED.show();;}
  {leds[124] = CRGB::Black;
  FastLED.show();;}
  {leds[125] = CRGB::Black;
  FastLED.show();;}
  {leds[126] = CRGB::Black;
  FastLED.show();;}
  {leds[127] = CRGB::Black;
  FastLED.show();;}
  {leds[128] = CRGB::Black;
  FastLED.show();;}
  {leds[129] = CRGB::Black;
  FastLED.show();;}
  {leds[130] = CRGB::Black;
  FastLED.show();;}
  {leds[131] = CRGB::Black;
  FastLED.show();;}
  {leds[132] = CRGB::Black;
  FastLED.show();;}
  {leds[133] = CRGB::Black;
  FastLED.show();;}
  {leds[134] = CRGB::Black;
  FastLED.show();;}
  {leds[135] = CRGB::Black;
  FastLED.show();;}
  {leds[136] = CRGB::Black;
  FastLED.show();;}
  {leds[137] = CRGB::Black;
  FastLED.show();;}
  {leds[138] = CRGB::Black;
  FastLED.show();;}
  {leds[139] = CRGB::Black;
  FastLED.show();;}
  {leds[140] = CRGB::Black;
  FastLED.show();;}
  {leds[141] = CRGB::Black;
  FastLED.show();;}
  {leds[142] = CRGB::Black;
  FastLED.show();;}
  {leds[143] = CRGB::Black;
  FastLED.show();;}
  {leds[144] = CRGB::Black;
  FastLED.show();;}
  {leds[145] = CRGB::Black;
  FastLED.show();;}
  {leds[146] = CRGB::Black;
  FastLED.show();;}
  {leds[147] = CRGB::Black;
  FastLED.show();;}
  {leds[148] = CRGB::Black;
  FastLED.show();;}
  {leds[149] = CRGB::Black;
  FastLED.show();;}
}



  
    



}
