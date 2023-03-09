//ID 18307

  //sets up the pin for the button
const byte BTN = A0;
/*sets up the counter for how many time the 
 button has been pressed. */
int counter = 0;

//sets up pins, servo and serial monitor
void setup() {
  // put your setup code here, to run once:
  //make this pin an input pin
  pinMode(BTN, INPUT);
//sets up serial ready for error messages
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //check if the button is pressed
if (analogRead(BTN) > 512 ) {//0-1023

  //add one to the value of counter
  counter = counter + 1;

  switch (counter) {
    case 1:
   Serial.println("You pressed me :D");
    break;
    case 2:
   Serial.println("You pressed me again :)");
    break;
    case 3:
   Serial.println("Stop pressing me >:c");
    break;
    case 4:
   Serial.println("I said stop :(");
    break;
    case 5:
   Serial.println(":c");
   counter = 0;
    break;
    default:
    Serial.println("Oh no, an error! :(");
      break;
  
  }

  //print the counter number whenever it is updated.
 Serial.println(counter);
  //delay 250 milliseconds to debounce
  delay(250);
}

  }
