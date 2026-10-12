/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: MidTerm
Problem Number: Quiz 2
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 3/11/2025

Purpose: This program ask the user for a positive integer no greater
than 15 and then display a pattern with numbers.
********************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int n, i = 1, j = 1;

    cout << "Enter a positive integer (1-15): ";
    cin >> n;

    while (n <= 0 || n > 15) {
        cout << "Invalid Input. Please enter a number between 1 and 15: ";
        cin >> n;
    }

    while (i <= n) {
        while (j <= i) {
            cout << j << " ";
            j++;
        }
        j = 1;
        i++;
        cout << endl;
    }
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
