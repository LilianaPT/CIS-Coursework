#include <iostream>
#include <iomanip>
#include "DivSales.h"

using namespace std;

int main()
{
    const int NUM_DIVISIONS = 6;
    DivSales divisions[NUM_DIVISIONS];      //Array of six DivSales objects

    //Loop to gather inout for each division
    for (int i = 0; i < NUM_DIVISIONS; i++) {
        double q1, q2, q3, q4;
        cout << "Enter sales for all quarters of division " << (i + 1) << endl;

        cout << "Quarter 1: ";
        cin >> q1;
        while (q1 < 0) {
            cout << "Please enter a non-negative number: ";
            cin >> q1;
        }

        cout << "Quarter 2: ";
        cin >> q2;
        while (q2 < 0) {
            cout << "Please enter a non-negative number: ";
            cin >> q2;
        }

        cout << "Quarter 3: ";
        cin >> q3;
        while (q3 < 0) {
            cout << "Please enter a non-negative number: ";
            cin >> q3;
        }

        cout << "Quarter 4: ";
        cin >> q4;
        while (q4 < 0) {
            cout << "Please enter a non-negative number: ";
            cin >> q4;
        }

        divisions[i].addSales(q1, q2, q3, q4);
        cout << endl;
    }

    //Display formatted output table matching sample output
    cout << fixed << setprecision(2);
    cout << "Sales in each division per quarter:" << endl;

    for (int i = 0; i < NUM_DIVISIONS; i++) {
        cout << "Div " << setw(8) << (i + 1);
        for (int q = 0; q < 4; q++) {
            cout << setw(12) << divisions[i].getQuarterSales(q);
        }
        cout << endl;
    }

    //Display total corporate sales using static getter
    cout << "Total corporate sales for the year: $" << DivSales::getTotalCorporateSales() << endl;

    return 0;
}
