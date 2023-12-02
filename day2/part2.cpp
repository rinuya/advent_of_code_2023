#include "../main.hpp"

using namespace std;

void day2part2() {
    ifstream input("day2/input.txt");
    string line;
    unsigned int sum = 0;

    while (getline(input, line)) {
        line = line.substr(5);
        removeChar(line, ' ');
        vector<string> idAndDraws = splitString(line, ':');
        vector<string> draws = splitString(idAndDraws[1], ';');
        int red = 0, green = 0, blue = 0;
        
        for (auto draw : draws) {
            vector<string> drawVec = splitString(draw, ',');
            for (auto color : drawVec) {
                if (color[color.size() -1] == 'd') {
                    if (stoi(color.substr(0, color.length() - 3)) > red) {
                        red = stoi(color.substr(0, color.length() - 3));
                    }
                } else if (color[color.size() -1] == 'n') {
                    if (stoi(color.substr(0, color.length() - 5)) > green) {
                        green = stoi(color.substr(0, color.length() - 5));
                    }
                } else {
                    if (stoi(color.substr(0, color.length() - 4)) > blue) {
                        blue = stoi(color.substr(0, color.length() - 4));
                    }
                }
            }
        }
        sum += (red * green * blue);
    }
    input.close();
    
    cout << "Day2  - Part2: The solution is " << sum << endl;
}