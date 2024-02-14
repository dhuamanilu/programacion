#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

bool isRussianFormat(const string& date) {
    return date.find('.') != string::npos;
}

string convertToEuropeanFormat(const string& date) {
    stringstream ss(date);
    string day, month, year;
    getline(ss, day, '/');
    getline(ss, month, '/');
    getline(ss, year, '/');
    return setw(2) << setfill('0') << day << "." << setw(2) << setfill('0') << month << "." << year;
}

string convertToAmericanFormat(const string& date) {
    stringstream ss(date);
    string day, month, year;
    getline(ss, month, '.');
    getline(ss, day, '.');
    getline(ss, year, '.');
    return setw(2) << setfill('0') << month << "/" << setw(2) << setfill('0') << day << "/" << year;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Clear input buffer
    
    vector<string> dates(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, dates[i]);
    }
    
    for (const string& date : dates) {
        if (isRussianFormat(date)) {
            cout << convertToEuropeanFormat(date) << " " << convertToAmericanFormat(date) << endl;
        } else {
            cout << convertToAmericanFormat(date) << " " << convertToEuropeanFormat(date) << endl;
        }
    }
    
    return 0;
}









