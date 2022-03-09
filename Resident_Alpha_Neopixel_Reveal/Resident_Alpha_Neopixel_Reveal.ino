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

#include <Adafruit_NeoPixel.h>
#define NUMPIXELS 100  
#define PIN        33
#define NUMPIXELS2 100  
#define PIN2        31

int     mode     = 0;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);


#define DELAYVAL 200 // Time (in milliseconds) to pause between pixels

// Update these with values suitable for your network.
byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
IPAddress ip(192, 168, 68, 185);
IPAddress server(192, 168, 68, 110);
int scene = 0;
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;
int f = 0;
int g = 0;
int h = 0;
int i = 0;
int j = 0;
int k = 0;






// Callback function header
void callback(char* topic, byte* payload, unsigned int length);

EthernetClient ethClient;
PubSubClient client(server, 1883, callback, ethClient);

// Callback function
void callback(char* topic, byte* payload, unsigned int length) {
    
  //turn the LED ON if the payload is '1' and publish to the MQTT server a confirmation message
  if(payload[0] == '1'){
  mode = 1;
  scene = 0;
    client.publish("outTopic", mode); }
    
  //turn the LED OFF if the payload is '0' and publish to the MQTT server a confirmation message
  if (payload[0] == '0'){
   mode = 0;
   scene = 0;
   pixels.clear();
    pixels.show();
    
       pixels2.clear();
    pixels2.show(); 
      a=1;
    client.publish("outTopic", "reset");
    }




} // void callback


void setup()
{
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
   pixels2.begin();

  
  Ethernet.begin(mac, ip);
  if (client.connect("arduinoClient")) {
    client.publish("outTopic","hello world");
    client.subscribe("inTopic");
  }
}

void loop()
{    //pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  if (mode == 1 && scene == 0){
  //for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
   for(a=NUMPIXELS; a>0; a--) { // For each pixel...

      b = a+1;  
      c = a+5;
      d = a+7;
      e = a+12;
      f = a+3;
      g = a+9;
      h = a+15;
      i = a+20;
      j = a+25;
      k = a+ 27;


     
     
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(a, pixels.Color(0, 100, 0));
    pixels.setPixelColor(b, pixels.Color(0, 20, 0));
    pixels.setPixelColor(c, pixels.Color(0, 150, 0));
    pixels.setPixelColor(d, pixels.Color(0, 61, 0));
    pixels.setPixelColor(e, pixels.Color(0, 200, 0));
    pixels.setPixelColor(f, pixels.Color(0, 20, 0));
    pixels.setPixelColor(g, pixels.Color(0, 45, 0));
    pixels.setPixelColor(h, pixels.Color(0, 255, 0));
    pixels.setPixelColor(i, pixels.Color(0, 100, 0));
    pixels.setPixelColor(j, pixels.Color(0, 23, 0));
    pixels.setPixelColor(k, pixels.Color(0, 150, 0));


    pixels2.setPixelColor(a, pixels2.Color(100, 0, 0));
    pixels2.setPixelColor(b, pixels2.Color(75, 0, 0));
    pixels2.setPixelColor(c, pixels2.Color(150, 0, 0));
    pixels2.setPixelColor(d, pixels2.Color(61, 0, 0));
    pixels2.setPixelColor(e, pixels2.Color(200, 0, 0));
    pixels2.setPixelColor(f, pixels2.Color(20, 0, 0));
    pixels2.setPixelColor(g, pixels2.Color(65, 0, 0));
    pixels2.setPixelColor(h, pixels2.Color(255, 0, 0));
    pixels2.setPixelColor(i, pixels2.Color(100, 0, 0));
    pixels2.setPixelColor(j, pixels2.Color(45, 0, 0));
    pixels2.setPixelColor(k, pixels2.Color(150, 0, 0));

    
       client.loop();
        

    pixels.show(); 
    pixels2.show();// Send the updated pixel colors to the hardware.

    delay(DELAYVAL);
    scene = 2;// Pause before next pass through loop
  }}
  if (mode == 1 && scene == 2){
  
   for( a=NUMPIXELS; a>0; a--) { // For each pixel...
  if (b > 0){b --;}else b= random(NUMPIXELS);
  if (c > 0){c --;}else c= random(NUMPIXELS);
  if (d > 0){d --;}else d= random(NUMPIXELS);
  if (e > 0){e --;}else e= random(NUMPIXELS);
  if (f > 0){f --;}else f= random(NUMPIXELS);
  if (g > 0){g --;}else g= random(NUMPIXELS);
  if (h > 0){h --;}else h= random(NUMPIXELS);
  if (i > 0){i --;}else i= random(NUMPIXELS);
  if (j > 0){j --;}else j= random(NUMPIXELS);
  if (k > 0){k --;}else k= random(NUMPIXELS);


     
     
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(a, pixels.Color(0, 100, 0));
    pixels.setPixelColor(b, pixels.Color(0, 20, 0));
    pixels.setPixelColor(c, pixels.Color(0, 150, 0));
    pixels.setPixelColor(d, pixels.Color(0, 61, 0));
    pixels.setPixelColor(e, pixels.Color(0, 200, 0));
    pixels.setPixelColor(f, pixels.Color(0, 20, 0));
    pixels.setPixelColor(g, pixels.Color(0, 45, 0));
    pixels.setPixelColor(h, pixels.Color(0, 255, 0));
    pixels.setPixelColor(i, pixels.Color(0, 100, 0));
    pixels.setPixelColor(j, pixels.Color(0, 23, 0));
    pixels.setPixelColor(k, pixels.Color(0, 150, 0));



    pixels2.setPixelColor(a, pixels2.Color(100, 0, 0));
    pixels2.setPixelColor(b, pixels2.Color(75, 0, 0));
    pixels2.setPixelColor(c, pixels2.Color(150, 0, 0));
    pixels2.setPixelColor(d, pixels2.Color(61, 0, 0));
    pixels2.setPixelColor(e, pixels2.Color(200, 0, 0));
    pixels2.setPixelColor(f, pixels2.Color(20, 0, 0));
    pixels2.setPixelColor(g, pixels2.Color(65, 0, 0));
    pixels2.setPixelColor(h, pixels2.Color(255, 0, 0));
    pixels2.setPixelColor(i, pixels2.Color(100, 0, 0));
    pixels2.setPixelColor(j, pixels2.Color(45, 0, 0));
    pixels2.setPixelColor(k, pixels2.Color(150, 0, 0));
       
        client.loop();

    pixels.show();
    pixels2.show();// Send the updated pixel colors to the hardware.

    delay(DELAYVAL);// Pause before next pass through loop
  }}
   
    pixels.show();
    pixels2.show();
  client.loop();
}
