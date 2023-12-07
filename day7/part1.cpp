#include "../main.hpp"

using namespace std;

struct handAndBet
{
    int bet;
    vector<int> hand;
    map<int, int> handMap;
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

void day7part1() {

    ifstream input("day7/input.txt");
    string line;
    vector<handAndBet> fives;
    vector<handAndBet> fours;
    vector<handAndBet> fulls;
    vector<handAndBet> threes;
    vector<handAndBet> twopairs;
    vector<handAndBet> pairs;
    vector<handAndBet> highCards;

    while (getline(input, line)) {

        handAndBet thisHand;
        vector<string> l = splitString(line, ' ');
        map<int, int> handMap;
        vector<int> hand;

        thisHand.bet = stoi(l[1]);

        for (char c : l[0]) {
            string ch = "";
            if (c == 'T') {
                ch="10";
            } else if (c == 'J') {
                ch="11";
            } else if (c == 'Q') {
                ch="12";
            } else if (c == 'K') {
                ch="13";
            } else if (c == 'A') {
                ch="14";
            } else {
                ch+=c;
            }
            if (handMap[stoi(ch)]) {
                handMap[stoi(ch)]+=1;
            } else {
                handMap[stoi(ch)] = 1;
            }
            hand.push_back(stoi(ch));
        }
        thisHand.hand = hand;
        thisHand.handMap = handMap;

        bool inserted = false;

        int pairAmt = 0;
        int tripAmount = 0;
        for (auto el : handMap) {
            if (el.second == 5) {
                fives.push_back(thisHand);
                inserted = true;
                break;
            } 
            if (el.second == 4) {
                fours.push_back(thisHand);
                inserted = true;
                break;
            }
            if (el.second == 3) {
                tripAmount++;
            }
            if (el.second == 2) {
                pairAmt++;
            }
        }
        if (inserted == false) {
            if (tripAmount == 1 && pairAmt == 1) {
                fulls.push_back(thisHand);
            } else if (pairAmt == 2) {
                twopairs.push_back(thisHand);
            } else if (tripAmount == 1) {
                threes.push_back(thisHand);
            } else if (pairAmt == 1) {
                pairs.push_back(thisHand);
            } else {
                highCards.push_back(thisHand);
            }
        }
    };
    input.close();

    sort(fives.begin(), fives.end(), compareHands);
    sort(fours.begin(), fours.end(), compareHands);
    sort(fulls.begin(), fulls.end(), compareHands);
    sort(threes.begin(), threes.end(), compareHands);
    sort(twopairs.begin(), twopairs.end(), compareHands);
    sort(pairs.begin(), pairs.end(), compareHands);
    sort(highCards.begin(), highCards.end(), compareHands);

    int result = 0;

    int rank = 0; 
    for (auto el : highCards) {
        rank++;
        result += el.bet * rank;
    }
    for (auto el : pairs) {
        rank++;
        result += el.bet * rank;
    }
    for (auto el : twopairs) {
        rank++;
        result += el.bet * rank;
    }
    for (auto el : threes) {
        rank++;
        result += el.bet * rank;
    }
    for (auto el : fulls) {
        rank++;
        result += el.bet * rank;
    }
    for (auto el : fours) {
        rank++;
        result += el.bet * rank;
    }
    for (auto el : fives) {
        rank++;
        result += el.bet * rank;
    }

    cout << "Day7  - Part1: The solution is " << result << endl;
}

