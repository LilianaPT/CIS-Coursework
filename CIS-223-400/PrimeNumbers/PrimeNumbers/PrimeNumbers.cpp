/* Chapter 17 Pt 2. Prime Number Generator
Ask the user for an integer greater than 1, fills a vector with
every integer from 2 up to that number, and then uses the STL
for each algoritm with a function object to display the primes.*/

#include <iostream>
#include <vector>
#include <algorithm>        //for _each

using namespace std;

/*Function object class: overloading operator() lets an objecto of this
class be called like a function. It displays the number if it is prime.*/
class DisplayIfPrime {
public:
    void operator()(int num) const {
        if (isPrime(num))
            cout << num << " ";
    }

private:
    //Returns true if num is prime (no divisors other than 1 and itself)
    bool isPrime(int num) const {
        if (num < 2)
            return false;

        //Only need to test divisors up to the square root of num
        for (int divisor = 2; divisor * divisor <= num; divisor++) {
            if (num % divisor == 0)
                return false;       //found a divisor, so it is composite
        }
        return true;
    }
};

int main()
{
    int number;

    //Get a valid number from the user (must be greater than 1)
    cout << "Enter an integer greater than 1: ";
    cin >> number;
    while (!cin || number <= 1) {
        cin.clear();                //clear an error if a letter was typedd
        cin.ignore(1000, '\n');     //throw away the bad input
        cout << "Invalid. Enter an integer greater than 1: ";
        cin >> number;
    }

    //Populate the vector with all integers from 2 up through number
    vector<int> numbers;
    for (int value = 2; value <= number; value++)
        numbers.push_back(value);

    //Step through the vector wih for_each. Each element is passed
    //to the DisplayIfPrime function object.
    cout << "\nThe prime numbers less than or equal to " << number << " are: \n";
    for_each(numbers.begin(), numbers.end(), DisplayIfPrime());
    cout << endl;

    return 0;
}