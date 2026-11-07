/*Chapter 17 Part 2 - Gas Prices
Reads GasPrices.txt and:
1. Calculates the average price of gas for each year
2. Finds the lowest AND highest price (with dates) for each year
3. Writes a text file listing every date and price, sorted from
   the lowest price to the highest*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <algorithm>        //sort

using namespace std;

//Holds one line of the file
struct GasRecord {
    string date;                //"MM-DD-YYYY"
    int year = 0;
    double price = 0.0;
};

//Function prototypes
bool readFile(const string& fileName, vector<GasRecord>& records);
void averagePerYear(const vector<GasRecord>& records);
void lowHighPerYear(const vector<GasRecord>& records);
void writeSortedFile(vector <GasRecord> records, const string& fileName);

int main()
{ 
    const string INPUT_FILE = "GasPrices.txt";
    const string OUTPUT_FILE = "SortedGasPrices.txt";

    vector<GasRecord> records;

    if (!readFile(INPUT_FILE, records)) {
        cout << "Error opening " << INPUT_FILE << endl;
        return 1;
    }

    cout << "Read" << records.size() << " weekly prices from " << INPUT_FILE << ".\n";

    cout << fixed << setprecision(3);               //prices have 3 decimal places

    averagePerYear(records);
    lowHighPerYear(records);
    writeSortedFile(records, OUTPUT_FILE);

    return 0;
}

/*Reads every line of the file into the records vector
Returns false if the file could not be opened.*/
bool readFile(const string& fileName, vector<GasRecord>& records) {
    ifstream inFile(fileName);
    if (!inFile)
        return false;

    string line;
    while (getline(inFile, line)) {
        //Each line looks like 04-05-1993:1.068
        size_t colon = line.find(':');
        if (colon == string::npos)
            continue;               //skip blank or bad lines

        GasRecord rec;
        rec.date = line.substr(0, colon);           //"04-05-1993"
        rec.year = stoi(rec.date.substr(6, 4));     //characters 6-9 = year
        rec.price = stod(line.substr(colon + 1));   //text after the colon

        records.push_back(rec);
    }

    inFile.close();
    return true;
}

//1. Average price per year
void averagePerYear(const vector<GasRecord>& records) {
    
    //Map: key = year, value = all of that year's prices. A map keeps the years in order automatically.
    map<int, vector<double>> pricesByYear;

    for (auto it = records.begin(); it != records.end(); ++it)
        pricesByYear[it->year].push_back(it->price);

    cout << "\n===== Average Price per Year =====\n";
    cout << "Year    Average\n";

    for (auto it = pricesByYear.begin(); it != pricesByYear.end(); ++it) {
        double total = 0.0;

        //Add up the prices using an iterator over the inner vector
        for (auto p = it->second.begin(); p != it->second.end(); ++p)
            total += *p;

        double average = total / it->second.size();
        cout << it->first << "     $" << average << endl;
    }
}

//2. Lowest and highest price (with date) for each year
void lowHighPerYear(const vector<GasRecord>& records) {
    map<int, GasRecord> lowest;                         //key = year, value = lowest record
    map<int, GasRecord> highest;                        //key = year, value = highest record

    for (auto it = records.begin(); it != records.end(); ++it) {
        //count() returns 0 if this year isn't in the map yet
        if (lowest.count(it->year) == 0 || it->price < lowest[it->year].price)
            lowest[it->year] = *it;

        if (highest.count(it->year) == 0 || it->price > highest[it->year].price)
            highest[it->year] = *it;
    }

    cout << "\n===== Lowest and Highest Price per Year =====\n";
    cout << "Year    Lowest (Date)            Highest (Date)\n";

    auto lowIt = lowest.begin();
    auto highIt = highest.begin();

    //Both maps have the same years in the same order
    while (lowIt != lowest.end() && highIt != highest.end()) {
        cout << lowIt->first << "    $";
        cout << lowIt->second.price << " (" << lowIt->second.date << ")      $"
            << highIt->second.price << " (" << highIt->second.date << ")\n";
        ++lowIt;
        ++highIt;
    }
}

//3. Writes all dates and prices to a file, sorted lowest to highest
//records is passed by value so sorting doesn't change the original.
void writeSortedFile(vector<GasRecord> records, const string& fileName) {
    //Sort with a lambda expression that compares two prices
    sort(records.begin(), records.end(), [](const GasRecord& a, const GasRecord& b)
        { return a.price < b.price; });

    ofstream outFile(fileName);
    if (!outFile) {
        cout << "Error creating " << fileName << endl;
        return;
    }

    outFile << fixed << setprecision(3);
    for (auto it = records.begin(); it != records.end(); ++it)
        outFile << it->date << ":" << it->price << endl;

    outFile.close();

    cout << "\n===== List of Prices, Lowest to Highest =====\n";
    cout << "Sorted list written to " << fileName << ".\n";
    cout << "Lowest: " << records.front().date << " $" << records.front().price << endl;
    cout << "Highest: " << records.back().date << " $" << records.back().price << endl;
}