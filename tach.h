/*
 * tach.h
 * Tachometer that reads an optical sensor on a specified pin
 * 
 * The sensor should be aimed at a black line on a white shaft. Everytime the line
 * passes the sensor the speed of the shaft is calculated in rotations/minute
 * 
 * Run the update function in your loop and read RPM to get a result.
 * https://www.sparkfun.com/products/11769
 */

#include "Arduino.h"

// The hysteresys between a low and high signal
#define HIST 350
 
class tach {
	private:
		char ready;
		int max;
		int min;
		int threshold;
		unsigned long lastTrigger;
		int pin;
		char triggered;
		void recalibrate();
	public:
		int RPM;
		char update();
		tach(int p);
};
