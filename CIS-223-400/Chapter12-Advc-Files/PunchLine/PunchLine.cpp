// PunchLine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Function prototypes
void printJoke(ifstream& jokeFile);
void printPunchLine(ifstream& punchFile);

int main()
{
    //Open the joke file
    ifstream jokeFile("joke.txt");
    if (jokeFile.fail()) {
        cout << "Error opening joke.txt" << endl;
        exit(1);
    }

    //Open the punch file
    ifstream punchFile("punchline.txt");
    if (punchFile.fail()) {
        cout << "Error opening punchline.txt" << endl;
        jokeFile.close();
        exit(1);
    }

    //Call functions passing each file
    printJoke(jokeFile);
    printPunchLine(punchFile);

    //Close the files
    jokeFile.close();
    punchFile.close();

    return 0;
}

//First function: reads and displays each line in the joke file
void printJoke(ifstream& jokeFile) {
    string line;
    while (getline(jokeFile, line)) {
        cout << line << endl;
    }
}

//Second function: displays only the last line by seeking to the end and backing up
void printPunchLine(ifstream& punchFile) {
    //Move to the end of the file to determine its size/position
    punchFile.seekg(0, ios::end);
    long pos = punchFile.tellg();

    //Step back pass any trailing newline characters at the very end
    pos--;
    while (pos > 0) {
        punchFile.seekg(pos, ios::beg);
        char ch;
        punchFile.get(ch);
        if (ch != '\n' && ch != '\r') {
            break;
        }
        pos--;
    }

    //Move backwards until the newline preceding the last line is found
    while (pos > 0) {
        punchFile.seekg(pos, ios::beg);
        char ch;
        punchFile.get(ch);
        if (ch == '\n') {
            pos++;      //Move past the newline to the beginning of the last line
            break;
        }
        pos--;
    }

    //If we hit the very beginning of the file
    if (pos < 0) pos = 0;

    //Seek to the start of the last line and read/print it
    punchFile.seekg(pos, ios::beg);
    string lastline;
    getline(punchFile, lastline);
    cout << lastline << endl;
}