// PizzaParty.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

void calcBill(double subtotal, double tipPct, double& tax,
    double& tip, double& total);
void splitBill(double total, int people, double& share);

const double TAX_RATE = 0.08;

int main()
{
    cout << fixed << showpoint << setprecision(2);
    double subtotal, tipPct, tax, tip, total, share;
    int people;

    cout << "Enter pizza subtotal: ";
    cin >> subtotal;
    cout << "Enter tip percentage (e.g. 0.020): ";
    cin >> tipPct;
    cout << "Enter number of people: ";
    cin >> people;

    calcBill(subtotal, tipPct, tax, tip, total);
    splitBill(total, people, share);

    cout << "---- Pizza Party Summary ----" << endl;
    cout << "Subtotal: \t $" << subtotal << endl;
    cout << "Tax (8%): \t $" << tax << endl;
    cout << "Tip (20%): \t $" << tip << endl;
    cout << "Total Bill: \t $" << total << endl;
    cout << "Each Person: \t $" << share << endl;

    if (share > 15.0) {
        cout << "\nWow, that's an expensive pizza night!" << endl;
    }

    return 0;
}

void calcBill(double subtotal, double tipPct, double& tax,
    double& tip, double& total) {
    tax = subtotal * TAX_RATE;
    tip = subtotal * tipPct;
    total = subtotal + tax + tip;
}

void splitBill(double total, int people, double& share) {
    share = total / static_cast<double>(people);
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
