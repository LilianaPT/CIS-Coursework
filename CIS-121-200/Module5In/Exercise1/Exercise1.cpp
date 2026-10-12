// Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    char choice;

    cout << "Please enter a letter grade between (A,B or C): ";
    cin >> choice;

    switch(choice){
    case 'A': 
    case 'a': cout << "\nExcellent" << endl; break;
    case 'B': 
    case 'b': cout << "\nGood" << endl; break;
    case 'C': 
    case 'c': cout << "\nPassing" << endl; break;
    default: cout << "\nThat is not a possible grade, please try again." << endl;
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
