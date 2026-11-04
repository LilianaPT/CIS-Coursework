/*******************************************************************
                          CIS121 Spring 2026
Type of Assignment: Lab 5
Problem Number: 2 (Extra Credit)
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 2/21/2025

Purpose: The purpose of this program is to have the user input the
number of terms that would like to use to calculate Pi.
********************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Variables declared
    long long term;
    char repeat;

    do {
        cout << "How many terms would you like to use to calculate Pi: ";
        cin >> term;

        double pi = 0.0;
        double denominator = 1.0;
         
        for (long long i = 0; i < term; i++) {
            //Check if term is even or odd. If even will add. If odd will substract.
            if (i % 2 == 0) {
                pi += 4.0 / denominator;
            }
            else {
                pi -= 4.0 / denominator;
            }
            //Moving to the next odd denominator
            denominator += 2.0;
        }
        //Output of Pi using 10 decimals
        cout << fixed << showpoint << setprecision(10);
        cout << "Pi = " << pi << "." << endl;

        cout << "\nWould you like to calculate again (Y or N): ";
        cin >> repeat;
        cout << endl;

    } while (repeat == 'Y' || repeat == 'y');

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
