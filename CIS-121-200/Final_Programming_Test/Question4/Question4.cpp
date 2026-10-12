/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Final_Test
Problem Number: Question 3
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 5/06/2025

Purpose: The primary purpose of this program is to demonstrate 
Encapsulation using a Class.
********************************************************************/

#include <iostream>

using namespace std;

const int ROW_SIZE = 3;
const int COLUMN_SIZE = 4;

class Location {
public:
    int row;
    int column;
    double maxValue;

    Location(int r, int c, double v) {
        row = r;
        column = c;
        maxValue = v;
    }
};

Location locateLargest(const double a[][COLUMN_SIZE]);

int main()
{
    double matrix[ROW_SIZE][COLUMN_SIZE];
    
    cout << "Enter a 3 by 4 array: " << endl;
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COLUMN_SIZE; j++) {
            cin >> matrix[i][j];
        }
    }

    Location result = locateLargest(matrix);

    cout << "The location of the largest element is " << result.maxValue
        << " at (" << result.row << ", " << result.column << ")" << endl;

    return 0;
}

Location locateLargest(const double a[][COLUMN_SIZE]) {
    int maxRow = 0;
    int maxCol = 0;
    double maxVal = a[0][0];

    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COLUMN_SIZE; j++) {
            if (a[i][j] > maxVal) {
                maxVal = a[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    return Location(maxRow, maxCol, maxVal);
}
