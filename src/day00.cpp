// Advent of Code 2025 - Day 00
#include "aoc.h"

// const std::string fileName = "day00-testing.txt";
const std::string fileName = "day00.txt";

int main()
{
    auto lines = aoc::read_lines(fileName);

    // If running from project root, try alternate path
    if (lines.empty())
    {
        lines = aoc::read_lines("../../../inputs/" + fileName);
    }

    if (lines.empty())
    {
        std::cerr << "No input found! Place your input in inputs/day00.txt" << std::endl;
        return 1;
    }

    // Part 1
    long long part1 = 0;

    for (const auto &line : lines)
    {
    }

    std::cout << "Part 1: " << part1 << std::endl;

    // Part 2
    long long part2 = 0;

    for (const auto &line : lines)
    {
    }

    std::cout << "Part 2: " << part2 << std::endl;

    return 0;
}
