// Excersice4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 5;

void readScores(int scores[], int n);
double computeAverage(const int scores[], int n);
void displayScores(const int scores[], int n, double result);

int main()
{
    int scores[MAX];

    readScores(scores, MAX);
    cout << endl;
    double result = computeAverage(scores,MAX);
    displayScores(scores, MAX, result);
}

void readScores(int scores[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter quiz score " << (i + 1) << ": ";
        cin >> scores[i];
    }
    
}

double computeAverage(const int scores[], int n) {
    double average;
    int total = 0;

    for (int i = 0; i < n; i++) {
        total += scores[i];
    }

    return average = static_cast<double>(total) / n;
}

void displayScores(const int scores[], int n, double result) {
    for (int i = 0; i < n; i++) {
        cout << "\nScore " << (i + 1) << ": " << scores[i];
    }
    cout << "\nThe Class average is: " << endl;
    cout << fixed << showpoint << setprecision(2) << result << endl;
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
