#ifndef TIME_H
#define TIME_H

class Time {
protected:
	int hours;
	int min;
	int sec;

public:
	//Default constructor
	Time() {
		hours = 0;
		min = 0;
		sec = 0;
	}

	//Constructor
	Time(int h, int m, int s) {
		hours = h;
		min = m;
		sec = s;
	}

	//Accessor functions
	int getHour() const { return hours; }
	int getMin() const { return min; }
	int getSec() const { return sec; }
};

#endif // !TIME_H

