/*Array Allocator: Write a function that dynamically allocates an array of integers. The function should accept
an integer argument indicating the number of elements to allocate. The function should return a pointer to the array*/

#include <iostream>

using namespace std;

int* allocateArray(int size) {
    int* array = nullptr;
    array = new int[size];

    for (int i = 0; i < size; i++)
        array[i] = i;

    return array;
}

int main()
{
    int size;

    cout << "Enter an array size: ";
    cin >> size;

    int* myArray = allocateArray(size);

    cout << "\nHere are the values in the array: " << endl;
    for (int i = 0; i < size; i++)
        cout << "Element " << i << " has the value " << myArray[i] << endl;

    delete[] myArray;
    return 0;
}

