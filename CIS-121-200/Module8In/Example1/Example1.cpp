// Example1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//void tripleValue(int& n);
//void calcTax(double price, double& tax);
void swap(int& a, int& b);

int main()
{
   /* double unitPrice = 2.5;
    double taxValue;
    calcTax(unitPrice, taxValue);
    cout << "The tax is " << taxValue << endl;*/

    int x = 5, y = 10;
    swap(x, y);
    cout << "After swaping, x = " << 
        x << "\t y = " << y << endl;
    /*int x = 4;
    cout << &x << endl;
    tripleValue(x);
    cout << x << endl;*/
    return 0;
}

//void tripleValue(int& n)   // <-- look carefully
//{
//    n = n * 3;
//}

//const double TAX = 0.07;     // global
//
//void calcTax(double price, double& tax)
//{
//    tax = price * TAX;
//}
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;

}
// Called as: swap(x, y);
// After call: x and y are unchanged in main





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
