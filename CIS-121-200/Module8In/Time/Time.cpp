/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Extra Programming Project
Problem Number: 1
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 3/16/2025

Purpose: The purpose of this program is to calculate a future time by 
adding a specific duration (waiting period) to a starting time using 
24-hour notation.
********************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Set formatting for potential floating point outputs (though not used in this integer logic)
    cout << fixed << showpoint << setprecision(2);
    char colon, choice;                 // 'colon' stores the ':' character; 'choice' stores the loop continuation input
    int currH, currM, waitH, 
        waitM, totalMins, extraHours,
        finalM, finalH, totalHours;

    cout << "Compute completion time from current time and waiting period" << endl;
    // Loop allows the user to perform multiple calculations
    do {
        // Get current time from user input
        cout << "Current time: " << endl;
        cout << "Enter 24 hour time in the format HH:MM" << endl;
        cin >> currH >> colon >> currM;                             // Reads hours, skips the ':', then reads minutes

        // Get waiting duration from user input
        cout << "Waiting time: " << endl;
        cout << "Enter 24 hour time in the format HH:MM " << endl;
        cin >> waitH >> colon >> waitM;

        // Calculate total minutes and determine if they carry over into an hour
        totalMins = currM + waitM;
        extraHours = totalMins / 60;        // Get number of full hours from the minutes
        finalM = totalMins % 60;            // Get remaining minutes (0-59)

        // Sum all hours (start time + wait time + carry-over from minutes)
        totalHours = currH + waitH + extraHours;

        // Check if the resulting time rolls over past midnight (24+ hours)
        if (totalHours >= 24) {
            cout << "Completion time is in the day following the start time" << endl;
        }

        // Use modulo to wrap the hour back to the 0-23 range
        finalH = totalHours % 24;

        // Display the calculated result
        cout << "Completion Time in 24 hour format: " << endl;
        cout << finalH << ":" << finalM << endl << endl;

        // Prompt user to continue or exit
        cout << "Enter Y or y to continue, any other halts" << endl << endl;
        cin >> choice;


    } while (choice == 'Y' || choice == 'y'); // Loop continues if input is 'Y' or 'y'

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
