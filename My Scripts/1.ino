#include "Keyboard.h"

// 1, 2, 3, 4, 5, 6, 7, 8, 9, 0
//int EWOKeyArray[]={10, 49, 50, 51, 52, 53, 54, 55, 56, 57, 48};

// `, F1, F2, F3, F4, F5, F6, F7, F8
//int EWOKeyArray[]={10, 96, 194, 195, 196, 197, 198, 199, 200, 201, 202};

// `, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12
//int EWOKeyArray[]={13, 96, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205};

// `, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, Enter
//int EWOKeyArray[]={14, 96, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 176};

// F12, F11, F10, F9, F8, F7, F6, F5, F4, F3, F2, F1, `
int EWOKeyArray[]={13, 205, 204, 203, 202, 201, 200, 199, 198, 197, 196, 195, 194, 96};

// F12, F11, F10, F9, F1, `
//int EWOKeyArray[]={6, 205, 204, 203, 202, 194, 96};

// `, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0
//int EWOKeyArray[]={23, 96, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 49, 50, 51, 52, 53, 54, 55, 56, 57, 48};

void setup()
{
	pinMode(2, INPUT_PULLUP);
}

void loop()
{
	// Do nothing until pin 2 goes low.
	while (digitalRead(2) == HIGH)
	{
		delay(1000);
	}
	
	Keyboard.begin();
	int EWOKeyCount = 1;
	int EWOTimer = 0;
	
	// Hours * Minutes * Seconds * Milliseconds / 200 Milliseconds
	int EWOTimerMax = 1.5 * 60 * 60 * 1000 / 200;
	
	while (digitalRead(2) == LOW)
	{
		Keyboard.press(EWOKeyArray[EWOKeyCount]);
		Keyboard.release(EWOKeyArray[EWOKeyCount]);
		delay(200);
		EWOTimer++;
		
		if (EWOTimer < EWOTimerMax)
		{
			EWOKeyCount++;
			if (EWOKeyCount > EWOKeyArray[0])
			{
				EWOKeyCount = 1;
			}
		}
	}
	
	Keyboard.end();
}
