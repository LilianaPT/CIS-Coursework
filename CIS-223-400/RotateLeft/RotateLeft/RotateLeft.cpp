/*Chapter 16 - Program 2: Rotate Left
Template functions that perform a circular left rotation on a
vector and print a vector of any type.*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*Performs a single circular left rotation on the vector:
the first element moves to the end, and every other element
shifts one position to the left*/
template <class T>
void rotateLeft(vector<T>& v) {
    if (v.size() < 2)
        return;

    T first = v[0];
    for (size_t i = 0; i < v.size() - 1; i++) {
        v[i] = v[i + 1];
    }
    v[v.size() - 1] = first;
}

//Prints the elements of the vector on one line
template <class T>
void output(vector<T> v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

//Prints the vector, then rotates and prints it once for each
//remaining position, producing every rotation
template <class T>
void showAllRotations(vector<T> v) {
    for (size_t i = 0; i < v.size(); i++) {
        output(v);
        rotateLeft(v);
    }
    cout << endl;
}

int main()
{
    vector<int> intVec = { 1, 3, 5, 7 };
    vector<char> charVec = { 'a', 'b', 'c', 'd', 'e' };
    vector<double> doubleVec = { 1.5, 2.5, 3.5, 4.5 };
    vector<string> stringVec = { "red", "green", "blue" };

    cout << "Vector of int:\n";
    showAllRotations(intVec);

    cout << "Vector of char:\n";
    showAllRotations(charVec);

    cout << "Vector of double:\n";
    showAllRotations(doubleVec);

    cout << "Vector of string:\n";
    showAllRotations(stringVec);

    return 0;
}
