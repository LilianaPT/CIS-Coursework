// Example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double i;

    cout <<  sqrt(144.0);
    cout << pow(3.0, 4.0) << endl;
    cout << ceil(7.2) << endl;
    cout << floor(7.9) << endl;
    cout << fabs(-12.5) << endl;
    cout << abs(-12.5) << endl;

    /*while (true) {
        cout << "Enter a positive number: ";
        if (cin >> i && i > 0) {
            cout << "\nThe square root of " << i << " is " << sqrt(i);
            cout << pow(3.0, 4.0) << endl;
            cout << ceil(7.2) << endl;
            cout << floor(7.9) << endl;
            cout << fabs(-12.5) << endl;
            break;
        }
        else {
            cout << "\nInvalid number. ";
        }
    }

    cout << endl;*/

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
