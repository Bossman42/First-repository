///////////////////////////////////   OTA Stuff ///////////////////////
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

#ifndef STASSID
#define STASSID "SUBScape-24g"
#define STAPSK  "unlockthewifi"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

//////////////////////////end OTA Stuff  /////////////////////////////////////

////////////////////////////  Physical Button  ///////////////////////////////

int button1 = 14;
int button2 = 12;

int button1L = 1;
int button2L = 1;
int buttonCounter = 0;
int newbuttonpress = 0;




//////////////////////////// End Physical Button////////////////////////////////
///////////////////////////Mqtt/////////////////////////////

#include <PubSubClient.h>
#include "DHT.h"


// Change the variable to your Raspberry Pi IP address, so it connects to your MQTT broker
const char* mqtt_server = "192.168.1.14";               /////////////////////////     change this to what ever pi is running mosquitto
//const char* mqtt_server = "192.168.1.87";

WiFiClient espClient;
PubSubClient client(espClient);

////////////////////////////end mqtt  /////////////////////////////////


////////////////////Neopixels/////////////////////////////////////////////////////////////////

#include <FastLED.h>
int UPDATES_PER_SECOND = 100;
#define FASTLED_INTERRUPT_RETRY_COUNT 0  //// These 2 lines gets rid of the glitches on the nodemcu devices comment out on arduino
//#define FASTLED_ALLOW_INTERRUPTS 0


#define NUM_LEDS_PER_STRIP 103
CRGB redLeds[NUM_LEDS_PER_STRIP];
CRGB greenLeds[NUM_LEDS_PER_STRIP];
CRGB blueLeds[NUM_LEDS_PER_STRIP];


CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;




/////////////////////  End Neopixels  /////////////////////////////////////////////////////////////////////////

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






// Timers auxiliar variables
long now = millis();
long lastMeasure = 0;



void setup() {
/////////////////////////////////////// Physical Buttons  //////////////////////
//
  pinMode(button1, INPUT_PULLUP);//button 1
  pinMode(button2, INPUT_PULLUP);//button 2

///////////////////////////////////End Physical Buttons ////////////////////////




  ///////////////////////////// OTA Settings   /////////////////////////////////////
  Serial.begin(115200);
  Serial.println("Booting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  // Port defaults to 8266
  // ArduinoOTA.setPort(8266);

  // Hostname defaults to esp8266-[ChipID]
  // ArduinoOTA.setHostname("myesp8266");

  // No authentication by default
  // ArduinoOTA.setPassword("admin");

  // Password can be set with it's md5 value as well
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else { // U_FS
      type = "filesystem";
    }

    // NOTE: if updating FS this would be the place to unmount FS using FS.end()
    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Serial.println("End Failed");
    }
  });
  ArduinoOTA.begin();
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

/////////////////////////////END OTA Settings  ///////////////////////////////////


///////////////////////////  MQTT ///////////////////////////////////
  client.publish("Status","Node 3");
//////////////////////////// end MQTT ////////////////////////
//////////////////////// NEO PIXELS  Setup  //////////////////////////
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

String up_str;
String down_str;



//////////////////////// END NEOPIXELS Setup  ///////////////////////

  Serial.begin(115200);
  Serial.println ("helloworld");

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);






  
}    ///////////////////////// end Void Setup  ///////////////////////




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



    if(topic=="Connection"){
      Serial.print("Connection Status");
      if(messageTemp == "ocean"){
   currentPalette = OceanColors_p;           currentBlending = LINEARBLEND;
        Serial.print("Ocean");
        client.publish("Status","Ocean");
      }
     
  }
  Serial.println();

      if(topic=="Connection"){
      Serial.print("Connection Status");
      if(messageTemp == "rainbowstripe"){
   currentPalette = RainbowStripeColors_p;           currentBlending = LINEARBLEND;
        Serial.print("RainbowStripe");
        client.publish("Status","RainbowStripe");
      }
     
  }
  Serial.println();

        if(topic=="Connection"){
      Serial.print("Connection Status");
      if(messageTemp == "rainbowstripe2"){
   currentPalette = RainbowStripeColors_p;           currentBlending = NOBLEND;
        Serial.print("RainbowStripe2");
        client.publish("Status","RainbowStripe2");
      }
     
  }
  Serial.println();


        if(topic=="Connection"){
      Serial.print("Connection Status");
      if(messageTemp == "purplegreen"){
    SetupPurpleAndGreenPalette();         currentBlending = LINEARBLEND;
        Serial.print("purplegreen");
        client.publish("Status","purplegreen");
      }
     
  }
  Serial.println();

  
        if(topic=="Connection"){
      Serial.print("Connection Status");
      if(messageTemp == "purple"){
    SetupPurplePalette();         currentBlending = NOBLEND;
        Serial.print("purple");
        client.publish("Status","purple");
      }
     
  }
  Serial.println();

        if(topic=="Connection"){
      Serial.print("Connection Status");
      if(messageTemp == "police"){
    SetupPolicePalette();         currentBlending = NOBLEND;
        Serial.print("police");
        client.publish("Status","police");
      }
     
  }
  Serial.println();





        if(topic=="Connection"){
      Serial.print("Connection Status");
      if(messageTemp == "1"){
    UPDATES_PER_SECOND = 10;
        Serial.print("Speed 1");
        client.publish("Status","Speed 1");
       
      }
     
  }
  Serial.println();

        if(topic=="Connection"){
      Serial.print("Connection Status");
      if(messageTemp == "2"){
    UPDATES_PER_SECOND = 40;
        Serial.print("Speed 2");
        client.publish("Status","Speed 2");
      
      }
     
  }
  Serial.println();


        if(topic=="Connection"){
      Serial.print("Connection Status");
      if(messageTemp == "3"){
    UPDATES_PER_SECOND = 60;
        Serial.print("Speed 3");
        client.publish("Status","Speed 3");
      
      }
     
  }
  Serial.println();

          if(topic=="Connection"){
      Serial.print("Connection Status");
      if(messageTemp == "4"){
    UPDATES_PER_SECOND = 80;
        Serial.print("Speed 4");
        client.publish("Status","Speed 4");
      
      }
     
  }
  Serial.println();

          if(topic=="Connection"){
      Serial.print("Connection Status");
      if(messageTemp == "5"){
    UPDATES_PER_SECOND = 100;
        Serial.print("Speed 5");
        client.publish("Status","Speed 5");
      
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




void loop() {
  ArduinoOTA.handle();



  if (!client.connected()) {
    reconnect();
  }
  if(!client.loop())
    client.connect("ESP8266Client");

  now = millis();

/////////////////////////////// Physical Buttons /////////////////////////////

  int button1S = digitalRead(button1);
  int button2S = digitalRead(button2);

  if (button1S != button1L) 
  {if (button1S == LOW)
  {buttonCounter ++;
  newbuttonpress ++;
  client.publish("Status", "Button Pressed");
  delay (50);}}
  
  button1L = button1S;


  if (newbuttonpress == 1){
    switch (buttonCounter){
      case 1:

      currentPalette = CloudColors_p;
      currentBlending = LINEARBLEND;
      newbuttonpress = 0;

      break;
      case 2:

       currentPalette = PartyColors_p;
       currentBlending = LINEARBLEND;
       newbuttonpress = 0;

      break;
      case 3:

      currentPalette = LavaColors_p;
      currentBlending = LINEARBLEND;
       newbuttonpress = 0;

             break;
      case 4:

      currentPalette = HeatColors_p;
      currentBlending = LINEARBLEND;
       newbuttonpress = 0;

             break;
      case 5:

      currentPalette = OceanColors_p; 
      currentBlending = LINEARBLEND;
       newbuttonpress = 0;

             break;
      case 6:

      currentPalette = RainbowStripeColors_p;   
      currentBlending = LINEARBLEND;
       newbuttonpress = 0;

             break;
      case 7:

      currentPalette = RainbowStripeColors_p;   
      currentBlending = NOBLEND;
       newbuttonpress = 0;

             break;
      case 8:

      SetupPurpleAndGreenPalette();
      currentBlending = LINEARBLEND;
       newbuttonpress = 0;

             break;
      case 9:

      SetupPurplePalette();    
      currentBlending = NOBLEND;
       newbuttonpress = 0;

             break;
      case 10:

      SetupPolicePalette(); 
      currentBlending = NOBLEND;
       newbuttonpress = 0;

             break;
      case 11:

      SetupBlackAndWhiteStripedPalette();  
      currentBlending = NOBLEND;
       newbuttonpress = 0;


       
    }
  }
  if (buttonCounter > 11){
    buttonCounter = 1;
  }


  
//////////////////////////////End Physical Buttons  /////////////////////////////////




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

void SetupPurpleAndGreenPalette()
{
    CRGB purple = CHSV( HUE_PURPLE, 255, 255);
    CRGB green  = CHSV( HUE_GREEN, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   green,  green,  black,  black,
                                   purple, purple, black,  black,
                                   green,  green,  black,  black,
                                   purple, purple, black,  black );
}
void SetupPurplePalette()
{
    CRGB purple = CHSV( HUE_PURPLE, 255, 255);
    CRGB green  = CHSV( HUE_GREEN, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   purple, purple, black,  black,
                                   purple, purple, black,  black,
                                   purple, purple, black,  black,
                                   purple, purple, black,  black );
}


void SetupPolicePalette()
{
    CRGB red = CHSV( HUE_RED, 255, 255);
    CRGB blue  = CHSV( HUE_BLUE, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   red, black, blue,  black,
                                   black, black, black,  black,
                                   red, black, blue,  black,
                                   black, black, black,  black );
}






  
