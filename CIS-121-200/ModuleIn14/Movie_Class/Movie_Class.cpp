/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 14
Problem Number: 3
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 5/10/2026

Purpose: Model movie data and calculate weighted average user ratings
using a frequency-distribution class.
********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Movie {
private:
    string title;
    string mpaaRating;
    //Variables to track count of each rating level
    int rate1, rate2, rate3, rate4, rate5;

public:
    //Constructor
    Movie(string t, string mpaa);

    //Accessors
    string getTitle() const;
    string getMpaaRating() const;

    //Mutator
    void addRating(int rating);
    double getAverage() const;
};

int main()
{
    string userTitle, userMPAA;
    int ratingInput;

    //Ask user to input values
    cout << "Enter movie title: ";
    getline(cin, userTitle);
    cout << "Enter MPAA rating (G, PG, PG-13, R): ";
    cin >> userMPAA;

    //Create the Movie object
    Movie userMovie(userTitle, userMPAA);
    cout << "Enter ratings (1-5) separated by spaces. Enter -1 to stop: " << endl;

    //Lopp tp accept ratings until -1 is entered
    while (cin >> ratingInput && ratingInput != -1) {
        userMovie.addRating(ratingInput);
    }

    //Final Report
    cout << "\n--- Movie Review Summary ---" << endl;
    cout << "Title: " << userMovie.getTitle() << endl;
    cout << "MPAA Rating: " << userMovie.getMpaaRating() << endl;
    cout << fixed << setprecision(1);               //Format average to 1 decimal place
    cout << "Average Rating: " << userMovie.getAverage() << " / 5.0" << endl;

    return 0;
}

Movie::Movie(string t, string mpaa) {
    title = t;
    mpaaRating = mpaa;
    //Initialize all rating counts to 0.
    rate1 = rate2 = rate3 = rate4 = rate5 = 0;
}

string Movie::getTitle() const {
    return title;
}

string Movie::getMpaaRating() const {
    return mpaaRating;
}

//Mutator to add a rating
void Movie::addRating(int rating) {
    if (rating == 1) {
        rate1++;
    }
    else if (rating == 2) {
        rate2++;
    }
    else if (rating == 3) {
        rate3++;
    }
    else if (rating == 4) {
        rate4++;
    }
    else if (rating == 5) {
        rate5++;
    }
}

// Calculate average rating
double Movie::getAverage() const {
    int totalResponses = rate1 + rate2 + rate3 + rate4 + rate5;
    if (totalResponses == 0) return 0.0;

    double sum = (rate1 * 1) + (rate2 * 2) + (rate3 * 3) + (rate4 * 4) + (rate5 * 5);
    return sum / totalResponses;
}

