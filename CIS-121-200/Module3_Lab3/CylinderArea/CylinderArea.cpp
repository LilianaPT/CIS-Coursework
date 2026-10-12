/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 3
Problem Number: 1
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 1/30/2025

Purpose: This program compute the volume V of a cylinder of radius r 
and height h. The program will ask the user for the radius of the 
cylinder, and the height of the cylinder.

********************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.1416; //It holds the constant number of pi that we will use in the below ecuation.

//Main program
int main()
{
    double r, h,                            //It holds the value of radius(r) and the height(h)
        area_Cylinder, volume_Cylinder;     //It holds the value of the area and volume of the cylinder.

    //Ask the user to input the values of the radius and the height.
    cout << "Lab 3 - Exercise #1 by Liliana Pantoja\n\n";
    cout << "Press return after entering a number.\n\n";
    cout << "Enter the radius of the cylinder (meters): \n";
    cin >> r;
    cout << "Enter the height of the cylinder (meters): \n";
    cin >> h;

    //Compute the Area of the Cylinder
    area_Cylinder = 2 * (pi * r * h) + 2 * (pi * pow(r, 2.0));
    //Compute the Volume of the Cylinder
    volume_Cylinder = pi * (pow(r, 2.0) * h);

    //Displaying the two results of the Area and Volume
    cout << "\nThe surface area of a cylinder of radius "
        << r << " and height " << h << " is "
        << area_Cylinder << " square meters" << endl;
    
    cout << "\nThe volume of a cylinder of radius " << r
        << " and height " <<  h << " is " << volume_Cylinder
        << " cubic meters" << endl;

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
