#include <SparkFun_LPS25HB_Arduino_Library.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>

//creates a variable for the OpenLog SD card called "sdCard" and another variable for the LPS25HB temperature sensor called "theSensor".
OpenLog sdCard;
LPS25HB theSensor;

//creates a file under the variable myFile called "MaxsFile.txt" and sets up the constant SBEGIN as 9600
String myFile = "MaxsFile.txt";
const int SBEGIN = 9600;

//Sets up a connection to the arduino board and also sets up a connection from the arduino board to the temperature sesnor and SD card.
void setup()
{
  Serial.begin(SBEGIN);
  Wire.begin();
  theSensor.begin();
  sdCard.begin();

  //If the sensor is not connected it will present an error message.
  if (theSensor.isConnected() == false)
  {
    Serial.println("The black sensor is disconnected. Reset the board to try again.");
  }
  //moves my file to the SD card and sends a message to the file in the SD card and creates a heading.
  sdCard.append(myFile);
  sdCard.println("Pressure, Temperature");
  //Syncs the file to the SDcard so that no further action will be made until the file is properly synced
 sdCard.syncFile();
}

//Fetches the temperature and pressure from the temperature sensor and responds back with the result on the SD card and serial.
void loop()
{
  //Set testing to either true or false, which will allow the code bellow to recieve specific results depending on if testing is set to true or false.
  recieveResult(true);
}

//If I am testing I will recieve results from the serial, if not I will recieve results from the sd card.
void recieveResult (boolean ifTesting) {
  if (ifTesting) {//If I am testing (set to true), it will activate the results within the serial monitor through this code
    Serial.print("The pressure is ");
    Serial.print(theSensor.getPressure_hPa());
    Serial.print(", and the temperature is ");
    Serial.print(theSensor.getTemperature_degC());
    Serial.println(". ");
  } else {//If i am not testing (set to false), It will activate the results within the SDcard through this code
    sdCard.print(theSensor.getPressure_hPa());
    sdCard.print(", ");
    sdCard.println(theSensor.getTemperature_degC());
    sdCard.syncFile();
  }
}
