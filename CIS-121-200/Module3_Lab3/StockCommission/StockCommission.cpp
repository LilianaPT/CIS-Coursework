/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 3
Problem Number: 2
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 1/30/2025

Purpose: Susan bought 750 shares of stock at a price of $35.00 per 
share. She must pay her stockbroker a 2 percent commission for the 
transaction. Write a program that calculates and displays the following:

  •   The amount paid for the stock alone (without the commission)  
  •   The amount of the commission 
  •   The total amount paid (for the stock plus the commission)

********************************************************************/
//Libraries used
#include <iostream>
#include <iomanip>

using namespace std;

const double price = 35.00; //It holds a constant number for price

//Main Program
int main()
{
    int numberOfShares, commissionRate;             //It holds the values of the amount of shares and the commission rate of 2%
    double stockAlone, commissionAmount, totalPaid; //It holds the number of amount paid, commision amount, and total amount

    //Ask the user to enter the values of shares and commission rate
    cout << "Enter the number of shares: ";
    cin >> numberOfShares;
    cout << "Enter the commission rate (as percentage, e.g, 2): ";
    cin >> commissionRate;

    stockAlone = numberOfShares * price;                        //Calculate the amount paid for the stock alone
    commissionAmount = stockAlone * (commissionRate / 100.00);  //Calculate the amount of the commission
    totalPaid = stockAlone + commissionAmount;                  //Calculate the total amount paid

    //Displaying the final results using the static cast to convert the doubles into int and printing decimals for the constant variable.
    cout << "\nHow many shares did you buy? " << numberOfShares << endl;
    cout << "How much each is each share? " << fixed << showpoint << setprecision(2) << price << endl;
    cout << "Stock: $" << static_cast<int>(stockAlone) << endl;
    cout << "Commission: $" << static_cast<int>(commissionAmount) << endl;
    cout << "Total: $" << static_cast<int>(totalPaid) << endl;


    cout << "\n" << numberOfShares << " shares of stock at a price of $" 
        << fixed << showpoint << setprecision(2) << price << " per share, the total is " << static_cast<int>(totalPaid);
    
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
