#include "../main.hpp"

using namespace std;

void day4part2() {

    ifstream input("day4/input.txt");
    string line;

    int sum = 0;
    int cardCounter = 0;
    unordered_map<string, int> wonCardCount;
    for (int i = 1; i <= 201; i++) {
        wonCardCount[to_string(i)] = 1;
    }

    while (getline(input, line)) {
        cardCounter++;
    
        int matches = 0;
        line = line.substr(9);
        vector<string> split = splitString(line, '|');
        vector<string> solutions = splitString(split[0], ' ');
        removeEntriesFromVec(solutions, string(""));

        vector<string> numbers = splitString(split[1], ' ');
        removeEntriesFromVec(numbers, string(""));

        for (auto num : numbers) {
            for (auto sol : solutions) {
                if (num == sol) {
                    matches++;
                    continue;
                }
            }
        }
        for (int c = 1; c <= wonCardCount[to_string(cardCounter)]; c++) {
            for (int i = 1; i <= matches; i++) {
                wonCardCount[to_string(cardCounter + i)]+=1;
            }
        }

    }
    for (auto entry : wonCardCount) {
        sum+=entry.second;
    }


    cout << "Day4  - Part2: The solution is " << sum << endl;
}