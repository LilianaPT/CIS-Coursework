#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include "KossCoMembership.h"

using namespace std;

//Function prototypes
KossCoMembership signUpMember();
int getMenuChoice();
double getAmount(string prompt);
void clearInput();

int main()
{
    vector<KossCoMembership> allMembers;        //record of every member (uses copy constructor)
    bool done = false;

    while (!done) {
        //Create a new member object from the user's answers
        KossCoMembership member = signUpMember();

        bool sameMember = true;
        while (sameMember) {
            int choice = getMenuChoice();

            if (choice == 1) {                  //Purchase
                double amount = getAmount("What is the purchase amount? $");
                member.purchase(amount);
                cout << "Your new point balance is " << member.getPoints() << endl;
            }
            else if (choice == 2) {             //Return
                double amount = getAmount("What is the return amount? $");
                member.returnItem(amount);
                cout << "Your new point balance is " << member.getPoints() << endl;
            }
            else if (choice == 3) {             //Redeem
                double dollars = member.redeem();
                cout << fixed << setprecision(2);
                cout << "Your redeem amount is $" << dollars << endl;
                cout.unsetf(ios::fixed);
                cout << setprecision(6);
                cout << "Your new point balance is " << member.getPoints() << endl;
            }
            else if (choice == 4) {                 //Different new member
                allMembers.push_back(member);       //copy constructor saves the record
                sameMember = false;
            }
            else {                              //Quit
                allMembers.push_back(member);
                sameMember = false;
                done = true;
            }
        }
    }

    //Summary of all members
    cout << "\n------------- KossCo Member Summary -------------\n";
    cout << left << setw(15) << "Name" << setw(6) << "Age"
        << setw(12) << "Type" << setw(8) << "Fee" << "Points\n";

    for (int i = 0; i < (int)allMembers.size(); i++) {
        cout << left << setw(15) << allMembers[i].getName()
            << setw(6) << allMembers[i].getAge()
            << setw(12) << allMembers[i].getMembershipType() << "$"
            << setw(7) << allMembers[i].getFee()
            << allMembers[i].getPoints() << endl;
    }

    cout << "\nTotal members: " << KossCoMembership::getMemberCount() << endl;
    cout << "Bye!" << endl;

    return 0;
}

//Ask for name, age and membership type, validates them, and builds the object
KossCoMembership signUpMember() {
    string name, type;
    int age;

    cout << "\nWELCOME TO KOSSCO!\n\n";
    cout << "Goldstar $" << KossCoMembership::GOLDSTAR_FEE << endl;
    cout << "Executive $" << KossCoMembership::EXECUTIVE_FEE << endl << endl;

    cout << "Please enter your name ";
    getline(cin, name);

    while (name.empty()) {
        cout << "Name cannot be empty. Please enter your name ";
        getline(cin, name);
    }

    //Age validation: must ne a number and 21 or older
    cout << "Please enter your age ";
    while (!(cin >> age) || age < KossCoMembership::MIN_AGE || age > 120) {
        if (cin.fail()) {
            cout << "Invalid input. Please enter your age as a number ";
        }
        else if (age < KossCoMembership::MIN_AGE) {
            cout << "Sorry, you must be 21 or older to get a membership.\n"
                << "Please enter a valid age ";
        }
        else {
            cout << "Please enter a realistic age ";
        }
        clearInput();
    }
    clearInput();

    //Membership type validation
    cout << "Please enter the type of membership you want ";
    getline(cin, type);
    while (!KossCoMembership::isValidType(type)) {
        cout << "Invalid type. Please enter Goldstar or Executive ";
        getline(cin, type);
    }

    //Create the object with the constructor that takes arguments
    KossCoMembership newMember(name, age, type);

    if (newMember.getMembershipType() == "Executive") {
        cout << "\nCongrats! Your are NOW an Executive member of KossCo!\n";
    }
    else {
        cout << "\nCongrats! Your are NOW a Goldstar member of KossCo!\n";
    }
    cout << "Your Points balance is " << newMember.getPoints() << endl;

    return newMember;
}

//Shows the menu and returns a valid choice 1-5
int getMenuChoice() {
    int choice;

    cout << "\n1. Purchase";
    cout << "\n2. Return";
    cout << "\n3. Redeem";
    cout << "\n4. Different New Member";
    cout << "\n5. Quit\n";
    cout << "Please enter your choice: ";
    while (!(cin >> choice) || choice < 1 || choice > 5) {
        cout << "Invalid choice. Please enter a number from 1 to 5";
        clearInput();
    }
    clearInput();
    return choice;
}

//Get a positive dollar amount
double getAmount(string prompt) {
    double amount;
    cout << prompt;
    while (!(cin >> amount) || amount <= 0) {
        cout << "Please enter an amount greater than 0. $";
        clearInput();
    }
    clearInput();
    return amount;
}

//Clears error flags and leftover characters from cin
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}