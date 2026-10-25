/*Chapter 16 - Program 1: Arithmetic Exceptions
A function that returns the integer square root of its arguments and
throws an exception if the argument is not a perfect square.*/

#include <iostream>
#include <string>

using namespace std;

//Exception class throw when a number is not a perfect square
class NotPerfectSquare {
private:
    int value;
public:
    NotPerfectSquare(int v) { value = v; }
    int getValue() const { return value; }
};

//Returns the integer square root of num.
//Throws NotPerfectSquare if num is negative or not a perfect square.
int intSqaureRoot(int num) {
    if (num < 0) {
        throw NotPerfectSquare(num);
    }

    int root = 0;
    //Find the largest root where root * root <= num
    while ((long long)(root + 1) * (root + 1) <= num)
        root++;

    if (root * root != num) {
        throw NotPerfectSquare(num);
    }
    return root;
}

int main()
{
    //Demonstrate with a list of test values
    int tests[] = { 0, 1, 16, 25, 20, 144, 50, -9, 10000 };
    const int SIZE = sizeof(tests) / sizeof(tests[0]);

    cout << "Testing intSquareRoot with sample values: \n";
    for (int i = 0; i < SIZE; i++) {
        try {
            int root = intSqaureRoot(tests[i]);
            cout << "The square root of " << tests[i] << " is " << root << endl;
        }
        catch (NotPerfectSquare &e) {
            cout << "\nError: " << e.getValue() << " is not a perfect square.\n";
        }
    }

    //Let the user try their own values
    char again;
    do {
        int num;
        cout << "\nEnter an integer: ";
        cin >> num;

        try {
            int root = intSqaureRoot(num);
            cout << "The square root of " << num << " is " << root << endl;
        }
        catch (NotPerfectSquare& e) {
            cout << "\nError: " << e.getValue() << " is not a perfect square.\n";
        }

        cout << "Try another member? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    return 0;
}
