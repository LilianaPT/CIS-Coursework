// Classwork1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//void display(fstream& mfile) {
//    string line;
//    while (mfile >> line) {
//        cout << line;
//    }
//}
//
//bool openfile(fstream& tfile, string name) {
//    tfile.open(name, ios::in);
//    if (tfile.fail()) {
//        return false;
//    }
//    else {
//        return true;
//    }
//}

int main()
{
    fstream secretFile("sec.txt", ios::out);
    fstream dataFile("info.txt", ios::in);

    char ch;
    while (!dataFile.eof()) {
        dataFile >> ch;
        //display(secretFile);
        ch = (ch + 10);
        secretFile << ch;
    }

    secretFile.close();
    dataFile.close();

    return 0;
}