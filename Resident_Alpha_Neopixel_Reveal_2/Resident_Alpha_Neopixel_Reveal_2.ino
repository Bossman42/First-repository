/*
 Publishing in the callback
  - connects to an MQTT server
  - subscribes to the topic "inTopic"
  - when a message is received, republishes it to "outTopic"
  This example shows how to control pins using Ethernet shield via MQTT


  This is version 2
*/



#include <Adafruit_NeoPixel.h>
#define NUMPIXELS 300  
#define NUMPIXELS2 300  
#define NUMPIXELS3 300  
#define NUMPIXELS4 300  
#define NUMPIXELS5 150 
#define NUMPIXELS6 300  

#define PIN        31  // planet helix with dot in middle or #2
#define PIN2        33 // T Function thing #3
#define PIN3        35 // H with arrows #1
#define PIN4        37  //#4
#define PIN5        39  // Blood Tube
#define PIN6        41 // #5

int Canister1 = 22 ;
int Canister2 = 24 ;
int Canister3 = 26 ;
int Canister4 = 28 ;
int Canister5 = 30 ;
int LCanister1S = 0 ;
int LCanister2S = 0 ;
int LCanister3S = 0 ;
int LCanister4S = 0 ;
int LCanister5S = 0 ;

int Canister1S = 0 ;
int Canister2S = 0 ;
int Canister3S = 0 ;
int Canister4S = 0 ;
int Canister5S = 0 ;

int canister1placed = 0;
int canister2placed = 0;
int canister3placed = 0;
int canister4placed = 0;
int canister5placed = 0;



int Mag1 = 38 ;
int Mag2 = 40 ;

int mode = 0 ;
int breakout = 0;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3(NUMPIXELS3, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4(NUMPIXELS4, PIN4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels5(NUMPIXELS5, PIN5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels6(NUMPIXELS6, PIN6, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 10 // Time (in milliseconds) to pause between pixels


int scene = 1;
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
int l = 0;








void setup()
{
   pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
   pixels2.begin();
   pixels3.begin();
   pixels4.begin();
   pixels5.begin();
   pixels6.begin();

     pinMode(Canister1, INPUT_PULLUP);
     pinMode(Canister2, INPUT_PULLUP);
     pinMode(Canister3, INPUT_PULLUP);
     pinMode(Canister4, INPUT_PULLUP);
     pinMode(Canister5, INPUT_PULLUP);

       pinMode(Mag1, OUTPUT);
       pinMode(Mag2, OUTPUT);

           digitalWrite (Mag1,LOW);
           digitalWrite (Mag2,LOW);
           Serial.println ("Mag 1 ON");
           Serial.println ("Mag 2 ON");
       
Serial.begin(9600);
Serial.println ("Zombie Antidote online");
delay (200);
Serial.println ("aa = start timer");
delay (200);
Serial.println ("bb = pause timer");
delay (200);
Serial.println ("cc = add 1 minute to timer");
delay (200);
Serial.println ("dd == add 5 minutes to timer");
delay (200);
Serial.println ("ee == reset timer to 10:00 and stops timer");
delay (200);
Serial.println ("ff == sub 1 minute from timer");
delay (200);
Serial.println ("gg == sub 5 minutes from timer");
delay (200);
Serial.println ("Bomb Ready");
}
  



void loop()
{    //pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  handleSerial(); 
  

 

 if (Canister1S == LOW && Canister2S == LOW 
 && Canister3S == LOW && Canister4S == LOW 
 && Canister5S == LOW && scene == 1 || mode == 1){
  
 
 
 // if (mode == 1 && scene == 0){
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

    pixels2.setPixelColor(a, pixels2.Color(0, 100, 0));
    pixels2.setPixelColor(b, pixels2.Color(0, 20, 0));
    pixels2.setPixelColor(c, pixels2.Color(0, 150, 0));
    pixels2.setPixelColor(d, pixels2.Color(0, 61, 0));
    pixels2.setPixelColor(e, pixels2.Color(0, 200, 0));
    pixels2.setPixelColor(f, pixels2.Color(0, 20, 0));
    pixels2.setPixelColor(g, pixels2.Color(0, 45, 0));
    pixels2.setPixelColor(h, pixels2.Color(0, 255, 0));
    pixels2.setPixelColor(i, pixels2.Color(0, 100, 0));
    pixels2.setPixelColor(j, pixels2.Color(0, 23, 0));
    pixels2.setPixelColor(k, pixels2.Color(0, 150, 0));


    pixels3.setPixelColor(a, pixels3.Color(0, 100, 0));
    pixels3.setPixelColor(b, pixels3.Color(0, 20, 0));
    pixels3.setPixelColor(c, pixels3.Color(0, 150, 0));
    pixels3.setPixelColor(d, pixels3.Color(0, 61, 0));
    pixels3.setPixelColor(e, pixels3.Color(0, 200, 0));
    pixels3.setPixelColor(f, pixels3.Color(0, 20, 0));
    pixels3.setPixelColor(g, pixels3.Color(0, 45, 0));
    pixels3.setPixelColor(h, pixels3.Color(0, 255, 0));
    pixels3.setPixelColor(i, pixels3.Color(0, 100, 0));
    pixels3.setPixelColor(j, pixels3.Color(0, 23, 0));
    pixels3.setPixelColor(k, pixels3.Color(0, 150, 0));

    pixels4.setPixelColor(a, pixels4.Color(0, 100, 0));
    pixels4.setPixelColor(b, pixels4.Color(0, 20, 0));
    pixels4.setPixelColor(c, pixels4.Color(0, 150, 0));
    pixels4.setPixelColor(d, pixels4.Color(0, 61, 0));
    pixels4.setPixelColor(e, pixels4.Color(0, 200, 0));
    pixels4.setPixelColor(f, pixels4.Color(0, 20, 0));
    pixels4.setPixelColor(g, pixels4.Color(0, 45, 0));
    pixels4.setPixelColor(h, pixels4.Color(0, 255, 0));
    pixels4.setPixelColor(i, pixels4.Color(0, 100, 0));
    pixels4.setPixelColor(j, pixels4.Color(0, 23, 0));
    pixels4.setPixelColor(k, pixels4.Color(0, 150, 0));

    pixels6.setPixelColor(a, pixels6.Color(0, 100, 0));
    pixels6.setPixelColor(b, pixels6.Color(0, 20, 0));
    pixels6.setPixelColor(c, pixels6.Color(0, 150, 0));
    pixels6.setPixelColor(d, pixels6.Color(0, 61, 0));
    pixels6.setPixelColor(e, pixels6.Color(0, 200, 0));
    pixels6.setPixelColor(f, pixels6.Color(0, 20, 0));
    pixels6.setPixelColor(g, pixels6.Color(0, 45, 0));
    pixels6.setPixelColor(h, pixels6.Color(0, 255, 0));
    pixels6.setPixelColor(i, pixels6.Color(0, 100, 0));
    pixels6.setPixelColor(j, pixels6.Color(0, 23, 0));
    pixels6.setPixelColor(k, pixels6.Color(0, 150, 0));
    
      handleSerial();
      if (breakout == 1){
        break;
      }
        
    pixels.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
    pixels5.show();
    pixels6.show();

    delay(DELAYVAL);
    scene = 2;// Pause before next pass through loop
  }}  
  if (Canister1S == LOW && Canister2S == LOW 
 && Canister3S == LOW && Canister4S == LOW 
 && Canister5S == LOW && scene == 2 || mode == 1){

  for( l=0; l<NUMPIXELS5; l++) { // For each pixel...

      b = l+1;  
      c = l+5;
      d = l+7;
      e = l+12;
      f = l+3;
      g = l+9;
      h = l+15;
      i = l+20;
      j = l+25;
      k = l+ 27;
    
    pixels5.setPixelColor(a, pixels5.Color(100, 0, 0));
    pixels5.setPixelColor(b, pixels5.Color(75, 0, 0));
    pixels5.setPixelColor(c, pixels5.Color(150, 0, 0));
    pixels5.setPixelColor(d, pixels5.Color(61, 0, 0));
    pixels5.setPixelColor(e, pixels5.Color(200, 0, 0));
    pixels5.setPixelColor(f, pixels5.Color(20, 0, 0));
    pixels5.setPixelColor(g, pixels5.Color(65, 0, 0));
    pixels5.setPixelColor(h, pixels5.Color(255, 0, 0));
    pixels5.setPixelColor(i, pixels5.Color(100, 0, 0));
    pixels5.setPixelColor(j, pixels5.Color(45, 0, 0));
    pixels5.setPixelColor(k, pixels5.Color(150, 0, 0));
          handleSerial();
      if (breakout == 1){
        break;
      }
     pixels5.show();
       scene = 3;
        delay(100);
  }
  
     digitalWrite (Mag1,HIGH);
     Serial.println ("They got the Antidote!");
     Serial.println ("Mag 1 OFF");}
 



 if (Canister1S == LOW && Canister2S == LOW 
 && Canister3S == LOW && Canister4S == LOW 
 && Canister5S == LOW && scene == 3 || mode == 1){
    
  
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

    pixels2.setPixelColor(a, pixels2.Color(0, 100, 0));
    pixels2.setPixelColor(b, pixels2.Color(0, 20, 0));
    pixels2.setPixelColor(c, pixels2.Color(0, 150, 0));
    pixels2.setPixelColor(d, pixels2.Color(0, 61, 0));
    pixels2.setPixelColor(e, pixels2.Color(0, 200, 0));
    pixels2.setPixelColor(f, pixels2.Color(0, 20, 0));
    pixels2.setPixelColor(g, pixels2.Color(0, 45, 0));
    pixels2.setPixelColor(h, pixels2.Color(0, 255, 0));
    pixels2.setPixelColor(i, pixels2.Color(0, 100, 0));
    pixels2.setPixelColor(j, pixels2.Color(0, 23, 0));
    pixels2.setPixelColor(k, pixels2.Color(0, 150, 0));


    pixels3.setPixelColor(a, pixels3.Color(0, 100, 0));
    pixels3.setPixelColor(b, pixels3.Color(0, 20, 0));
    pixels3.setPixelColor(c, pixels3.Color(0, 150, 0));
    pixels3.setPixelColor(d, pixels3.Color(0, 61, 0));
    pixels3.setPixelColor(e, pixels3.Color(0, 200, 0));
    pixels3.setPixelColor(f, pixels3.Color(0, 20, 0));
    pixels3.setPixelColor(g, pixels3.Color(0, 45, 0));
    pixels3.setPixelColor(h, pixels3.Color(0, 255, 0));
    pixels3.setPixelColor(i, pixels3.Color(0, 100, 0));
    pixels3.setPixelColor(j, pixels3.Color(0, 23, 0));
    pixels3.setPixelColor(k, pixels3.Color(0, 150, 0));

    pixels4.setPixelColor(a, pixels4.Color(0, 100, 0));
    pixels4.setPixelColor(b, pixels4.Color(0, 20, 0));
    pixels4.setPixelColor(c, pixels4.Color(0, 150, 0));
    pixels4.setPixelColor(d, pixels4.Color(0, 61, 0));
    pixels4.setPixelColor(e, pixels4.Color(0, 200, 0));
    pixels4.setPixelColor(f, pixels4.Color(0, 20, 0));
    pixels4.setPixelColor(g, pixels4.Color(0, 45, 0));
    pixels4.setPixelColor(h, pixels4.Color(0, 255, 0));
    pixels4.setPixelColor(i, pixels4.Color(0, 100, 0));
    pixels4.setPixelColor(j, pixels4.Color(0, 23, 0));
    pixels4.setPixelColor(k, pixels4.Color(0, 150, 0));

    pixels6.setPixelColor(a, pixels6.Color(0, 100, 0));
    pixels6.setPixelColor(b, pixels6.Color(0, 20, 0));
    pixels6.setPixelColor(c, pixels6.Color(0, 150, 0));
    pixels6.setPixelColor(d, pixels6.Color(0, 61, 0));
    pixels6.setPixelColor(e, pixels6.Color(0, 200, 0));
    pixels6.setPixelColor(f, pixels6.Color(0, 20, 0));
    pixels6.setPixelColor(g, pixels6.Color(0, 45, 0));
    pixels6.setPixelColor(h, pixels6.Color(0, 255, 0));
    pixels6.setPixelColor(i, pixels6.Color(0, 100, 0));
    pixels6.setPixelColor(j, pixels6.Color(0, 23, 0));
    pixels6.setPixelColor(k, pixels6.Color(0, 150, 0));

    pixels5.setPixelColor(a, pixels5.Color(100, 0, 0));
    pixels5.setPixelColor(b, pixels5.Color(75, 0, 0));
    pixels5.setPixelColor(c, pixels5.Color(150, 0, 0));
    pixels5.setPixelColor(d, pixels5.Color(61, 0, 0));
    pixels5.setPixelColor(e, pixels5.Color(200, 0, 0));
    pixels5.setPixelColor(f, pixels5.Color(20, 0, 0));
    pixels5.setPixelColor(g, pixels5.Color(65, 0, 0));
    pixels5.setPixelColor(h, pixels5.Color(255, 0, 0));
    pixels5.setPixelColor(i, pixels5.Color(100, 0, 0));
    pixels5.setPixelColor(j, pixels5.Color(45, 0, 0));
    pixels5.setPixelColor(k, pixels5.Color(150, 0, 0));

      handleSerial();
      if (breakout == 1){
        break;
      }
      
    pixels.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
    pixels5.show();
    pixels6.show();

    delay(DELAYVAL);// Pause before next pass through loop
  }  }
   
    pixels.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
    pixels5.show();
    pixels6.show();
    
 handleSerial();
}




void handleSerial(){
  while (Serial.available()>0){
    char incomingCharacter = Serial.read();
    switch (incomingCharacter) {
        case 'a':
        mode = 1;
        breakout = 0;
   //   gametimer = 1;
   //   standby = 0;
      Serial.println ("Mode 1");
      break;  
        
      case 'b':
      mode = 0;
                   pixels.clear();
             pixels2.clear(); 
             pixels3.clear();
             pixels4.clear();
             pixels5.clear();
             pixels6.clear();
     
             pixels.show();
             pixels2.show();
             pixels3.show();
             pixels4.show();
             pixels5.show();
             pixels6.show();
             breakout = 1;
             digitalWrite (Mag1,LOW);
             digitalWrite (Mag2,LOW);
      Serial.println ("Mode 0");
      break;      
           
      case 'c':
    // Mag 1 on
    digitalWrite (Mag1,LOW);
      Serial.println ("Mag 1 ON");
      break;

      case 'd':
    digitalWrite (Mag1,HIGH);
      Serial.println ("Mag 1 OFF");
      break;

      case 'e':
    digitalWrite (Mag2,LOW);
      Serial.println ("Mag 2 ON");
      break;

      case 'f':
    digitalWrite (Mag2,HIGH);
      Serial.println ("Mag 2 OFF");
      break;

      case 'g':
     // status
      Serial.print ("Scene    ");
      Serial.println (scene);
      Serial.print ("Canister 1 State    ");
      Serial.println (Canister1S);
      Serial.print ("Canister 2 State    ");
      Serial.println (Canister2S);
      Serial.print ("Canister 3 State    ");
      Serial.println (Canister3S);
      Serial.print ("Canister 4 State    ");
      Serial.println (Canister4S);
      Serial.print ("Canister 5 State    ");
      Serial.println (Canister5S);
      Serial.print ("Mode     ");
      Serial.println (mode);


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
  Canister1S = digitalRead(Canister1);
  Canister2S = digitalRead(Canister2);
  Canister3S = digitalRead(Canister3);
  Canister4S = digitalRead(Canister4);
  Canister5S = digitalRead(Canister5);
  

 
  
    if (Canister1S != LCanister1S) {    
      if (Canister1S == LOW) {
             for( a=NUMPIXELS; a>0; a--) { // For each pixel...
             pixels4.setPixelColor(a, pixels4.Color(0, 0, 200));
             pixels4.show();}}
      if (Canister1S == LOW){
             breakout = 0;
             Serial.println ("Canister1 placed");}    
      if (Canister1S == HIGH){
             pixels4.clear();
             pixels4.show();
             breakout = 1;
             Serial.println ("Canister1 Removed");
             scene = 1;}
    }
 LCanister1S = Canister1S;





 
    if (Canister2S != LCanister2S) {    
      if (Canister2S == LOW) {
             for( a=NUMPIXELS; a>0; a--) { // For each pixel...
             pixels2.setPixelColor(a, pixels2.Color(0, 0, 200));
             pixels2.show();}}
      if (Canister2S == LOW){
             breakout = 0;
             Serial.println ("Canister2 placed");}    
      if (Canister2S == HIGH){
             pixels2.clear();
             pixels2.show();
             breakout = 1;
             Serial.println ("Canister2 Removed");
             scene = 1;}
    }
 LCanister2S = Canister2S;

 
    if (Canister3S != LCanister3S) {    
      if (Canister3S == LOW) {
             for( a=NUMPIXELS; a>0; a--) { // For each pixel...
             pixels6.setPixelColor(a, pixels6.Color(0, 0, 200));
             pixels6.show();}}
      if (Canister3S == LOW){
             breakout = 0;
             Serial.println ("Canister3 placed");}    
      if (Canister3S == HIGH){
             pixels6.clear();
             pixels6.show();
             breakout = 1;
             Serial.println ("Canister3 Removed");
             scene = 1;}
    }
 LCanister3S = Canister3S;


 
    if (Canister4S != LCanister4S) {    
      if (Canister4S == LOW) {
             for( a=NUMPIXELS; a>0; a--) { // For each pixel...
             pixels.setPixelColor(a, pixels.Color(0, 0, 200));
             pixels.show();}}
      if (Canister4S == LOW){
             breakout = 0;
             Serial.println ("Canister4 placed");}    
      if (Canister4S == HIGH){
             pixels.clear();
             pixels.show();
             breakout = 1;
             Serial.println ("Canister4 Removed");
             scene = 1;}
    }
 LCanister4S = Canister4S;



    
    

 
    if (Canister5S != LCanister5S && mode == 0) {    
      if (Canister5S == LOW) {
             for( a=NUMPIXELS; a>0; a--) { // For each pixel...
             pixels3.setPixelColor(a, pixels3.Color(0, 0, 200));
             pixels3.show();}}
      if (Canister5S == LOW){
             breakout = 0;
             scene = 1;
             Serial.println ("Canister5 placed");}    
      if (Canister5S == HIGH){
            pixels3.clear(); 
            pixels3.show();
             breakout = 1;
             Serial.println ("Canister5 Removed");
             scene = 1;}
    }
 LCanister5S = Canister5S;

 
//// For resetting puzzle after all canisters are removed
/* if (Canister1S == 1 && Canister2S == 1 
 && Canister3S == 1 && Canister4S == 1
 && Canister5S == 1 && scene >=2 && mode == 0){
             pixels.clear();
             pixels2.clear(); 
             pixels3.clear();
             pixels4.clear();
             pixels5.clear();
             pixels6.clear();
     
             pixels.show();
             pixels2.show();
             pixels3.show();
             pixels4.show();
             pixels5.show();
             pixels6.show();
             breakout = 0;
             scene = 1;
             Serial.println ("Game is Reset");
 }
*/
  
}


/// END ///
