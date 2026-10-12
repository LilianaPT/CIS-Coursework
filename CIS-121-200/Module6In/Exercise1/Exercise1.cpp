// Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{

    /*int a = 3, b = 7;

    cout << a++ << endl;
    cout << ++a << endl;
    cout << b-- << endl;
    cout << --b << endl;
    cout << a + b << endl;*/

    /*int sum;
    sum = 0;

    for (int i = 9; i <= 90; i+=3) {
        cout << i << endl;
        sum += i;
    }*/

    float rain, total = 0.0;
    int   month = 1;

    cout << "Rainfall for month 1 (or -1 to stop): ";
    cin >> rain;                       // priming read

    //input validation
   /* while (rain < 0) {
        cout << "Invalid. Rainfall for month 1 (or -1 to stop): ";
        cin >> rain;
    }*/

    while (rain != -1)    // sentinel condition
    {
        total += rain;     // accumulate
        month++;     // count months
        cout << "Rainfall for month " << month << " (or -1 to stop): ";
        cin >> rain;
    }

    if (month > 1)
        cout << "Total: " << total << " in.   Avg: "
        << total/(month-1) << " in." << endl;
    else
        cout << "No data entered." << endl;


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
