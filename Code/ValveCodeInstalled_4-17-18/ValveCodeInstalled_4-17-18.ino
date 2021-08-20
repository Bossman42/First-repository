//Valve Code
int Valve1 = A0;   
int Valve2 = A1;
int Valve3 = A2; 
int Valve4 = A3; 
int Valve5 = A4;
int Valve6 = A5;
int ToolRelease = 13;

int ValveSounds = 4;
int CurrentValveState1 = 0;
int CurrentValveState2 = 0;
int CurrentValveState3 = 0;
int CurrentValveState4 = 0;
int CurrentValveState5 = 0;
int CurrentValveState6 = 0;
int LastValveState1 = 0;
int LastValveState2 = 0;
int LastValveState3 = 0;
int LastValveState4 = 0;
int LastValveState5 = 0;
int LastValveState6 = 0;







void setup() {
  // put your setup code here, to run once:
  pinMode(Valve1, INPUT_PULLUP);//Valve1
  pinMode(Valve2, INPUT_PULLUP);//Valve2
  pinMode(Valve3, INPUT_PULLUP);//Valve3
  pinMode(Valve4, INPUT_PULLUP);//Valve4
  pinMode(Valve5, INPUT_PULLUP);//Valve5
  pinMode(Valve6, INPUT_PULLUP);//Valve6
  pinMode(ToolRelease, OUTPUT);//Tool Release
  
  pinMode(ValveSounds, OUTPUT);//ValveSound2
  digitalWrite (ToolRelease,HIGH);

  digitalWrite (ValveSounds,HIGH);
 



 
  }


void loop() {
  // put your main code here, to run repeatedly:
  int Valve1S = analogRead(Valve1);
  int Valve2S = analogRead(Valve2);
  int Valve3S = analogRead(Valve3);
  int Valve4S = analogRead(Valve4);
  int Valve5S = analogRead(Valve5);
  int Valve6S = analogRead(Valve6);
 
 
     
if  (Valve1S>= 900){ CurrentValveState1 = 0;}
else CurrentValveState1=1;


if  (Valve2S>= 900){ CurrentValveState2 = 0;}
else CurrentValveState2=1;

if  (Valve3S>= 900){ CurrentValveState3 = 0;}
else CurrentValveState3=1;
if  (Valve4S>= 900){ CurrentValveState4 = 0;}
else CurrentValveState4=1;

if  (Valve5S>= 900){ CurrentValveState5 = 0;}
else CurrentValveState5=1;

if  (Valve6S>= 900){ CurrentValveState6 = 0;}
else CurrentValveState6=1;



      
  {if (CurrentValveState1 != LastValveState1){
    digitalWrite (ValveSounds,LOW);
    delay (200);
    digitalWrite (ValveSounds,HIGH);}
    else digitalWrite (ValveSounds,HIGH);}
    delay(50);
    
   LastValveState1= CurrentValveState1;
         
  {if (CurrentValveState2 != LastValveState2){
    digitalWrite (ValveSounds,LOW);
    delay (200);
    digitalWrite (ValveSounds,HIGH);}
    else digitalWrite (ValveSounds,HIGH);}
    delay(50);
    
   LastValveState2= CurrentValveState2;

         
  {if (CurrentValveState3 != LastValveState3){
    digitalWrite (ValveSounds,LOW);
    delay (200);
    digitalWrite (ValveSounds,HIGH);}
    else digitalWrite (ValveSounds,HIGH);}
    delay(50);
    
   LastValveState3= CurrentValveState3;


         
  {if (CurrentValveState4 != LastValveState4){
    digitalWrite (ValveSounds,LOW);
    delay (200);
    digitalWrite (ValveSounds,HIGH);}
    else digitalWrite (ValveSounds,HIGH);}
    delay(50);
    
   LastValveState4= CurrentValveState4;

      
  {if (CurrentValveState5 != LastValveState5){
    digitalWrite (ValveSounds,LOW);
    delay (200);
    digitalWrite (ValveSounds,HIGH);}
    else digitalWrite (ValveSounds,HIGH);}
    delay(50);
    
   LastValveState5= CurrentValveState5;

         
  {if (CurrentValveState6 != LastValveState6){
    digitalWrite (ValveSounds,LOW);
    delay (200);
    digitalWrite (ValveSounds,HIGH);}
    else digitalWrite (ValveSounds,HIGH);}
    delay(50);
    
   LastValveState6= CurrentValveState6;
     


if (Valve1S <= 900  && Valve2S >= 900 && Valve3S <= 900 && Valve4S >= 900 && Valve5S >= 950 && Valve6S <= 900)
 {
  digitalWrite (ToolRelease, LOW);
  delay (1000);
  digitalWrite (ToolRelease, HIGH);}}
   else digitalWrite (ToolRelease, HIGH);   
      //  < is equal to open  > is equal to closed



      
}
