#include <iostream>
#include "MilTime.h"
#include "TimeClock.h"

using namespace std;

int main()
{
    int mHours, mSec;

    cout << "=== Program 4: Time Format Demonstration ===\n";
    cout << "Enter military time hours (ex., 1300 for 1:00PM): ";
    cin >> mHours;
    cout << "Enter seconds (0-59): ";
    cin >> mSec;

    MilTime clockTime(mHours, mSec);

    cout << "\n--- Time Conversion Results ---\n";
    cout << "Military Time: " << clockTime.getHour() << " hours, " << mSec << " seconds\n";
    cout << "Standard Time: " << clockTime.getStandingHour() << ":"
        << (clockTime.getMin() < 10 ? "0" : "") << clockTime.getMin() << ":"
        << (clockTime.getSec() < 10 ? "0" : "") << clockTime.getSec() << endl;

    cout << "\n=== Program 5: Time Clock Demonstration ===\n";
    int startHour, endHour;
    cout << "Enter starting military time (ex., 900): ";
    cin >> startHour;
    cout << "Enter ending military time (ex., 1300): ";
    cin >> endHour;

    MilTime startTime(startHour, 0);
    MilTime endTime(endHour, 0);
    TimeClock clockCalc;
    MilTime elapsed = clockCalc.calculateElapsedTime(startTime, endTime);

    cout << "Elapsed military hours between start and end: " << elapsed.getHour() << " hours.\n";
    
    return 0;
}