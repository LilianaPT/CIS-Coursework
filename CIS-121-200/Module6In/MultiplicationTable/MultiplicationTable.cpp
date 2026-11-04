/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 6
Problem Number: 2
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 2/23/2025

Purpose: This program generates a multiplication table based on a 
size (1-15). It utilizes nested loops for the table generation and 
includes input validation to ensure the size remains within bounds.
********************************************************************/

#include <iostream>
#include <iomanip>      //Needed for setw() to align table columns
#include <cstdlib>      //Needed for system("pause") and system ("cls")

using namespace std;

int main()
{
    int size;               //It stores the size of the table
    char choice = 'Y';      //It stores the option that user select at the end of the program

    //Loop that allows the user to repeat the program multiple times
    while (choice == 'Y' || choice == 'y') {
       //Input validation for the size of the table
        while (true) {
            cout << "Enter the table size: ";
            cin >> size;
            if (size >= 1 && size <= 15) {
                break; //Finishes the validation if the size meet the criteria
            }
            else {
                cout << "\nSize must be between 1 and 15. Enter the table size: ";
            }
        }

        //Print header of multiplication table
        cout << setw(4) << " ";
        for (int i = 1; i <= size; ++i) {
            cout << setw(4) << i;
        }

        cout << endl;

        for (int i = 1; i <= size; ++i) {
            cout << setw(4) << i;               //Print the side of the multiplication table
            for (int j = 1; j <= size; ++j) {
                cout << setw(4) << i * j;       //Print the body of the multiplication table
            }
            cout << endl;
        }

        //User prompt for repetition of the program
        cout << "\nWould you like to print another table? (Y/N): ";
        cin >> choice;

        //system("pause");
        //system("cls");
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
