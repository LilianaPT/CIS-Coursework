/*Chapter 17 - File Encryption.
Uses a map to assign a code to each character, reads a text file,
and writes an encrypted copy of it to a second file.*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

const string PLAIN = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
const string CODE = "3GstwBY<\\v7/5UFa-._T'rAxcW)NL$df%@]R0lpi!z{^QyuI;?\"8`bnP,|oC[q(~9#h+2O>6=m*k4XMeE}VD&1Hj:JSKZg";

int main()
{
    //Build the map: key = original character, value = its code
    map<char, char> codes;
    for (size_t i = 0; i < PLAIN.length(); i++)
        codes[PLAIN[i]] = CODE[i];

    string inName, outName;
    cout << "Enter the name of the file to encrypt: ";
    getline(cin, inName);
    cout << "Enter the name of the encrypted file to create: ";
    getline(cin, outName);

    ifstream inFile(inName);
    if (!inFile) {
        cout << "Error opening " << inName << endl;
        return 1;
    }

    ofstream outFile(outName);
    if (!outFile) {
        cout << "Error creating " << outName << endl;
        return 1;
    }

    char ch;
    //get() read every character, including spaces and newlines
    while (inFile.get(ch)) {
        if (codes.count(ch))                 //character has a code
            outFile.put(codes[ch]);
        else
            outFile.put(ch);                //spacesm newlines, tabs stay the same
    }

    inFile.close();
    outFile.close();

    cout << "The file " << inName << " was encrypted and saved as "
        << outName << ".\n";

    return 0;
}
