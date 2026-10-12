/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 15
Problem Number: 2
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 5/12/2026

Purpose: This program implements a QuadraticEquation class to calculate 
the roots of a quadratic equation (ax^2 + bx + c = 0). It handles positive, 
zero, and negative discriminants as per the problem requirements.
********************************************************************/

#include <iostream>
#include <math.h>

using namespace std;

class QuadraticEquation {
private:
    // Data fields for coefficients
    double a, b, c;

public:
    // Default Constructor
    QuadraticEquation() {
        a = b = c = 0;
    }

    // Constructor with arguments for a, b, and c
    QuadraticEquation(double newA, double newB, double newC) {
        a = newA;
        b = newB;
        c = newC;
    }

    // Accessor (get) functions
    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }
    
    // Mutator (set) functions
    void setA(double newA) { a = newA; }
    void setB(double newB) { b = newB; }
    void setC(double newC) { c = newC; }

    // Function to calculate the discriminant : b^2 - 4ac
    double getDiscriminant() const {
        return pow(b, 2) - (4 * a * c);
    }

    // Returns the first root: (-b + sqrt(b^2 - 4ac)) / 2a
    double getRoot1() const {
        double disc = getDiscriminant();
        if (disc < 0) return 0;             // Requirement: return 0 if negative
        return(-b + sqrt(disc)) / (2 * a);
    }

    // Returns the second root: (-b - sqrt(b^2 - 4ac)) / 2a
    double getRoot2() const {
        double disc = getDiscriminant();
        if (disc < 0) return 0;
        return(-b - sqrt(disc)) / (2 * a);
    }
};

int main()
{
    double a, b, c;
    
    cout << "Week 6  Programming  Exercise: Quadratic Equation" << endl;
    cout << "\nPlease enter value for a, b and c:";
    cin >> a >> b >> c;

    // Create the object with user values
    QuadraticEquation eq(a, b, c);

    cout << "The coefficients for a, b, and c are: "
        << eq.getA() << " " << eq.getB() << " " << eq.getC() << endl;

    double discriminant = eq.getDiscriminant();

    if (discriminant > 0) {
        cout << "The two roots are: " << eq.getRoot1() << " and " << eq.getRoot2() << endl;
    }
    else if (discriminant == 0) {
        cout << "The one root is: " << eq.getRoot1() << endl;
    }
    else {
        cout << "The equation has no roots" << endl;
    }
    return 0;
}