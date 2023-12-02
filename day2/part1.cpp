#include "../main.hpp"

const unsigned int MAX_RED = 12;
const unsigned int MAX_GREEN = 13;
const unsigned int MAX_BLUE = 14;

using namespace std;

void day2part1() {
    ifstream input("day2/input.txt");
    string line;
    unsigned int sum = 0;

    while (getline(input, line)) {
        line = line.substr(5);
        removeChar(line, ' ');
        bool invalidRound = false;
        vector<string> idAndDraws = splitString(line, ':');
        unsigned int id = stoi(idAndDraws[0]);
        vector<string> draws = splitString(idAndDraws[1], ';');
        for (auto draw : draws) {
            vector<string> drawVec = splitString(draw, ',');
            for (auto color : drawVec) {
                if (color[color.size() -1] == 'd') {
                    if (stoi(color.substr(0, color.length() - 3)) > MAX_RED) {
                        invalidRound = true;
                    }
                } else if (color[color.size() -1] == 'n') {
                    if (stoi(color.substr(0, color.length() - 5)) > MAX_GREEN) {
                        invalidRound = true;
                    }
                } else {
                    if (stoi(color.substr(0, color.length() - 4)) > MAX_BLUE) {
                        invalidRound = true;
                    }
                }
            }
        }
        if (!invalidRound) {
            sum += id;
        }
    }
    input.close();
    
    cout << "Day2  - Part1: The solution is " << sum << endl;
}