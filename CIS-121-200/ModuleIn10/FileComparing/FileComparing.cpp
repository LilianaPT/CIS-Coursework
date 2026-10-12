/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 10
Problem Number: 3
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 3/22/2026

Purpose: This program compares two user-specified text files character 
by character. It determines if the files are identical or if they 
contain differences. If they differ, it identifies the specific 
line numbers where discrepancies occur and detects if one file is 
longer than the other.
********************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    //Variable Declarations
    ifstream inFile1, inFile2;
    string fileName1, fileName2;
    char ch1, ch2;
    int currentLine = 1;                    // Track current line position
    bool isIdentical = true;                // Flag to track overall file similarity
    bool mismatchOnThisLine = false;        // Flag to ensure line number prints only once per line

    // Get file names from user
    cout << "Enter the first File Name, please include .txt: ";
    cin >> fileName1;
    cout << "Enter the second File Name, please include .txt: ";
    cin >> fileName2;

    // Open both files for reading
    inFile1.open(fileName1, ios::in);
    inFile2.open(fileName2, ios::in);

    // Validation: Check if both files opened successfully
    if (inFile1.fail() || inFile2.fail()) {
        cout << "We couldn't open one or both files." << endl;
        exit(1);
    }

    cout << "\nChecking for differences...." << endl;
    // Compare character by character as long as both files have content
    while (inFile1.get(ch1) && inFile2.get(ch2)) {
        // If characters at the same position don't match
        if (ch1 != ch2) {
            // Initialize the difference message
            if (isIdentical) {
                cout << "\nDifferences found on line(s): ";
                isIdentical = false;
            }
            // Print the line number only if we haven't already reported a mismatch on this specific line
            if (!mismatchOnThisLine) {
                cout << currentLine << " ";
                mismatchOnThisLine = true;
            }
        }
        // Detect newline characters to increment line counter and reset line mismatch flag
        if (ch1 == '\n') {
            currentLine++;
            mismatchOnThisLine = false;
        }
    }
    // Check if files are different lengths (one file still has characters left)
    if (isIdentical && (inFile1.get(ch1) || inFile2.get(ch2))) {
        isIdentical = false;
        cout << "\nDifferences found: One file is longer than the other (starts at line " << currentLine << ") ";
    }
    // Final result output
    if (isIdentical) {
        cout << "\nThe files are exactly the same." << endl;
    }
    else {
        cout << "\nEnd of comparison." << endl;
    }

    // Close file streams
    inFile1.close();
    inFile2.close();

    return 0;
}

