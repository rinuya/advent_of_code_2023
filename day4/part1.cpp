#include "../main.hpp"

using namespace std;

void day4part1() {

    ifstream input("day4/input.txt");
    string line;

    int sum = 0;

    while (getline(input, line)) {
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
        if (matches > 0) {
            int addToSum = 1;
            matches--;
            while (matches != 0) {
                addToSum*=2;
                matches--;
            }
            sum+=addToSum;
        }
    }
    input.close();

   

    cout << "Day4 - Part1: The solution is " << sum << endl;
}