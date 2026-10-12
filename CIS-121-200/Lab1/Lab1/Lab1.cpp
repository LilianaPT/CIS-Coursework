/*******************************************************************
                          CIS121 Spring 2026
Type of Assignment: Lab 1
Problem Number: 1
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 1/19/2025

Purpose: This program asks the user to enter their favorite movie,
food, hobby, and quote. Then the program should display it neatly.
At the end, the program will ask the size o the pyramid and should
print it.
********************************************************************/

#include <iostream>
#include <string>

using namespace std;

//Main Program
int main()
{
    //Variable Declarations
    string movie, food, hobby, quote; //Variables of the favorite things
    int n, i = 0, j = 0, k = 0; //Variables for the art pyramid

    //Input Identification
    cout << "Enter your favorite movie: ";
    getline(cin, movie);
    cout << "Enter your favorite food: ";
    getline(cin, food);
    cout << "Enter your favorite hobby: ";
    getline(cin, hobby);
    cout << "Enter your favorite quote: ";
    getline(cin, quote);
    cout << "Enter the desire size of the pyramid: "; //Input of the pyramid size
    cin >> n;

    //Output Identification
    cout << "\n--- Your Favorites ---";
    cout << "\nMovie: " << movie;
    cout << "\nFood: " << food;
    cout << "\nHobby: " << hobby;
    cout << "\nQuote: " << quote;
    cout << endl;

    //Function to demonstrate printing the pyramid pattern
    while (i < n) {
        //For spacing printing
        while (k <= n - i - 2) {
            cout << " ";
            k++;
        }
        k = 0;
        //For Pattern printing
        while (j <= 2*i) {
            cout << "*";
            j++;
        }
        j = 0;
        i++;
        cout << endl;
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
