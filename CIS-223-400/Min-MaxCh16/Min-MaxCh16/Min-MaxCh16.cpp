#include <iostream>
#include <string>

using namespace std;

template<class T>
T min(T a, T b){
    return (a < b) ? a : b;
}

template<class T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

template<class T>
void swap(T& x, T& y) {
    T temp = x;
    x = y;
    y = temp;
}

int main()
{
    //int values
    int n1 = 5, n2 = 3;

    cout << "minimum of " << n1 << ", " << n2 << " is: "
        << ::min(n1, n2) << endl;
    cout << "maximum of " << n1 << ", " << n2 << " is: "
        << ::max(n1, n2) << endl;

    //double values
    double db1 = 5.5, db2 = 3.5;
    cout << "minimum of " << db1 << ", " << db2 << " is: "
        << ::min(db1, db2) << endl;
    cout << "maximum of " << db1 << ", " << db2 << " is: "
        << ::max(db1, db2) << endl;

    //string values
    string w1 = "hello", w2 = "hi";
    cout << "minimum of " << w1 << ", " << w2 << " is: "
        << ::min(w1, w2) << endl;
    cout << "maximum of " << w1 << ", " << w2 << " is: "
        << ::max(w1, w2) << endl;

    //Demonstrating the swap template with two ints
    int x = 10, y = 20;
    cout << "\nBefore swap: x = " << x << ", y = " << y << endl;
    ::swap(x, y);
    cout << "After swap: x =" << x << ", y = " << y << endl;

    return 0;
}