#include <SparkFun_LPS25HB_Arduino_Library.h> 
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>

//HAN NOTES what are these openlog and lps25hb objects letting us do?
OpenLog myLog;
LPS25HB theSensor; 

const byte Openlogadress = 42 //I saw something similiar to this but didn't get to add it and don't remember exactly what it was.

//HAN NOTES add a comment about the method here
void setup()
{
  Serial.begin(9600);
  Wire.begin();
  theSensor.begin(); 
  myLog.begin();

  
  //If the sensor is not connected it will present an error message.
  if (theSensor.isConnected() == false) 
  {
    Serial.println("The black sensor is disconnected. Reset the board to try again.");     
  }
//HAN NOTES what is myFile? should it be setup somewhere?
   myLog.append(myFile);
  myLog.println("This goes to the log file");
}

//HAN NOTES add a comment about the method here
//Fetches the temperature from the temperature sensor and responds back with the result.
void loop()
{

  Serial.print(theSensor.getPressure_hPa()); 
  Serial.print(", ");
  Serial.println(theSensor.getTemperature_degC()); 
    myLog.print(theSensor.getPressure_hPa()); 
   myLog.print(", ");
  myLog.println(theSensor.getTemperature_degC()); 

  delay(40);
}
//HAN NOTES - look at adding in some methods to help separate and make easier to read your code
//HAN NOTES - I suggest some for setting up the SD card,and the reading and writing of sensors to the sdcard
