/*
 Publishing in the callback
  - connects to an MQTT server
  - subscribes to the topic "inTopic"
  - when a message is received, republishes it to "outTopic"
  This example shows how to control pins using Ethernet shield via MQTT
*/

#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
IPAddress ip(192, 168, 68, 185);
IPAddress server(192, 168, 68, 105);

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


void setup()
{
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
     button1S = digitalRead (button1);
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
