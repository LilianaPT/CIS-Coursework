// WEEK8-18-26.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int* Reverse(int A[], int s) {
    int* Aptr = nullptr;
    Aptr = new int[s];
    for (int i = 0, j = s - 1; i < s; i++, j--)
        Aptr[j] = A[i];
    return Aptr;
}

int* Reverse2(int* A, int size) {
    int* ntpr = new int[size];
    for (int i = 0, j = size - 1; i < size; i++, j--)
        ntpr[j] = A[i];
    return ntpr;
}

int main()
{
    int myArray[5] = { 30,40,50,60,70 };
    //Display the array
    cout << "\nDisplay the array before reversing" << endl;
    for (int m = 0; m < 5; m++)
        cout << myArray[m] << "    ";

    int* arrayptr = myArray;
    //Call function to reverse
    arrayptr = Reverse(myArray, 5);
    cout << "\nDisplay the array after reversing" << endl;
    for (int m = 0; m < 5; m++)
        cout << arrayptr[m] << "    ";

    //Call Reverse2
    arrayptr = Reverse2(arrayptr, 5);
    cout << "\nReverse 2" << endl;
    for (int m = 0; m < 5; m++)
        cout << arrayptr[m] << "    ";

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
