#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <regex>

namespace aoc {

// Read entire file as a string
inline std::string read_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// Read file as vector of lines
inline std::vector<std::string> read_lines(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return lines;
    }
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}

// Split string by delimiter
inline std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Split string by string delimiter
inline std::vector<std::string> split(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = str.find(delimiter);
    while (end != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
        end = str.find(delimiter, start);
    }
    tokens.push_back(str.substr(start));
    return tokens;
}

// Trim whitespace from both ends
inline std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}

// Parse integers from a string
inline std::vector<int> parse_ints(const std::string& str) {
    std::vector<int> nums;
    std::regex re("-?\\d+");
    auto begin = std::sregex_iterator(str.begin(), str.end(), re);
    auto end = std::sregex_iterator();
    for (auto it = begin; it != end; ++it) {
        nums.push_back(std::stoi(it->str()));
    }
    return nums;
}

// Parse long longs from a string
inline std::vector<long long> parse_longs(const std::string& str) {
    std::vector<long long> nums;
    std::regex re("-?\\d+");
    auto begin = std::sregex_iterator(str.begin(), str.end(), re);
    auto end = std::sregex_iterator();
    for (auto it = begin; it != end; ++it) {
        nums.push_back(std::stoll(it->str()));
    }
    return nums;
}

// Common 2D grid directions (up, down, left, right)
const std::vector<std::pair<int, int>> DIRS4 = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// 8 directions including diagonals
const std::vector<std::pair<int, int>> DIRS8 = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1},
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
};

// Check if position is within grid bounds
inline bool in_bounds(int row, int col, int rows, int cols) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

} // namespace aoc
