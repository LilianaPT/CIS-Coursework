/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 4
Problem Number: 2
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 2/09/2025

Purpose: The purpose of this program is to calculate a user's average 
monthly water bill based on four quarterly inputs and provide feedback 
on their consumption habits. It classifies usage as excessive ($75), 
typical ($25-$75), or conservation-conscious (\(<\$25\)) to help 
users manage their water consumption. 

********************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

//Main program
int main()
{
    int q1, q2, q3, q4;     //It holds the numbers of each quarter water bill
    double average;         //It holds the average of each quarter

    //Ask user to input their quarter bill.
    cout << "Please input your water bill for quarter 1: \n";
    cin >> q1;
    cout << "Please input your water bill for quarter 2: \n";
    cin >> q2;
    cout << "Please input your water bill for quarter 3: \n";
    cin >> q3;
    cout << "Please input your water bill for quarter 4: \n";
    cin >> q4;

    //Calculates the average and convert the int values into double values.
    average = static_cast<double>(q1 + q2 + q3 + q4) / 12.0;

    //Set 2 decimals for the average.
    cout << fixed << showpoint << setprecision(2);
    //If the  average  bill  exceeds  $75,  the  output should include a message indicating that too  much  water  is  being  used
    if (average > 75.0) {
        cout << "\nYour average monthly bill is $" << average <<
            ". You are using excessive amount of water" << endl;
    }
    //If the average bill is at least $25 but no more than  $75,  the  output should indicate that  a  typical  amount of  water  is  being  used
    else if (average >= 25.0 && average <= 75.0) {
        cout << "\nYour average monthly bill is $" << average <<
            ". You are using a typical amount of water" << endl;
    }
    //If the average bill is less than $25, the output should contain a message praising the user for conserving water
    else {
        cout << "\nYour average monthly bill is $" << average <<
            ". Thank you for conserving water" << endl;
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
