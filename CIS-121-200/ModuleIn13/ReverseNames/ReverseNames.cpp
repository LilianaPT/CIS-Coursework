/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 13
Problem Number: 3
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 4/20/2026

Purpose: 
********************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string fileName, line;
    
    cout << "Enter the file you wish to process: ";
    cin >> fileName;

    ifstream inputFile(fileName);

    if (!inputFile) {
        cout << "Error: Could not open file" << endl;
        return 1;
    }

    cout << "The reformatted names are: " << endl;

    while (getline(inputFile, line)) {
        if (line == ".") {
            break;
        }

        size_t commaPos = line.find(',');

        if (commaPos != string::npos) {
            string lastName = line.substr(0, commaPos);
            string firstAndMI = line.substr(commaPos + 2);
            cout << firstAndMI << " " << lastName << endl;
        }
        else {
            cout << line << endl;
        }
    }

    inputFile.close();
    cout << "End program." << endl;

    return 0;
}

