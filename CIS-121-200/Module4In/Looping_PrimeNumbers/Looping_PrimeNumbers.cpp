/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Extra Assignment
Problem Number: 5
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 2/13/2025

Purpose: This program asks the user for an integer k (greater than 2) 
and calculates/prints all prime numbers in the range from 3 to k.  
********************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int k;          //It holds the upper limit entered by the user
    bool isPrime;   //It tracks if a number is prime.

    //Input Validation Loop: Ensures k is a valid integer greater than 2.
    do {
        cout << "Enter n (to print primes from 3 to n): ";
        //Check if the input is a non-integer (like a letter).
        if (!(cin >> k)) {
            cout << "\nInvalid input. Please enter an integer." << endl;
            cin.clear();                //Clear error flags.
            cin.ignore(1000, '\n');     //Remove bad input from the buffer.
        }

    } while (k <= 2);

    //Outer Loop: Iterates through every number from 3 up to the user's input k.
    for (int n = 3; n <= k; n++) {
        isPrime = true;                 //Assume n is prime until proven otherwise.
        //Inner Loop: Checks for divisors from 2 up to n-1.
        for (int i = 2; i < n; i++) {
            //If n is divisible by i, it is not a prime.
            if (n % i == 0) {
                isPrime = false;
            }
        }
        //Output the results if the isPrime flag remained true.
        if (isPrime) {
            cout << n << " is prime number." << endl;
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
