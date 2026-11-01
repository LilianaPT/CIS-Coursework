/*Chapter 17 - Word Index
Reads a text file and builds a map where each key is a word and
each value is a set of the line numbers where that word appears.
Then writes the map to an index file in alphabetical order*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cctype>

using namespace std;

//Function prototype
string cleanWord(string word);

int main()
{
    map<string, set<int>> index;        //word -> line numbers
    string inName, outName;

    cout << "Enter the name of the text file: ";
    getline(cin, inName);
    cout << "Enter the name of the index file to create: ";
    getline(cin, outName);

    ifstream inFile(inName);
    if (!inFile) {
        cout << "Error opening " << inName << endl;
        return 1;
    }

    string line;
    int lineNumber = 0;

    //Read the file one line at a time
    while (getline(inFile, line)) {
        lineNumber++;

        //Tokenize the line into words
        istringstream lineStream(line);
        string word;
        while (lineStream >> word) {
            word = cleanWord(word);
            if (word != "")
                index[word].insert(lineNumber);             //a set ignores duplicates
        }
    }
    inFile.close();

    ofstream outFile(outName);
    if (!outFile) {
        cout << "Error creating " << outName << endl;
        return 1;
    }

    //A map is already sorted by key, so the words come out alphabetically
    for (auto element : index) {
        outFile << element.first << ":";
        for (int num : element.second)
            outFile << " " << num;
        outFile << endl;
    }
    outFile.close();

    cout << "The word index was written to " << outName << ".\n";

    return 0;
}

//Removes punctuation from the start and end of a word,
//so "end", and "end" count as the same word.
string cleanWord(string word) {
    while (word.length() > 0 && ispunct(word[0]))
        word.erase(0, 1);
    while (word.length() > 0 && ispunct(word[word.length() - 1]))
        word.erase(word.length() - 1, 1);
    return word;
}