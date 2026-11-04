/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Assn 1
Problem Number: 2
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 2/13/2025

Purpose: This program calculates the optimal packaging for a school 
supply order of pencils (boxes, packs, and singles) and notebooks. 
It validates input and calculates total costs based on user prices.
********************************************************************/

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    char choice = 'Y';

    //Set currency formatting to two decimals
    cout << fixed << setprecision(2);

    
    while (choice == 'Y') {
        int pencils, boxes, packs, single, remaining, notebooks = 0;
        double priceBox, pricePack, priceSingle, priceNotebook, totalCost;
        //Validates and ask the user to input the number of pencils
        cout << "Enter the total number of pencils needed: ";
        while (!(cin >> pencils) || pencils <= 0) {
            cout << "\nInvalid. Enter the total number of pencils needed: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        
        //Ask the user to add prices
        cout << "Enter the cost of a box of 100 pencils: $";
        cin >> priceBox;
        cout << "Enter the cost of a pack of 20 pencils: $";
        cin >> pricePack;
        cout << "Enter the cost of a single pencil: $";
        cin >> priceSingle;
        cout << "Enter the cost of a notebook: $";
        cin >> priceNotebook;

        //Calculates the quantity of boxes, packs and single pencil
        boxes = pencils / 100;
        remaining = pencils % 100;
        packs = remaining / 20;
        single = remaining % 20;
        //Calculates the total cost
        totalCost = (boxes * priceBox) + (packs * pricePack) + 
            (single * priceSingle) + (notebooks * priceNotebook);
        //Output of the quantity of pencils and total cost
        cout << "\nYou will need to purchase ";
        if (boxes > 0) {
            cout << boxes;
            if (boxes == 1) {
                cout << " box, ";
            }
            else {
                cout << " boxes, ";
            }
        }
        if (packs > 0) {
            cout << packs;
            if (packs == 1) {
                cout << " pack, and ";
            }
            else {
                cout << " packs, and ";
            }
        }
        if (single > 0) {
            cout << single << " single ";
        }
        cout << " pencils." << endl;

        cout << "Total cots: $" << totalCost << endl;

        //Validate and ask the user if want to continue with the calculation
        cout << "\nWould you like to calculate again? (Y/N): ";
        cin >> choice;
        while (choice != 'Y' && choice != 'N') {
            cout << "\nInvalid input. Please enter an uppercase Y or N: ";
            cin >> choice;
        }
        cout << endl;
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
