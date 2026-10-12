#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main() {

	/*char msg[35] = "Like tears in the rain";
	cout << strlen(msg);
	char s1[25] = "In the Garden ";
	char s2[10] = "of Eden";
	strcat_s(s1, s2);

	cout << s1;
	char a[10] = "Hello";
	char b[10];
	strcpy_s(b, a);

	cout << b;
	char w1[10] = "apple";
	char w2[10] = "banana";
	cout << strcmp(w1, w2);*/

	//char names[4][15]; // 4 strings, each up to 14 characters + '\0'
	//char days[7][10] = { // initialized 2D array of strings
	//"Monday", "Tuesday", "Wednesday", "Thursday",
	//"Friday", "Saturday", "Sunday"
	//};
	//cout << days[0]; // prints: Monday
	//cout << days[2]; // prints: Wednesday

	int n = atoi("125");
	double d = atof("9.81");
	int x = atoi("abc");
	int y = atoi("42abc");
	double g = atof("3.14xyz");

	cout << n << endl;
	cout << d << endl;
	cout << x << endl;
	cout << y << endl;
	cout << g << endl;


	return 0;
}
