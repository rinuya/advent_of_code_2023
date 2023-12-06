#include "../main.hpp"

using namespace std;

void day6part2() {

    ifstream input("day6/input.txt");
    string line;
    string timeString;
    string distanceString;
    vector<int> results;

    getline(input, line);
    line = line.substr(10);
    vector<string> times = splitString(line, ' ');
    removeEntriesFromVec(times, string(""));
    for (auto t : times) timeString+=t;

    getline(input, line);
    line = line.substr(10);
    vector<string> distances = splitString(line, ' ');
    removeEntriesFromVec(distances, string(""));
    for (auto d : distances) distanceString+=d;

    input.close();

    int winPossibilities = 0;
    long int time = stol(timeString);
    long int distance = stol(distanceString);
    for (long int t = 1; t < time; t++) {
        long int remainingTime = time-t;
        long int distancePossible = remainingTime * t;
        if (distancePossible > distance) {
            winPossibilities++;
        }
    }
 
    cout << "Day6  - Part2: The solution is " << winPossibilities << endl;
}