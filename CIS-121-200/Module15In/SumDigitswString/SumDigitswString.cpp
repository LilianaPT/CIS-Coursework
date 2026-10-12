/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 15
Problem Number: 1
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 5/12/2026

Purpose: This program demonstrates object-oriented programming in 
C++ by processing a string of numeric digits. It accepts a C-string 
from the user, encapsulates the data within a class, and calculates 
the sum, the highest digit, and the lowest digit provided in the sequence.
********************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

// Class to handle the parsing and analysis of numeric C-strings
class DigitAnalyzer {
private: 
    static const int SIZE = 100;            // Constant to define max buffer size
    char digits[SIZE];                      // Internal storage for the C-string

public:
    // Constructor to initialize the C-string
    DigitAnalyzer(const char* input) {
        // strncpy_s is used to prevent buffer overflows
        strncpy_s(digits, input, SIZE - 1);
        digits[SIZE - 1] = '\0';            //Ensure null-termination
    }

    // Method to calculate the sum
    int getSum() const {
        int total = 0;
        for (int i = 0; i < strlen(digits); i++) {
            // Subtract '0' (ASCII 48) to convert char digit to actual int
            total += (digits[i] - '0');
        }
        return total;
    }

    // Method to find the highest digit
    int getHighest() const {
        int highest = 0;                    // Initialize with the lowest possible digit
        for (int i = 0; i < strlen(digits); i++) {
            int current = digits[i] - '0';
            if (current > highest) highest = current;
        }
        return highest;
    }

    // Method to find the lowest digit
    int getLowest() const {
        int lowest = 9;                     // Initialize with the highest possible digit
        for (int i = 0; i < strlen(digits); i++) {
            int current = digits[i] - '0';
            if (current < lowest) lowest = current;
        }
        return lowest;
    }
};

int main()
{
    // Buffer to hold raw user input before object creation
    char inputBuffer[100];

    cout << "Enter a series of digits with no spaces between them." << endl;
    cin >> inputBuffer;

    // Instantiate the DigitAnalyzer object with the user's input
    DigitAnalyzer analyzer(inputBuffer);

    // Call class methods to retrieve and display the analyzed data
    cout << "\nThe sum of those digits is " << analyzer.getSum() << endl;
    cout << "The highest digit is " << analyzer.getHighest() << endl;
    cout << "The lowest digit is " << analyzer.getLowest() << endl;

    cout << "End program." << endl;

    return 0;
}

