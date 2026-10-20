#include <iostream>
#include <string>


using namespace std;

int main()
{
    int d, m, size;
    int* Aptr;

    try {
        cout << "Enter size of array: ";
        cin >> size;
        Aptr = new int[size];

        cout << "Enter month 1-12: ";
        cin >> m;
        if (m < 1 || m>12) throw "invalid month";
    }

    catch (int n) {
        cout << "Date not valid";
    }
    catch (string e) {
        cout << e;
    }

    catch (bad_alloc) {
        cout << "memory not enough to create Array";
    }
}
