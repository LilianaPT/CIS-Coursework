/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 12
Problem Number: 1
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 4/12/2026

Purpose: This program demonstrates how to manipulate 2D arrays in C++.
It initializes an array with random floating-point values, calculates 
totals and averages, and performs specific row/column analysis such 
as finding the highest and lowest values in a row.
********************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Global constants for array dimensions to ensure consistency across functions
const int NUM_ROWS = 3;
const int NUM_COLS = 4;

//Function Prototype
void printArray(double scores[][NUM_COLS], int size);
double getTotal(double scores[][NUM_COLS], int size);
double getAverage(double scores[][NUM_COLS], int size);
double getColumnTotal(double scores[][NUM_COLS], int rowSize, int colNum);
double getRowTotal(double scores[][NUM_COLS], int rowNum);
double getHighestInRow(double scores[][NUM_COLS], int rowIndex);
double getLowestInRow(double scores[][NUM_COLS], int rowIndex);
int rand_int(int a, int b);
double rand_float(double a, double b);

int main()
{
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    double scores[NUM_ROWS][NUM_COLS];
    int testCol, testRow;

    // Initialize the array using rand_float prototype (e.g., between 1.0 and 100.0)
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            scores[i][j] = rand_float(1.0, 100.0);
        }
    }

    // Print the array safely now that it holds data
    cout << "--- Randomly Generated Array ---\n";
    printArray(scores, NUM_ROWS);

    //I use NUM-1 because array indices are zero-based (0 to N-1)
    testCol = rand_int(0, NUM_COLS-1);
    testRow = rand_int(0, NUM_ROWS-1);

    //Displaying the calculations
    cout << "\n--- Calculations ---\n";
    cout << "Total of all elements: " << getTotal(scores, NUM_ROWS) << endl;
    cout << "Average of all elements: " << getAverage(scores, NUM_ROWS) << endl;
    cout << "Total of column " << testCol << ": " << getColumnTotal(scores, NUM_ROWS, testCol) << endl;
    cout << "Total of row " << testRow << ": " << getRowTotal(scores, testRow) << endl;
    cout << "Highest in row " << testRow << ": " << getHighestInRow(scores, testRow) << endl;
    cout << "Lowest in row " << testRow << ": " << getLowestInRow(scores, testRow) << endl;

    return 0;
}

// Displays the 2D array in a formatted grid
void printArray(double scores[][NUM_COLS], int size) {
    cout << fixed << setprecision(2);                   // Format to 2 decimal places
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            cout << setw(8) << scores[i][j] << " ";
        }
        cout << endl;
    }
}

// Sums every single element in the 2D array
double getTotal(double scores[][NUM_COLS], int size) {
    double total = 0.0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            total += scores[i][j];
        }
    }
    return total;
}

// Calculates the average of all array values
double getAverage(double scores[][NUM_COLS], int size) {
    double total = getTotal(scores, size);
    return total / (size * NUM_COLS);
}

// Sums values in a specific vertical column
double getColumnTotal(double scores[][NUM_COLS], int rowSize, int colNum) {
    double total = 0.0;
    for (int i = 0; i < rowSize; i++) {
        total += scores[i][colNum];
    }

    return total;
}

// Sums values in a specific horizontal row
double getRowTotal(double scores[][NUM_COLS], int rowNum) {
    double total = 0.0;
    for (int j = 0; j < NUM_COLS; j++) {
        total += scores[rowNum][j];
    }
    return total;
}

// Scans a specific row to find the maximum value
double getHighestInRow(double scores[][NUM_COLS], int rowIndex) {
    double highest = scores[rowIndex][0];
    for (int j = 1; j < NUM_COLS; j++) {
        if (scores[rowIndex][j] > highest) {
            highest = scores[rowIndex][j];
        }
    }
    return highest;
}

// Scans a specific row to find the minimum value
double getLowestInRow(double scores[][NUM_COLS], int rowIndex) {
    double lowest = scores[rowIndex][0];
    for (int j = 1; j < NUM_COLS; j++) {
        if (scores[rowIndex][j] < lowest) {
            lowest = scores[rowIndex][j];
        }
    }
    return lowest;
}

// Helper: Generates a random integer within a range [a, b] for the testing cols and rows.
int rand_int(int a, int b) {
    return a + rand() % ((b - a) + 1);
}

// Generates a random floating-point number between a and b
double rand_float(double a, double b) {
    // static_cast to double ensures the program does floating-point division
    double randomFraction = static_cast<double>(rand()) / RAND_MAX;
    return a + randomFraction * (b - a);
}

