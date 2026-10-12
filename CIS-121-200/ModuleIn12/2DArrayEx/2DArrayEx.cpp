#include <iostream>

using namespace std;

const int COLS = 3;
void display2DArray(int num[][COLS], int rows);
int calculateDiagonalSum(int num[][COLS], int rows);

int main()
{
    int num[3][COLS] = { {1,2,3},{4,5,6},{7,8,9} };

    display2DArray(num, 3);
    int diagSum = calculateDiagonalSum(num, 3);
    

    cout << "\nMain Diagonal sum: " << diagSum << endl;

    return 0;
}

void display2DArray(int num[][COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        cout << endl;
        for (int j = 0; j < COLS; j++) {
            cout << num[i][j] << " ";
        }
    }
}

int calculateDiagonalSum(int num[][COLS], int rows) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
       sum += num[i][i];
    }
    return sum;
}

