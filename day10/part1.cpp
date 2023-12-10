#include "day10.hpp"

using namespace std;

void day10part1() {

    ifstream input("day10/input.txt");
    string line;

    Point start;
    vector<vector<char>> charGrid;
    vector<vector<int>> intGrid;
    int rowCount = 0;

    while (getline(input, line)) {
        int colCount = 0;
        vector<char> charRow;
        vector<int> intRow;
        for (char c : line) {
            if (c == 'S') {
                start.x = rowCount;
                start.y = colCount;
            }
            charRow.push_back(c);
            intRow.push_back(-1);
            colCount++;
        }
        charGrid.push_back(charRow);
        intGrid.push_back(intRow);
        rowCount++;
    }
    input.close();

    Point firstWay = { .x=start.x , .y=start.y-1};
    Point secondWay = { .x=start.x , .y=start.y+1};

    intGrid[start.x][start.y] = 0;
    intGrid[firstWay.x][firstWay.y] = 1;
    intGrid[secondWay.x][secondWay.y] = 1;
    int solution = 2; 

    bool xSame = firstWay.x == secondWay.x;
    bool ySame = firstWay.y == secondWay.y;
    while (!(xSame && ySame)) {
        firstWay = day10GetNextPoint(charGrid, intGrid, firstWay);
        secondWay = day10GetNextPoint(charGrid, intGrid, secondWay);
        intGrid[firstWay.x][firstWay.y] = solution;
        intGrid[secondWay.x][secondWay.y] = solution;
        solution++;
        xSame = firstWay.x == secondWay.x;
        ySame = firstWay.y == secondWay.y;
    }

    cout << "Day10 - Part1: The solution is " << solution-1 << endl;
}