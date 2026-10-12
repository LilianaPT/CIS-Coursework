/*******************************************************************
                          CIS121 Spring 2026
Type of Assignment: Practice 2 In
Problem Number: 1
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 1/20/2025

Purpose: Write a program that computes kinetic energy using the formula:
KE = (1 / 2) × m × v²
Requirements:
 Use constants where appropriate
 Use double for calculations
 Clearly label all output
Explain why writing (1 / 2) directly causes a problem and how to fix it.
********************************************************************/

#include <iostream>

using namespace std;

int main()
{
    //Variable declaration
    double mass;        //It holds the mass
    double velocity;    //It holds the velocity
    double kineticEnergy;   //

    //Ask the user to enter the mass and velocity
    cout << "Enter the mass: ";
    cin >> mass;
    cout << "Enter the velocity: ";
    cin >> velocity;

    //Compute the Kinetic Energy
    kineticEnergy = (1 / 2.0) * mass * velocity * velocity;

    //Display the result
    cout << "\nKinetic Energy = " << kineticEnergy << " J" << endl;

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
