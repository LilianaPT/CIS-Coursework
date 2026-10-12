/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 2
Problem Number: 3
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 1/26/2025

Purpose: Write a program that allows the user to enter a number of 
quarters, dimes and nickels and then outputs the monetary of the 
coins in cents.
For example, if the user enters 2 for the number of quarters, 3 for 
the number of dimes, and 3 for the number of nickels, then the 
program should output that the coins are worth 95 cents.
Example Output:
Enter the number of quarters: 2
Enter the number of dims: 3
Enter the number of nickels: 3
You have 95 cents.
********************************************************************/

//Libraries
#include <iostream>
#include <math.h>

using namespace std;

//Main Program
int main()
{
    //Constants variables declared for coins
    const int quarters = 25, dimes = 10, nickels = 5;
    //Variables declared
    int numberOfQuarters, numberOfDimes, numberOfNickels, totalCents;

    //Input User data
    cout << "Enter the number of quarters: ";
    cin >> numberOfQuarters;
    cout << "Enter the number of dimes: ";
    cin >> numberOfDimes;
    cout << "Enter the number of nickels: ";
    cin >> numberOfNickels;

    //Calculate the total in cents with the total of each coins
    totalCents = (numberOfQuarters * quarters) + (numberOfDimes * dimes) + (numberOfNickels * nickels);

    //Output of the result
    cout << "\nYou have " << totalCents << " cents.";

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
