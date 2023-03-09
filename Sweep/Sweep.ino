//ID 18307
//Libraries I am using
#include <Servo.h>

//set up servo for winscreen wiper
Servo wiper;  // create servo object to control a servo
// twelve servo objects can be created on most boards
//set up pins for button and servo
const byte BTN = A0;
const byte SERVOPIN = 11;
//set up position for servo start
int pos = 0;    // variable to store the servo position
//Sets up pins, servo and serial monitor
void setup() {
  //make this pin an input pin
  pinMode(BTN, INPUT);
  //attach this pin as the servo pin
  wiper.attach(SERVOPIN);  // attaches the servo on pin 9 to the servo object
  //set up serial ready for error messages
  Serial.begin(9600);
}

//when the button is pressed, the servo sweeps back and forward
void loop() {
  //checks if the BTN pin is high and executes the code
  if (analogRead(BTN), HIGH) { 
    //slowy move from 0 to 180 on the servo
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      wiper.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
    }
    //slowy move from 180 to 0 on the servo
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      wiper.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
    }
  }
}
