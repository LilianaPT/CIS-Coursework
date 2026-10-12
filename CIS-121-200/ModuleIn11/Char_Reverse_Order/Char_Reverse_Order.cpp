/*******************************************************************
                          CIS121 Spring 2026
Type of Assignment: Lab 11
Problem Number: 3
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 4/6/2025

Purpose: This program reads a sequence of up to 20 characters from 
the user, stopping when a '.' is entered. It then prints the 
characters in reverse order. The program includes a nested loop to 
allow the user to process multiple lists.
********************************************************************/

#include <iostream>

using namespace std;

int main()
{
    const int SIZE = 20;
    char list[SIZE];
    char repeat;

    do {
        int count = 0;
        char input;
        cout << "Enter a list of Characters (. to end list): " << endl;

        //Read characters until '.' is hit or array is full
        //We use a while loop to handle the specific termination condition
        while (count < SIZE) {
            cin >> input;

            //If the character is a period, stop reading
            if (input == '.') {
                break;
            }

            //Store the character and increment the counter
            list[count] = input;
            count++;
        }

        //Print characters in reverse order
        if (count == 0) {
            cout << "\nAny characters were entered into the list. " << endl;
        }
        else {
            cout << "\nThe characters in reverse order are: " << endl;
            //Start at the last filled index (count - 1) and move toward index 0
            for (int i = count - 1; i >= 0; i--) {
                cout << list[i] << " ";
            }
            cout << endl;
        }

        //Ask the user if they want to run the program again
        cout << "\nWould you like to process another list? (Y or N): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    cout << "\nEnd program..." << endl;

    return 0;
}

