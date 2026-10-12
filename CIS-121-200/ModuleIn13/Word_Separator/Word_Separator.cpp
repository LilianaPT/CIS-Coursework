/*******************************************************************
                          CIS-121 Spring 2026
Type of Assignment: Lab 13
Problem Number: 2
Programmer: Liliana Pantoja
Section: 400/M40
Date Due: 4/20/2026

Purpose: Convert a "CamelCase" or "PascalCase" string (where words 
are joined together with uppercase letters) into a standard sentence. 
It detects uppercase letters to identify the start of new words, 
inserts a space before them, and converts those leading letters to
lowercase (unless it is the very first letter of the sentence).
********************************************************************/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string sentence, output = "";
    char c;

    cout << "Enter a sentence with words and no spaces: ";
    cin >> sentence;

    // Iterate through each character of the input string
    for (int i = 0; i < sentence.length(); i++) {
        c = sentence[i];

        // Check if the current character is uppercase (indicating a new word)
        if (isupper(c)) {
            // If it's not the first character, add a space and lowercase the letter
            if (i > 0) {
                output += ' ';
                output += (char)tolower(c);
            }
            // If it is the first character, keep it uppercase for the start of the sentence
            else {
                output += c;
            }
        }
        // If the character is already lowercase, just add it to the output
        else {
            output += c;
        }
    }

    // Display the final converted result
    cout << "Converted sentence: " << endl;
    cout << output << endl;

    return 0;
}

