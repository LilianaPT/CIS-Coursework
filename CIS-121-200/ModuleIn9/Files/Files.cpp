/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 9
Problem Number: 1
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 3/16/2025

Purpose: This program reads an unknown number of integers from an input 
file (input.txt). For each number, it calculates its square and a 
total, then formats this data into a table within an output 
file (output.txt). Finally, calculate and print the total sum and 
average to the file and displays the file's content in the console.
********************************************************************/


#include <iostream>
#include <cstdlib>
#include <fstream>      //Library for files function
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    //Variable declaration
    ifstream inputFile;
    ofstream outputFile;
    int x, count = 0;
    double average, sum = 0;
    string result;

    inputFile.open("input.txt", ios::in); //Open the file "input" in lecture mode.
    //Check if an error occur while is opening the file
    if (inputFile.fail()) {
        cout << "We couldn't open input file.";
        exit(1);
    }
    // Open/Create the output file and check for errors
    outputFile.open("output.txt", ios::out);
    if (outputFile.fail()) {
        cout << "We couldn't open and create output file.";
        exit(1);
    }
    // Write the table headers to the output file
    outputFile << left << setw(5) << "x" << setw(7) << "x^2" << "Current Sum" << endl;
    outputFile << left << setw(5) << "===" << setw(7) << "===" << "==========" << endl;
    // Loop through the input file until no more integers remain
    while (inputFile >> x) {
        sum += x;               // Update running total
        count++;                // Increment the number of integers read

        // Write the value, its square, and the current sum to the table
        outputFile << left << setw(5) << x << setw(7) 
            << static_cast<int>(pow(x, 2.0)) << sum << endl;
    }
    // Calculate average and write final statistics if data was found
    if (count > 0) {
        average = sum / count;
        outputFile << "\nThe average of these " << count << " numbers is: " << average << endl;
        outputFile << "\nThe sum of these " << count << " numbers is: " << sum << endl;
    }
    
    // Close files to ensure data is saved and resources are freed
    inputFile.close();
    outputFile.close();

    // Display a preview of the results to the user console
    cout << "Data processed! Below is an example of how the output.txt will looks like: " << endl;
    ifstream showOutFile;
    showOutFile.open("output.txt", ios::in);
    // Read the output file line by line and print to screen
    while (!showOutFile.eof()) {
        getline(showOutFile, result);
        cout << result << endl;
    }

    showOutFile.close();


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
