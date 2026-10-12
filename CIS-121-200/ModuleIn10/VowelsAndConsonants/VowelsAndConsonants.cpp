/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 10
Problem Number: 1
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 3/22/2026

Purpose: This program reads a user-specified text file to count and 
display the number of vowels, consonants, and spaces it contains. 
It then re-opens the file to display its original content for 
verification against the calculated counts.
********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    // Variable Declarations
    ifstream inputFile;
    int vowels = 0, consonants = 0, spaces = 0;
    char phrase;
    string result, fileName;

    // Get the file name from the user
    cout << "Enter the file name and include .txt: ";
    cin >> fileName;
    inputFile.open(fileName, ios::in);          // Open the file for reading
    if (inputFile.fail()) {                     // Check if the file opened successfully
        cout << "We couldn't open the file";
        exit(1);
    }

    // Process the file character by character
    while (inputFile.get(phrase)) {
        if (isalpha(phrase)) {                      // Check if the character is a letter (A-Z or a-z)
            char lowerV = tolower(phrase);           // Standardize to lowercase for easier comparison
            // Check if the letter is a vowel
            if (lowerV == 'a' || lowerV == 'e' || lowerV == 'i' || lowerV == 'o' || lowerV == 'u') {
                vowels++;
            }
            else {
                // If it's a letter but not a vowel, it's a consonant
                consonants++;
            }
        }
        // Check if the character is whitespace
        else if (isspace(phrase)) {
            // Specifically count standard spaces ' '
            if (phrase == ' ') {
                spaces++;
            }
        }
    }
    inputFile.close();          //Close the file

    //Display Output
    cout << "\nThe input file has the following counts: \n";
    cout << "\n\tVowels: " << vowels << endl;
    cout << "\tConsonants: " << consonants << endl;
    cout << "\tSpaces: " << spaces << endl;
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << "Above results are for the test file: \n";

    // Second pass: Open the file again to display its contents to the user
    ifstream showOutFile;
    showOutFile.open(fileName, ios::in);
    while (!showOutFile.eof()) {
        getline(showOutFile, result);
        cout << result << endl;
    }

    showOutFile.close();

    return 0;
}


