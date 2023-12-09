#include "../main.hpp"

using namespace std;

void day9part2() {

    ifstream input("day9/input.txt");
    string line;

    int sum = 0;

    while (getline(input, line)) {
        int depth = 0;
        vector<string> rawReadings = splitString(line, ' ');
        vector<int> readings = vecStrToInt(rawReadings);
        map<int, vector<int>> differences;
        differences[0] = readings;
        while (!everyEntryEquals(differences[depth], 0)) {
            vector<int> currentDiff;
            for (int i = 0; i < differences[depth].size()-1; i++) {
                currentDiff.push_back(differences[depth][i+1]-differences[depth][i]);
            }
            depth++;
            differences[depth] = currentDiff;
        }
        depth--;
        while (depth != 0) {
            differences[depth].insert(differences[depth].begin() ,differences[depth][0]-differences[depth+1][0]);
            depth--;
        }
        sum += differences[depth][0]-differences[depth+1][0];
    }
    input.close();

    cout << "Day9  - Part2: The solution is " << sum << endl;
}