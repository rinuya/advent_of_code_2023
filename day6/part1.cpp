#include "../main.hpp"

using namespace std;

void day6part1() {

    ifstream input("day6/input.txt");
    string line;
    vector<string> times;
    vector<string> distances;
    vector<int> results;

    getline(input, line);
    line = line.substr(10);
    times = splitString(line, ' ');
    removeEntriesFromVec(times, string(""));

    getline(input, line);
    line = line.substr(10);
    distances = splitString(line, ' ');
    removeEntriesFromVec(distances, string(""));

    input.close();

    for (int i = 0; i< times.size(); i++) {
        int winPossibilities = 0;
        int time = stoi(times[i]);
        int distance = stoi(distances[i]);
        for (int t = 1; t < time; t++) {
            int remainingTime = time-t;
            int distancePossible = remainingTime * t;
            if (distancePossible > distance) {
                winPossibilities++;
            }
        }
        results.push_back(winPossibilities);
    }

    int result = 1;
    for (auto r : results) {
        result*=r;
    }

    cout << "Day6  - Part1: The solution is " << result << endl;
}