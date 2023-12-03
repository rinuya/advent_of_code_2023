#include "../main.hpp"

using namespace std;

void day3part1() {

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

    string bufferForNumber = "";
    bool isNumberValid = false;

    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[0].size(); col++) {
            char current_char = grid[row][col];
            if (isdigit(current_char)) {
                bufferForNumber += current_char;
                // check everything around it to see if it's valid
                for (int i = row-1; i <= row+1; i++) {
                    if (i < 0 || i >= grid.size()) {
                        continue;
                    }
                    for (int j = col -1; j <= col +1; j++) {
                        if (j < 0 || j >= grid[0].size()) {
                            continue;
                        }
                        char elementAround = grid[i][j];
                        if (elementAround != '.' && !isdigit(elementAround)) {
                            isNumberValid = true;
                        }
                    }
                }
            }
            if (!isdigit(current_char) && bufferForNumber != "") {
                if (isNumberValid) {
                    sum += stoi(bufferForNumber);
                }
                bufferForNumber = "";
                isNumberValid = false;
            }

        }
    }

    cout << "Day3  - Part1: The solution is " << sum << endl;
}