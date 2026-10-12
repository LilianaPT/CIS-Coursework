// Soccer-Scores-Team.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

struct Player {
    string name;
    int number, points;
};

//Function to get the player's info and validate input for a single player
void getPlayerInfo(Player& p, int playerNum) {
    cout << "PLAYER #" << playerNum << endl;
    cout << "----------" << endl;

    cout << "Player's Name: ";
    cin >> p.name;

    cout << "Player's Number:  ";
    cin >> p.number;

    while (p.number < 0) {
        cout << "Number can't be negative. Enter Player's Number Again: ";
        cin >> p.number;
    }

    cout << "Points scored: ";
    cin >> p.points;

    while (p.points < 0) {
        cout << "Points can't be negative. Enter Points scored again: ";
        cin >> p.points;
    }
}

//Function to display one row of player info
void displayPlayerInfo(const Player& p) {
    cout << left << setw(15) << p.name
        << setw(10) << p.number << p.points << endl;
}

//Function to calculate and print total points scored by the team
void displayTotalPoints(const Player team[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++)
        total += team[i].points;

    cout << "TOTAL POINTS: " << total << endl;
}

//Function to find a display the player with the highest score
void displayHighestScorer(const Player team[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++)
        if (team[i].points > team[maxIndex].points) maxIndex = i;

    cout << "The player who scored the highest points is: " << team[maxIndex].name << endl;
}

int main()
{
    const int TEAM_SIZE = 12;
    Player team[TEAM_SIZE];

    //Input loop to get the info for each player
    for (int i = 0; i < TEAM_SIZE; i++) {
        getPlayerInfo(team[i], i + 1);
        cout << endl;
    }

    //Display table header
    cout << left << setw(15) << "NAME"
        << setw(10) << "NUMBER" << "POINTS SCORED" << endl;

    //Output loop to display each player info using the single structure function
    for (int j = 0; j < TEAM_SIZE; j++) {
        displayPlayerInfo(team[j]);
    }

    //Calling the functions where we do calculations and summary calls using the full array
    displayTotalPoints(team, TEAM_SIZE);
    displayHighestScorer(team, TEAM_SIZE);

    return 0;
}
