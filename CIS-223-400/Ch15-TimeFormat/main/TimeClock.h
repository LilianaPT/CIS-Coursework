#ifndef TIMECLOCK_H
#define TIMECLOCK_H

#include "MilTime.h"

class TimeClock : public MilTime {
public:
	//Default constructor
	TimeClock() : MilTime() {}

	//Constructor taking start and end times in military format
	TimeClock(int startMilHours, int startMilSec, int endMilHours, int endMilSec) {
	}

	//Member function to calculate elapsed time between two MilTime objects
	MilTime calculateElapsedTime(MilTime startTime, MilTime endTime) {
		int startTotalSec = (startTime.getHour() / 100) * 3600 + (startTime.getHour() % 100) * 60;
		int endTotalSec = (endTime.getHour() / 100) * 3600 + (endTime.getHour() % 100) * 60;

		//Account for crossing midnight if necessary, or simple difference
		int diffSec = endTotalSec - startTotalSec;
		if (diffSec < 0) {
			diffSec += 24 * 3600;			// 24-hours offset
		}

		int elapsedHours = diffSec / 3600;
		int elapsedMinutes = (diffSec % 3600) / 60;
		//int milElapsed = (elapsedHours * 100) + elapsedMinutes;

		MilTime elapsedTime(elapsedHours, 0);
		return elapsedTime;
	}
};

#endif // !TIMECLOCK_H