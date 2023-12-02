#include "../main.hpp"

using namespace std;

string replaceDigits(string line, bool leftToRight);

void day1part2() {
    ifstream input("day1/input.txt");
    string line;
    int sum = 0;

    while (getline(input, line)) {
        string calibrationValue;
        string reversedLine = "";
        for (char c : replaceDigits(line, false)) {
            reversedLine = c + reversedLine;
        }
        line = replaceDigits(line, true);

        for (char c : line) {
            if (isdigit(c)) {
                calibrationValue += c;
                break;
            }
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
    
    cout << "Day1  - Part2: The solution is " << sum << endl;
}

unordered_map<string, string> digits = {
    {"one", "1"},
    {"two", "2"},
    {"three", "3"},
    {"four", "4"},
    {"five", "5"},
    {"six", "6"},
    {"seven", "7"},
    {"eight", "8"},
    {"nine", "9"},
};

// replaces all the digits with their counterpart number, so "one" -> "1", "two" -> "2", etc..
string replaceDigits(string line, bool leftToRight) {
    string updatedLine = line;
    unordered_map<string, size_t> digitPositions;

    while (true) {
        digitPositions["one"] = updatedLine.find("one");
        digitPositions["two"] = updatedLine.find("two");
        digitPositions["three"] = updatedLine.find("three");
        digitPositions["four"] = updatedLine.find("four");
        digitPositions["five"] = updatedLine.find("five");
        digitPositions["six"] = updatedLine.find("six");
        digitPositions["seven"] = updatedLine.find("seven");
        digitPositions["eight"] = updatedLine.find("eight");
        digitPositions["nine"] = updatedLine.find("nine");

        string targetDigit;
        long unsigned int index;
        if (leftToRight) {
            index = 10000; // assumption: no line is longer than 10000 chars    
            for (const auto pair : digitPositions) {
                if (pair.second < index && pair.second != string::npos) {
                    index = pair.second;
                    targetDigit = pair.first;
                }
            }
            if (index == 10000) {
                break;
            } 
        } else {
            index = string::npos;
            for (const auto pair: digitPositions) {
                if (pair.second != string::npos) {
                    if (index == string::npos) {
                        index = pair.second;
                        targetDigit = pair.first;
                    } else if (pair.second > index) {
                        index = pair.second;
                        targetDigit = pair.first;
                    }
                }
            }
            if (index == string::npos) {
                break;
            }
        }
        updatedLine.replace(index, targetDigit.length(), digits[targetDigit]);
    }

    return updatedLine;
}