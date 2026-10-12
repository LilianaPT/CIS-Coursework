/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 15
Problem Number: 3
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 5/12/2026

Purpose: This program validates a user's password based on specific
security criteria. It checks for the presence of at least one
uppercase letter, one lowercase letter, and one digit using a class-
based approach.
********************************************************************/

#include <iostream>
#include <string>
#include <cctype>   //Required for isupper, islower, and isdigit

using namespace std;

class PasswordVerifier {
private:
    string password;

public:
    //Constructor
    PasswordVerifier(string p) {
        password = p;
    }

    //Method to check if password meets all criteria
    bool isValid() const {
        return hasUpper() && hasLower() && hasDigit();
    }

    //Helper method: Check for uppercase
    bool hasUpper() const {
        for (char c : password) {
            if (isupper(c)) return true;
        }
        return false;
    }

    //Helper method: Check for lowercase
    bool hasLower() const {
        for (char c : password) {
            if (islower(c)) return true;
        }
        return false;
    }

    //Helper method: Check for digit
    bool hasDigit() const {
        for (char c : password) {
            if (isdigit(c)) return true;
        }
        return false;
    }

    //Method to display specific requirements missing
    void displayRequirements() const {
        cout << "The password must have: " << endl;
        cout << "  at least one upper" << endl;
        cout << "  at least one lower" << endl;
        cout << "  at least one number" << endl;
    }
};

int main()
{
    string input;
    bool valid = false;

    //Loop to match the sample output's multiple attempts.
    while (!valid) {
        cout << "Enter a password: ";
        cin >> input;

        PasswordVerifier pv(input);

        if (pv.isValid()) {
            cout << "The password is valid." << endl;
            valid = true;       //Exit loop
        }
        else {
            pv.displayRequirements();
            cout << "The password is not valid.\n" << endl;
        }
    }
    return 0;
}
