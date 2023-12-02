#include "../main.hpp"

using namespace std;

void day1part1() {
    ifstream input("day1/input.txt");
    string line;
    int sum = 0;

    while (getline(input, line)) {
        string reversedLine;
        string calibrationValue;

        bool firstDigitFound = false;
        
        for (char c : line) {
            if (!firstDigitFound && isdigit(c)) {
                calibrationValue += c;
                firstDigitFound = true;
            }
            reversedLine = c + reversedLine;
        }

        for (char c : reversedLine) {
            if (isdigit(c)) {
                calibrationValue += c;
                break;
            }
        }

        sum += stoi(calibrationValue);
    }
    input.close();
    
    cout << "Day1  - Part1: The solution is " << sum << endl;
}