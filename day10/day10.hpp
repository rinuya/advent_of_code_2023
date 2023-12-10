#ifndef DAY10_HPP
#define DAY10_HPP

#include "../main.hpp"

using namespace std;

bool day10IsPointInside(vector<vector<char>> grid, vector<vector<int>> intGrid, Point point) {
    int counter = 0;
    char horizontalSequence;
    for (int i = 0; i < point.y; i++) {
        if (intGrid[point.x][i] == 1) {
            switch (grid[point.x][i])
            {
            case '|':
                counter++;
                break;
            // only cases that could start a horizontal sequence
            case 'F':
                horizontalSequence = 'F';
                break;
            case 'L':
                horizontalSequence = 'L';
                break;
            // these cases mean we had an L or F already
            case '7':
                if (horizontalSequence == 'L') {
                    counter++;
                }
                horizontalSequence = NULL;
                break;
            case 'J':
                if (horizontalSequence == 'F') {
                    counter++;
                }
                horizontalSequence = NULL;
                break;
            default:
                break;
            }
        }
    }
    if (counter % 2 == 0) {
        return false;
    } else {
        return true;
    }
};


Point day10GetNextPoint(vector<vector<char>> grid, vector<vector<int>> intGrid, Point position) {
    switch (grid[position.x][position.y]) {
    case '-':
        if (intGrid[position.x][position.y-1] == -1) {
            return { position.x, position.y-1 };
        } else if (intGrid[position.x][position.y+1] == -1) {
            return { position.x, position.y+1 };
        }
        break;
    case '|':
        if (intGrid[position.x-1][position.y] == -1) {
            return { position.x-1, position.y };
        } else if (intGrid[position.x+1][position.y] == -1) {
            return { position.x+1, position.y };
        }
        break;
    case 'F':
        if (intGrid[position.x+1][position.y] == -1) {
            return { position.x+1, position.y };
        } else if (intGrid[position.x][position.y+1] == -1) {
            return { position.x, position.y+1 };
        }
        break;
    case '7':
        if (intGrid[position.x][position.y-1] == -1) {
            return { position.x, position.y-1 };
        } else if (intGrid[position.x+1][position.y] == -1) {
            return { position.x+1, position.y };
        }
        break;
    case 'J':
        if (intGrid[position.x-1][position.y] == -1) {
            return { position.x-1, position.y };
        } else if (intGrid[position.x][position.y-1] == -1) {
            return { position.x, position.y-1 };
        }
        break;
    case 'L':
        if (intGrid[position.x-1][position.y] == -1) {
            return { position.x-1, position.y };
        } else if (intGrid[position.x][position.y+1] == -1) {
            return { position.x, position.y+1 };
        }
        break;
    default:
        break;
    }
}

#endif