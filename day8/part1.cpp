#include "day8.hpp"

using namespace std;

void day8part1() {

    ifstream input("day8/input.txt");
    string line;
    string directions;
    getline(input, directions);
    getline(input, line);
    map<string, day8Node> Map;

    while (getline(input, line)) {
        day8Node node;
        node.value = line.substr(0, 3);
        node.lft = line.substr(7, 3);
        node.rgt = line.substr(12, 3);
        Map[line.substr(0, 3)] = node;
    }
    input.close();

    int counter = 0;
    string currentEl = "AAA";
    for (int i = 0; i <= directions.size(); i++) {
        if (currentEl == "ZZZ") break;
        if (i == directions.size()) i = 0;
        if (directions[i] == 'L') {
            currentEl = Map[Map[currentEl].lft].value;
        } else {
            currentEl = Map[Map[currentEl].rgt].value;
        }
        counter++;
    }

    cout << "Day8  - Part1: The solution is " << counter << endl;
}