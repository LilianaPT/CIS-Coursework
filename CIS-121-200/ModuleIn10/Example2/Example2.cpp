// Example2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cctype> 

using namespace std;

int main()
{
    char letter;

    cout << "Enter a character: ";
    //cin >> letter;

    cin.get(letter); //read all whitespaces

    if (isalpha(letter))
    {
        //check to see if it is a letter of alphabet 
        if (isupper(letter)) //check to see if it is uppercase 
        {
            cout << "Your character " << letter << " is in uppercase.";
            letter = tolower(letter);
            cout << "Its lowercase case is " << letter << endl;
        }
        else
        {
            cout << "Your character " << letter << " is in lowercase. ";
            letter = toupper(letter);
            cout << "Its uppercase is " << letter << endl;
        }
    }
    else if(isdigit(letter))        // digit: 0 through 9
    {
        cout << "Your character " << letter << " is a digit.\n";
    }
    else if (isspace(letter)) {
        //cout << "Your character is a space.\n";
        if (letter == '\n') {
            cout << "Your character is a new line.\n";
        }
        else if (letter == '\t') {
            cout << "Your character is a tab key.\n";
        }
        else if (letter == ' ') {
            cout << "Your character is a blank.\n";
        }
    }
    else {
        cout << "You entered something else....\n";
    }


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
