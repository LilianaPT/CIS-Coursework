#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

//These MUST be the same two strings used in Encrypt.cpp
const string PLAIN = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
const string CODE = "3GstwBY<\\v7/5UFa-._T'rAxcW)NL$df%@]R0lpi!z{^QyuI;?\"8`bnP,|oC[q(~9#h+2O>6=m*k4XMeE}VD&1Hj:JSKZg";

int main() {
	//Build the REVERSE map: key = code, value = originl character
	map<char, char> decodes;
	for (size_t i = 0; i < CODE.length(); i++)
		decodes[CODE[i]] = PLAIN[i];

	string fileName;
	cout << "Enter the name of the encrypted file: ";
	getline(cin, fileName);

	ifstream inFile(fileName);
	if (!inFile) {
		cout << "Error opening " << fileName << endl;
		return 1;
	}

	cout << "\nDecrypted contents:\n\n";

	char ch;
	while (inFile.get(ch)) {
		if (decodes.count(ch))			//character is a code
			cout << decodes[ch];
		else							//spaces, newlines, tabs stay the same				
			cout << ch;
	}

	cout << endl;
	inFile.close();

	return 0;
}