/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Final_Test
Problem Number: Question 1
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 5/06/2025

Purpose: The purpose of this program is to demonstrate random number 
generation and functional decomposition in C++. On a practical level, 
it mimics the real-world physics of a coin flip using software logic.
********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Function prototype
void coinToss();

int main()
{
    int times;

    srand(static_cast<unsigned int>(time(0)));

    cout << "How many times should the coin be tossed? ";
    cin >> times;

    //Loop to perform the tosses
    for (int i = 1; i <= times; i++) {
        cout << i << ": ";
        coinToss();
    }

    return 0;
}


void coinToss() {
    int result = (rand() % 2) + 1;

    if (result == 1) cout << "Heads" << " (coin is " << result << " )." << endl;
    else cout << "Tails" << " (coin is " << result << " )." << endl;
}

