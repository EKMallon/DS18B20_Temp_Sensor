// DS18B20 datasheet at: http://datasheets.maximintegrated.com/en/ds/DS18B20.pdf

// adapted from https://github.com/BitKnitting/prototypes/blob/master/SensorNode433/SensorNode433.ino
// and from  http://forum.bildr.org/viewtopic.php?f=17&t=779
// sleep function from http://www.gammon.com.au/forum/?id=11497

// also see
// OneWire DS18S20, DS18B20, DS1822 Temperature Example
// http://www.pjrc.com/teensy/td_libs_OneWire.html
// The DallasTemperature library can do all this work for you!
// http://milesburton.com/Dallas_Temperature_Control_Library



#include <avr/sleep.h>
#include <avr/wdt.h>

#include <OneWire.h>
const byte DS18B20_PIN=8;
OneWire ds(DS18B20_PIN);
byte addr[8];
int tempRaw;
float DS18B20float;
float celsius, fahrenheit;
// resolution is configurable to 9, 10, 11, or 12 bits, corresponding to increments of 0.5°C, 0.25°C, 0.125°C, and 0.0625°C, respectively. default at power-up is 12-bit.
  
void setup() {
  Serial.begin(9600);

  //Set up Temp sensor - I am only using 1 sensor here, but you could have more
  if ( !ds.search(addr)) {
    Serial.println(F("---> ERROR: Did not find the DS18B20 Temperature Sensor!"));
    return;
  }
  else {
    Serial.print(F("DS18B20 ROM address ="));
    for(byte i = 0; i < 8; i++) {
      Serial.write(' ');
      Serial.print(addr[i], HEX);
    }
    Serial.println();
  }
  delay (500);
}

void loop() {

  DS18B20float = getTemp();
  Serial.print(F("RAW temp from Sensor: "));
  Serial.println(tempRaw);
  Serial.print(F("FLOAT temp in celcius: "));
  Serial.println(DS18B20float);
  //if you read the registers before the conversion is complete it will give the default "85" value
  delay (5000);
}

// watchdog interrupt
ISR (WDT_vect) 
{
  wdt_disable();  // disable watchdog
}  // end of WDT_vect

// this returns the temperature from one DS18S20 in DEG Celsius using 12 bit conversion
float getTemp(){  
  //byte data[12];
  byte data[2];
  ds.reset();
  //ds.select(addr); // if you want to speak to only one at a time
  ds.write(0xCC); // Skip Rom sends the next command to all devices on one wire bus
  ds.write(0x44); // start conversion, read temperature and store it in the scratchpad 

  //this next bit creates a 1 second WDT delay for the DS18b20 temp conversion 
  //The time needed between the CONVERT_T command and the READ_SCRATCHPAD command has to be at least 
  //default 12-bit = 750 millisecs (can be shorter if using a D18B20 type with resolutions < 12 bits)
  ADCSRA = 0;   // disable ADC
  MCUSR = 0;   // clear various "reset" flags  
  WDTCSR = bit (WDCE) | bit (WDE); // allow changes, disable reset
  // set interrupt mode and an interval 
  WDTCSR = bit (WDIE) | bit (WDP2) | bit (WDP1);    //this creates a 1 second delay for the DS18b20 temp conversion
  wdt_reset();  // pat the dog 
  set_sleep_mode (SLEEP_MODE_PWR_DOWN);  
  sleep_enable();
  sleep_cpu ();    
  // cancel sleep as a precaution
  sleep_disable();

  byte present = ds.reset(); // Returns 1 if a device asserted a presence pulse, 0 otherwise.
  ds.select(addr);  
  ds.write(0xBE); // Read Scratchpad
  for (int i = 0; i < 2; i++) { // we read 9 bytes? but you only use two of them?
    data[i] = ds.read();
  }
  byte MSB = data[1];
  byte LSB = data[0];
  tempRaw = ((MSB << 8) | LSB); //using two's compliment
  //fahrenheit = celsius * 1.8 + 32.0;
  celsius = (float)tempRaw / 16.0; 
  return celsius;

}


