#include <LiquidCrystal.h> 
 
int S = 0; // count seconds 
int M = 0; // count minutes
int H = 1; // count hours
//initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4,6,10,11,12,13); // pins connected to LCD
 
void setup()
{
 lcd.begin(16,2);//set up the LCD's number of columns and rows
}
void loop()
{
 lcd.setCursor(1,0); 
 lcd.print ("Boss-Play");
 lcd.setCursor(6,1);
 lcd.print(":");
 lcd.setCursor(9,1);
 lcd.print(":");
 
 S--;
 delay(1000);
  
 if(S<0)
 {
 M--;
 S=59;
 }
 if(M<0)
 {
 H--;
 M=59;
 }
 if(H<0)
 {
 H=23;
 M=59;
 S=59;
 }
 if(M>9)
 {
 lcd.setCursor(7,1);
 lcd.print(M);
 }
 else
 {
 lcd.setCursor(7,1);
 lcd.print("0"); 
 lcd.setCursor(8,1);
 lcd.print(M);
 lcd.setCursor(9,1);
 lcd.print(":");
 }
  
 if(S>9)
 {
 lcd.setCursor(10,1);
 lcd.print(S);
 }
 else
 {
 lcd.setCursor(10,1);
 lcd.print("0"); 
 lcd.setCursor(11,1);
 lcd.print(S);
 lcd.setCursor(12,1);
 lcd.print(" ");
 }
  
 if(H>9)
 {
 lcd.setCursor(4,1);
 lcd.print (H);
 }
 else
 {
 lcd.setCursor(4,1);
 lcd.print("0"); 
 lcd.setCursor(5,1);
 lcd.print(H);
 lcd.setCursor(6,1);
 lcd.print(":");
 }
}
