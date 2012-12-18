// Example sketch for PIR sensor
// Written by Oskari Rauta

#include "PIR.h"

// We output state of sensor every 2,5 seconds..
#define outputInterval 2500

#define PIRPIN 15     // what pin we're connected to

// Connect pin 1 (on the right) of the sensor to +5v
// Connect pin 2 of the sensor to whatever your PIRPIN is
// Connect pin 3 (on the left) of the sensor to GND (of 5v)

PIR pir1(PIRPIN);

uint32 lastOutput;

void setup() {
  delay(2000);
  SerialUSB.println("PIR sensor test!");
  lastOutput = millis() - outputInterval;
}

void loop() {
  pir1.update();

  if ( millis() > lastOutput + outputInterval ) {
	if ( pir1.calibrating() )
		SerialUSB.println("Sensor is still calibrating, please wait.");
	else {
		if ( pir1.state() )
			SerialUSB.println("Movement has been detected.");
		else
			SerialUSB.println("There was no movement in the last interval.");
		pir1.resetState(); // We have checked if there has been movement, so clear
				// the state flag..
	}
    lastOutput = millis();
  }

}