#ifndef DAY10_HPP
#define DAY10_HPP

#include "../main.hpp"

using namespace std;

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