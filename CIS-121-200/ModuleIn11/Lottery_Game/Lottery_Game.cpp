/*******************************************************************
                          CIS121 Spring 2026
Type of Assignment: Lab 11
Problem Number: 2
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 4/6/2025

Purpose: This program simulates a 5-digit lottery game. It generates five 
random digits (0-9) and compares them against five user-input digits. 
The program tracks exact matches at corresponding indices and announces 
if the user has won the grand prize by matching all five digits.
********************************************************************/

#include <iostream>
#include <ctime>

using namespace std;

//Prototype Functions
void generateLottery(int array[], int size);
void getUserPicks(int user_array[], int size);
int countMatches(const int array[], const int user_array[], int size);
void displayArrays(const int array[], const int user_array[], int size);

int main()
{
    const int ARRAY_SIZE = 5;
    int lottery[ARRAY_SIZE];    //Holds the winning numbers
    int user[ARRAY_SIZE];       //Holds the user's guesses
    int totalMatches;

    //Seed the random number generator with current system time
    srand(static_cast<unsigned int>(time(0)));

    //Generate the winning lottery numbers
    generateLottery(lottery, ARRAY_SIZE);
    //Get the user's 5 digits
    getUserPicks(user, ARRAY_SIZE);
    //Compare the two arrays and calculate total matches
    totalMatches = countMatches(lottery, user, ARRAY_SIZE);

    //Show the results of both arrays to the user
    displayArrays(lottery, user, ARRAY_SIZE);

    //Output the match count and check for a grand prize win
    cout << "\nTotal matching numbers: " << totalMatches << endl;
    if (totalMatches == ARRAY_SIZE) {
        cout << "\nCONGRATULATIONS! You are the grand prize WINNER!" << endl;
    }

    return 0;
}

//Generates random digits between 0 and 9 for each element in the array
void generateLottery(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 10;     // % 10 ensures the result is 0 through 9
    }
}

//Collects 5 digits from the user with basic input validation
void getUserPicks(int user_array[], int size) {
    cout << "Enter 5 numbers between (0-9): ";
    for (int i = 0; i < size; i++) {
        cin >> user_array[i];

        //Validation: Ensure input is within the allowed lottery range
        while (user_array[i] < 0 || user_array[i] > 9) {
            cout << "Invalid input. Please enter a number between 0 - 9: ";
            cin >> user_array[i];
        }
    }
}

//Compares corresponding elements in the two arrays
//Returns the count of indices where the values are identical
int countMatches(const int array[], const int user_array[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        //Only increments if the numbers match at the exact same index
        if (user_array[i] == array[i]) {
            count++;
        }
    }

    return count;
}

//Prints both arrays side-by-side for the user to see the comparison
void displayArrays(const int array[], const int user_array[], int size) {
    cout << "Lottery array: \n";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "\nUser array: \n";
    for (int i = 0; i < size; i++) {
        cout << user_array[i] << " ";
    }
}

