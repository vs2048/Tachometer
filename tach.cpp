/*
 * tach.c
 * Tachometer
 */
 
#include "tach.h"

// Constructor takes the pin of the optical sensor
tach::tach(int p) {
	pin = p;
	lastTrigger = 0;
	recalibrate();
}

// This resets the calibration of the line sensor
void tach::recalibrate() {
	Serial.println("Tachometer recalibrating!");
	max = 0;
	min = 1024;
	ready = 0;
	triggered = 0;
	RPM = 0;
}

char tach::update() {
	char updated = 0;
	unsigned long deltaT;
	// Read the pin and update min/max reading
	int currentReading = analogRead(pin);
	if(currentReading > max)
		max = currentReading;
	if(currentReading < min)
		min = currentReading;

	// If min and max are greater than the hysteresis we can calculate the threshold to
	// trigger the sensor
	if(max-min > HIST) {
		ready = 1;
		threshold = min + 0.75*(max-min);
	}
	
	// If ready compute the RPM
	if(ready == 1) {
		// Update the trigger and calculate RPM;
		if(triggered == 0 && currentReading > threshold) {	// on rising edge set trigger
			updated = 1;
			triggered = 1;
			deltaT = micros() - lastTrigger;
			lastTrigger = lastTrigger + deltaT;
			RPM = 60000000 / deltaT;
		}
		
		else if (triggered == 1 && currentReading < threshold) { // On falling edge reset
			triggered = 0;
		}
		else {	// Otherwise test for stale signal
			deltaT = micros() - lastTrigger;
			if(deltaT > 2000000) {
				recalibrate();
				updated = 1;
			}
		}		
	}
	return updated;
}
