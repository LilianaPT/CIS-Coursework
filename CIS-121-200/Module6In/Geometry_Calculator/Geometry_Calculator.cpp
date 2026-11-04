/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 7
Problem Number: 2
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 3/2/2025

Purpose: Geometry Calculator with an interactive menu that calculates
the areas of rectangles, triangles, and circles with input validation
and repetition capabilities.
********************************************************************/


#include <iostream>
#include <cstdlib>      //Needed for system("pause") and system ("cls")
#include <iomanip>      //Needed for setprecision
#include <cmath>        //Needed for mathematical calculations

using namespace std;

//Global Constant for PI
const double PI = 3.14159;

//Function Prototypes
void menu();
double areaRectangle(double length, double width);
double areaTriangle(double base, double height);
double areaCircle(double radius);

int main()
{
    //Set output to 2 decimal places for all calculations
    cout << fixed << showpoint << setprecision(1);
    menu();         //Call the menu function to start the program

    return 0;
}
//Function to display menu and handle user choice
void menu() {
    int choice;
    double length = 0, width = 0;
    double base = 0, height = 0;
    double radius = 0;

    do {
        cout << "---:Geometry Calculator:---";
        cout << "\n1. Calculate the Area of a Rectangle.";
        cout << "\n2. Calculate the Area of a Triangle.";
        cout << "\n3. Calculate the Area of a Circle.";
        cout << "\n4. Quit";

        cout << "\nEnter your choice (1 - 4): ";
        cin >> choice;

        cout << endl;
        //Switch statement to execute appropriate function based on input
        switch (choice) {
        case 1: areaRectangle(length, width); break;
        case 2: areaTriangle(base, height); break;
        case 3: areaCircle(radius); break;
        case 4: break;
        default: cout << "Invalid Choice. Please choose an option between (1 - 4)." << endl; break;
        }
        cout << endl;
        system("pause");        //Avoiding a window to close instantly
        system("cls");          //Clear screen for better readability
    } while (choice != 4);      //Loop continues until user chooses to quit
}
//Function to calculate Rectangle Area
double areaRectangle(double length, double width) {
    double recArea = 0.0;
    char repeat = 'Y';

    while (repeat == 'Y' || repeat == 'y') {
        cout << "[Rectangle Calculations]" << endl;
        cout << "Enter Length: ";
        cin >> length;
        cout << "Enter Width: ";
        cin >> width;
        //Input validation where Length and Width must not be negative
        if (length > 0 && width > 0) {
            cout << "Area: " << (recArea = length * width) << endl;
        }
        else {
            cout << "\nError: Length and Width cannot be negative" << endl;
        }
        cout << "\nCalculate another Rectangle? (Y/N): ";
        cin >> repeat;
    }
    return recArea;
}
//Function to calculate Triangle Area
double areaTriangle(double base, double height) {
    double triArea = 0.0;
    char repeat = 'Y';

    while (repeat == 'Y' || repeat == 'y') {
        cout << "[Triangle Calculations]" << endl;
        cout << "Enter Base: ";
        cin >> base;
        cout << "Enter Height: ";
        cin >> height;
        //Input Validation
        if (base > 0 && height > 0) {
            cout << "Area: " << (triArea = base * height * 0.5) << endl;
        }
        else {
            cout << "\nError: Base and Height cannot be negative" << endl;
        }
        cout << "\nCalculate another Triangle? (Y/N): ";
        cin >> repeat;
    }
    return triArea;
}
//Function to calculate Circle Area
double areaCircle(double radius) {
    double cirArea = 0.0;
    char repeat = 'Y';

    while (repeat == 'Y' || repeat == 'y') {
        cout << "[Circle Calculations]" << endl;
        cout << "Enter radius: ";
        cin >> radius;
        //Input Validation
        if (radius > 0) {
            cout << "Area: " << (cirArea = PI * pow(radius, 2.0)) << endl;
        }
        else {
            cout << "\nError: Radius cannot be negative" << endl;
        }
        cout << "\nCalculate another Circle? (Y/N): ";
        cin >> repeat;
    }
    return cirArea;
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
