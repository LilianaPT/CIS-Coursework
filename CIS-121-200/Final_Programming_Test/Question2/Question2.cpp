/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Final_Test
Problem Number: Question 2
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 5/06/2025

Purpose: The purpose of this program is to implement a logical 
comparison algorithm for multi-dimensional data structures. It serves 
as a practical exercise in data validation and memory traversal.
********************************************************************/

#include <iostream>

using namespace std;

//Constant for the number of columns
const int SIZE = 3;

//Function prototype
bool equals(int m1[][SIZE], int m2[][SIZE], int rowSize);

int main()
{
    int list1[SIZE][SIZE];
    int list2[SIZE][SIZE];

    //Prompt user for the first 3x3 array
    cout << "Enter list1: ";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> list1[i][j];
        }
    }

    //Prompt user for the second 3x3 array
    cout << "Enter list2: ";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> list2[i][j];
        }
    }

    //Call the function and display the result
    if (equals(list1, list2, SIZE)) {
        cout << "Two arrays are strictly identical" << endl;
    }
    else {
        cout << "Two arrays are not strictly identical" << endl;
    }

    return 0;
}

//Check if two 2D arrays are strictly identical
bool equals(int m1[][SIZE], int m2[][SIZE], int rowSize) {
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (m1[i][j] != m2[i][j]) {
                return false;
            }
        }
    }

    return true;
}
