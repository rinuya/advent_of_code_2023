#include "day10.hpp"

using namespace std;

void day10part2() {

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

    intGrid[start.x][start.y] = 1;
    intGrid[firstWay.x][firstWay.y] = 1;
    intGrid[secondWay.x][secondWay.y] = 1;

    bool xSame = firstWay.x == secondWay.x;
    bool ySame = firstWay.y == secondWay.y;
    while (!(xSame && ySame)) {
        firstWay = day10GetNextPoint(charGrid, intGrid, firstWay);
        secondWay = day10GetNextPoint(charGrid, intGrid, secondWay);
        intGrid[firstWay.x][firstWay.y] = 1;
        intGrid[secondWay.x][secondWay.y] = 1;
        xSame = firstWay.x == secondWay.x;
        ySame = firstWay.y == secondWay.y;
    }

    int result = 0;
    for (int r = 0; r < intGrid.size(); r++) {
        for (int c = 0; c < intGrid[0].size(); c++) {
            if (intGrid[r][c] != 1) {
                if (day10IsPointInside(charGrid, intGrid, {.x = r, .y = c})) result++;
            }
        }
    }
    cout << "Day10 - Part2: The solution is " << result << endl;
}