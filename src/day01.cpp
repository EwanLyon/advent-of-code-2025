// Advent of Code 2025 - Day 01
#include "aoc.h"

int main() {
    // Read input - the input file should be at inputs/day01.txt
    auto lines = aoc::read_lines("day01.txt");
    
    // If running from project root, try alternate path
    if (lines.empty()) {
        lines = aoc::read_lines("../../../inputs/day01.txt");
    }
    
    if (lines.empty()) {
        std::cerr << "No input found! Place your input in inputs/day01.txt" << std::endl;
        return 1;
    }

    // Part 1
    long long part1 = 0;
    
    // TODO: Implement Part 1 solution
    for (const auto& line : lines) {
        // Process each line
        (void)line; // Remove this when implementing
    }
    
    std::cout << "Part 1: " << part1 << std::endl;

    // Part 2
    long long part2 = 0;
    
    // TODO: Implement Part 2 solution
    
    std::cout << "Part 2: " << part2 << std::endl;

    return 0;
}
