#include "Mouse.h"

void setup()
{
	pinMode(2, INPUT_PULLUP);
}

void loop()
{
	// Do nothing until pin 2 goes low.
	while (digitalRead(2) == HIGH)
	{
	}
	
	Mouse.begin();
	
	while (digitalRead(2) == LOW)
	{
		Mouse.click();
		delay(25);
	}
	
	Mouse.end();
}
