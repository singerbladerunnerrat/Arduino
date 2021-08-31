#include "Keyboard.h"

// 1, 2, 3, 4, 5, 6, 7, 8, 9, 0
//int EWOKeyboardArray[]={10, 49, 50, 51, 52, 53, 54, 55, 56, 57, 48};

// `, F1, F2, F3, F4, F5, F6, F7, F8
//int EWOKeyboardArray[]={10, 96, 194, 195, 196, 197, 198, 199, 200, 201, 202};

// `, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12
int EWOKeyboardArray[]={13, 96, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205};

// `, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, Enter
//int EWOKeyboardArray[]={14, 96, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 176};

// F12, F11, F10, F9, F8, F7, F6, F5, F4, F3, F2, F1, `
//int EWOKeyboardArray[]={13, 205, 204, 203, 202, 201, 200, 199, 198, 197, 196, 195, 194, 96};

// F12, F11, F10, F9, F1, `
//int EWOKeyboardArray[]={6, 205, 204, 203, 202, 194, 96};

// `, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0
//int EWOKeyboardArray[]={23, 96, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 49, 50, 51, 52, 53, 54, 55, 56, 57, 48};

void setup()
{
	pinMode(2, INPUT_PULLUP);
}

int EWOKeyboardCount = 1;

void loop()
{
	// Do nothing until pin 2 goes low.
	while (digitalRead(2) == HIGH)
	{
		delay(1000);
	}
	
	Keyboard.begin();
	
	while (digitalRead(2) == LOW)
	{
		Keyboard.press(EWOKeyboardArray[EWOKeyboardCount]);
		Keyboard.release(EWOKeyboardArray[EWOKeyboardCount]);
		delay(200);
		EWOKeyboardCount++;
		if (EWOKeyboardCount > EWOKeyboardArray[0])
		{
			EWOKeyboardCount = 1;
		}
	}
	
	Keyboard.end();
}
