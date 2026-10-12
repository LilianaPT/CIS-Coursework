/*******************************************************************
                          CIS121 Spring 2026
Type of Assignment: Lab 1
Problem Number: 3
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 1/19/2025

Purpose: Write a program that allows the user to enter a time in 
seconds and then outputs how far an object would drop if it is in 
freefall for that length of time. Assume that the object starts at rest,
there is no friction or resistance from air, and then there is a 
constant acceleration of 32 feet per second due to gravity. 
********************************************************************/

#include <iostream>
#include<conio.h>
#include<cmath>

using namespace std;

//Main Program
int main()
{
    //Variable declarations
    double t, distance; //t is equal to time per second
    int a = 32; //a is the accelaration constant that is 32ft per second

    //Input Identification
    cout << "Enter a time in seconds to see how far an object is dropped: ";
    cin >> t;
    
    //Calculate the distance, using the Kinematic Equation where 1/2 is represented by 0.5 mutiplied by a and t^2.
    distance = 0.5 * a * (t * t);

    //Output Identification
    cout << "\nThe object would fall: " << distance << " feet in " << t << " seconds.";
    cout << endl;

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
