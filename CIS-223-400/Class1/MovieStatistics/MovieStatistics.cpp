/*Write a program that can be used to gather statistical data about the number of movies college students see in a month.
The program should perform the following steps:
a) Ask the user how many students were surveyed. An array of integers with this many elements should then be dynamically allocated.
b) Allow the user to enter the number of movies each student saw into the array.
c) Calculate and display the average and median of the values entered.
Input validation: Do not accept negative numbers for input.*/

#include <iostream>
#include <iomanip>

using namespace std;

int* allocateArray(int studentsize) {
    int* studentArr = new int[studentsize];

    for (int i = 0; i < studentsize; i++)
        studentArr[i] = i;

    return studentArr;
}

double calculateAverage(int arr[], int studentsize) {
    int sum = 0;
    for (int i = 0; i < studentsize; i++)
        sum += arr[i];

    return static_cast<double>(sum) / studentsize;
}

double calculateMedian(int arr[], int studentsize) {
    //Make a sorted copy so we don't disturb or change the original order
    int* sortedArr = new int[studentsize];
    for (int i = 0; i < studentsize; i++)
        sortedArr[i] = arr[i];

    //Manual bubble sort
    for(int i=0; i<studentsize-1;i++)
        for(int j=0; j< studentsize-1-i;j++)
            if (sortedArr[j] > sortedArr[j + 1]) {
                int temp = sortedArr[j];
                sortedArr[j] = sortedArr[j + 1];
                sortedArr[j + 1] = temp;
            }
    double median;
    if (studentsize % 2 == 0) {
        median = (sortedArr[studentsize / 2 - 1] + sortedArr[studentsize / 2]) / 2.0;
    }
    else {
        median = sortedArr[studentsize / 2];
    }

    delete[] sortedArr;
    return median;
}

int main()
{
    int studentsize;

    cout << "How many students were surveyed? ";
    cin >> studentsize;

    int* Arr = allocateArray(studentsize);

    cout << "\nEnter the number of movies each student saw: ";
    cout << endl;
    for (int i = 0; i < studentsize; i++) {
        int movies;
        do {
            cout << "Student " << (i + 1) << ": ";
            cin >> movies;
            if (movies < 0) {
                cout << "Error: Negative numbers are not allowed. Please try again." << endl;
            }

        } while (movies < 0);
        Arr[i] = movies;
    }

    double average = calculateAverage(Arr, studentsize);
    double median = calculateMedian(Arr, studentsize);

    cout << endl;
    cout << fixed << setprecision(5);
    cout << "The average number of movies seen is " << average << "." << endl;
    cout << defaultfloat;
    cout << "The median of the number of movies seen is " << median << "." << endl;

    delete[] Arr;

    return 0;
}

