// Exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const double G = 9.8;
    double height, distance;
    int    numOfSeconds, count;

    // Prompt for h and T
    cout << "Enter Height value: ";
    cin >> height;
    cout << "Enter max seconds (T): ";
    cin >> numOfSeconds;

    // Table header
    cout << setw(8) << "Time(s)" << setw(16) << "Distance(m)" << endl;

    for (int count = 0; count <= numOfSeconds; count++)
    {
        distance = 0.5 * G * pow(count, 2.0);   // formula
        cout << "\n";
        //Display the result
        cout << setw(5) << fixed << setprecision(2) << count << setw(14) << fixed << setprecision(2) << distance;

        if (distance > height)
        {
            cout << "  <-- Object has hit the water" << endl;
            break;                    // stop the loop
        }
    }


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
