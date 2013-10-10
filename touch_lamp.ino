#include <CapSense.h>

/*
 This uses Capacitive touch sensing to turn a lamp on and of
  * Use a 1M resistor between send pin and receive pin
  * Receive pin is the sensor pin
  *Above is from the original capsense example*
##### *I CHANGED in the library "CapSense.c"#######
 	CS_Timeout_Millis = (70 * (float)loopTimingFactor * (float)F_CPU) / 16000000;
	CS_AutocaL_Millis = 30000;
the smaller the timout the faster it will respond, the autocal time I wanted longer for my setup
   WAS 2,000 and 20,000 
######################################################### 
 */
int LED = 9 ; // LED used to visualize simulated button press, button for this ties to ground when pressed

CapSense   cs_4_6 = CapSense(2,3);        // 1M resistor between pins 2 and 3 (the name 'cs_4_6' is from the original capsense example and I'm lazy'

void setup()                    
{
//   Serial.begin(9600);   //debug
   pinMode(LED,OUTPUT);       //setup pin as an output
   digitalWrite(LED,LOW);    //pull pin low (lamp on) to start
}

void loop()                    
{
    long start = millis();               
    long total2 =  cs_4_6.capSense(30);  //read the sense pins


/*  uncomment for debug
    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing
    Serial.print(total2);                  // print sensor output 2
    Serial.print("\t");
    delay(1);                             // arbitrary delay to limit data to serial port 
*/

if (total2 > 250){                          //determines if the sensor has been touched 250 was my minimum threshold, this will vary depending on material and size of sensor
 if(digitalRead(LED) == HIGH){          //if touched,is it off?
 digitalWrite (LED,LOW);               //if so, turns the lamp on
 delay (100);                          //wait 100ms before checking again
 }
 else if(digitalRead(LED) == LOW){    //if touched, is it already on?
 digitalWrite (LED,HIGH);             // if so, turns lamp off
 delay (100);                         //wait 100ms before checking again       
 }
}
}
