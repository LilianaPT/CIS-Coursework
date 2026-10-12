/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: MidTerm
Problem Number: Quiz 4
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 3/11/2025

Purpose: This program acts as a Number Series Analyzer. it reads a 
series of integers from the user until a sentinel value (0) is entered. 
Then calculates and displays statistical data, including the sum, 
count, minimum, maximum, average, and a tally of even vs. odd numbers.
********************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

bool isEven(int n);
double computeAverage(double total, int count);
void printReport(int count, double sum, int minVal, int maxVal, double avg, int evenCount, int oddCount);

int main()
{
    int input, count = 0, 
        evenCount = 0, oddCount = 0;
    int minVal, maxVal;
    double sum = 0.0, avg;

    cout << "Enter integers (0 to stop): " << endl;
    // Sentinel-controlled loop: stops when user enters 0
    while (cin >> input && input != 0) {
        // Correctly initialize min and max using the very first valid entry
        if (count == 0) {
            minVal = input;
            maxVal = input;
        }
        else {
            // Update min/max if the current input is smaller or larger
            if (input < minVal) {
                minVal = input;
            }
            if (input > maxVal) {
                maxVal = input;
            }
        }

        sum += input;
        count++;

        if (isEven(input)) {
            evenCount++;
        }
        else {
            oddCount++;
        }
    }

    if (count == 0) {
        cout << "No data entered." << endl;
    }
    else {
        avg = computeAverage(sum, count);
        printReport(count, sum, minVal, maxVal, avg, evenCount, oddCount);
    }


    return 0;
}

bool isEven(int n) {
    return n % 2 == 0;
}

double computeAverage(double total, int count) {
    if (count == 0) {
        return 0.0;
    }
    else {
        return total / count;
    }
}

void printReport(int count, double sum, int minVal, int maxVal, double avg, int evenCount, int oddCount) {
    cout << "\n==============================" << endl;
    cout << "      Number Series Report " << endl;
    cout << "==============================" << endl;
    cout << left << setw(13) << "Count" << ": " << count << endl;
    cout << left << setw(13) << "Sum" << ": " << sum << endl;
    cout << left << setw(13) << "Minimum" << ": " << minVal << endl;
    cout << left << setw(13) << "Maximum" << ": " << maxVal << endl;
    cout << fixed << setprecision(2);
    cout << left << setw(13) << "Average" << ": " << avg << endl;
    cout << left << setw(13) << "Even numbers" << ": " << evenCount << endl;
    cout << left << setw(13) << "Odd numbers" << ": " << oddCount << endl;
    cout << "==============================" << endl;

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
