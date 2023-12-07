#ifndef DAY7_HPP
#define DAY7_HPP

#include "../main.hpp"

using namespace std;

struct handAndBet
{
    int bet;
    vector<int> hand;
};

bool compareHands(const handAndBet& hand1, const handAndBet& hand2) {
    for (size_t i = 0; i < hand1.hand.size(); i++) {
        if (hand1.hand[i] < hand2.hand[i]) {
            return true;
        } else if (hand1.hand[i] > hand2.hand[i]) {
            return false;
        }
    }
    return false;
}


bool containsJoker(vector<int> hand) {
    for (int e: hand) {
        if (e == 1) {
            return true;
        }
    }
    return false;
}


int jokerCount(vector<int> hand) {
    int count = 0;
    for (int e: hand) {
        if (e == 1) {
            count++;
        }
    }
    return count;
}

#endif