/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 8
Problem Number: 1
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 3/9/2025

Purpose: The purpose of this program is to solve the roots for
quadratic equation.
If the real roots do not exist, display a message and if recognize that
is a linear equation it also print another message. Otherwise display
the two roots.
********************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

//Function Prototype declaration
int quadratic(double a, double b, double c, double& r1, double& r2);
void getInput(double& a, double& b, double& c);

int main()
{
    //Variable declaration
    double a, b, c, r1, r2;     //Holds the three coefficients and the two real roots.
    char choice;                //Holds the selection for continue running the program

    //Output identification
    cout << "Lab 8 Programming Exercise 1 by Liliana Pantoja\n";
    cout << "Quadratic Equation Formula\n" << endl;

    //Loop for continue running the program
    do {
      
        getInput(a, b, c);

        //Check if the quadratic equation received all values
        if (quadratic(a, b, c, r1, r2)) {
            //Check if the quadratic equation is linear or not, if not
            //will print the two real roots.
            if (a == 0) {
                cout << "This is a linear equation, not quadratic." << endl;
            }
            else {
                cout << "\nThe two roots are " << r1 << " and " << r2 << endl;
            }
        }
        //Print the complex root message when the quadratic equation
        //do not have the 2 real roots.
        else {
            cout << "\nThe equation has complex roots." << endl;
        }
        //Ask the user if wants to do another calculation
        cout << "\nWould you like to do it again (Y or N): ";
        cin >> choice;
        cout << endl;

    } while (choice == 'Y' || choice == 'y');  

    return 0;
}
// Reads three values and returns them via reference
void getInput(double& a, double& b, double& c) {
    cout << "Please enter value for a: ";
    cin >> a;
    cout << "Please enter value for b: ";
    cin >> b;
    cout << "Please enter value for c: ";
    cin >> c;
}
//Computes roots. Return 1 if real, 0 if complex.
int quadratic(double a, double b, double c, double& r1, double& r2) {
    double discriminant = (b * b) - (4 * a * c);
    //Handle the case where a is 0 (Linear, not Quadratic)
    if (a == 0) {
        if (b != 0) {
            r1 = r2 = -c / b;   //Solve as linear equation
            return 1;
        }
        else {
            return 0;           //No solution if both a and b are zero
        }
    }
    //Solve the 2 real root cases.
    if (discriminant >= 0) {
        r1 = (-b + sqrt(discriminant)) / (2 * a);
        r2 = (-b - sqrt(discriminant)) / (2 * a);
        return 1;
    }
    else {
        return 0;
    }
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
