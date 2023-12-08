#include "day8.hpp"

using namespace std;

void day8part2() {

    ifstream input("day8/input.txt");
    string line;
    string directions;
    getline(input, directions);
    getline(input, line);
    map<string, day8Node> Map;
    vector<string> positions;

    while (getline(input, line)) {
        day8Node node;
        node.value = line.substr(0, 3);
        node.lft = line.substr(7, 3);
        node.rgt = line.substr(12, 3);
        Map[line.substr(0, 3)] = node;
        if (node.value[2]=='A') {
            positions.push_back(node.value);
        }
    }
    input.close();

    vector<long int> allLoopTimes;

    for (auto pos : positions) {
        string firstZ;
        vector<int> loopTimesToZ;
        int counter = 0;
        bool firstZFound = false;
        string currentPos = pos;
        string directionsCopy = directions;
        while (true) {
            while (counter == 0 || currentPos[2] != 'Z') {
                char firstEl = directionsCopy[0];
                if (firstEl == 'L') {
                    currentPos = Map[Map[currentPos].lft].value;
                } else {
                    currentPos = Map[Map[currentPos].rgt].value;
                }
                directionsCopy = directionsCopy.substr(1)+firstEl;
                counter++;
            }
            if (firstZFound == false) {
                firstZFound = true;
                firstZ = currentPos;
                loopTimesToZ.push_back(counter);
            } else if (firstZFound == true && currentPos != firstZ) {
                loopTimesToZ.push_back(counter);
            } else if (firstZFound == true && currentPos == firstZ) {
                // full loop
                loopTimesToZ.push_back(counter);
                break;
            }
            counter = 0;

        }
        allLoopTimes.push_back(loopTimesToZ[0]);
    }

    long int result = 1;
    for (auto time : allLoopTimes) {
        result = result * time / gcd(result, time);
    }

    cout << "Day8  - Part2: The solution is " << result << endl;
}

// if this doesnt work figure out for each individual starting point:
// 1. how long does it take for it to arrive at a point Z
// 2. how long does it take for that point to arrive to another point Z, and when does it start looping, so when is it coming back to Z?. We add a->z + z*X, where X is a loop length
// 3. Mathematically, just check about % for lengths. When they devide, we can assume we ariive then
