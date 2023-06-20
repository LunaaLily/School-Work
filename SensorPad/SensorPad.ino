#include <SparkFun_LPS25HB_Arduino_Library.h> 
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>

//creates a variable for the OpenLog SD card called "sdCard" and another variable for the LPS25HB temperature sensor called "theSensor".
OpenLog sdCard;
LPS25HB theSensor; 

String myFile = "MaxsFile.txt";

//Sets up a connection to the arduino board and also sets up a connection from the arduino board to the temperature sesnor and SD card.
void setup()
{
  Serial.begin(9600);
  Wire.begin();
  theSensor.begin(); 
  sdCard.begin();

  
  //If the sensor is not connected it will present an error message.
  if (theSensor.isConnected() == false) 
  {
    Serial.println("The black sensor is disconnected. Reset the board to try again.");     
  }
//allows the SD card to access my file and sends a message to the file in the SD card.
   sdCard.append(myFile);
  sdCard.println("Pressure, Temperature");
}

//Fetches the temperature and pressure from the temperature sensor and responds back with the result on the SD card and serial.
void loop()
{

  Serial.print(theSensor.getPressure_hPa()); 
  Serial.print("The pressure is () and the temperature is (). ");
  Serial.println(theSensor.getTemperature_degC()); 
    sdCard.print(theSensor.getPressure_hPa()); 
   sdCard.print("The pressure is () and the temperature is (). ");
  sdCard.println(theSensor.getTemperature_degC()); 

  delay(40);
}
//HAN NOTES - look at adding in some methods to help separate and make easier to read your code
//HAN NOTES - I suggest some for setting up the SD card,and the reading and writing of sensors to the sdcard
