//Valve Code
int Valve1 = A0;   
int Valve2 = A1;
int Valve3 = A2; 
int Valve4 = A3; 
int Valve5 = A4;
int Valve6 = A5;
int ToolRelease = 13;
int ValveSound1 = 2;
int ValveSound2 = 3;
int ValveSound3 = 4;
int ValveSound4 = 5;
int ValveSound5 = 6;
int ValveSound6 = 7;



void setup() {
  // put your setup code here, to run once:
  pinMode(Valve1, INPUT_PULLUP);//Valve1
  pinMode(Valve2, INPUT_PULLUP);//Valve2
  pinMode(Valve3, INPUT_PULLUP);//Valve3
  pinMode(Valve4, INPUT_PULLUP);//Valve4
  pinMode(Valve5, INPUT_PULLUP);//Valve5
  pinMode(Valve6, INPUT_PULLUP);//Valve6
  pinMode(ToolRelease, OUTPUT);//Tool Release
  pinMode(ValveSound1, OUTPUT);//ValveSound1
  pinMode(ValveSound2, OUTPUT);//ValveSound2
  pinMode(ValveSound3, OUTPUT);//ValveSound3
  pinMode(ValveSound4, OUTPUT);//ValveSound4
  pinMode(ValveSound5, OUTPUT);//ValveSound5
  pinMode(ValveSound6, OUTPUT);//ValveSound6
  digitalWrite (ToolRelease,HIGH);
  digitalWrite (ValveSound1,HIGH);
  digitalWrite (ValveSound2,HIGH);
  digitalWrite (ValveSound3,HIGH);
  digitalWrite (ValveSound4,HIGH);
  digitalWrite (ValveSound5,HIGH);
  digitalWrite (ValveSound6,HIGH);

    Serial.begin(9600);
  Serial.println("Yep");
 
  }


void loop() {
  // put your main code here, to run repeatedly:
  int Valve1S = analogRead(Valve1);
  int Valve2S = analogRead(Valve2);
  int Valve3S = analogRead(Valve3);
  int Valve4S = analogRead(Valve4);
  int Valve5S = analogRead(Valve5);
  int Valve6S = analogRead(Valve6);
  

      Serial.println ("Valve1");
      Serial.println (Valve1S);
      Serial.println ("Valve2");
      Serial.println (Valve2S);
      Serial.println ("Valve3");
      Serial.println (Valve3S);
      Serial.println ("Valve4");
      Serial.println (Valve4S);
      Serial.println ("Valve5");
      Serial.println (Valve5S);
      Serial.println ("Valve6");
      Serial.println (Valve6S);
      /*delay(2000);*/



      

     
      if (Valve1S <= 500)
      {   digitalWrite (ValveSound1,LOW);
          delay(300);
          digitalWrite (ValveSound1,HIGH);   }
             else digitalWrite (ValveSound1, HIGH);

      if (Valve2S <= 500)
      {   digitalWrite (ValveSound1,LOW);
          delay(300);
          digitalWrite (ValveSound1,HIGH);   }
      else digitalWrite (ValveSound1, HIGH);

      if (Valve3S <= 500)
      {   digitalWrite (ValveSound1,LOW);
          delay(300);
          digitalWrite (ValveSound1,HIGH);   }
             else digitalWrite (ValveSound1, HIGH);

      if (Valve4S <= 500)
      {   digitalWrite (ValveSound1,LOW);
          delay(300);
          digitalWrite (ValveSound1,HIGH);   }
             else digitalWrite (ValveSound1, HIGH);

      if (Valve5S <= 900)
      {   digitalWrite (ValveSound1,LOW);
          delay(300);
          digitalWrite (ValveSound1,HIGH);   }
             else digitalWrite (ValveSound1, HIGH);

      if (Valve6S <= 500)
      {   digitalWrite (ValveSound1,LOW);
          delay(300);
          digitalWrite (ValveSound1,HIGH);   }
             else digitalWrite (ValveSound1, HIGH);

if (Valve1S <= 500 && Valve2S >= 500 && Valve3S <= 500 && Valve4S >= 500 && Valve5S >= 900 && Valve6S <= 500)
 {   digitalWrite (ToolRelease, LOW);   }
   else digitalWrite (ToolRelease, HIGH);   
      //  < is equal to open  > is equal to closed



      
}
