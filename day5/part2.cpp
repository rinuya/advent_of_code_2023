#include "../main.hpp"

using namespace std;

// probably fried my cpu solving this one

void day5part2() {

    ifstream input("day5/test_input.txt");
    string line;

    vector<long int> seedNumbers;
    vector<long int> soilNumbers;
    vector<long int> fertNumbers;
    vector<long int> waterNumbers;
    vector<long int> lightNumbers;
    vector<long int> tempNumbers;
    vector<long int> humidNumbers;
    vector<long int> locationNumbers;

    string inputHelper = "start";

    while (getline(input, line)) {
        // INPUT HELPERS
        if (line.empty()) continue;
        if (line == "seed-to-soil map:") {
            inputHelper = "seed";
            continue;
        } else if (line == "soil-to-fertilizer map:") {
            for (auto el : seedNumbers) {
                soilNumbers.push_back(el);
            }
            inputHelper = "soil";
            continue;
        } else if (line == "fertilizer-to-water map:") {
            for (auto el : soilNumbers) {
                fertNumbers.push_back(el);
            }
            inputHelper = "fertilizer";
            continue;
        } else if (line == "water-to-light map:") {
            for (auto el : fertNumbers) {
                waterNumbers.push_back(el);
            }
            inputHelper = "water";
            continue;
        } else if (line == "light-to-temperature map:") {
            for (auto el : waterNumbers) {
                lightNumbers.push_back(el);
            }
            inputHelper = "light";
            continue;
        } else if (line == "temperature-to-humidity map:") {
            for (auto el : lightNumbers) {
                tempNumbers.push_back(el);
            }
            inputHelper = "temperature";
            continue;
        } else if (line == "humidity-to-location map:") {
            for (auto el : tempNumbers) {
                humidNumbers.push_back(el);
            }
            inputHelper = "humidity";
            continue;
        } 

        // ACTUAL MAPPING
        if (inputHelper == "start") {
            vector<string> rawValues = splitString(line.substr(7), ' ');
            vector<long int> seedRanges = vecStrToLongInt(rawValues);
            for (int i = 0; i < seedRanges.size(); i+=2) {
                for (int j = seedRanges[i]; j < seedRanges[i] + seedRanges[i+1]; j++) {
                    seedNumbers.push_back(j);
                }
            }
            continue;
        } else {
            vector<string> rawValues = splitString(line, ' ');
            vector<long int> values = vecStrToLongInt(rawValues);

            if (inputHelper == "seed") {
                vector<long int> tmp;
                for (long int el : seedNumbers) {
                    if (el >= values[1] && el < values[1]+values[2]) {
                        soilNumbers.push_back(values[0]+el-values[1]);
                    } else {
                        tmp.push_back(el);
                    }
                }
                seedNumbers = tmp;
            } else if (inputHelper == "soil") {
                vector<long int> tmp;
                for (long int el : soilNumbers) {
                    if (el >= values[1] && el < values[1]+values[2]) {
                        fertNumbers.push_back(values[0]+el-values[1]);
                    } else {
                        tmp.push_back(el);
                    }
                }
                soilNumbers = tmp;
            } else if (inputHelper == "fertilizer") {
                vector<long int> tmp;
                for (long int el : fertNumbers) {
                    if (el >= values[1] && el < values[1]+values[2]) {
                        waterNumbers.push_back(values[0]+el-values[1]);
                    } else {
                        tmp.push_back(el);
                    }
                }
                fertNumbers = tmp;
            } else if (inputHelper == "water") {
                vector<long int> tmp;
                for (long int el : waterNumbers) {
                    if (el >= values[1] && el < values[1]+values[2]) {
                        lightNumbers.push_back(values[0]+el-values[1]);
                    } else {
                        tmp.push_back(el);
                    }
                }
                waterNumbers = tmp;
            } else if (inputHelper == "light") {
                vector<long int> tmp;
                for (long int el : lightNumbers) {
                    if (el >= values[1] && el < values[1]+values[2]) {
                        tempNumbers.push_back(values[0]+el-values[1]);
                    } else {
                        tmp.push_back(el);
                    }
                }
                lightNumbers = tmp;
            } else if (inputHelper == "temperature") {
                vector<long int> tmp;
                for (long int el : tempNumbers) {
                    if (el >= values[1] && el < values[1]+values[2]) {
                        humidNumbers.push_back(values[0]+el-values[1]);
                    } else {
                        tmp.push_back(el);
                    }
                }
                tempNumbers = tmp;
            } else if (inputHelper == "humidity") {
                vector<long int> tmp;
                for (long int el : humidNumbers) {
                    if (el >= values[1] && el < values[1]+values[2]) {
                        locationNumbers.push_back(values[0]+el-values[1]);
                    } else {
                        tmp.push_back(el);
                    }
                }
                humidNumbers = tmp;
            }
        }
    } 

    input.close();
    for (auto el : humidNumbers) {
        locationNumbers.push_back(el);
    }
    long int result = locationNumbers[0];
    for (long int el : locationNumbers) {
        if (el < result) {
            result = el;
        }
    }

    cout << "Day5  - Part2: The solution is " << result << endl;
}                