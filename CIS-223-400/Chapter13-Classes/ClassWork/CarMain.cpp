// ClassWork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<string>

using namespace std;

#include "Car.h"

int main()
{
    Car Honda(2024, "Accord");
    Car Tesla;
    Tesla.setyear(2025);

    cout << Honda.getspeed() << endl;
    for (int i = 0; i < 8; i++)
        Honda.Accelerate();
    cout << "Accelerating" << endl;
    cout << Honda.getspeed();

    return 0;
}