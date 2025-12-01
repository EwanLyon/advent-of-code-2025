// Advent of Code 2025 - Day 01
#include "aoc.h"

int parseLockLine(const std::string &line)
{
    // E.g. L10 or R100

    // Get first character
    int positiveOrNegative = 1;
    if (line[0] == 'L')
    {
        positiveOrNegative = -1;
    }

    int number = std::stoi(line.substr(1));

    return positiveOrNegative * number;
}

int dialWrapping(int value, int mod)
{
    return ((value % mod) + mod) % mod;
}

// std::string fileName = "day01-testing.txt";
std::string fileName = "day01.txt";

constexpr int DIAL_SIZE = 100;
constexpr int START_POSITION = 50;

int main()
{
    // Read input - the input file should be at inputs/day01.txt
    auto lines = aoc::read_lines(fileName);

    // If running from project root, try alternate path
    if (lines.empty())
    {
        lines = aoc::read_lines("../../../inputs/" + fileName);
    }

    if (lines.empty())
    {
        std::cerr << "No input found! Place your input in inputs/day01.txt" << std::endl;
        return 1;
    }

    // Part 1
    long long part1 = 0;

    int dial = START_POSITION;
    for (const auto &line : lines)
    {
        int result = parseLockLine(line);

        dial += result;
        dial = dialWrapping(dial, DIAL_SIZE);

        // std::cout << "Dial: " << dial << " | Input: " << line << " (" << result << ")" << std::endl;

        if (dial == 0)
        {
            part1++;
        }
    }

    std::cout << "Part 1: " << part1 << std::endl;

    // Part 2
    long long part2 = 0;

    dial = START_POSITION; // Reset dial
    // int dialPrevious = 0;
    for (const auto &line : lines)
    {
        int result = parseLockLine(line);
        int magnitude = std::abs(result);

        int distanceToZero = 0;

        if (result > 0)
        {
            // Rotating right
            distanceToZero = DIAL_SIZE - dial;
        }
        else
        {
            // Rotating left
            distanceToZero = (dial == 0) ? DIAL_SIZE : dial;
        }

        if (magnitude >= distanceToZero)
        {
            part2 += 1 + (magnitude - distanceToZero) / DIAL_SIZE;
        }

        dial += result;
        dial = dialWrapping(dial, DIAL_SIZE);
    }

    std::cout << "Part 2: " << part2 << std::endl;

    return 0;
}
