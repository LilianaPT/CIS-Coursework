/*Creare a structure for Shoe with 2 variables type, price*/

#include <iostream>

using namespace std;

struct shoe {
    string type;
    double price = 0.0;
};

void getInfo(shoe& s) {
    cout << "Please enter the style of the shoe: ";
    cin >> s.type;
    cout << "Enter the price of the shoe: ";
    cin >> s.price;
}

shoe getShoeInfo() {
    shoe s1;
    cout << "\nEnter Style: ";
    cin >> s1.type;
    cout << "Enter Price: ";
    cin >> s1.price;

    return s1;
}

void displayInfo(shoe MyShoe) {
    cout << "\nStyle: " << MyShoe.type << endl;
    cout << "Price: " << MyShoe.price << endl;
}

void showArray(shoe s3[], int size) {
    for (int j = 0; j < size; j++) {
        cout << (j+1) << ". Style: " << s3[j].type << endl;
        cout << "  Price: " << s3[j].price << endl;
    }
}

int main()
{
    shoe shoe1, shoe2;

    //getInfo(shoe1);
    //shoe2 = getShoeInfo();
    //displayInfo(shoe1);
    //displayInfo(shoe2);

    shoe shoes[10];
    for (int i = 0; i < 10; i++) {
        //Use second function
        shoes[i] = getShoeInfo();
        //Use first function
        //getInfo(shoes[i]);
    }

    cout << endl;
    showArray(shoes, 10);

    return 0;
}

