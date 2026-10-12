/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: MidTerm
Problem Number: Quiz 3
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 3/11/2025

Purpose: This program calculates the product of two user-provided 
integers and determines the sign of that product (positive, negative, 
or zero).
********************************************************************/

#include <iostream>

using namespace std;

int calculateProduct(int a, int b, double& result);

int main()
{
    int num1, num2;
    double product_result;
    int signOfProduct;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    signOfProduct = calculateProduct(num1, num2, product_result);

    cout << "\nThe product of " << num1 << " and " << num2 << " is: " << product_result << endl;

    if (signOfProduct == 1) {
        cout << "\nThe product is positive." << endl;
    }
    else if (signOfProduct == -1) {
        cout << "\nThe product is negative." << endl;
    }
    else {
        cout << "\nThe product is zero." << endl;
    }

    return 0;
}

int calculateProduct(int a, int b, double& result) {
    result = static_cast<double>(a * b);

    if (result > 0) {
        return 1;
    }
    else if (result < 0) {
        return -1;
    }
    else {
        return 0;
    }
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
