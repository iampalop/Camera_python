#include "ESP_MICRO.h" //Include the micro library 

String input_ssid = "";
String input_pass = "";

char* get_ssid = "";
char* get_pass = "";

char buf[50];

//char* ssid = "iampalop_2.4G";
//char* password = "Pop0612299900";

//String ssid = "iampalop_2.4G";
//String password = "Pop0612299900";

char* ssid = "iampalop";
char* password = "iampalop1997";

int buttonPin = 16; //D0
int testvariable = 0;
int value;

int ssid_pass = 1;


void setup(){
  
  Serial.begin(9600); // Starting serial port for seeing details

  while(ssid_pass == 0)
  {
    Serial.println("Enter the ssid: ");
    while(Serial.available() == 0) {}
    input_ssid = Serial.readString();
    Serial.print(input_ssid);
    Serial.println("Enter the password: ");
    while(Serial.available() == 0) {}
    input_pass = Serial.readString();
    Serial.print(input_pass);

    ssid_pass = 1;
  }

//  Serial.println("Connecting...");
//  get_ssid = input_ssid.c_str();
//  get_pass = input_pass.c_str();
  
//  start(ssid, password);  // EnAIt will connect to your wifi with given details
//  start(get_ssid, get_pass);
  start(input_ssid, input_pass);

  pinMode(buttonPin, INPUT);
}

void loop(){

  value = digitalRead(buttonPin);
  Serial.println(value);
  if(value == 1)
  {
    waitUntilNewReq();  //Waits until a new request from python come
    returnThisInt(1);
  }

//  waitUntilNewReq();  //Waits until a new request from python come
  /* increases index when a new request came*/
//  testvariable += 1;
//  returnThisInt(testvariable); //Returns the data to python

//  value = digitalRead(buttonPin);
//  Serial.println(value);
//  returnThisInt(value);
}
