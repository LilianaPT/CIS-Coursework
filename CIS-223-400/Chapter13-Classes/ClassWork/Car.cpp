#include<iostream>
#include<string>
using namespace std;
#include "Car.h"

Car::Car() {
    year = 0;
    speed = 0;
    make = " ";
}
Car::Car(int y, string m) {
    year = y;
    make = m;
    speed = 0;
}

void Car::Accelerate() {
    speed += 5;
}

void Car::brake() {
    if (speed >= 5) {
        speed = speed - 5;
    }
}