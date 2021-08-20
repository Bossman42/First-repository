//Piano Puzzle
int Key1 = 2;   
int Key2 = 3;
int Key3 = 4; 
int Key4 = 5; 
int Key5 = 6;
int Key6 = 7;

int Led1 =  A0;
int Led2 =  A1;
int Led3 =  A2;   
int Led4 =  A3;   
int Led5 =  A4; 
int Led6 =  A5; 
int Led7 =  A6; 
int Led8 =  A7; 
int Led9 =  A8; 
int Led10 =  A9; 
int Led11 =  A10; 
int Led12 =  A11; 
int Led13 =  A12; 
int Led14 =  A13; 
int Led15 =  A14; 
int Led16 =  A15; 

int Trigger = 13;

                 //Have to declare these before void setup

void setup() {
  pinMode(Key1, INPUT_PULLUP);//Key 1
  pinMode(Key2, INPUT_PULLUP);//Key 2
  pinMode(Key3, INPUT_PULLUP);//Key 3
  pinMode(Key4, INPUT_PULLUP);//Key 4
  pinMode(Key5, INPUT_PULLUP);//Key 5
  pinMode(Key6, INPUT_PULLUP);//Key 6

   pinMode(Led1, OUTPUT);// Led1
   pinMode(Led2, OUTPUT);// Led2
   pinMode(Led3, OUTPUT);// Led3
   pinMode(Led4, OUTPUT);// Led4
   pinMode(Led5, OUTPUT);// Led5
   pinMode(Led6, OUTPUT);// Led6
   pinMode(Led7, OUTPUT);// Led7
   pinMode(Led8, OUTPUT);// Led8
   pinMode(Led9, OUTPUT);// Led9
   pinMode(Led10, OUTPUT);// Led10
   pinMode(Led11, OUTPUT);// Led11
   pinMode(Led12, OUTPUT);// Led12
   pinMode(Led13, OUTPUT);// Led13
   pinMode(Led14, OUTPUT);// Led14
   pinMode(Led15, OUTPUT);// Led15
   pinMode(Led16, OUTPUT);// Led16

   pinMode(Trigger, OUTPUT);
               
   
digitalWrite(Led1,HIGH);
digitalWrite(Led2,HIGH);
digitalWrite(Led3,HIGH);
digitalWrite(Led4,HIGH);
digitalWrite(Led5,HIGH);
digitalWrite(Led6,HIGH);
digitalWrite(Led7,HIGH);
digitalWrite(Led8,HIGH);
digitalWrite(Led9,HIGH);
digitalWrite(Led10,HIGH);
digitalWrite(Led11,HIGH);
digitalWrite(Led12,HIGH);
digitalWrite(Led13,HIGH);
digitalWrite(Led14,HIGH);
digitalWrite(Led15,HIGH);
digitalWrite(Led16,HIGH);
digitalWrite(Trigger,HIGH);

  Serial.begin(9600);
  Serial.println("Yep");
  }


void loop() {
     
  int Key1S = digitalRead(Key1);
  int Key2S = digitalRead(Key2);
  int Key3S = digitalRead(Key3);
  int Key4S = digitalRead(Key4);
  int Key5S = digitalRead(Key5);
  int Key6S = digitalRead(Key6);
  

  int Led1S = analogRead(Led1);
  int Led2S = analogRead(Led2);
  int Led3S = analogRead(Led3);
  int Led4S = analogRead(Led4);
  int Led5S = analogRead(Led5);
  int Led6S = analogRead(Led6);
  int Led7S = analogRead(Led7);
  int Led8S = analogRead(Led8);
  int Led9S = analogRead(Led9);
  int Led10S = analogRead(Led10);
  int Led11S = analogRead(Led11);
  int Led12S = analogRead(Led12);
  int Led13S = analogRead(Led13);
  int Led14S = analogRead(Led14);
  int Led15S = analogRead(Led15);
  int Led16S = analogRead(Led16);
  
      Serial.println (Key1S);
      Serial.println (Key2S);
      Serial.println (Key3S);
      Serial.println (Key4S);
      Serial.println (Key5S);
      Serial.println (Key6S);
      
      Serial.println(Led1S);
      Serial.println(Led2S);
      Serial.println(Led3S);
      Serial.println(Led4S);
      Serial.println(Led5S);
    
      
//Reset Key  
      if (Key6S == LOW){
      digitalWrite(Led1, HIGH);digitalWrite(Led2, HIGH);digitalWrite(Led3, HIGH);digitalWrite(Led4, HIGH);digitalWrite(Led5, HIGH);digitalWrite(Led6, HIGH);digitalWrite(Led7, HIGH);digitalWrite(Led8, HIGH);digitalWrite(Led9, HIGH);digitalWrite(Led10, HIGH);digitalWrite(Led11, HIGH);digitalWrite(Led12, HIGH);digitalWrite(Led13, HIGH);digitalWrite(Led14, HIGH);digitalWrite(Led15, HIGH);digitalWrite(Led16, HIGH);} 
// Pressing 2 notes      
      else if (Key1S == LOW && Key2S == LOW && Key3S == HIGH && Key4S == HIGH && Key5S == HIGH){  
      digitalWrite(Led1, HIGH);digitalWrite(Led2, HIGH);digitalWrite(Led3, HIGH);digitalWrite(Led4, HIGH);digitalWrite(Led5, HIGH);digitalWrite(Led6, HIGH);digitalWrite(Led7, HIGH);digitalWrite(Led8, HIGH);digitalWrite(Led9, HIGH);digitalWrite(Led10, HIGH);digitalWrite(Led11, HIGH);digitalWrite(Led12, HIGH);digitalWrite(Led13, HIGH);digitalWrite(Led14, HIGH);digitalWrite(Led15, HIGH);digitalWrite(Led16, HIGH);}

      else if (Key1S == LOW && Key2S == HIGH && Key3S == LOW && Key4S == HIGH && Key5S == HIGH){  
      digitalWrite(Led1, HIGH);digitalWrite(Led2, HIGH);digitalWrite(Led3, HIGH);digitalWrite(Led4, HIGH);digitalWrite(Led5, HIGH);digitalWrite(Led6, HIGH);digitalWrite(Led7, HIGH);digitalWrite(Led8, HIGH);digitalWrite(Led9, HIGH);digitalWrite(Led10, HIGH);digitalWrite(Led11, HIGH);digitalWrite(Led12, HIGH);digitalWrite(Led13, HIGH);digitalWrite(Led14, HIGH);digitalWrite(Led15, HIGH);digitalWrite(Led16, HIGH);}

      else if (Key1S == LOW && Key2S == HIGH && Key3S == HIGH && Key4S == LOW && Key5S == HIGH){  
      digitalWrite(Led1, HIGH);digitalWrite(Led2, HIGH);digitalWrite(Led3, HIGH);digitalWrite(Led4, HIGH);digitalWrite(Led5, HIGH);digitalWrite(Led6, HIGH);digitalWrite(Led7, HIGH);digitalWrite(Led8, HIGH);digitalWrite(Led9, HIGH);digitalWrite(Led10, HIGH);digitalWrite(Led11, HIGH);digitalWrite(Led12, HIGH);digitalWrite(Led13, HIGH);digitalWrite(Led14, HIGH);digitalWrite(Led15, HIGH);digitalWrite(Led16, HIGH);}

      else if (Key1S == LOW && Key2S == HIGH && Key3S == HIGH && Key4S == HIGH && Key5S == LOW){  
      digitalWrite(Led1, HIGH);digitalWrite(Led2, HIGH);digitalWrite(Led3, HIGH);digitalWrite(Led4, HIGH);digitalWrite(Led5, HIGH);digitalWrite(Led6, HIGH);digitalWrite(Led7, HIGH);digitalWrite(Led8, HIGH);digitalWrite(Led9, HIGH);digitalWrite(Led10, HIGH);digitalWrite(Led11, HIGH);digitalWrite(Led12, HIGH);digitalWrite(Led13, HIGH);digitalWrite(Led14, HIGH);digitalWrite(Led15, HIGH);digitalWrite(Led16, HIGH);}

      else if (Key1S == HIGH && Key2S == LOW && Key3S == LOW && Key4S == HIGH && Key5S == HIGH){  
      digitalWrite(Led1, HIGH);digitalWrite(Led2, HIGH);digitalWrite(Led3, HIGH);digitalWrite(Led4, HIGH);digitalWrite(Led5, HIGH);digitalWrite(Led6, HIGH);digitalWrite(Led7, HIGH);digitalWrite(Led8, HIGH);digitalWrite(Led9, HIGH);digitalWrite(Led10, HIGH);digitalWrite(Led11, HIGH);digitalWrite(Led12, HIGH);digitalWrite(Led13, HIGH);digitalWrite(Led14, HIGH);digitalWrite(Led15, HIGH);digitalWrite(Led16, HIGH);}

      else if (Key1S == HIGH && Key2S == LOW && Key3S == HIGH && Key4S == LOW && Key5S == HIGH){  
      digitalWrite(Led1, HIGH);digitalWrite(Led2, HIGH);digitalWrite(Led3, HIGH);digitalWrite(Led4, HIGH);digitalWrite(Led5, HIGH);digitalWrite(Led6, HIGH);digitalWrite(Led7, HIGH);digitalWrite(Led8, HIGH);digitalWrite(Led9, HIGH);digitalWrite(Led10, HIGH);digitalWrite(Led11, HIGH);digitalWrite(Led12, HIGH);digitalWrite(Led13, HIGH);digitalWrite(Led14, HIGH);digitalWrite(Led15, HIGH);digitalWrite(Led16, HIGH);}

      else if (Key1S == HIGH && Key2S == LOW && Key3S == HIGH && Key4S == HIGH && Key5S == LOW){  
      digitalWrite(Led1, HIGH);digitalWrite(Led2, HIGH);digitalWrite(Led3, HIGH);digitalWrite(Led4, HIGH);digitalWrite(Led5, HIGH);digitalWrite(Led6, HIGH);digitalWrite(Led7, HIGH);digitalWrite(Led8, HIGH);digitalWrite(Led9, HIGH);digitalWrite(Led10, HIGH);digitalWrite(Led11, HIGH);digitalWrite(Led12, HIGH);digitalWrite(Led13, HIGH);digitalWrite(Led14, HIGH);digitalWrite(Led15, HIGH);digitalWrite(Led16, HIGH);}

      else if (Key1S == HIGH && Key2S == HIGH && Key3S == LOW && Key4S == LOW && Key5S == HIGH){  
      digitalWrite(Led1, HIGH);digitalWrite(Led2, HIGH);digitalWrite(Led3, HIGH);digitalWrite(Led4, HIGH);digitalWrite(Led5, HIGH);digitalWrite(Led6, HIGH);digitalWrite(Led7, HIGH);digitalWrite(Led8, HIGH);digitalWrite(Led9, HIGH);digitalWrite(Led10, HIGH);digitalWrite(Led11, HIGH);digitalWrite(Led12, HIGH);digitalWrite(Led13, HIGH);digitalWrite(Led14, HIGH);digitalWrite(Led15, HIGH);digitalWrite(Led16, HIGH);}

      else if (Key1S == HIGH && Key2S == HIGH && Key3S == LOW && Key4S == HIGH && Key5S == LOW){  
      digitalWrite(Led1, HIGH);digitalWrite(Led2, HIGH);digitalWrite(Led3, HIGH);digitalWrite(Led4, HIGH);digitalWrite(Led5, HIGH);digitalWrite(Led6, HIGH);digitalWrite(Led7, HIGH);digitalWrite(Led8, HIGH);digitalWrite(Led9, HIGH);digitalWrite(Led10, HIGH);digitalWrite(Led11, HIGH);digitalWrite(Led12, HIGH);digitalWrite(Led13, HIGH);digitalWrite(Led14, HIGH);digitalWrite(Led15, HIGH);digitalWrite(Led16, HIGH);}

      else if (Key1S == HIGH && Key2S == HIGH && Key3S == HIGH && Key4S == LOW && Key5S == LOW){  
      digitalWrite(Led1, HIGH);digitalWrite(Led2, HIGH);digitalWrite(Led3, HIGH);digitalWrite(Led4, HIGH);digitalWrite(Led5, HIGH);digitalWrite(Led6, HIGH);digitalWrite(Led7, HIGH);digitalWrite(Led8, HIGH);digitalWrite(Led9, HIGH);digitalWrite(Led10, HIGH);digitalWrite(Led11, HIGH);digitalWrite(Led12, HIGH);digitalWrite(Led13, HIGH);digitalWrite(Led14, HIGH);digitalWrite(Led15, HIGH);digitalWrite(Led16, HIGH);}
      
   
//Key1
      else if (Key1S == LOW && Key2S == HIGH && Key3S == HIGH && Key4S == HIGH && Key5S == HIGH && Led1S >= 700 && Led2S >= 700 && Led3S >= 700 && Led4S >= 700 && Led5S >= 700 && Led6S >= 700 && Led7S >= 700 && Led8S >= 700 && Led9S >= 700 && Led10S >= 700 && Led11S >= 700 && Led12S >= 700 && Led13S >= 700 && Led14S >= 700 && Led15S >= 700 && Led16S >= 700){ // LED1
      digitalWrite(Led1, LOW);}

//Key2      
      else if (Key1S == HIGH && Key2S == LOW && Key3S == HIGH && Key4S == HIGH && Key5S == HIGH && Led1S <= 700 && Led2S >= 700 && Led3S >= 700 && Led4S >= 700 && Led5S >= 700 && Led6S >= 700 && Led7S >= 700 && Led8S >= 700 && Led9S >= 700 && Led10S >= 700 && Led11S >= 700 && Led12S >= 700 && Led13S >= 700 && Led14S >= 700 && Led15S >= 700 && Led16S >= 700) // LED2
      digitalWrite(Led2, LOW);

//Key3      
      else if (Key1S == HIGH && Key2S == HIGH && Key3S == LOW && Key4S == HIGH && Key5S == HIGH && Led1S <= 700 && Led2S <= 700 && Led3S >= 700 && Led4S >= 700 && Led5S >= 700 && Led6S >= 700 && Led7S >= 700 && Led8S >= 700 && Led9S >= 700 && Led10S >= 700 && Led11S >= 700 && Led12S >= 700 && Led13S >= 700 && Led14S >= 700 && Led15S >= 700 && Led16S >= 700) // LED3
      digitalWrite(Led3, LOW);

//Key4      
      else if (Key1S == LOW && Key2S == HIGH && Key3S == HIGH && Key4S == HIGH && Key5S == HIGH && Led1S <= 700 && Led2S <= 700 && Led3S <= 700 && Led4S >= 700 && Led5S >= 700 && Led6S >= 700 && Led7S >= 700 && Led8S >= 700 && Led9S >= 700 && Led10S >= 700 && Led11S >= 700 && Led12S >= 700 && Led13S >= 700 && Led14S >= 700 && Led15S >= 700 && Led16S >= 700) // LED4
      digitalWrite(Led4, LOW);

//Key5      
      else if (Key1S == HIGH && Key2S == LOW && Key3S == HIGH && Key4S == HIGH && Key5S == HIGH && Led1S <= 700 && Led2S <= 700 && Led3S <= 700 && Led4S <= 700 && Led5S >= 700 && Led6S >= 700 && Led7S >= 700 && Led8S >= 700 && Led9S >= 700 && Led10S >= 700 && Led11S >= 700 && Led12S >= 700 && Led13S >= 700 && Led14S >= 700 && Led15S >= 700 && Led16S >= 700) // LED5
      digitalWrite(Led5, LOW);

//Key6      
      else if (Key1S == HIGH && Key2S == HIGH && Key3S == LOW && Key4S == HIGH && Key5S == HIGH && Led1S <= 700 && Led2S <= 700 && Led3S <= 700 && Led4S <= 700 && Led5S <= 700 && Led6S >= 700 && Led7S >= 700 && Led8S >= 700 && Led9S >= 700 && Led10S >= 700 && Led11S >= 700 && Led12S >= 700 && Led13S >= 700 && Led14S >= 700 && Led15S >= 700 && Led16S >= 700) // LED5
      digitalWrite(Led6, LOW);

//Key7      
      else if (Key1S == LOW && Key2S == HIGH && Key3S == HIGH && Key4S == HIGH && Key5S == HIGH && Led1S <= 700 && Led2S <= 700 && Led3S <= 700 && Led4S <= 700 && Led5S <= 700 && Led6S <= 700 && Led7S >= 700 && Led8S >= 700 && Led9S >= 700 && Led10S >= 700 && Led11S >= 700 && Led12S >= 700 && Led13S >= 700 && Led14S >= 700 && Led15S >= 700 && Led16S >= 700) // LED5
      digitalWrite(Led7, LOW);     

//Key8      
      else if (Key1S == HIGH && Key2S == LOW && Key3S == HIGH && Key4S == HIGH && Key5S == HIGH && Led1S <= 700 && Led2S <= 700 && Led3S <= 700 && Led4S <= 700 && Led5S <= 700 && Led6S <= 700 && Led7S <= 700 && Led8S >= 700 && Led9S >= 700 && Led10S >= 700 && Led11S >= 700 && Led12S >= 700 && Led13S >= 700 && Led14S >= 700 && Led15S >= 700 && Led16S >= 700) // LED5
      digitalWrite(Led8, LOW);
         
//Key9      
      else if (Key1S == HIGH && Key2S == HIGH && Key3S == HIGH && Key4S == LOW && Key5S == HIGH && Led1S <= 700 && Led2S <= 700 && Led3S <= 700 && Led4S <= 700 && Led5S <= 700 && Led6S <= 700 && Led7S <= 700 && Led8S <= 700 && Led9S >= 700 && Led10S >= 700 && Led11S >= 700 && Led12S >= 700 && Led13S >= 700 && Led14S >= 700 && Led15S >= 700 && Led16S >= 700) // LED5
      digitalWrite(Led9, LOW);
              
//Key10      
      else if (Key1S == HIGH && Key2S == HIGH && Key3S == HIGH && Key4S == HIGH && Key5S == LOW && Led1S <= 700 && Led2S <= 700 && Led3S <= 700 && Led4S <= 700 && Led5S <= 700 && Led6S <= 700 && Led7S <= 700 && Led8S <= 700 && Led9S <= 700 && Led10S >= 700 && Led11S >= 700 && Led12S >= 700 && Led13S >= 700 && Led14S >= 700 && Led15S >= 700 && Led16S >= 700) // LED5
      digitalWrite(Led10, LOW);
      
//Key11      
      else if (Key1S == HIGH && Key2S == HIGH && Key3S == HIGH && Key4S == LOW && Key5S == HIGH && Led1S <= 700 && Led2S <= 700 && Led3S <= 700 && Led4S <= 700 && Led5S <= 700 && Led6S <= 700 && Led7S <= 700 && Led8S <= 700 && Led9S <= 700 && Led10S <= 700 && Led11S >= 700 && Led12S >= 700 && Led13S >= 700 && Led14S >= 700 && Led15S >= 700 && Led16S >= 700) // LED5
      digitalWrite(Led11, LOW);
      
//Key12      
      else if (Key1S == HIGH && Key2S == HIGH && Key3S == HIGH && Key4S == HIGH && Key5S == LOW && Led1S <= 700 && Led2S <= 700 && Led3S <= 700 && Led4S <= 700 && Led5S <= 700 && Led6S <= 700 && Led7S <= 700 && Led8S <= 700 && Led9S <= 700 && Led10S <= 700 && Led11S <= 700 && Led12S >= 700 && Led13S >= 700 && Led14S >= 700 && Led15S >= 700 && Led16S >= 700) // LED5
      digitalWrite(Led12, LOW);

//Key13      
      else if (Key1S == HIGH && Key2S == HIGH && Key3S == HIGH && Key4S == LOW && Key5S == HIGH && Led1S <= 700 && Led2S <= 700 && Led3S <= 700 && Led4S <= 700 && Led5S <= 700 && Led6S <= 700 && Led7S <= 700 && Led8S <= 700 && Led9S <= 700 && Led10S <= 700 && Led11S <= 700 && Led12S <= 700 && Led13S >= 700 && Led14S >= 700 && Led15S >= 700 && Led16S >= 700) // LED5
      digitalWrite(Led13, LOW);

//Key14      
      else if (Key1S == HIGH && Key2S == HIGH && Key3S == HIGH && Key4S == HIGH && Key5S == LOW && Led1S <= 700 && Led2S <= 700 && Led3S <= 700 && Led4S <= 700 && Led5S <= 700 && Led6S <= 700 && Led7S <= 700 && Led8S <= 700 && Led9S <= 700 && Led10S <= 700 && Led11S <= 700 && Led12S <= 700 && Led13S <= 700 && Led14S >= 700 && Led15S >= 700 && Led16S >= 700) // LED5
      digitalWrite(Led14, LOW);

//Key15      
      else if (Key1S == HIGH && Key2S == HIGH && Key3S == HIGH && Key4S == LOW && Key5S == HIGH && Led1S <= 700 && Led2S <= 700 && Led3S <= 700 && Led4S <= 700 && Led5S <= 700 && Led6S <= 700 && Led7S <= 700 && Led8S <= 700 && Led9S <= 700 && Led10S <= 700 && Led11S <= 700 && Led12S <= 700 && Led13S <= 700 && Led14S <= 700 && Led15S >= 700 && Led16S >= 700) // LED5
      digitalWrite(Led15, LOW);

//Key16      
      else if (Key1S == HIGH && Key2S == HIGH && Key3S == LOW && Key4S == HIGH && Key5S == HIGH && Led1S <= 700 && Led2S <= 700 && Led3S <= 700 && Led4S <= 700 && Led5S <= 700 && Led6S <= 700 && Led7S <= 700 && Led8S <= 700 && Led9S <= 700 && Led10S <= 700 && Led11S <= 700 && Led12S <= 700 && Led13S <= 700 && Led14S <= 700 && Led15S <= 700 && Led16S >= 700) // LED5
     { digitalWrite(Led16, LOW);
      digitalWrite(Trigger,LOW);}
      
     
        
}





























