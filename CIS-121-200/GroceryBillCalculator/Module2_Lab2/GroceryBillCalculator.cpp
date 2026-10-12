/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 2
Problem Number: 1
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 1/26/2025

Purpose: Write a program that asks the user to enter the number of 
items they are buying and the price of one item.
The program should calculate and display:
o The total cost of the items.
o The total cost including sales tax (assume 7% sales tax).
Make sure to use double variables for prices and totals to handle 
fractional values correctly
********************************************************************/

//Initial Libraries
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

//Main Program
int main()
{
    //Variables Declared
    int numberOfItems;
    double pricePerItem, totalBeforeTax, salesTaxAmount, totalCost;
    const double salesTax = 0.07; //Constant variables because we assumed that the taxes are 7%

    //Input by the user for number of items
    cout << "How many items did you buy? ";
    cin >> numberOfItems;
    //Input by the user for the price of one item
    cout << "Enter the price of one item: $";
    cin >> pricePerItem;

    totalBeforeTax = numberOfItems * pricePerItem; //Calculate the total price before taxes
    salesTaxAmount = totalBeforeTax * salesTax; //Calculate the sales tax amount that we'll include in our total price
    totalCost = totalBeforeTax + salesTaxAmount; //Calculate the total price after taxes

    //Output of the results
    cout << "\n---- RECEIPT DETAILS ----";
    cout << "\nSubtotal: $" << totalBeforeTax;
    cout << "\nSales Tax: $" << setprecision(3) << salesTaxAmount;
    cout << "\nTotal Cost: $" << setprecision(4) << totalCost;

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
