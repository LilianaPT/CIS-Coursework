/*
* Name : ________________________________
* Date : ________________________________
* Program : Module 14 Week 2 -- Movie Collection Manager
* Purpose : Demonstrate parameterized constructors, private helpers,
* and arrays of objects. Chapter 13, Gaddis 10th Ed.
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
// ─────────────────────────────────────────────────
// CLASS DECLARATION
// ─────────────────────────────────────────────────
class Movie
{
public:
	// Default constructor (Step 1)
	Movie();
	// TODO Step 2 -- Add the parameterized constructor PROTOTYPE here:
	Movie(string t, string d, int y, double r);
	// Inline accessors (defined inside the class -- no :: needed)
	string getTitle() { return title; }
	string getDirector() { return director; }
	int getYear() { return year; }
	double getRating() { return rating; }
	// Mutators
	void setTitle(string t);
	void setDirector(string d);
	void setYear(int y);
	void setRating(double r); // uses isValidRating()
	// Display function
	void displayInfo();
private:
	string title;
	string director;
	int year;
	double rating;
	// TODO Step 3 -- Add the PROTOTYPE for isValidRating() here:
	bool isValidRating(double r);
	// It takes a double and returns bool
};
// ─────────────────────────────────────────────────
// MAIN FUNCTION
// ─────────────────────────────────────────────────
int main()
{
	const int SIZE = 4;
	// TODO Step 6a -- Declare an array of SIZE Movie objects
	Movie films[SIZE];
	// TODO Step 6b -- Populate films[0] using set functions:
	// Title: "Inception" Director: "Christopher Nolan" Year: 2010 Rating: 4.8
	films[0].setTitle("Inception");
	films[0].setDirector("Christopher Nolan");
	films[0].setYear(2010);
	films[0].setRating(4.8);
	// TODO Step 6c -- Populate films[1] using set functions:
	// Title: "Parasite" Director: "Bong Joon-ho" Year: 2019 Rating: 4.9
	films[1].setTitle("Parasite");
	films[1].setDirector("Bong Joon-ho");
	films[1].setYear(2019);
	films[1].setRating(4.9);
	// TODO Step 7 -- Use the parameterized constructor for films[2] and films[3]:
	// films[2]: "Dune", "Denis Villeneuve", 2021, 4.5
	films[2].setTitle("Dune");
	films[2].setDirector("Denis Villeneuve");
	films[2].setYear(2021);
	films[2].setRating(4.5);
	// films[3]: "Oppenheimer", "Christopher Nolan", 2023, 4.7
	films[3].setTitle("Oppenheimer");
	films[3].setDirector("Christopher Nolan");
	films[3].setYear(2023);
	films[3].setRating(4.7);
	cout << "====================================" << endl;
	cout << " MOVIE COLLECTION CATALOG " << endl;
	cout << "====================================" << endl;
	// TODO Step 8 -- Loop through the array and call displayInfo() on each film
	for (int i = 0; i <	SIZE; i++) {
		films[i].displayInfo();
	}
	// TODO Step 9 (Challenge) -- Find and display the highest-rated movie
	// Hint: loop, keep track of the index with the max rating, use getRating()
	int maxIndx = 0;
	for (int i = 0; i < SIZE; i++) {
		if (films[i].getRating() > films[maxIndx].getRating()) {
			maxIndx = i;
		}
	}

	cout << "\nHighest rated movie: " << films[maxIndx].getTitle() << " (" << films[maxIndx].getRating() << ") " << endl;

	return 0;
}

// ─────────────────────────────────────────────────
// MEMBER FUNCTION IMPLEMENTATIONS
// ─────────────────────────────────────────────────

// TODO Step 1 -- Implement the default constructor
// Set: title = "Unknown", director = "Unknown", year = 0, rating = 0.0
Movie::Movie()
{
	title = "Unknown";		//No title yet
	director = "Unknown";
	year = 0;
	rating = 0.0;
}
// TODO Step 2 -- Implement the PARAMETERIZED constructor
// Parameters: string t, string d, int y, double r
// Validate rating with isValidRating() before storing it
Movie::Movie(string t, string d, int y, double r)
{
	// TODO: assign title, director, year
	// TODO: if isValidRating(r) is true, set rating = r; else set rating = 0.0
	title = t;
	director = d;
	year = y;

	if (isValidRating(r)) {
		rating = r;
	}
	else {
		rating = 0.0;
	}
}
// Mutators -- provided for you
void Movie::setTitle(string t) { title = t; }
void Movie::setDirector(string d) { director = d; }
void Movie::setYear(int y) { year = y; }
// setRating uses the private helper -- DO NOT MODIFY
void Movie::setRating(double r)
{
	if (isValidRating(r)) rating = r;
	else {
		cout << "Invalid rating. Must be 1.0-5.0. Set to 0.0." << endl; 
		rating = 0.0;
	}
}
// TODO Step 3 -- Implement isValidRating()
// Returns true if r is between 1.0 and 5.0 inclusive, false otherwise
bool Movie::isValidRating(double r)
{
	// TODO: return the boolean expression (one line)
	if (r >= 1.0 && r <= 5.0) return true;
	else return false;
}
// TODO Step 4 -- Implement displayInfo()
// Print all four data members in a formatted layout (see sample output below)
void Movie::displayInfo()
{
	// TODO: use cout with fixed and setprecision(2) for the rating
	cout << fixed << setprecision(2) << endl;
	cout << "\n-----------------------------------" << endl;
	cout << "Title		: " << title << endl;
	cout << "Director	: " << director << endl;
	cout << "Year		: " << year << endl;
	cout << "Rating		: " << rating << endl;
	cout << "-----------------------------------" << endl;
}