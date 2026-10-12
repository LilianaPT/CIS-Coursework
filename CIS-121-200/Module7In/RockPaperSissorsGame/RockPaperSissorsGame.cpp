/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 7
Problem Number: 3
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 3/2/2025

Purpose: This program simulates a game of Rock, Paper, Scissors between
a user and the computer. It utilizes modular functions to handle input
validation, random number generation, and game logic.
The program ensures a clear winner by forcing a rematch in the event
of a tie and allows for continuous play until the user quits.
********************************************************************/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>    //Added for time()

using namespace std;

//Function Prototypes
int getUserChoice();
int getComputerChoice();
void displayChoice(int choices);
void determineWinner(int, int);

int main()
{
    //Seed the random number generator with current system time
    srand(static_cast<unsigned int>(time(0)));
    int userChoice = 0, computerChoice = 0;

    do {
        //Tie Logic: Re-run inner loop if choices are identical
        do {
            userChoice = getUserChoice();

            //Check if user wants to exit before computer moves.
            if (userChoice == 4) {
                cout << "Thank you for playing!\n";
                return 0;
            }
            computerChoice = getComputerChoice();

            //Display selections for both players
            cout << "\nYou choose: ";
            displayChoice(userChoice);
            cout << "\nComputer choose: ";
            displayChoice(computerChoice);

            //Handle the tie scenario
            if (userChoice == computerChoice) {
                cout << "It's a tie! Re-playing to determine the winner...\n" << endl;
            }
        } while (userChoice == computerChoice);
        //Calculate and announce the winner based on established rules
        determineWinner(userChoice, computerChoice);
        cout << "\n-------------------------------\n" << endl;
    } while (userChoice != 4);      //Loop continues until "Quit" is selected

    return 0;
}
//Displays the menu and ensures the user enters a value between 1 and 4
int getUserChoice() {
    int choice;
    cout << "---:Game Menu:---";
    cout << "\n1. Rock.";
    cout << "\n2. Paper.";
    cout << "\n3. Scissor.";
    cout << "\n4. Quit";

    cout << "\nEnter your choice (1 - 4): ";
    cin >> choice;

    cout << endl;
    //Input validation loop
    while (choice < 1 || choice > 4) {
        cout << "Invalid Choice. Please enter a valid choice between (1 - 4): ";
        cin >> choice;
    }
    return choice;
}
//Generates a random integer between 1 and 3 to represent the computer's move
int getComputerChoice() {
    return (rand() % 3) + 1;
}
//Converts the integer choices back into strings for user display
void displayChoice(int choices) {
    if (choices == 1) {
        cout << "Rock" << endl;
    }
    else if (choices == 2) {
        cout << "Paper" << endl;
    }
    else if (choices == 3) {
        cout << "Scissor" << endl;
    }
}
//Compares user and computer choices to decide the winner based on game rules
void determineWinner(int user, int computer) {
    //1 = Rock, 2 = Paper, 3 = Scissors
    if (user == 1 && computer == 3) {
        cout << "The rock smashes the scissors. YOU WIN!!" << endl;
    }
    else if (user == 3 && computer == 2) {
        cout << "Scissors cut paper. YOU WIN!!" << endl;
    }
    else if (user == 2 && computer == 1) {
        cout << "Paper wraps rock. YOU WIN!!" << endl;
    }
    else {
        //If it wasn't a tie (handled in main) and user didn't win, computer wins
        cout << "COMPUTER WINS!!" << endl;
    }
    
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
