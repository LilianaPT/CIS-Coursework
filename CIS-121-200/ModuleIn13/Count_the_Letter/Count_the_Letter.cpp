/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 13
Problem Number: 1
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 4/20/2026

Purpose: The purpose of this program is to analyze a line of text 
provided by the user. It identifies and counts the total number of 
words (defined as sequences of alphabetic characters) and calculates 
the frequency of each letter used, regardless of whether the input was 
uppercase or lowercase.
********************************************************************/

#include <iostream>
#include <string>
#include <cctype>       //Required for isspace, isalpha, and tolower

using namespace std;

int main()
{
    string line;
    cout << "Enter a line of text: ";
    getline(cin, line);             // Read the full line of text from the user

    int word_count = 0;
    int letter_counts[26] = { 0 };      // Array to store counts for letters a-z
    bool in_word = false;               // Tracks if we are currently traversing a word
    char c;

    // Loop through every character in the input string
    for (int i = 0; i < line.length(); i++) {
        // Cast char to unsigned char to prevent issues with extended ASCII/negative values
        unsigned char c = static_cast<unsigned char>(line[i]);

        // If the character is whitespace or specific punctuation, the current word has ended
        if (isspace(c) || c == ',' || c == '.') {
            in_word = false;
        }
        // Check if the character is a letter (A-Z or a-z)
        else if (isalpha(c)) {
            // If we weren't in a word, this is the start of a new one
            if (!in_word) {
                in_word = true;
                word_count++;
            }

            // Convert to lowercase and find its index in the array (e.g., 'a' is 0, 'b' is 1)
            int index = tolower(c) - 'a';

            // Safety check to ensure we only update indices within the 0-25 range
            if (index >= 0 && index < 26) {
                letter_counts[index]++;
            }
        }
    }

    // Output the final counts
    cout << "\nNumber of words: " << word_count << endl;
    cout << "Letter occurrences: " << endl;

    for (int i = 0; i < 26; i++) {
        // Only display letters that were actually found in the text
        if (letter_counts[i] > 0) {
            cout << static_cast<char>('a' + i) << ": " << letter_counts[i] << endl;
        }
    }

    return 0;
}

