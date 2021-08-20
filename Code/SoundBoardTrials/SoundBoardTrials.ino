int Valve1Snd = 8;
int Valve1 = 2;
int Valve1S;


int Valve2Snd = 9;
int Valve2 = 3;
int Valve2S;

int Valve3Snd = 10;
int Valve3 = 4;
int Valve3S;

int Valve4Snd = 11;
int Valve4 = 5;
int Valve4S;

int Valve5Snd = 12;
int Valve5 = 6;
int Valve5S;

int Valve6Snd = 13;
int Valve6 = 7;
int Valve6S;





void setup () {

pinMode (Valve1Snd, OUTPUT);
pinMode (Valve1, INPUT_PULLUP);
pinMode (Valve2Snd, OUTPUT);
pinMode (Valve2, INPUT_PULLUP);
pinMode (Valve3Snd, OUTPUT);
pinMode (Valve3, INPUT_PULLUP);
pinMode (Valve4Snd, OUTPUT);
pinMode (Valve4, INPUT_PULLUP);
pinMode (Valve5Snd, OUTPUT);
pinMode (Valve5, INPUT_PULLUP);
pinMode (Valve6Snd, OUTPUT);
pinMode (Valve6, INPUT_PULLUP);
digitalWrite (Valve1Snd, HIGH);
digitalWrite (Valve2Snd, HIGH);
digitalWrite (Valve3Snd, HIGH);
digitalWrite (Valve4Snd, HIGH);
digitalWrite (Valve5Snd, HIGH);
digitalWrite (Valve6Snd, HIGH);
}

void loop () {

Valve1S = digitalRead (Valve1);
Valve2S = digitalRead (Valve2);
Valve3S = digitalRead (Valve3);
Valve4S = digitalRead (Valve4);
Valve5S = digitalRead (Valve5);
Valve6S = digitalRead (Valve6);
if ( Valve1S == LOW)
  
    digitalWrite (Valve1Snd, LOW);
    else digitalWrite (Valve1Snd, HIGH);
    
    if ( Valve2S == LOW)
  
    digitalWrite (Valve2Snd, LOW);
    else digitalWrite (Valve2Snd, HIGH);

        if ( Valve3S == LOW)
  
    digitalWrite (Valve3Snd, LOW);
    else digitalWrite (Valve3Snd, HIGH);

        if ( Valve4S == LOW)
  
    digitalWrite (Valve4Snd, LOW);
    else digitalWrite (Valve4Snd, HIGH);

        if ( Valve5S == LOW)
  
    digitalWrite (Valve5Snd, LOW);
    else digitalWrite (Valve5Snd, HIGH);

        if ( Valve6S == LOW)
  
    digitalWrite (Valve6Snd, LOW);
    else digitalWrite (Valve6Snd, HIGH);
    
 
}




  

