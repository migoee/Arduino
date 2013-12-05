#include <Servo.h>

//Two Light, Single Blink Boat Code
//Robert Fisher
//Design Lab 1 Fall 2013

// This code produces a blinking light with out having a delay that would interupt
// other functions and processes. Simple and easy.

int ledPin = 8; // Red LED pin
int ledYel = 7; // Yello LED pin

int i = 0; // Variable to contain time stamp 1; begin at 0
int i2 = 0; // Variable to contain time stamp 2; begin at 0
int j = 0; // Variable to count change; begin at 0

Servo myservo;  // create servo object to control a servo 
 
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup()
{
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(ledPin, OUTPUT);// Red LED is OUTPUT
  pinMode(ledYel, OUTPUT);// Yellow LED is OUTPUt
  Serial.begin(9600); // Begin Serial Com
  
}

void loop()
{
  digitalWrite(ledPin, HIGH); // Red LED remains on constantly
  
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  
  val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  
  myservo.write(val);                  // sets the servo position according to the scaled value 
  
  i = (millis())/2000; // Set time stamp 1
  
  delay(50);  // delay between Timestamps to be tested
  
  i2 = (millis())/2000; // Set time stamp 2
  
  
  if (i != i2) // if time stamps do not match:
  {
    j++; // increment j by one
  }
    
  if (j == 0) // while j is 0, true:
 {
   
  digitalWrite(ledYel, LOW); // Yellow LED is off
  //Serial.println("Light is off, and current run time is:"); // Serial print light is off
  //Serial.println((millis())/1000);
  //Serial.println("sec");
  if ((analogRead(potpin))/5 < 90)
  {
    Serial.println("Left Turn Initiated");
  }

 }
 
 if (j == 1)
 {
   digitalWrite(ledYel, HIGH); // Yellow LED is on
   //Serial.println("Light is on, and current run time is:");// Serial print light is on
   //Serial.println((millis())/1000);
  //Serial.println("sec");
  if ((analogRead(potpin))/5 > 90)
  {
    Serial.println("Right Turn Initiated");
  }
 }
 
 if (j > 1) // if j is larger than 1:
 {
   j = 0; // set j back to 0
 }
   
}

