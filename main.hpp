#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype>
#include <unordered_map>
#include <algorithm>

std::vector<std::string> splitString(const std::string input, const char delimiter) {
    // Split a string based on a char and return a vec of the split up tokens
    std::vector<std::string> tokens;
    std::istringstream ss(input);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
};

void removeChar(std::string& input, const char toRemove) {
    input.erase(std::remove(input.begin(), input.end(), toRemove), input.end());
};

#endif