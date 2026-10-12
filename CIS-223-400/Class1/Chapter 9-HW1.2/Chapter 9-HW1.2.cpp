/*Write a function that accepts an int array and the array's size as arguments.
The function should create a new array that is twice the size of the argument array.
The function should copy the contents of the argument array to the new array and
initialize the unused elements of the second array with 0. The function should return
a pointer to the new array.*/

#include <iostream>

using namespace std;

int* expandArray(int arr[], int size) {
    int* bigArr = new int[size * 2];

    for (int i = 0; i < size; i++)
        bigArr[i] = arr[i];

    for (int j = size; j < size * 2; j++)
        bigArr[j] = 0;

    return bigArr;
}

int main()
{
    int originalArr[] = { 1,2,3,4,5 };
    int size = 5;

    cout << "The contents of the original array are: " << endl;
    for (int i = 0; i < size; i++)
        cout << originalArr[i] << " ";
    cout << endl;
    
    int* expanded = expandArray(originalArr, size);

    cout << "\nThe contents of the expanded array are: " << endl;
    for (int i = 0; i < size * 2; i++)
        cout << expanded[i] << " ";
    cout << endl;

    delete[] expanded;
    return 0;
}

