// StringSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
    ifstream infile;
    string fileName, searchStr;

    cout << "This program counts the number of occurrences of a specific word in a file." << endl;

    //Getting the file name
    cout << "Please enter the file name: ";
    cin >> fileName;
    cout << "Enter string to search for: ";
    cin >> searchStr;

    //Open the file for reading
    infile.open(fileName, ios::in);

    //Validation: Check if the file was opened succesfully
    if (infile.fail()) {
        cout << "\nWe couldn't open the file. Does not exist";
        exit(1);
    }

    //Create a lowercase version of the search string for case-insesitive matching
    string searchLower = searchStr;
    transform(searchLower.begin(), searchLower.end(), searchLower.begin(), ::tolower);
    
    string line;
    int count = 0;

    cout << endl;
    cout << "Lines that contain the word searched:" << endl;
    while (getline(infile, line)) {
        //Create a lowercase version of the line for searching, while keeping the original line to display
        string lineLower = line;
        transform(lineLower.begin(), lineLower.end(), lineLower.begin(), ::tolower);
        
        size_t pos = lineLower.find(searchLower);
        bool printedLine = false;

        while (pos != string::npos) {
            count++;
            if (!printedLine) {
                cout << line << endl;
                printedLine = true;
            }
            pos = lineLower.find(searchLower, pos + searchLower.length());
        }
    }

    infile.close();

    cout << "\n" << searchStr << " was found " << count << " times" << endl;

    return 0;
}

