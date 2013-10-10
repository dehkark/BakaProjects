	//#include <Bounce.h>
	#include <SD.h>                      // need to include the SD library
	//#define SD_ChipSelectPin 53  //example uses hardware SS pin 53 on Mega2560
	#define SD_ChipSelectPin 10  //using digital pin 4 on arduino nano 328
	#include <TMRpcm.h>           //  also need to include this library...
	#define buttonPin 2
	//const int buttonPin = 2;     // the number of the pushbutton pin
	//int buttonState = digitalRead (buttonPin);         // variable for reading the pushbutton status 
	int count;
	int wait;
	TMRpcm tmrpcm;   // create an object for use in this sketch
	//char mychar;
	//Bounce bouncer = Bounce( buttonPin,1 ); //bounce the button pin
	
	void setup(){
	 
	  tmrpcm.speakerPin = 9; //11 on Mega, 9 on Uno, Nano, etc
	 // initialize the pushbutton pin as an input:
	  int count = 1;
	int wait = 0;
	  pinMode(buttonPin, INPUT);
	  digitalWrite(buttonPin, HIGH);
	  //Serial.begin(9600);
	  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
	    //Serial.println("SD fail");  
	    return;   // don't do anything more if not
	  }
	 // tmrpcm.play("1.wav"); //the sound file "music" will play each time the arduino powers up, or is reset
	}
	 
	 
	 
	void loop(){  
	 // read the state of the pushbutton value:
	 // Update the debouncer
	//  bouncer.update ( );
	  
	 // Get the update value
	 int value = digitalRead (buttonPin);//bouncer.read();
	
	
	  // check if the pushbutton is pressed.
	  // if it is, the buttonState is HIGH:
	  if ( value == LOW) { //send the letter p over the serial monitor to start playback
	      if (wait < 10000){
	        wait = (wait + 1);
	      }
	      else if (count == 0) {
	        count = (count +1);
	       wait = 0; 
	      }      
	      else if (count == 6) {
	        count = 0;
	       wait = 0; 
	      }
	      else if (count == 1) {      
	      tmrpcm.play("1.wav");
	            count = (count + 1);
	       wait = 0; 
	       }
	      else if (count == 2) {      
	      tmrpcm.play("2.wav");
	            count = (count + 1);
	        wait = 0; 
	      }    
	      else if (count == 3) {      
	      tmrpcm.play("3.wav");
	            count = (count + 1);
	       wait = 0; 
	     }
	      else if (count == 4) {      
	      tmrpcm.play("4.wav");
	     count = (count + 1);
	//     count = 0;
	     wait = 0;
	   }
	      else if (count == 5) {      
	      tmrpcm.play("5.wav");
	     count = 0;
	          wait = 0;
	    }
	    }
}
