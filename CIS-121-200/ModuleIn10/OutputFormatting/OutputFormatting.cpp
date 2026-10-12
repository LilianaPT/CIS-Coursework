/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 10
Problem Number: 2
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 3/22/2026

Purpose: This program reads two floating-point numbers from a 
user-defined text file and calculates their sum, product, and 
difference. It outputs these results in two specific formats: 
fixed-point notation and scientific notation, using strict 
field widths of 20 characters for labels and 12 for values.
********************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    //Variable Declarations
    ifstream inFile;
    double num1, num2;
    string fileName;

    // Prompt user for file name and open file
    cout << "Enter the file name and include .txt: ";
    cin >> fileName;
    inFile.open(fileName, ios::in);
    // Validate if the file opened successfully
    if (inFile.fail()) {
        cout << "We couldn't open the file '" << fileName << "' " << endl;
        exit(1);
    }

    // Read the two numbers from the file and close it immediately
    inFile >> num1 >> num2;
    inFile.close();

    // Set formatting to 3 decimal places for all subsequent output
    cout << fixed << setprecision(3);

    // Display the numbers read from the file
    cout << "Read the first number: " << num1 << endl;
    cout << "Read the second number: " << num2 << endl;

    // Calculate arithmetic results
    double sum = num1 + num2;
    double product = num1 * num2;
    double difference = num1 - num2;
    // Output results in Fixed-Point notation
    // setw(20) sets label width, setw(12) sets number width
    cout << left << setw(20) << "The sum is " << right << setw(12) << sum << "." << endl;
    cout << left << setw(20) << "The product is " << right << setw(12) << product << "." << endl;
    cout << left << setw(20) << "The difference is " << right << setw(12) << difference << "." << endl;

    // Output results in Scientific notation
    cout << "Here is the same data in scientific notation: " << endl;
    cout << scientific;                 // Switch stream to scientific format
    cout << left << setw(20) << "The sum is " << right << setw(12) << sum << "." << endl;
    cout << left << setw(20) << "The product is " << right << setw(12) << product << "." << endl;
    cout << left << setw(20) << "The difference is " << right << setw(12) << difference << "." << endl;


    return 0;
}


