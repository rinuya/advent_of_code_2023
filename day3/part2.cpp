#include "../main.hpp"

using namespace std;

string getNumberFromGrid(vector<vector<char>> grid, int row, int col);

void day3part2() {

    ifstream input("day3/input.txt");
    string line;

    vector<vector<char>> grid;
    int sum = 0;

    while (getline(input, line)) {
        vector<char> row;
        for (char c : line) {
            row.push_back(c);
        }
        grid.push_back(row);
    }
    input.close();

    vector<string> bufferForNumbers;
    bool isGearValid = false;

    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[0].size(); col++) {
            char current_char = grid[row][col];
            if (current_char == '*') {

                if (isdigit(grid[row][col-1])) {
                    bufferForNumbers.push_back(getNumberFromGrid(grid, row, col-1));
                }
                if (isdigit(grid[row][col+1])) {
                    bufferForNumbers.push_back(getNumberFromGrid(grid, row, col+1));
                }
                vector<int> two = {row - 1, row + 1};
                for (int r : two ) {
                    if (r == row || r < 0) continue;
                    if (isdigit(grid[r][col-1]) && isdigit(grid[r][col]) && isdigit(grid[r][col+1])) {          // all digit
                        bufferForNumbers.push_back(getNumberFromGrid(grid, r, col));
                    } else if (!isdigit(grid[r][col-1]) && !isdigit(grid[r][col]) && isdigit(grid[r][col+1])) { // first and second not digit
                        bufferForNumbers.push_back(getNumberFromGrid(grid, r, col+1));
                    } else if (!isdigit(grid[r][col-1]) && isdigit(grid[r][col]) && !isdigit(grid[r][col+1])) { // first and last not digit
                        bufferForNumbers.push_back(getNumberFromGrid(grid, r, col));
                    } else if (isdigit(grid[r][col-1]) && !isdigit(grid[r][col]) && !isdigit(grid[r][col+1])) { // second and last not digit
                        bufferForNumbers.push_back(getNumberFromGrid(grid, r, col-1));
                    } else if (!isdigit(grid[r][col-1]) && isdigit(grid[r][col]) && isdigit(grid[r][col+1])) { // first not digit
                        bufferForNumbers.push_back(getNumberFromGrid(grid, r, col));
                    } else if (isdigit(grid[r][col-1]) && !isdigit(grid[r][col]) && isdigit(grid[r][col+1])) { // second not digit
                        bufferForNumbers.push_back(getNumberFromGrid(grid, r, col-1));
                        bufferForNumbers.push_back(getNumberFromGrid(grid, r, col+1));
                    } else if (isdigit(grid[r][col-1]) && isdigit(grid[r][col]) && !isdigit(grid[r][col+1])) { // last not digit
                        bufferForNumbers.push_back(getNumberFromGrid(grid, r, col));
                    }
                }
            }
            if (current_char != '*') {
                if (bufferForNumbers.size() == 2) {
                    sum += stoi(bufferForNumbers[0])*stoi(bufferForNumbers[1]);
                }
                bufferForNumbers.clear();
            }
        }
    }

    cout << "Day3  - Part2: The solution is " << sum << endl;
}

string getNumberFromGrid(vector<vector<char>> grid, int row, int col) {
    string base = string(1, grid[row][col]);
    int leftCount = 1;
    int rightCount = 1;
    while (isdigit(grid[row][col-leftCount])) {
        base = grid[row][col-leftCount] + base;
        leftCount++;
    };
    while (isdigit(grid[row][col+rightCount])) {
        base =  base + grid[row][col+rightCount];
        rightCount++;
    };
    return base;
}