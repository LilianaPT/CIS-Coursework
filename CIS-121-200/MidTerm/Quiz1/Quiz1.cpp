/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: MidTerm
Problem Number: Quiz 1
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 3/11/2025

Purpose: This program calculates the sum of a specific mathematical 
series (1/3 + 3/5 + 5/7 + ... +. It allows the user to specify the 
number of terms (n) to sum and ensures accurate floating-point 
results using double precision.
********************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

double calculatesSeriesSum(int num);

int main()
{
    int n;
    double totalSum;

    cout << fixed << showpoint << setprecision(4);


    cout << "Enter the number of terms to calculate: ";
    cin >> n;

    while (n < 0) {
        cout << "\nInvalid Input. Please enter a positive term: " << endl;
        cin >> n;
    }

    totalSum = calculatesSeriesSum(n);

    cout << "The sum of the first " << n << " items is: " << totalSum << endl;

    return 0;
}

double calculatesSeriesSum(int num) {
    double sum = 0.0;
    double numerator, denominator;
    // Loop through the requested number of terms
    for (int i = 0; i < num; i++) {
        // Generate the odd numbers for numerator and denominator
        numerator = 2 * i + 1;
        denominator = 2 * i + 3;
        sum += numerator / denominator;
    }
    return sum;
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
