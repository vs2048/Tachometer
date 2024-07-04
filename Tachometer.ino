#include "tach.h"
#include <LiquidCrystal.h>

// Update display every 250 millis
#define UPDATE 250

// Define the pins of the LCD and tachometer
LiquidCrystal lcd(7,6,5,4,3,2);
tach t0(A0);
unsigned long lastPrint = 0;

// Setup function initializes the LCD
void setup() {
	lcd.begin(16,2);
	lcd.clear();
}

void loop() {
	// Read tachometer as fast as possible
	t0.update();

	// Print the results every UPDATE interval
	if(millis() - lastPrint > UPDATE) {
		lastPrint = millis();
		lcd.clear();
		lcd.print("t0: ");
		if(t0.RPM <10)
			lcd.print("   ");
		else if(t0.RPM < 100)
			lcd.print("  ");
		else if(t0.RPM < 1000)
			lcd.print(" ");
		lcd.print(t0.RPM);
		lcd.print(" RPM");
		
	}
}
