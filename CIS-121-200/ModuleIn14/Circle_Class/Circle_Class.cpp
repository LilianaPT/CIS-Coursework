/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 14
Problem Number: 1
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 5/10/2026

Purpose: Create a circle class where we define different functions like,
default constructor, overloaded, mutator. etc. Then we print the first
circle with a default radius of 0.0 and then we ask for the radius
value of the circle 2, and then we print the information.
********************************************************************/

#include <iostream>
#include <math.h>       //Library for the Area of the circle

using namespace std;

class Circle {
private:
    double radius;
    const double PI = 3.14159;

public:
    Circle();
    Circle(double r);
    void setRadius(double r);
    double getRadius() const;
    double getArea() const;
    double getCircumference() const;
};

int main()
{
    double userRadius;

    //Create a Circle object using the default constructor (radius 0.0)
    Circle circle1;
    cout << "Circle 1 (Default):" << endl;
    cout << "Radius: " << circle1.getRadius() << endl;
    cout << "Area: " << circle1.getArea() << endl;
    cout << "Circumference: " << circle1.getCircumference() << endl;
    cout << "-----------------------------" << endl;

    //Ask user for a radius
    cout << "Enter the radius for a new Circle: ";
    cin >> userRadius;

    //Create a Circle object using the overloaded constructor
    Circle circle2(userRadius);

    //Report the results for the second circle
    cout << "\nCircle 2 (User Defined): " << endl;
    cout << "Radius: " << circle2.getRadius() << endl;
    cout << "Area: " << circle2.getArea() << endl;
    cout << "Circumference: " << circle2.getCircumference() << endl;

    return 0;
}

//Default Constructor
Circle::Circle() {
    radius = 0.0;
}

//Overloaded Constructor
Circle::Circle(double r) {
    radius = r;
}

//Mutator (Setter)
void Circle::setRadius(double r) {
    radius = r;
}

//Accessor (Getter)
double Circle::getRadius() const {
    return radius;
}

//Calculate Area: PI*r^2
double Circle::getArea() const {
    return PI * pow(radius, 2.0);
}

//Calculate Circumference: 2xPIxr
double Circle::getCircumference() const {
    return 2 * PI * radius;
}

