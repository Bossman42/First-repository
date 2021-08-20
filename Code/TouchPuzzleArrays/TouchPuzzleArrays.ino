int Led1 = 22;
int Led2 = 23;
int Led3 = 24;
int Led4 = 25;
int Led5 = 26;
int Led6 = 27;
int Led7 = 28;
int Led8 = 29;
int Led9 = 30;
int Led10 = 31;
int Led11 = 32;
int Led12 = 33;
int Led13 = 34;
int Led14 = 35;
int Led15 = 36;
int Led16 = 37;
int Led17 = 38;
int Led18 = 39;
int Led19 = 40;
int Led20 = 41;

int Touch = 2;
int Keyswitch = 3;
int Trigger = 4;

long Delay = 500;
int  CurrentLed = 22;

int LedPosition = 1;

void setup() {
pinMode (Led1, OUTPUT);
pinMode (Led2, OUTPUT);
pinMode (Led3, OUTPUT);
pinMode (Led4, OUTPUT);
pinMode (Led5, OUTPUT);
pinMode (Led6, OUTPUT);
pinMode (Led7, OUTPUT);
pinMode (Led8, OUTPUT);
pinMode (Led9, OUTPUT);
pinMode (Led10, OUTPUT);
pinMode (Led11, OUTPUT);
pinMode (Led12, OUTPUT);
pinMode (Led13, OUTPUT);
pinMode (Led14, OUTPUT);
pinMode (Led15, OUTPUT);
pinMode (Led16, OUTPUT);
pinMode (Led17, OUTPUT);
pinMode (Led18, OUTPUT);
pinMode (Led19, OUTPUT);
pinMode (Led20, OUTPUT);

digitalWrite (Led1, HIGH);
digitalWrite (Led2, HIGH);
digitalWrite (Led3, HIGH);
digitalWrite (Led4, HIGH);
digitalWrite (Led5, HIGH);
digitalWrite (Led6, HIGH);
digitalWrite (Led7, HIGH);
digitalWrite (Led8, HIGH);
digitalWrite (Led9, HIGH);
digitalWrite (Led10, HIGH);
digitalWrite (Led11, HIGH);
digitalWrite (Led12, HIGH);
digitalWrite (Led13, HIGH);
digitalWrite (Led14, HIGH);
digitalWrite (Led15, HIGH);
digitalWrite (Led16, HIGH);
digitalWrite (Led17, HIGH);
digitalWrite (Led18, HIGH);
digitalWrite (Led19, HIGH);
digitalWrite (Led20, HIGH);





pinMode (Touch, INPUT_PULLUP);
pinMode (Keyswitch, INPUT_PULLUP);
pinMode (Trigger,OUTPUT);
Serial.begin (9600);
digitalWrite (Trigger,HIGH);


}


void loop(){
  // put your main code here, to run repeatedly:
int TouchS = digitalRead(Touch);
int KeyswitchS = digitalRead(Keyswitch);
Serial.println (CurrentLed);

Serial.println (TouchS);
Serial.println (LedPosition);
Serial.println (KeyswitchS);
delay(Delay);
if (KeyswitchS == LOW && LedPosition == 1){
  
  LedPosition++;
  
}



if (TouchS == HIGH && LedPosition == 2){
   digitalWrite (Led1,LOW);
     LedPosition++;
   delay(Delay);
}
   else
   if (TouchS == HIGH && LedPosition == 3){
   digitalWrite (Led2,LOW);
        LedPosition++;
      delay(Delay);
   }
     else
        if (TouchS == HIGH && LedPosition == 4){
   digitalWrite (Led3,LOW);
        LedPosition++;
      delay(Delay);
        }
          else
        if (TouchS == HIGH && LedPosition == 5){
   digitalWrite (Led4,LOW);
        LedPosition++;
      delay(Delay);
        }
          else
        if (TouchS == HIGH && LedPosition == 6){
   digitalWrite (Led5,LOW);
        LedPosition++;
      delay(Delay);
        }
          else
        if (TouchS == HIGH && LedPosition == 7){
   digitalWrite (Led6,LOW);
        LedPosition++;
      delay(Delay);
        }
          else
        if (TouchS == HIGH && LedPosition == 8){
   digitalWrite (Led7,LOW);
        LedPosition++;
      delay(Delay);
        }
          else
        if (TouchS == HIGH && LedPosition == 9){
   digitalWrite (Led8,LOW);
        LedPosition++;
      delay(Delay);
        }
          else
              if (TouchS == HIGH && LedPosition == 10){
   digitalWrite (Led9,LOW);
     
      delay(Delay);
              }
      //Going Down


      

        if (TouchS == LOW && LedPosition == 10){
   digitalWrite (Led9,HIGH);
        LedPosition--;
      delay(Delay);
      
        }
          else
        if (TouchS == LOW && LedPosition == 9){
   digitalWrite (Led8,HIGH);
        LedPosition--;
      delay(Delay);
        }
              else
              if (TouchS == LOW && LedPosition == 8){
   digitalWrite (Led7,HIGH);
        LedPosition--;
      delay(Delay);
              }
                else
              if (TouchS == LOW && LedPosition == 7){
   digitalWrite (Led6,HIGH);
        LedPosition--;
      delay(Delay);
              }
                else
              if (TouchS == LOW && LedPosition == 6){
   digitalWrite (Led5,HIGH);
        LedPosition--;
      delay(Delay);
              }
                else
              if (TouchS == LOW && LedPosition == 5){
   digitalWrite (Led4,HIGH);
        LedPosition--;
      delay(Delay);
              }
                else
              if (TouchS == LOW && LedPosition == 4){
   digitalWrite (Led3,HIGH);
        LedPosition--;
      delay(Delay);
              }
                else
              if (TouchS == LOW && LedPosition == 3){
   digitalWrite (Led2,HIGH);
        LedPosition--;
      delay(Delay);
              }
                else
              if (TouchS == LOW && LedPosition == 2){
   digitalWrite (Led1,HIGH);
    LedPosition--;
    LedPosition--;
      delay(Delay);
}
if (LedPosition == 0 && TouchS == LOW){
digitalWrite (Trigger,LOW);
}
  
}





