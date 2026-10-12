/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 4
Problem Number: 1
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 2/09/2025

Purpose: The program is designed to evaluate properties of individual
numbers, calculate relationships between pairs, and perform aggregate 
operations on a set of three values. 

********************************************************************/

#include <iostream>

using namespace std;

//Main program
int main()
{
    //Variable declaration
    int num1, num2, num3,       //It holds the three numbers.
        largest, aux, i=0;      //It holds the largest number from the array.
    double remainder, average;           //Holds the remainder from the division in step 2 and the average from step 3.
    bool order = false;

    //Ask user to enter three numbers
    cout << "Enter the three numbers: ";
    cin >> num1 >> num2 >> num3;

    //Step 1:
    //Even or odd number
    if (num1 % 2 == 0) {
        cout << "\n" << num1 << " is an even number.";
    }
    else {
        cout << "\n" << num1 << " is an odd number.";
    }
    //Positive, negative or zero
    if (num1 > 0) {
        cout << "\n" << num1 << " is positive.";
    }
    else if (num1 < 0) {
        cout << "\n" << num1 << " is negative.";
    }
    else {
        cout << "\n" << num1 << " is zero.";
    }
    //Divisible by 3 AND 4.
    if (num1 % 3 == 0 && num1 % 4 == 0) {
        cout << "\n" << num1 << " is divisible by 3 and 4.";
    }
    else {
        cout << "\n" << num1 << " is NOT divisible by 3 and 4.";
    }
    //Divisible by 3 OR 4.
    if (num1 % 3 == 0 || num1 % 4 == 0) {
        cout << "\n" << num1 << " is divisible by 3 or 4.";
    }
    else {
        cout << "\n" << num1 << " is NOT divisible by 3 or 4.";
    }
    cout << endl;

    //Step 2:
    //We check if the second number is not equal to zero
    if (num2 != 0) {
        //Determine whether the first number is divisible by the second
        if (num1 % num2 == 0) {
            cout << "\n" << num1 << " is divisible by " << num2;
        }
        else {
            cout << "\n" << num1 << " is NOT divisible by " << num2;
            remainder = (num1 % num2);
            cout << "\nThe remainder of " << num1 << " divided by " << num2 << " is " << remainder;
        }
    }
    else {
        cout << "\nZero FOUND, division can't be completed.";
    }
    cout << endl;

    //Step3: 
    //Calculate the average of the 3 numbers.
    average = static_cast<double>(num1 + num2 + num3)/3.0;
    cout << "\nThe average of the three numbers is: " << average;
    cout << endl;
    
    int num[3]{ num1,num2,num3 }; //Array declared that it holds the three numbers.
    largest = num[0];         
    //Output the largest number among the three other numbers.
    //We iterate through the array to find the largest number
    cout << endl;
    for (int i = 0; i < 3; i++) {
        if (num[i] > largest) {
            largest = num[i];
        }
    }
   
    //Display the three numbers from smallest to largest.
    cout << "\nThe largest number is: " << largest << endl;

    while (order == false && i < 2) {
        order = true;
        for (int j = 0; j < 2; j++) {
            if (num[j] > num[j + 1]) {
                aux = num[j];
                num[j] = num[j + 1];
                num[j + 1] = aux;
                order = false;
            }
        }
        i++;
    }

    cout << "\nNumbers from smallest to largest: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << num[i] << " ";
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
