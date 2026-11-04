/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Assn 1
Problem Number: 1
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 2/13/2025

Purpose: This program simulates a coffee shop order system, allowing
users to select coffee types, apply a membership discount, calculate
total costs including tax, and display a formatted receipt in a loop
until the user exits.
********************************************************************/

#include <iostream>
#include <cstdlib>  //Required for clear the screen and wait for user to press enter key to continue with the program
#include <iomanip> //Required for fixed and setprecision

using namespace std;

//Global Constants
const double espressoP = 2.50, latteP = 3.75, 
cappuP = 3.25,mochaP = 4.00;
const double membership = 0.05;

//Function Prototypes
int getValidCups();
bool getValidMembership();
void printReceipt(double pricePerCup, int cupsPurchased, double subTotal, double discount, double tax, double finalTotal);
void calculations(double pricePerCup, double &subTotal, double &discount, double &tax, double &finalTotal, bool isMember, int cups);

int main()
{
    //Variable Declarations
    int choice, cups;
    bool isMember;
    double subTotal, discount, tax, finalTotal;

    //This set formatting for all currency display in main
    cout << fixed << setprecision(2);

    //Main program loop: Repeat until user selects '0' to exit
    do {
        //Display Menu
        cout << "Welcome to the Coffee Shop Order\n" << endl;
        cout << "\t.:MENU:." << endl;
        cout << "1. Espresso - $" << espressoP << endl;
        cout << "2. Latte - $" << latteP << endl;
        cout << "3. Cappuccino - $" << cappuP << endl;
        cout << "4. Mocha - $" << mochaP << endl;
        cout << "0. Exit" << endl;
        cout << "\nSelect coffee type (1 - 4) or 0 to quit: ";
        cin >> choice;

        //Process User choice
        switch (choice) {
        case 1:                              //Espresso calculation
            cups = getValidCups();
            cout << endl;
            isMember = getValidMembership();
            cout << endl;
            calculations(espressoP, subTotal, discount, tax, finalTotal, isMember, cups);
            printReceipt(espressoP, cups, subTotal, discount, tax, finalTotal);
            break;
        case 2:                                 //Latte calculation
            cups = getValidCups();
            cout << endl;
            isMember = getValidMembership();
            cout << endl;
            calculations(latteP, subTotal, discount, tax, finalTotal, isMember, cups);
            printReceipt(latteP, cups, subTotal, discount, tax, finalTotal);
            break;
        case 3:                                 //Cappuccino calculation
            cups = getValidCups();
            cout << endl;
            isMember = getValidMembership();
            cout << endl;
            calculations(cappuP, subTotal, discount, tax, finalTotal, isMember, cups);
            printReceipt(cappuP, cups, subTotal, discount, tax, finalTotal);
            break;
        case 4:                                 //Mocha calculation
            cups = getValidCups();
            cout << endl;
            isMember = getValidMembership();
            cout << endl;
            calculations(mochaP, subTotal, discount, tax, finalTotal, isMember, cups);
            printReceipt(mochaP, cups, subTotal, discount, tax, finalTotal);
            break;
        case 0:         //Exit the loop
            break;
        default: cout << "\nInvalid. Please enter a correct choice from (0-4)." << endl;
        }
        //Pause and clear screen for the next iteration of the loop
        system("pause");
        system("cls");
    } while (choice != 0);



    return 0;
}

//Function Definitions

/* This function ask the user for number of cups and it also 
validates the input, and will return a positive integer for the number of cups*/
int getValidCups() {
    int numCup;
    while (true) {                                //Loop  until valid input is received
        cout << "Enter number of Cups: ";
        if (cin >> numCup && numCup > 0) {
            return numCup;
        }
        //Handle invalid input (non-number or <= 0)
        cout << "\nInvalid. Please enter a valid positive number of Cups." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

/*This function ask the user for membership status and validates the input.
Will be returning a true if 'Y' is entered or false if 'N' is entered.*/
bool getValidMembership() {
    char input;
    while (true) {
        cout << "Do you have a membership card? (Y/N): ";
        cin >> input;
        if (input == 'Y') {
            return true;
        }
        if (input == 'N') {
            return false;
        }
        //Handle invalid input (anything other than uppercase Y or N).
        cout << "\nERROR. The option must be uppercase." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void calculations(double pricePerCup, double &subTotal, double &discount, double &tax, double &finalTotal, bool isMember, int cups) {
    subTotal = pricePerCup * cups;    //Calculate sub total
    //Apply 5% discount if member
    if (isMember == true) {
        discount = subTotal * membership;
    }
    else {
        discount = 0.0;
    }
    //Calculate tax and final total
    tax = static_cast<int>((subTotal - discount) * 0.06 * 100.0) / 100.0;
    finalTotal = (subTotal - discount) + tax;
}

/*This function will displays the receipt using calculated values, using
all necessary order details like price, quantity, subtotal, tax and final total.*/
void printReceipt(double pricePerCup, int cupsPurchased, double subTotal, double discount, double tax, double finalTotal) {
    cout << "\n----Receipt----" << endl;
    cout << "\nCoffee price per cup: $" << pricePerCup;
    cout << "\nCups purchased: " << cupsPurchased << endl;
    cout << "SubTotal: $" << subTotal << endl;
    cout << "Membership Discount: -$" << discount << endl;
    cout << "Tax (6%): $" << tax << endl;
    cout << fixed << showpoint << setprecision(2) << "Total: $" << finalTotal << endl;
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
