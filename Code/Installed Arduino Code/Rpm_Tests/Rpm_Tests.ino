 //this code measures the difference between two rising edges of the digitalised signal coming from hall sensor and then prints the rpm.
 //pin A0 is the signal pin
 int refsig = 150; //for converting the analog signal coming from hall sensor to digital through arduino code
 int val;//the digital value of the incoming analog signals
 int prev_val = 0;
 int t, cur_t; //time variables
 void setup()
 {
   Serial.begin(250000);
   pinMode(A8, INPUT);
 }
 void loop()//Measure RPM
 {
   int sig = analogRead(A8); //read raw value of hall sensor
   if (sig > refsig) val = HIGH; //convert it to digital 0,1 form
   else val = LOW;
   if (prev_val == 0 && val == 1 ) { //check for rising edge
     cur_t = micros();
    int rpm = (10000000 / (t-cur_t));
    if (rpm >=1000 or rpm <= 0)
    rpm = 0;
   if (rpm >0 && rpm < 1000)
   Serial.println ("Its on");
     Serial.println(rpm); //print the rpm
     t = micros();
   }
   
   prev_val = val;

   
 }
