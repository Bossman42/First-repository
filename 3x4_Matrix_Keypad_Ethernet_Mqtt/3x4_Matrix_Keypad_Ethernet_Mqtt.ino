// Use this example with the Adafruit Keypad products.
// You'll need to know the Product ID for your keypad.
// Here's a summary:
//   * PID3844 4x4 Matrix Keypad
//   * PID3845 3x4 Matrix Keypad
//   * PID1824 3x4 Phone-style Matrix Keypad
//   * PID1332 Membrane 1x4 Keypad
//   * PID419  Membrane 3x4 Matrix Keypad
/////////////////////////////////////////////////  Keypad //////////////////////////////////////////////////
#include "Adafruit_Keypad.h"

// define your specific keypad here via PID
#define KEYPAD_PID3845    //////////  3x4 keypad
// define your pins here
// can ignore ones that don't apply
#define R1    24
#define R2    34
#define R3    32
#define R4    28
#define C1    26
#define C2    22
#define C3    30
//#define C4    11
// leave this import after the above configuration
#include "keypad_config.h"

//initialize an instance of class NewKeypad
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);
////////////////////////////////////////////////  End Keypad  ////////////////////////////////////


///////////////////////////////////////  Ethernet/ MQTT  ///////////////////////////////////////
#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.          /////  Generate new address for each device!
byte mac[]    = {  0x90, 0xA2, 0xDA, 0xAC, 0x66, 0x91 };   /////https://ssl.crox.net/arduinomac/   
IPAddress ip(192, 168, 68, 160);
IPAddress server(192, 168, 68, 110);
///////////////////////////////////////////  90:A2:DA:AC:66:91 == 0x90, 0xA2, 0xDA, 0xAC, 0x66, 0x91 

const int lightPin = 8;
const int button1 = 7; 
int button1LS = 0;
int button1S = 0;
int count = 0;

// Callback function header
void callback(char* topic, byte* payload, unsigned int length);

EthernetClient ethClient;
PubSubClient client(server, 1883, callback, ethClient);

// Callback function
void callback(char* topic, byte* payload, unsigned int length) {
    
  //turn the LED ON if the payload is '1' and publish to the MQTT server a confirmation message
  if(payload[0] == '1'){
    digitalWrite(lightPin, HIGH);
    client.publish("outTopic", "Light On"); }
    
  //turn the LED OFF if the payload is '0' and publish to the MQTT server a confirmation message
  if (payload[0] == '0'){
    digitalWrite(lightPin, LOW);
    client.publish("outTopic", "Light Off");
    }



} // void callback

//////////////////////////////////////////////  End Ethernet / MQTT  ///////////////////////////////////////////////

void setup() {

  //////////////////////////////////////  Keypad  //////////////////////////////////////////
  Serial.begin(9600);
  customKeypad.begin();
///////////////////////////////////////  End Keypad  ////////////////////////////////////

///////////////////////////////////////// Ethernet / Mqtt  //////////////////////////////////
  pinMode(lightPin, OUTPUT);
  pinMode (button1,INPUT_PULLUP);
  digitalWrite(lightPin, LOW);
  
  Ethernet.begin(mac, ip);
  if (client.connect("arduinoClient")) {
    client.publish("outTopic","hello world");
    client.subscribe("inTopic");
  }


  /////////////////////////////////////  End Ethernet / Mqtt  //////////////////////////////////////////  
}

void loop() {
  // put your main code here, to run repeatedly:

/////////////////////////////////////////  Keypad //////////////////////////////////
  
  customKeypad.tick();

  while(customKeypad.available()){
    keypadEvent e = customKeypad.read();
    
   Serial.print((char)e.bit.KEY);

 // int keys = ((char)e.bit.KEY);
   // Serial.print (keys);
   // Serial.print ("Keys");



    float keys = ((char)e.bit.KEY);
    char charkeys[] = "00";
    dtostrf(keys, 2, 0, charkeys);
 //   client.publish("outTopic", charkeys);
    
 //   client.publish ("outTopic",(char*)e.bit.KEY);
    
    
    if(e.bit.EVENT == KEY_JUST_PRESSED)  client.publish("Pressed",charkeys);
    else if(e.bit.EVENT == KEY_JUST_RELEASED)  client.publish("Released",charkeys);
    
 //       if(e.bit.EVENT == KEY_JUST_PRESSED) Serial.println(" pressed");
 //   else if(e.bit.EVENT == KEY_JUST_RELEASED) Serial.println(" released");
 

 // client.beginPublish ("outTopic",10,false);

//  client.print(charkeys);
//  if(e.bit.EVENT == KEY_JUST_PRESSED)
//  { client.print (" pressed");
//   client.endPublish();}
  
//    else if(e.bit.EVENT == KEY_JUST_RELEASED)
//    {  client.print(" released");    
//    client.endPublish();}
    
    
        if(e.bit.EVENT == KEY_JUST_PRESSED) Serial.println(" pressed");
    else if(e.bit.EVENT == KEY_JUST_RELEASED) Serial.println(" released");
 }
  delay(10);
////////////////////////////////////////  End Keypad  //////////////////////////////////////////////


//////////////////////////////////////// Ethernet / Mqtt  ////////////////////////////////////////
 //      button1S = digitalRead (button1);
 //   if (button1S != button1LS) {
 //   if (button1S == LOW) {
 //     client.publish("outTopic", "Button Pressed");
 //     client.publish("outTopic", count);}
 // button1LS = button1S;
 // count++;
 // delay (50);
 //   }
  client.loop();

////////////////////////////////////////////// End Ethernet / mqtt /////////////////////////////////
  
}
