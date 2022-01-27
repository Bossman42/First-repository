#include <FastLED.h>

//#define LED_PIN     5
//#define NUM_LEDS    200

//#define BRIGHTNESS  64
//#define LED_TYPE    WS2811
//#define COLOR_ORDER GRB
//CRGB leds[NUM_LEDS];

int UPDATES_PER_SECOND = 100;


//#define FASTLED_INTERRUPT_RETRY_COUNT 0  //// These 2 lines gets rid of the glitches on the nodemcu devices comment out on arduino
#define FASTLED_ALLOW_INTERRUPTS 0
#define NUM_LEDS 300
CRGB leds[NUM_LEDS];




// This example shows several ways to set up and use 'palettes' of colors
// with FastLED.
//
// These compact palettes provide an easy way to re-colorize your
// animation on the fly, quickly, easily, and with low overhead.
//
// USING palettes is MUCH simpler in practice than in theory, so first just
// run this sketch, and watch the pretty lights as you then read through
// the code.  Although this sketch has eight (or more) different color schemes,
// the entire sketch compiles down to about 6.5K on AVR.
//
// FastLED provides a few pre-configured color palettes, and makes it
// extremely easy to make up your own color schemes with palettes.
//
// Some notes on the more abstract 'theory and practice' of
// FastLED compact palettes are at the bottom of this file.



CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;


void setup() {
    delay( 3000 ); // power-up safety delay



    
   
    Serial.begin (9600);
    Serial.println ("Ready to go");

}


void loop()
{
 handleSerial();
    
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
}


void handleSerial(){
  while (Serial.available()>0){
    char incomingCharacter = Serial.read();
    switch (incomingCharacter) {
        case 'a':
         leds[15] = CRGB::Red;
      
      Serial.println ("Cloud Colors");
      break;  
        
      case 'b':
            leds[25] = CRGB::Red;
      Serial.println ("Rainbow Colors Blended");
      break;      
           
      case 'c':
       leds[35] = CRGB::Red;
      Serial.println ("Rainbow Colors no Blend");
      break;

      case 'd':
    leds[45] = CRGB::Red;
      Serial.println ("Rainbow Colors Strip Blend");
      break;

            case 'e':
      leds[55] = CRGB::Red;
      Serial.println ("Party Colors");
      break;





                   
     



    }
  }
}
