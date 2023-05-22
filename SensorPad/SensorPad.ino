#include <SparkFun_LPS25HB_Arduino_Library.h> 
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>

OpenLog myLog;
LPS25HB theSensor; 

const byte Openlogadress = 42 //I saw something similiar to this but didn't get to add it and don't remember exactly what it was.

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  theSensor.begin(); 
  myLog.begin();

  if (theSensor.isConnected() == false) /
  {
    Serial.println("LPS25HB disconnected. Reset the board to try again.");     
  }

   myLog.append(myFile);
  myLog.println("This goes to the log file");
}

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
