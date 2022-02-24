#include <FastLED.h>

//#define LED_PIN     5
//#define NUM_LEDS    50
//#define BRIGHTNESS  64
//#define LED_TYPE    WS2811
//#define COLOR_ORDER GRB
//CRGB leds[NUM_LEDS];

int UPDATES_PER_SECOND = 100;


#define FASTLED_INTERRUPT_RETRY_COUNT 0  //// These 2 lines gets rid of the glitches on the nodemcu devices comment out on arduino
//#define FASTLED_ALLOW_INTERRUPTS 0


#define NUM_LEDS_PER_STRIP 60
CRGB redLeds[NUM_LEDS_PER_STRIP];
CRGB greenLeds[NUM_LEDS_PER_STRIP];
CRGB blueLeds[NUM_LEDS_PER_STRIP];


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



/*****
 
 All the resources for this project:
 https://randomnerdtutorials.com/
 
*****/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"

// Uncomment one of the lines bellow for whatever DHT sensor type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

// Change the credentials below, so your ESP8266 connects to your router
const char* ssid = "Boss Castle";
const char* password = "whatisyourpassword";
//const char* ssid = "ATT5KrE5yK";
//const char* password = "5s?u8#8r9v9h";
// Change the variable to your Raspberry Pi IP address, so it connects to your MQTT broker
const char* mqtt_server = "192.168.68.102";

// Initializes the espClient. You should change the espClient name if you have multiple ESPs running in your home automation system
WiFiClient espClient;
PubSubClient client(espClient);

// DHT Sensor - GPIO 5 = D1 on ESP-12E NodeMCU board
const int DHTPin = 5;

// Lamp - LED - GPIO 4 = D2 on ESP-12E NodeMCU board
const int lamp = 4;

// Initialize DHT sensor.
DHT dht(DHTPin, DHTTYPE);

// Timers auxiliar variables
long now = millis();
long lastMeasure = 0;

// Don't change the function below. This functions connects your ESP8266 to your router
void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected - ESP IP address: ");
  Serial.println(WiFi.localIP());
}

// This functions is executed when some device publishes a message to a topic that your ESP8266 is subscribed to
// Change the function below to add logic to your program, so when a device publishes a message to a topic that 
// your ESP8266 is subscribed you can actually do something
void callback(String topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  // Feel free to add more if statements to control more GPIOs with MQTT

  // If a message is received on the topic room/lamp, you check if the message is either on or off. Turns the lamp GPIO according to the message
  if(topic=="Connection"){
      Serial.print("Changing Room lamp to ");
      if(messageTemp == "cloud"){
        digitalWrite(lamp, HIGH);
         currentPalette = CloudColors_p;
        Serial.print("cloud colors");
      }
      else if(messageTemp == "party"){
        digitalWrite(lamp, LOW);
        currentPalette = PartyColors_p; 
        Serial.print("party colors");
      }
  }
  Serial.println();
}

// This functions reconnects your ESP8266 to your MQTT broker
// Change the function below if you want to subscribe to more topics with your ESP8266 
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    /*
     YOU MIGHT NEED TO CHANGE THIS LINE, IF YOU'RE HAVING PROBLEMS WITH MQTT MULTIPLE CONNECTIONS
     To change the ESP device ID, you will have to give a new name to the ESP8266.
     Here's how it looks:
       if (client.connect("ESP8266Client")) {
     You can do it like this:
       if (client.connect("ESP1_Office")) {
     Then, for the other ESP:
       if (client.connect("ESP2_Garage")) {
      That should solve your MQTT multiple connections problem
    */
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");  
      // Subscribe or resubscribe to a topic
      // You can subscribe to more topics (to control more LEDs in this example)
      client.subscribe("Connection");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

// The setup function sets your ESP GPIOs to Outputs, starts the serial communication at a baud rate of 115200
// Sets your mqtt broker and sets the callback function
// The callback function is what receives messages and actually controls the LEDs





void setup() {
    delay( 3000 ); // power-up safety delay


  pinMode(lamp, OUTPUT);
  
  dht.begin();
  
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  WiFi.setSleepMode(WIFI_NONE_SLEEP);

  /// This selects which pins are for controlling neopixels

     // tell FastLED there's 60 NEOPIXEL leds on pin 4
  FastLED.addLeds<NEOPIXEL, 8>(redLeds, NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 NEOPIXEL leds on pin 5
  FastLED.addLeds<NEOPIXEL, 1>(greenLeds, NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 NEOPIXEL leds on pin 12
  FastLED.addLeds<NEOPIXEL, 2>(blueLeds, NUM_LEDS_PER_STRIP);
    
 //   FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
//    FastLED.setBrightness(  BRIGHTNESS );
    
    currentPalette = RainbowColors_p;
    currentBlending = LINEARBLEND;
   // Serial.begin (9600);
    Serial.println ("Ready to go");

}


void loop()
{
 handleSerial();


  if (!client.connected()) {
    reconnect();
  }
  if(!client.loop())
    client.connect("ESP8266Client");

  now = millis();
  // Publishes new temperature and humidity every 30 seconds



  
    
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    
    FillLEDsFromPaletteColors( startIndex);
    
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 255;
    
    for( int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
        redLeds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;}

            for( int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
        greenLeds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;}

   //  { currentPalette = RainbowColors_p;         currentBlending = LINEARBLEND; }   //b
     //  { currentPalette = RainbowStripeColors_p;   currentBlending = NOBLEND;  }    //c
   //      { currentPalette = RainbowStripeColors_p;   currentBlending = LINEARBLEND; }  //d
    //    { SetupPurpleAndGreenPalette();             currentBlending = LINEARBLEND; }
    //     { SetupTotallyRandomPalette();              currentBlending = LINEARBLEND; }
//         { SetupBlackAndWhiteStripedPalette();       currentBlending = NOBLEND; }
    //     { SetupBlackAndWhiteStripedPalette();       currentBlending = LINEARBLEND; }
    //      { currentPalette = CloudColors_p;           currentBlending = LINEARBLEND; }   //  a
    //     { currentPalette = PartyColors_p;           currentBlending = LINEARBLEND; }
    //     { currentPalette = myRedWhiteBluePalette_p; currentBlending = NOBLEND;  }
    //   { currentPalette = myRedWhiteBluePalette_p; currentBlending = LINEARBLEND; }




    
}


void handleSerial(){
  while (Serial.available()>0){
    char incomingCharacter = Serial.read();
    switch (incomingCharacter) {
        case 'a':
      currentPalette = CloudColors_p;           currentBlending = LINEARBLEND; 
      
      Serial.println ("Cloud Colors");
      break;  
        
      case 'b':
     currentPalette = RainbowColors_p;         currentBlending = LINEARBLEND;
      Serial.println ("Rainbow Colors Blended");
      break;      
           
      case 'c':
      currentPalette = RainbowStripeColors_p;   currentBlending = NOBLEND;
      Serial.println ("Rainbow Colors no Blend");
      break;

      case 'd':
      currentPalette = RainbowStripeColors_p;   currentBlending = LINEARBLEND;
      Serial.println ("Rainbow Colors Strip Blend");
      break;

            case 'e':
      currentPalette = PartyColors_p;           currentBlending = LINEARBLEND; 
      Serial.println ("Party Colors");
      break;



               case 'g':
           UPDATES_PER_SECOND= UPDATES_PER_SECOND +10 ;
      Serial.println ("UPDATES PER SECOND +10 ");
      Serial.println (UPDATES_PER_SECOND);
      break;

                case 'h':
           UPDATES_PER_SECOND= UPDATES_PER_SECOND -10 ;
      Serial.println ("UPDATES PER SECOND +10 ");
      Serial.println (UPDATES_PER_SECOND);
      break;


                   
     


      
// a = start timer
// b = pause timer
// c = add 1 minute to timer
// d == add 5 minutes to timer
// e == reset timer to 1500 and stops timer
// f == 1 minute subtracted from timer
// g == 5 minutes subtracted from timer
    }
  }
}





// This function fills the palette with totally random colors.

// This function sets up a palette of black and white stripes,
// using code.  Since the palette is effectively an array of
// sixteen CRGB colors, the various fill_* functions can be used
// to set them up.




// Additionl notes on FastLED compact palettes:
//
// Normally, in computer graphics, the palette (or "color lookup table")
// has 256 entries, each containing a specific 24-bit RGB color.  You can then
// index into the color palette using a simple 8-bit (one byte) value.
// A 256-entry color palette takes up 768 bytes of RAM, which on Arduino
// is quite possibly "too many" bytes.
//
// FastLED does offer traditional 256-element palettes, for setups that
// can afford the 768-byte cost in RAM.
//
// However, FastLED also offers a compact alternative.  FastLED offers
// palettes that store 16 distinct entries, but can be accessed AS IF
// they actually have 256 entries; this is accomplished by interpolating
// between the 16 explicit entries to create fifteen intermediate palette
// entries between each pair.
//
// So for example, if you set the first two explicit entries of a compact 
// palette to Green (0,255,0) and Blue (0,0,255), and then retrieved 
// the first sixteen entries from the virtual palette (of 256), you'd get
// Green, followed by a smooth gradient from green-to-blue, and then Blue.
