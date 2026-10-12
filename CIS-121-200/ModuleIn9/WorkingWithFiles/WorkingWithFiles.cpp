/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 9
Problem Number: 2
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 3/16/2025

Purpose: This program prompts the user for a filename and reads a series 
of double values from it. It displays each number, calculates the 
running sum, and identifies the largest value. After processing the 
file, it outputs the maximum value and the calculated average. 
The program allows the user to repeat the process for multiple files.
********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    //Variable declaration
    string fileName;
    char repeat;
    double num, sum, maxVal, average;
    int count;

    //Loop that allows the user to repeat the program.
    do {
        ifstream inputFile;
        //Get the file name from the user
        cout << "Enter the file name including .txt: ";
        cin >> fileName;

        // Reset accumulators for each new file
        sum = 0;
        count = 0;
        maxVal = 0;

        //Open the file and check if user had errors when enters the name
        inputFile.open(fileName, ios::in);
        if (inputFile.fail()) {
            cout << "We couldn't open file. Please include the extension of the file." << fileName << endl;
        }
        else {
            cout << "The numbers in the file " << fileName << " are: " << endl;

            if (inputFile >> num) {
                // Process the very first number
                cout << fixed << noshowpoint << setprecision(1) << num << endl;
                sum = num;
                maxVal = num; // Start maxVal with the first actual number
                count = 1;
            }
            //Read doubles until end of file is reached
            while (inputFile >> num) {
                //Display the current number
                cout << fixed << noshowpoint << setprecision(1) << num << endl;

                //Accumulate total and update the maximum value found
                sum += num;
                if (num > maxVal) {
                    maxVal = num;
                }
                count++;
            }

            // If the file was not empty, calculate and display stats
            if (count > 0) {
                average = sum / count;
                cout << "\nThe largest number in the file is: " << maxVal << endl;
                cout << "\nThe average of all numbers in the file is: " <<
                    fixed << showpoint << setprecision(3) << average << endl;

            }
            else {
                cout << "The file is empty.";
            }
            // Close the file before potentially repeating
            inputFile.close();

        }
        // Prompt user to repeat or exit
        cout << "\nWould you like to do it again (Y or N): ";
        cin >> repeat;
        cout << endl;

    } while (repeat == 'Y' || repeat == 'y');

    cout << "\nFinished program." << endl;

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
