// Example2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int sumThree(int num1, int num2, int num3);
void showPowers(double i);
int factorial(int n);
const int MAX = 12;

int main()
{
    /*int a = 4, b = 7, c = 12;
    double num = 3.0;*/

    int number;
    cout << "Enter an integer (<=12): ";
    cin >> number;

    //Input validation
    while (number > MAX) {
        cout << "Invalid. Enter an integer (<=12): ";
        cin >> number;
    }

    for (int number = 0; number <= MAX; number++) {
        cout << number << "! = " << setw(10) << factorial(number) << endl;
    }

    /*cout << sumThree(a, b, c) << endl;
    showPowers(num);*/

    return 0;
}

int sumThree(int num1, int num2, int num3) {
    return num1 + num2 + num3;
}

void showPowers(double i) {
    cout << "Num: " << i << endl;
    cout << "Square: " << pow(i, 2.0) << endl;
    cout << "Cube: "<< pow(i, 3.0) << endl;
}

int factorial(int n) {
    int result;
    result = 1;
    /*for (int i = 1; i <= n; i++) {
        result *= i;
    }*/

    while (n >= 1) {
        result *= n;
        n--;
    }

    return result;
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
