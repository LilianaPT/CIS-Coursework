#include <iostream>
#include <iomanip>
#include "FeetInches.h"
#include "RoomDimension.h"
#include "RoomCarpet.h"

using namespace std;

int main()
{
    int lengthFeet, lengthInches;
    int widthFeet, widthInches;
    double costPerSqFt;

    cout << "Enter the room length (feet inches): ";
    cin >> lengthFeet >> lengthInches;

    cout << "Enter the room width (feet inches): ";
    cin >> widthFeet >> widthInches;

    cout << "Enter the carpet cost per square foot: ";
    cin >> costPerSqFt;

    FeetInches length(lengthFeet, lengthInches);
    FeetInches width(widthFeet, widthInches);

    RoomDimension dimensions(length, width);

    RoomCarpet carpet(dimensions, costPerSqFt);

    cout << endl;
    cout << fixed << setprecision(2);
    cout << "The total cost of carpeting the room is $" << carpet.getTotalCost() << endl;

    return 0;
}