/*******************************************************************
                          CIS121 Spring 2026
Type of Assignment: Lab 7
Problem Number: 1
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 3/2/2025

Purpose: The purpose of this program is to generate 10 random numbers 
and perform a comprehensive statistical analysis on them, like
finding the total of positive and negative, the total sum, the average
and the largest and smallest number.
********************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//Prototype Function
int randomInt(int min, int max);

//Main Program
int main()
{
    //See of random generator with the current time to generate new random numbers each run.
    srand(static_cast<unsigned int>(time(0)));
    //Variables declared
    const int count = 10;                                                   //Counter for FOR LOOP
    int num, largest, smallest, positive, negative,
        negSum, posSum, sum;
    double average;
    char choice = 'Y';

    //Input User request
    /*cout << "Enter number " << i + 1 << ": ";
    cin >> num;
    i++;*/

    do {
        positive = 0;
        negative = 0;
        sum = 0;
        posSum = 0;
        negSum = 0;

        cout << "Lab #7 by Liliana Pantoja - Sum, the Largest and the Smallest\n";
        cout << "The 10 random numbers are: \n";
        //For loop where the random function get the range of random numbers, in this case
        //from -20 to 20.
        for (int i = 0; i < count; ++i) {
            num = randomInt(-20, 20);
            cout << num << " ";

            //Finding the largest and smallest number
            if (i == 0) {
                largest = smallest = num;
            }
            else {
                if (num > largest) largest = num;
                if (num < smallest) smallest = num;
            }
            //Calculate the total sum of the 10 numbers
            sum += num;
            //If for counting positive and negative numbers
            if (num > 0) positive++;
            else if (num < 0) negative++;
            //If for the sum of positive and negative numbers
            if (num > 0) {
                posSum += num;
            }
            else {
                negSum += num;
            }
            
            

        }

        //Calculating the average of the sum
        average = (double)sum / 10.0;

        //Output of the program
        cout << endl;
        cout << "\nThere were a total of " << positive << " positive numbers entered" << endl;
        cout << "There were a total of " << negative << " negative numbers entered" << endl;
        cout << endl;

        cout << "The sum of all the negative numbers is: " << negSum << endl;
        cout << "The sum of all the positive numbers is: " << posSum << endl;
        cout << "The sum of all  numbers is: " << sum << endl;
        cout << endl;

        cout << "The average of all the numbers is: ";
        cout << fixed << showpoint << setprecision(1) << average << endl;
        cout << "The largest number is: " << largest << endl;
        cout << "The smallest number is: " << smallest << endl;

        cout << "\nWould you like to do it again (Y or N): ";
        cin >> choice;
        cout << endl;
        //system("cls");
    }while (choice == 'Y' || choice == 'y');

    

    return 0;
}

//Random function where we get 10 numbers from -20 to 20.
int randomInt(int min, int max) {

    return rand() % (max - min + 1) + min;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
