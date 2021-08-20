/*Countdown with buzzer*/

#define button 10     //button Pin
#define buz 11        //buzzer Pin
#define pin_tens 13   //tens   Pin, this pin control the tens
#define pin_unit 12   //unit   Pin, this pin control the unit
#define start 9       //start  Pin
#define reset A0      //reset Pin

//Variables
int timee = 0;
int unit = 0, tens = 0;
unsigned long time_countdown = 0;

//display segment
int a = 2; //pin 7 of the display 
int b = 3; //pin 6
int c = 4; //pin 4
int d = 5; //pin 2
int e = 6; //pin 1
int f = 7; //pin 9
int g = 8; //pin 10

void setup() {
  pinMode(button, INPUT);
  pinMode(reset, INPUT);
  pinMode(start, INPUT);
  pinMode(buz, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

//This function display the number with a combination of segments for each number 
void print_number(int n) {
  switch (n) {
    case 0: //number zero
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, LOW);
      break;
    case 1: //number one
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      break;
    case 2: //number two
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
      break;
    case 3: //number three
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
      break;
    case 4: //number four
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 5: //number five
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 6: //number six
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 7: //number seven
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      break;
    case 8: //number eight
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 9: //number nine
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
  }
}

void loop() {
  if(digitalRead(reset) == LOW){ //If you push the zero button, you reset the time
    delay(10);
    timee = 0;
  }
  if (digitalRead(button) == LOW) { //If you push the first botton the time rises up
    timee = timee + 1;
    if (timee == 100) timee = 0;    //time max = 99, if time == 100 -> time becomes 0
    delay(150);
  }
  //separation between unit and tens
  tens = timee / 10;
  unit = timee - (tens * 10);
  
  digitalWrite(pin_tens, HIGH); //active the tens display 
  digitalWrite(pin_unit, LOW); //disable the unit display
  if (tens != 0) {  //If tenses are == zero the tenses'display stay off
    print_number(tens);   //Display the tens
  }
  else digitalWrite(pin_tens, LOW); 
  delay(1);
  digitalWrite(pin_tens, LOW);
  digitalWrite(pin_unit, LOW);
  delay(2);
  digitalWrite(pin_tens, LOW);
  digitalWrite(pin_unit, HIGH);
  print_number(unit);     //Display the unit
  delay(1);
  digitalWrite(pin_tens, LOW);
  digitalWrite(pin_unit, LOW);
  delay(2);

  if (digitalRead(start) == LOW) { //If the start button is pressed the time go down
    time_countdown = millis(); 
    while (timee > 0) {
      tens = timee / 10;
      unit = timee - (tens * 10);
      digitalWrite(pin_tens, HIGH);
      digitalWrite(pin_unit, LOW);
      if (tens != 0) { 
        print_number(tens);   //Display the tens
      }
      else digitalWrite(pin_tens, LOW);
      delay(1);
      digitalWrite(pin_tens, LOW);
      digitalWrite(pin_unit, LOW);
      delay(2);
      digitalWrite(pin_tens, LOW);
      digitalWrite(pin_unit, HIGH);
      print_number(unit);   //Display the unit
      delay(1);
      digitalWrite(pin_tens, LOW);
      digitalWrite(pin_unit, LOW);
      delay(2);
      if (millis() - time_countdown >= 998) { //The while loop ends when 'timee' become zero
        timee = timee - 1;
        time_countdown = millis();
      }
      if (timee == 0) { //if time arrive to zero the buzzer play and display zero
        int i;
        digitalWrite(a, HIGH);
        digitalWrite(b, HIGH);
        digitalWrite(c, HIGH);
        digitalWrite(d, HIGH);
        digitalWrite(e, HIGH);
        digitalWrite(f, HIGH);
        digitalWrite(g, LOW);
        digitalWrite(pin_unit, HIGH);
        for (i = 0; i < 10; i++) {
          analogWrite(buz, 240);
          delay(100);
          digitalWrite(buz, LOW);
          delay(100);
        }
        digitalWrite(a, LOW);
        digitalWrite(b, LOW);
        digitalWrite(c, LOW);
        digitalWrite(d, LOW);
        digitalWrite(e, LOW);
        digitalWrite(f, LOW);
        digitalWrite(g, LOW);
      }
    }

  }
}

