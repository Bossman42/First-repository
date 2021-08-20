/*****
 
 All the resources for this project:
 https://randomnerdtutorials.com/
 
*****/


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);



#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include <SPI.h>
#include <MFRC522.h>
constexpr uint8_t RST_PIN = D3;     // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = D4;     // Configurable, see typical pin layout above
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
MFRC522::MIFARE_Key key;
String tag;
String correct;

// Change the credentials below, so your ESP8266 connects to your router
//const char* ssid = "pu-36";
//const char* password = "pasteltuba417";
const char* ssid = "Boss Castle";
const char* password = "whatisyourpassword";

// Change the variable to your Raspberry Pi IP address, so it connects to your MQTT broker
const char* mqtt_server = "192.168.68.112";

// Initializes the espClient. You should change the espClient name if you have multiple ESPs running in your home automation system
  WiFiClient espClient;
 PubSubClient client(espClient);  




// Timers auxiliar variables
long now = millis();
long lastMeasure = 0;

// Don't change the function below. This functions connects your ESP8266 to your router
void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected - ESP IP address: ");
  Serial.println(WiFi.localIP());
  client.publish("Status","Node 3");
}

// This functions is executed when some device publishes a message to a topic that your ESP8266 is subscribed to
// Change the function below to add logic to your program, so when a device publishes a message to a topic that 
// your ESP8266 is subscribed you can actually do something
void callback(String topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  // Feel free to add more if statements to control more GPIOs with MQTT

  // If a message is received on the topic room/lamp, you check if the message is either on or off. Turns the lamp GPIO according to the message
  if(topic=="Connection"){
      Serial.print("Connection Status");
      if(messageTemp == "hello"){
       
        Serial.print("Node 3");
        client.publish("Status","Node 3");
      }
      else if(messageTemp == "off"){
      
        Serial.print("Off");
      }
  }
  Serial.println();
}





// This functions reconnects your ESP8266 to your MQTT broker
// Change the function below if you want to subscribe to more topics with your ESP8266 
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    /*
     YOU MIGHT NEED TO CHANGE THIS LINE, IF YOU'RE HAVING PROBLEMS WITH MQTT MULTIPLE CONNECTIONS
     To change the ESP device ID, you will have to give a new name to the ESP8266.
     Here's how it looks:
       if (client.connect("ESP8266Client")) {
     You can do it like this:
       if (client.connect("ESP1_Office")) {
     Then, for the other ESP:
       if (client.connect("ESP2_Garage")) {
      That should solve your MQTT multiple connections problem
    */
    if (client.connect("ESP8266New")) {
      Serial.println("connected");  
      // Subscribe or resubscribe to a topic
      // You can subscribe to more topics (to control more LEDs in this example)
      client.subscribe("Connection");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

// The setup function sets your ESP GPIOs to Outputs, starts the serial communication at a baud rate of 115200
// Sets your mqtt broker and sets the callback function
// The callback function is what receives messages and actually controls the LEDs
void setup() {

  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522
  
  Serial.begin(115200);
  Serial.println ("helloworld");
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("Hello, world!");
 correct = String(68216827);

  
}

// For this project, you don't need to change anything in the loop function. Basically it ensures that you ESP is connected to your broker
void loop() {

  if (!client.connected()) {
    reconnect();
  }
  if(!client.loop())
    client.connect("ESP8266Client");

  now = millis();


  

  if ( ! rfid.PICC_IsNewCardPresent())
    return;
  if (rfid.PICC_ReadCardSerial()) {
    for (byte i = 0; i < 4; i++) {
      tag += rfid.uid.uidByte[i];
    }
    Serial.print("tag:      ");
    Serial.print("|");
    Serial.print(tag);
    Serial.println("|");
    Serial.print("correct:  ");
    Serial.print("|");
    Serial.print("68216827");
    Serial.println("|");
    lcd.clear();
    lcd.print(tag);
  String t = (tag);
 
  
  //  client.publish("RFID","tag");
    client.publish("RFID",t.c_str());

if( t == "68216827" ){
  delay(2000);
  lcd.clear();
  lcd.print("correct");
}


    
    tag = "";
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }


  }
 
