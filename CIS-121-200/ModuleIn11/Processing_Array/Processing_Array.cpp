/*******************************************************************
                          CIS121 Spring 2026
Type of Assignment: Lab 11
Problem Number: 1
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 4/6/2025

Purpose: This program demonstrates common array processing techniques 
in C++. It allows a user to initialize an array manually or randomly, 
then performs operations including copying, summing, finding the 
maximum/minimum values, and locating the first occurrence of the 
largest element using modular functions.
********************************************************************/

#include <iostream>
#include <ctime>    // Needed for time() to seed srand

using namespace std;

//Prototype Function
void initializeManual(int list[], int size);
void initializeRandom(int list[], int size);
void copyArray(const int list[], int copy[], int size);
void displayResults(int list[], int copy[], int size, int total, int max, int min, int index);
int sumArray(int list[], int size);
void findMaxMin(int list[], int size, int& max, int& min);
int findSmallestIndexOfLargest(int list[], int size);

int main()
{
    const int ARRAY_SIZE = 10;
    int myList[ARRAY_SIZE];
    int copyingArray[ARRAY_SIZE];
    int option, total, currentMax, currentMin, index;
    
    // Seed the random number generator using the current system time
    srand(static_cast<unsigned int>(time(0)));
    
    do {
        cout << "How do you prefer to initialize your array?\n";
        cout << "1) Adding numbers manually\n";
        cout << "2) Adding numbers randomly\n";
        cout << "0) Exit\n";
        cout << "Selection: ";
        cin >> option;

        switch (option) {
        case 1:
            // Task 1: Fill the array from user input
            initializeManual(myList, ARRAY_SIZE);
            cout << endl;
            // Perform all processing tasks
            copyArray(myList, copyingArray, ARRAY_SIZE);
            total = sumArray(myList, ARRAY_SIZE);
            findMaxMin(myList, ARRAY_SIZE, currentMax, currentMin);
            index = findSmallestIndexOfLargest(myList, ARRAY_SIZE);
            // Output all data
            displayResults(myList, copyingArray, ARRAY_SIZE, total,currentMax, currentMin, index);
            cout << endl;
            break;
        case 2:
            // Task 2: Fill the array with random numbers (1-100)
            initializeRandom(myList, ARRAY_SIZE);
            cout << endl;
            // Perform all processing tasks
            copyArray(myList, copyingArray, ARRAY_SIZE);
            total = sumArray(myList, ARRAY_SIZE);
            findMaxMin(myList, ARRAY_SIZE, currentMax, currentMin);
            index = findSmallestIndexOfLargest(myList, ARRAY_SIZE);
            // Output all data
            displayResults(myList, copyingArray, ARRAY_SIZE, total, currentMax, currentMin, index);
            cout << endl;
            break;
        case 0:
            break;
        default:
            cout << "Please select between 1,2, or 0\n" << endl;
        }
    } while (option != 0);
    
    

    return 0;
}

// 1. Fills the array using cin
void initializeManual(int list[], int size) {
    cout << "Enter 10 numbers: ";
    for (int i = 0; i < size; i++) {
        cin >> list[i];
    }
}

// 2. Fills the array with random numbers between 1 and 100
void initializeRandom(int list[], int size) {
    for (int i = 0; i < size; i++) {
        list[i] = rand() % 100 + 1;
    }
}

// 4. Copies elements from one array to another (Element-by-Element)
void copyArray(const int list[], int copy[], int size) {
    for (int i = 0; i < size; i++) {
        copy[i] = list[i];
    }
}

// 5. Uses an accumulator to calculate the sum of all elements
int sumArray(int list[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += list[i];
    }

    return sum;
}

// 6. Finds both max and min using Pass-by-Reference (&)
void findMaxMin(int list[], int size, int& max, int& min) {
    max = list[0], min = list[0];

    for (int i = 0; i < size; i++) {
        if (list[i] > max) {
            max = list[i];
        }
        if (list[i] < min) {
            min = list[i];
        }
    }
}

// 7. Returns the first (smallest) index where the max value is found
int findSmallestIndexOfLargest(int list[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        // Strict inequality (>) ignores subsequent matches, keeping the first index
        if (list[i] > list[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// 3. Formats and prints all array data and calculated metrics
void displayResults(int list[], int copy[], int size, int total, int max, int min, int index) {
    cout << "Original Array: \n";
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
    cout << "\nCopy of the Original Array: \n";
    for (int i = 0; i < size; i++) {
        cout << copy[i] << " ";
    }
    cout << endl;
    cout << "\n-----------------------------\n";
    cout << "\nThe total sum of the Array is: " << total << endl;
    cout << "Largest Number: " << max << endl;
    cout << "Smallest Number: " << min << endl;
    cout << "Smallest Index of Largest Number: " << index << endl;
}