/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 2
Problem Number: 2
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 1/26/2025

Purpose: Write a program that converts a temperature in degrees 
Celsius to the corresponding temperature in degrees Rankine.
The program should prompt the user to enter a temperature in degrees 
Celsius from the keyboard. Using the formulas below, the program 
should calculate and display the converted temperature to the console. 
Handle all temperatures as floating-point numbers (double) to allow
decimal values.
Use the following formulas for conversion:
 Convert Celsius to Fahrenheit:
o tempFahrenheit = tempCelsius * (9.0/ 5.0) + 32
 Convert Fahrenheit to Degrees Rankine (TR):
o tempRank = tempFahrenheit + 459.67
********************************************************************/

#include <iostream>
#include <math.h>

using namespace std;

//Main Program
int main()
{
    //Variables Declared
    double tempCelsius, tempFahrenheit, tempRank;

    //Input Celsius Data
    cout << "Enter a temperature in Degrees C: ";
    cin >> tempCelsius;

    //Calculate conversion from Celsius to Fahrenheit
    tempFahrenheit = tempCelsius * (9.0 / 5.0) + 32;
    //Calculate conversion from Fahrenheit to Rankin
    tempRank = tempFahrenheit + 459.67;

    //Output result
    cout << "\nThat is " << tempRank << " Degrees Rankine.\n";

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
