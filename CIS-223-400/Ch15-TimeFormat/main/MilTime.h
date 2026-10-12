#ifndef MILTIME_H
#define MILTIME_H

#include "Time.h"

class MilTime : public Time {
protected:
	int milHours;			// 24-hour format (0 - 2359)
	int milSeconds;			// Seconds (0 - 59)

public:
	//Default constructor
	MilTime() : Time() {
		milHours = 0;
		milSeconds = 0;
	}

	//Constructor
	MilTime(int mHours, int mSec);

	//Member functions
	void setTime(int mHours, int mSec);
	int getHour() const { return milHours; }
	int getStandingHour() const { return hours; }
};

#endif // !MILTIME_H
