/*Movie Data: Write a program that uses a structure name MovieData
to store the following information about a movie: Title, Director,
Year Release, Running Time(in minutes).*/

#include <iostream>
#include <iomanip>

using namespace std;

struct MovieData {
    string title, director;
    int yearReleased, runTime;
};

//Function Prototype
void displayMovies(const MovieData& movie);

int main()
{
    //Create and initialize  two MovieData variables with their assigned elements
    MovieData movie1 = { "War of the Worlds", "Byron Haskin", 1953, 88 };
    MovieData movie2 = { "War of the Worlds", "Stephen Spielberg", 2005, 118 };

    //Pass each variable in turn to the display function
    displayMovies(movie1);
    cout << endl;
    displayMovies(movie2);


    return 0;
}

//Function to display movie information
void displayMovies(const MovieData& movie) {
    cout << left << setw(14) << "Title           : " << movie.title << endl;
    cout << left << setw(14) << "Director        : " << movie.director << endl;
    cout << left << setw(14) << "Realeased       : " << movie.yearReleased << endl;
    cout << left << setw(14) << "Running Time    : " << movie.runTime << " minutes" << endl;
}
