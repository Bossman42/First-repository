/*
 Publishing in the callback
  - connects to an MQTT server
  - subscribes to the topic "inTopic"
  - when a message is received, republishes it to "outTopic"
  This example shows how to control pins using Ethernet shield via MQTT


  This is version 2
*/

#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.


byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
IPAddress ip(192, 168, 68, 185);
IPAddress server(192, 168, 68, 103);

// Keys Pinout
int Key1 = 3;   //2  3
int Key2 = 6;   //4  6
int Key3 = 2;   //1   2
int Key4 = 5;   //3  5
int Key5 = 7;   //5  7
int Key6 = 8;  /// Incorrect Keys
// Current state of pins
int Key1S=0;
int Key2S=0;
int Key3S=0;
int Key4S=0;
int Key5S=0;
int Key6S=0;


// For saving last state of keys 
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


int Complete = 0;
int b=200;   // Delay  for button 




const int lightPin = 9;
const int button1 = A1; 
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


void setup()
{
  pinMode(Key1, INPUT_PULLUP);//Key 1
  pinMode(Key2, INPUT_PULLUP);//Key 2
  pinMode(Key3, INPUT_PULLUP);//Key 3
  pinMode(Key4, INPUT_PULLUP);//Key 4
  pinMode(Key5, INPUT_PULLUP);//Key 5
  pinMode(Key6, INPUT_PULLUP);// Incorrect Key

  
  pinMode(lightPin, OUTPUT);
  pinMode (button1,INPUT_PULLUP);
  digitalWrite(lightPin, LOW);
  
  Ethernet.begin(mac, ip);
  if (client.connect("arduinoClient")) {
    client.publish("outTopic","hello world");
    client.subscribe("inTopic");
  }
}

void loop()
{
   Key1S = digitalRead(Key1);
   Key2S = digitalRead(Key2);
   Key3S = digitalRead(Key3);
   Key4S = digitalRead(Key4);
   Key5S = digitalRead(Key5);
   Key6S = digitalRead(Key6);
     
     button1S = digitalRead (button1);



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





     
    if (button1S != button1LS) {
    if (button1S == LOW) {
      client.publish("outTopic", "Button Pressed");
      client.publish("outTopic", count);}
  button1LS = button1S;
  count++;
  delay (50);
    }
  client.loop();
}
