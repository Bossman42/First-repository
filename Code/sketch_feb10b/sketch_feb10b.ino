//Controlling Led By Button
//Turns on and off a LED ,when pressings button attach to pin12
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2015.5.7
/**********************************/
const int keyPin = 12; //the number of the key pin 12
const int ledPin = 13;//the number of the led pin 13
/**********************************/
void setup()
{
pinMode(keyPin,INPUT);//initialize the key pin as input 
pinMode(ledPin,OUTPUT);//initialize the led pin as output
}
/**********************************/
void loop()
{
//read the state of the key value
//and check if the kye is pressed
//if it is,the state is HIGH 
if(digitalRead(keyPin) ==HIGH )
{
digitalWrite(ledPin,HIGH);//turn on the led
}
else
{
digitalWrite(ledPin,LOW);//turn off the led
}
}
/************************************/
