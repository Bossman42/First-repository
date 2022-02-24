/*****
 
 All the resources for this project:
 https://randomnerdtutorials.com/
 
*****/
///////////////////////////Mqtt/////////////////////////////
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"
/////////////////////////////////////////////////////////////






////////////////////Neopixels/////////////////////////////////////////////////////////////////

#include <FastLED.h>
int UPDATES_PER_SECOND = 100;
#define FASTLED_INTERRUPT_RETRY_COUNT 0  //// These 2 lines gets rid of the glitches on the nodemcu devices comment out on arduino
//#define FASTLED_ALLOW_INTERRUPTS 0


#define NUM_LEDS_PER_STRIP 60
CRGB redLeds[NUM_LEDS_PER_STRIP];
CRGB greenLeds[NUM_LEDS_PER_STRIP];
CRGB blueLeds[NUM_LEDS_PER_STRIP];


CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;




/////////////////////  End Neopixels  /////////////////////////////////////////////////////////////////////////

////////////////////////////  Physical Button  ///////////////////////////////

int button1 = 14;
//int button2 = 12;

int button1L = 1;
int button2L = 1;
int buttonCounter = 0;
int newbuttonpress = 0;




//////////////////////////// End Physical Button////////////////////////////////


///////////////////////////Rfid //////////////////////////////////////////////////////////

/*

#include <SPI.h>
#include <MFRC522.h>
constexpr uint8_t RST_PIN = D3;     // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = D4;     // Configurable, see typical pin layout above
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
MFRC522::MIFARE_Key key;
String tag;

*/

///////////////////////////////////    end RFID   //////////////////////////////////////////////////////////


// Change the credentials below, so your ESP8266 connects to your router
const char* ssid = "Boss Castle";
const char* password = "whatisyourpassword";

//const char* ssid = "ATT5KrE5yK";
//const char* password = "5s?u8#8r9v9h";

//const char* ssid = "SUBScape-24g";
//const char* password = "unlockthewifi";



unsigned long previousMillis = 0;
unsigned long interval = 30000;


// Change the variable to your Raspberry Pi IP address, so it connects to your MQTT broker
const char* mqtt_server = "192.168.68.110";               /////////////////////////     change this to what ever pi is running mosquitto
//const char* mqtt_server = "192.168.1.87";
// Initializes the espClient. You should change the espClient name if you have multiple ESPs running in your home automation system
WiFiClient espClient;
PubSubClient client(espClient);




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
  client.publish("Status","Node 3");

  /// This selects which pins are for controlling neopixels

     // tell FastLED there's 60 NEOPIXEL leds on pin 4
  FastLED.addLeds<NEOPIXEL, 8>(redLeds, NUM_LEDS_PER_STRIP);          /////////////////////////  Define pin on ESP8266   ////////////////////////////
                                                                      ////////////////////////   this is for 3 strips   /////////////////////////////
  // tell FastLED there's 60 NEOPIXEL leds on pin 5
  FastLED.addLeds<NEOPIXEL, 1>(greenLeds, NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 NEOPIXEL leds on pin 12
  FastLED.addLeds<NEOPIXEL, 2>(blueLeds, NUM_LEDS_PER_STRIP);
    
 //   FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
//    FastLED.setBrightness(  BRIGHTNESS );
    
    currentPalette = RainbowColors_p;
    currentBlending = LINEARBLEND;




  
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
      Serial.print("Connection Status");
      if(messageTemp == "hello"){
      
        Serial.print("Node 3");
        client.publish("Status","Node 3");
      }
     
  }
  Serial.println();
    if(topic=="Connection"){
      Serial.print("Connection Status");
      if(messageTemp == "cloud"){
      currentPalette = CloudColors_p;           currentBlending = LINEARBLEND; 
        Serial.print("cloud");
        client.publish("Status","cloud selected");
      }
     
  }
  Serial.println();

    Serial.println();
    if(topic=="Connection"){
      Serial.print("Connection Status");
      if(messageTemp == "party"){
   currentPalette = PartyColors_p;           currentBlending = LINEARBLEND;
        Serial.print("cloud");
        client.publish("Status","party selected");
      }
     
  }
  Serial.println();



  
    Serial.println();
    if(topic=="Connection"){
      Serial.print("Connection Status");
      if(messageTemp == "lava"){
   currentPalette = LavaColors_p;           currentBlending = LINEARBLEND;
        Serial.print("lava");
        client.publish("Status","Lava Colors");
      }
     
  }
  Serial.println();




    if(topic=="Connection"){
      Serial.print("Connection Status");
      if(messageTemp == "off"){
   SetupBlackAndWhiteStripedPalette();       currentBlending = NOBLEND;
        Serial.print("off");
        client.publish("Status","Off");
      }
     
  }
  Serial.println();

    if(topic=="Connection"){
      Serial.print("Connection Status");
      if(messageTemp == "heat"){
   currentPalette = HeatColors_p;           currentBlending = LINEARBLEND;
        Serial.print("Heat");
        client.publish("Status","Heat");
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



///////////////////////////   RFID //////////////////////////////
  
  /*
  
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522

*/
////////////////////////////   end RFID  ////////////////////////////////  

  

  
  Serial.begin(115200);
  Serial.println ("helloworld");
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);





}

// For this project, you don't need to change anything in the loop function. Basically it ensures that you ESP is connected to your broker
void loop() {

  if (!client.connected()) {
    reconnect();
  }
  if(!client.loop())
    client.connect("ESP8266Client");

  now = millis();



/////////////////////////////////////Neopixels ////////////////////////////////////
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    
    FillLEDsFromPaletteColors( startIndex);
    
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
/////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////// RFID /////////////////////////////////////////////  
 
/*  
 
 
 if ( ! rfid.PICC_IsNewCardPresent())
    return;
  if (rfid.PICC_ReadCardSerial()) {
    for (byte i = 0; i < 4; i++) {
      tag += rfid.uid.uidByte[i];
    }
    Serial.println(tag);
  String t = (tag);
  
  //  client.publish("RFID","tag");
    client.publish("RFID",t.c_str());
    tag = "";
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }                                    
  
  
  */
////////////////////////////////////////////////////////RFID  //////////////////////////////////////////////


  }          //////////////////////////////     end of void loop     //////////////////////////////////////


  

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
void SetupBlackAndWhiteStripedPalette()
{
    // 'black out' all 16 palette entries...
    fill_solid( currentPalette, 16, CRGB::Black);
    // and set every fourth one to white.
  //  currentPalette[0] = CRGB::White;
  //  currentPalette[4] = CRGB::White;
  //  currentPalette[8] = CRGB::White;
  //  currentPalette[12] = CRGB::White;
    
}



  
 
