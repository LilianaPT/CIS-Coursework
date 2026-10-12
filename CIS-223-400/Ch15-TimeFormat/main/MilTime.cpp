#include "MilTime.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//Constructor
MilTime::MilTime(int mHours, int mSec) {
	setTime(mHours, mSec);
}

//setTime function with input validation and conversion
void MilTime::setTime(int mHours, int mSec) {
	//Input validation as required by the prompt
	if (mHours < 0 || mHours > 2359) {
		cout << "Error: Invalid military hours. Must be between 0 and 2359.\n";
		milHours = 0;
	}
	else {
		milHours = mHours;
	}

	if (mSec < 0 || mSec > 59) {
		cout << "Error: Invalid seconds. Must be between 0 and 59.\n";
		milSeconds = 0;
	}
	else {
		milSeconds = mSec;
	}

	//Convert military time to Standard Time for the Time class variables
	//hours, min, sec
	int rawHours = milHours / 100;
	min = milHours % 100;
	sec = milSeconds;

	//Conversion logic from 24-hour to standard 12-hour/24-hour format
	if (rawHours == 0) {
		hours = 12;				//Midnight representation in 12-hour format or keep 24-hour depending on implementation
	}
	else if (rawHours > 12) {
		hours = rawHours - 12;
	}
	else {
		hours = rawHours;
	}
}