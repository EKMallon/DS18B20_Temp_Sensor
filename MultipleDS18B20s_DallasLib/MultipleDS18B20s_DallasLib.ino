/* YourDuino Multiple DS18B20 Temperature Sensors on 1 wire
  Connections:
  DS18B20 Pinout (Left to Right, pins down, flat side toward you)
  - Left   = Ground
  - Center = Signal (Pin 2):  (with 3.3K to 4.7K resistor to +5 or 3.3 )
  - Right  = +5 or +3.3 V

   Questions: terry@yourduino.com 
   V1.01  01/17/2013 ...based on examples from Rik Kretzinger
   
/*-----( Import needed libraries )-----*/
// Get 1-wire Library here: http://www.pjrc.com/teensy/td_libs_OneWire.html
#include <OneWire.h>

//Get DallasTemperature Library here:  http://milesburton.com/Main_Page?title=Dallas_Temperature_Control_Library
#include <DallasTemperature.h>

/*-----( Declare Constants and Pin Numbers )-----*/
#define ONE_WIRE_BUS_PIN 8

/*-----( Declare objects )-----*/
// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS_PIN);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

/*-----( Declare Variables )-----*/
// Assign the addresses of your 1-Wire temp sensors.
// See the tutorial on how to obtain these addresses:
// http://www.hacktronics.com/Tutorials/arduino-1-wire-address-finder.html

DeviceAddress Probe01 = { 0x28, 0x72, 0x37, 0xBE, 0x05, 0x00, 0x00, 0x8C}; 
DeviceAddress Probe02 = { 0x28, 0x88, 0x45, 0xBE, 0x05, 0x00, 0x00, 0xDF};
DeviceAddress Probe03 = { 0x28, 0x9F, 0x18, 0xBD, 0x05, 0x00, 0x00, 0xF0};
DeviceAddress Probe04 = { 0x28, 0xC1, 0x7E, 0xBE, 0x05, 0x00, 0x00, 0xC8};

DeviceAddress Probe05 = { 0x28, 0x01, 0xAD, 0xBC, 0x05, 0x00, 0x00, 0x40 };
DeviceAddress Probe06 = { 0x28, 0x5B, 0x45, 0x28, 0x06, 0x00, 0x00, 0x4E };
DeviceAddress Probe07 = { 0x28, 0x46, 0x0A, 0x54, 0x05, 0x00, 0x00, 0x87 };
DeviceAddress Probe08 = { 0x28, 0xF2, 0x01, 0x27, 0x06, 0x00, 0x00, 0xE8 };
DeviceAddress Probe09 = { 0x28, 0x2C, 0x51, 0x28, 0x06, 0x00, 0x00, 0x30 };
DeviceAddress Probe10 = { 0x28, 0x62, 0xE1, 0xBD, 0x05, 0x00, 0x00, 0x9D};

DeviceAddress Probe11 = { 0x28, 0x0B, 0x93, 0x26, 0x06, 0x00, 0x00, 0xB7};
DeviceAddress Probe12 = { 0x28, 0xD5, 0x24, 0x27, 0x06, 0x00, 0x00, 0xF1};
DeviceAddress Probe13 = { 0x28, 0x77, 0xD3, 0x25, 0x06, 0x00, 0x00, 0x33};
DeviceAddress Probe14 = { 0x28, 0x62, 0xDC, 0x26, 0x06, 0x00, 0x00, 0x64};
DeviceAddress Probe15 = { 0x28, 0xB0, 0x03, 0x26, 0x06, 0x00, 0x00, 0xFF};
DeviceAddress Probe16 = { 0x28, 0xB7, 0xB7, 0x25, 0x06, 0x00, 0x00, 0xA2};


/* the first hard wired set
DeviceAddress Probe01 = { 0x28, 0x36, 0xED, 0x83, 0x05, 0x00, 0x00, 0x13 }; 
DeviceAddress Probe02 = { 0x28, 0xDD, 0xA0, 0xBD, 0x05, 0x00, 0x00, 0x9A };
DeviceAddress Probe03 = { 0x28, 0xEE, 0xD6, 0xBD, 0x05, 0x00, 0x00, 0xDF};
DeviceAddress Probe04 = { 0x28, 0x43, 0x73, 0xBD, 0x05, 0x00, 0x00, 0x28 };
DeviceAddress Probe05 = { 0x28, 0x49, 0x14, 0xBD, 0x05, 0x00, 0x00, 0xA7 };
DeviceAddress Probe06 = { 0x28, 0xBC, 0x2D, 0xBE, 0x05, 0x00, 0x00, 0xC1 };
DeviceAddress Probe07 = { 0x28, 0x02, 0x79, 0xBD, 0x05, 0x00, 0x00, 0xD7 };
DeviceAddress Probe08 = { 0x28, 0x46, 0xA2, 0xBC, 0x05, 0x00, 0x00, 0xDF };
*/


void setup()   /****** SETUP: RUNS ONCE ******/
{
  // start serial port to show results
  Serial.begin(9600);
  Serial.print("Initializing Temperature Control Library Version ");
  Serial.println(DALLASTEMPLIBVERSION);
  
  // Initialize the Temperature measurement library
  sensors.begin();
  // The resolution of the temperature sensor is user-configurable to 9, 10, 11, or 12 bits, corresponding to increments of 0.5°C, 0.25°C, 0.125°C, and 0.0625°C, respectively. default at power-up is 12-bit.
  // set the resolution to 10 bit (Can be 9 to 12 bits .. lower is faster)
  sensors.setResolution(Probe01, 12);  //dallas lib
  sensors.setResolution(Probe02, 12);
  sensors.setResolution(Probe03, 12);
  sensors.setResolution(Probe04, 12);
  
  sensors.setResolution(Probe05, 12);
  sensors.setResolution(Probe06, 12);
  sensors.setResolution(Probe07, 12);
  sensors.setResolution(Probe08, 12);
  sensors.setResolution(Probe09, 12);
  sensors.setResolution(Probe10, 12);
  
  sensors.setResolution(Probe11, 12);
  sensors.setResolution(Probe12, 12);
  sensors.setResolution(Probe13, 12);
  sensors.setResolution(Probe14, 12);
  sensors.setResolution(Probe15, 12);
  sensors.setResolution(Probe16, 12);


}//--(end setup )---

void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{

  Serial.println();
  Serial.print("Number of Devices found on bus = ");  
  Serial.println(sensors.getDeviceCount());   //dallas lib
  Serial.print("Getting temperatures... ");  
  Serial.println();   
  
  // Command all devices on bus to read temperature  
  sensors.requestTemperatures();  
  
  Serial.print("Probe 01 temperature is:   ");
  printTemperature(Probe01);
  Serial.println();

  Serial.print("Probe 02 temperature is:   ");
  printTemperature(Probe02);
  Serial.println();

  Serial.print("Probe 03 temperature is:   ");
  printTemperature(Probe03);
  Serial.println();
  
  Serial.print("Probe 04 temperature is:   ");
  printTemperature(Probe04);
  Serial.println();
  

  Serial.print("Probe 05 temperature is:   ");
  printTemperature(Probe05);
  Serial.println();
  
  Serial.print("Probe 06 temperature is:   ");
  printTemperature(Probe06);
  Serial.println();
  
  Serial.print("Probe 07 temperature is:   ");
  printTemperature(Probe07);
  Serial.println();
  
  Serial.print("Probe 08 temperature is:   ");
  printTemperature(Probe08);
  Serial.println();
    
  Serial.print("Probe 09 temperature is:   ");
  printTemperature(Probe09);
  Serial.println();
    
  Serial.print("Probe 10 temperature is:   ");
  printTemperature(Probe10);
  Serial.println();
 
  
  Serial.print("Probe 11 temperature is:   ");
  printTemperature(Probe11);
  Serial.println();
  
  Serial.print("Probe 12 temperature is:   ");
  printTemperature(Probe12);
  Serial.println();
  
  Serial.print("Probe 13 temperature is:   ");
  printTemperature(Probe13);
  Serial.println();
  
  Serial.print("Probe 14 temperature is:   ");
  printTemperature(Probe14);
  Serial.println();
    
  Serial.print("Probe 15 temperature is:   ");
  printTemperature(Probe15);
  Serial.println();
    
  Serial.print("Probe 16 temperature is:   ");
  printTemperature(Probe16);
  Serial.println();

  delay(10000);
}//--(end main loop )---

/*-----( Declare User-written Functions )-----*/
void printTemperature(DeviceAddress deviceAddress)
{

float tempC = sensors.getTempC(deviceAddress);  //function from dallas lib
   if (tempC == -127.00) 
   {
   Serial.print("Error getting temperature  ");
   } 
   else
   {
   Serial.print("C: ");
   Serial.print(tempC);
   Serial.print(" F: ");
   Serial.print(DallasTemperature::toFahrenheit(tempC));  //dallas lib
   }
}// End printTemperature
//*********( THE END )***********
