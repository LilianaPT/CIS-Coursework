/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 12
Problem Number: 2
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 4/12/2026

Purpose: Measure and compare the execution time of Linear Search, 
Bubble Sort, and Selection Sort using an array of 100,000 integers.
********************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm> //for the copy function that is used to copy the original array in the temp array

using namespace std;

const int ARRAY_SIZE = 100000;

//Function Prototype
int LinearSearch(int randomArray[], int size, int searchValue);
void BubbleSort(int randomArray[], const int ARRAY_SIZE);
void SelectionSort(int randomArray[], int size);

int main()
{
    int key, result;
    long startTime, endTime;
    //Dynamic allocation for large arrays to avoid stack overflow
    int* originalArray = new int[ARRAY_SIZE];
    int* tempArray = new int[ARRAY_SIZE];
    

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Fill array with random values and pick a random key to find
    for (int i = 0; i < ARRAY_SIZE; i++) {
        originalArray[i] = rand();
    }
    key = originalArray[rand() % ARRAY_SIZE];           // Pick a key known to exist

    cout << "Starting benchmark for " << ARRAY_SIZE << " elements... \n" << endl;

    //Linear Searching
    startTime = time(0);
    result = LinearSearch(originalArray, ARRAY_SIZE, key);
    endTime = time(0);
    cout << "Linear Search Time: " << (endTime - startTime) << " seconds. " << endl;
    cout << "Key found at index: " << result << "\n" << endl;

    //Bubble Sort
    //// Copy the original array so we don't sort an already-sorted array later.
    copy(originalArray, originalArray + ARRAY_SIZE, tempArray);

    cout << "Running Bubble Sort (this may take a moment)..." << endl;
    startTime = time(0);
    BubbleSort(tempArray, ARRAY_SIZE);
    endTime = time(0);
    cout << "Bubble Sort Time: " << (endTime - startTime) << " seconds. \n" << endl;

    //Selection Sort
    copy(originalArray, originalArray + ARRAY_SIZE, tempArray);

    cout << "Running Selection Sort... " << endl;
    startTime = time(0);
    SelectionSort(tempArray, ARRAY_SIZE);
    endTime = time(0);
    cout << "Selection Sort Time: " << (endTime - startTime) << " seconds. \n" << endl;

    //Free allocated memory
    delete[] originalArray;
    delete[] tempArray;
    
    return 0;
}

// Sequential search through the array
int LinearSearch(int randomArray[], int size, int searchValue) {
    for (int i = 0; i < size - 1; i++) {
        if (randomArray[i] == searchValue) {
            return i;
        }
    }
    return -1;
}

// Bubble Sort: Swaps adjacent elements
void BubbleSort(int randomArray[], const int ARRAY_SIZE) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (randomArray[j] > randomArray[j + 1]) {
                // Swap elements
                int temp = randomArray[j];
                randomArray[j] = randomArray[j + 1];
                randomArray[j + 1] = temp;
            }
        }
    }
}

// Selection Sort: Finds the minimum and moves it to the front
void SelectionSort(int randomArray[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (randomArray[j] < randomArray[minIndex]) {
                minIndex = j;
            }
        }
        // Swap minimum element with the first element of unsorted part
        int temp = randomArray[minIndex];
        randomArray[minIndex] = randomArray[i];
        randomArray[i] = temp;
    }
}
