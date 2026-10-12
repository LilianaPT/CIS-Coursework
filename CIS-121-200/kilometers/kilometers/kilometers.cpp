/*******************************************************************
                          CIS121 Spring 2026
Type of Assignment: Lab 1
Problem Number: 2
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 1/19/2025

Purpose: Program that will read in a number that represents the
number of kilometers traveled. The output will convert this number to miles.
********************************************************************/

#include <iostream>
#include<conio.h>

using namespace std;

int main()
{
    //Variables declaration
    float km, miles;

    //Input Identification
    cout << "Enter the number of kilometers traveled: ";
    cin >> km;

    //Calculate the miles by multiplying kilometers by 0.621
    miles = km * 0.621;

    //Output Identification
    cout << "\nThe Miles that you traveled are: " << miles;

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
