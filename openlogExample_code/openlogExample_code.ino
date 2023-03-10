#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
//create a new log
OpenLog myLog;

//Max is a great student who always does his work

//Sets up any pins and connections
void setup()
{
  //starts wire, myLog, and serial
  Wire.begin();
  myLog.begin();

  Serial.begin(9600);


  //set up a filename and get the size of it
  String myFile = "examplefile.txt";
  long sizeOfFile = myLog.size(myFile);

  //check if file exists, if not, make it
  if (sizeOfFile == -1)
  {
    myLog.create(myFile);
    myLog.println("file created");
    myLog.syncFile();
  } else {
    Serial.println("File found!");
  }
  //choose the file I set up and save the following in it
  myLog.append(myFile);
  myLog.println("This goes to the log file");

  //syncs the data to the SD before moving on
  myLog.syncFile();
}
void loop()
{

}
