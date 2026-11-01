/*Chapter 17 - Capital Quiz
Stores the 50 U.S. states and their capitals in a map, then
randomly quizzes the user and counts correct/incorrect answers*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

//Function prototypes
string toLower(string str);

int main()
{
    const int NUM_QUESTIONS = 5;

    //Map: key = state, value = capital
    map<string, string> capitals = {
        {"Alabama", "Montgomery"}, {"Alaska", "Juneau"},
        {"Arizona", "Phoenix"}, {"Arkansas", "Little Rock"},
        {"California", "Sacramento"}, {"Colorado", "Denver"},
        {"Connecticut", "Harford"}, {"Delaware", "Dover"},
        {"Florida", "Tallahassee"}, {"Georgia", "Atlanta"},
        {"Hawaii", "Honolulu"}, {"Idaho", "Boise"},
        {"Illinois", "Springfield"}, {"Indiana", "Indianapolis"},
        {"Iowa", "Des Moines"}, {"Kansas", "Topeka"},
        {"Kentucky", "Frankfort"}, {"Louisiana", "Baton Rouge"},
        {"Maine", "Augusta"}, {"Maryland", "Annapolis"},
        {"Massachusetts", "Boston"}, {"Michigan", "Lansing"},
        {"Minnesota", "Saint Paul"}, {"Mississipi", "Jackson"},
        {"Missouri", "Jefferson City"}, {"Montana", "Helena"},
        {"Nebraska", "Lincoln"}, {"Nevada", "Carson City"},
        {"New Hampshire", "Concord"}, {"New Jersey", "Trenton"},
        {"New Mexico", "Santa Fe"}, {"New York", "Albany"},
        {"North Carolina", "Raleigh"}, {"North Dakota", "Bismarck"},
        {"Ohio", "Columbus"}, {"Oklahoma", "Oklahoma City"},
        {"Oregon", "Salem"}, {"Pennsylvania", "Harrisburg"},
        {"Rhode Island", "Providence"}, {"South Carolina", "Columbia"},
        {"South Dakota", "Pierre"}, {"Tennessee", "Nashville"},
        {"Texas", "Austin"}, {"Utah", "Salt Lake City"},
        {"Vermont", "Montpelier"}, {"Virginia", "Richmond"},
        {"Washington", "Olympia"}, {"West Virginia", "Charleston"},
        {"Wisconsin", "Madison"}, {"Wyoming", "Cheyenne"}
    };

    //Put the state names in a vector so we can pick one by random index
    vector<string> states;
    for (auto element : capitals)
        states.push_back(element.first);

    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    int correct = 0, incorrect = 0;
    string answer;

    cout << "I'm going to ask you for the capitals of " << NUM_QUESTIONS << " states.\n";

    for (int count = 0; count < NUM_QUESTIONS; count++) {
        //Pick a random state, then remove it so it isn't ask twice
        int index = rand() % states.size();
        string state = states[index];
        states.erase(states.begin() + index);

        cout << "\nWhat is the capital of " << state << "? ";
        getline(cin, answer);                                   //getline allows answers like "Salt Lake City"

        //Compare without worrying about upper/lower case
        if (toLower(answer) == toLower(capitals[state])) {
            cout << "Correct!\n";
            correct++;
        }
        else {
            cout << "Sorry, that's incorrect.\n";
            incorrect++;
        }
    }

    cout << endl;
    cout << "End of the quiz.\n";
    cout << "Correct answers: " << correct << endl;
    cout << "Incorrect answers: " << incorrect << endl;

    return 0;
}

//Returns a lowercase copy of str
string toLower(string str) {
    for (char& ch : str)
        ch = tolower(ch);
    return str;
}