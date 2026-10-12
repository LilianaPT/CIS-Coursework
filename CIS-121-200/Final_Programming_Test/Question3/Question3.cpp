/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Final_Test
Problem Number: Question 3
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 5/06/2025

Purpose: The purpose of this program is to demonstrate linear search
logic and data verification within an array. It simulates a common 
real-world scenario: checking a collection of stored data 
(your tickets) against a single external variable (the winning number).
********************************************************************/

#include <iostream>

using namespace std;

bool searchList(const int tickets[], int size, int winningNum);

int main()
{
    const int NUM_TICKETS = 10;

    //Initialize the array with the user's "lucky" numbers
    int luckyNumbers[NUM_TICKETS] = {
        13579, 26791, 26792, 33445, 55555,
        62483, 77777, 79422, 85647, 93121
    };

    int winningNumber;

    cout << "Please enter this week's 5 digit winning lottery number: ";
    cin >> winningNumber;

    if (searchList(luckyNumbers, NUM_TICKETS, winningNumber)) {
        cout << "You have a winning ticket! Congratulations!" << endl;
    }
    else {
        cout << "You did not win this week." << endl;
    }

    return 0;
}

bool searchList(const int list[], int size, int value) {
    for (int index = 0; index < size; index++) {
        if (list[index] == value) {
            return true;
        }
    }
    return false;
}

