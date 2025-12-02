// Advent of Code 2025 - Day 02
#include "aoc.h"
#include <tuple>
#include <vector>
#include <string>
#include <sstream>
#include <string_view>

// std::string fileName = "day02-testing.txt";
std::string fileName = "day02.txt";

std::tuple<long long, long long> parseBounds(const std::string& boundsString)
{
    // e.g. 00000-99999
    std::stringstream testString(boundsString);
    std::string segment;
    std::vector<long long> segmentList;

    while (std::getline(testString, segment, '-'))
    {
        segmentList.push_back(std::stoll(segment));
    }

    return {segmentList[0], segmentList[1]};
}

// LUT of Factors (handles digits from 10^0 to 10^15) then employ the function just in case
std::vector<std::vector<int>> factorsLUT = {
    {},                  // 0
    {1},                 // 1
    {1, 2},              // 2
    {1, 3},              // 3
    {1, 2, 4},           // 4
    {1, 5},              // 5
    {1, 2, 3, 6},        // 6
    {1, 7},              // 7
    {1, 2, 4, 8},        // 8
    {1, 3, 9},           // 9
    {1, 2, 5, 10},       // 10
    {1, 11},             // 11
    {1, 2, 3, 4, 6, 12}, // 12
    {1, 13},             // 13
    {1, 2, 7, 14},       // 14
    {1, 3, 5, 15},       // 15
};

std::vector<int> calculateFactors(int n)
{
    std::vector<int> factors;

    for (size_t i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(n);
        }
    }

    return factors;
}

std::vector<int> getFactors(long long number)
{
    return number < factorsLUT.size() ? factorsLUT[number] : calculateFactors(number);
}

bool doNumbersRepeatPart1(long long number)
{
    // Convert number back into string lol
    std::string numberString = std::to_string(number);

    int stringLength = numberString.length();

    // Part 1
    if (stringLength % 2 != 0)
    {
        return false;
    }

    // Check each possible combination of substrings
    bool doesNumberHaveRepetitions = true;

    int substringLength = stringLength / 2;

    std::string testingSubstring = numberString.substr(0, substringLength);

    doesNumberHaveRepetitions = true;

    // Check the string
    for (size_t i = substringLength; i < stringLength; i += substringLength)
    {
        std::string checkingSubstring = numberString.substr(i, substringLength);

        if (testingSubstring != checkingSubstring)
        {
            doesNumberHaveRepetitions = false;
            break;
        }
    }

    return doesNumberHaveRepetitions;
}

bool doNumbersRepeatPart2(long long number)
{
    // Convert number back into string lol
    std::string numberString = std::to_string(number);
    std::string_view numberStringView = numberString;

    int stringLength = numberString.length();

    // Get factors
    std::vector<int> factors = getFactors(stringLength);

    if (factors.size() <= 1) return false;
    factors.pop_back(); // We are looking for repeats so we can skip the whole number factor which is set to the last number in the vector

    // Check each possible combination of substrings
    for (const auto &substringLength : factors)
    {
        std::string_view testingSubstring = numberStringView.substr(0, substringLength);

        bool doesNumberHaveRepetitions = true;

        // Check the string
        for (size_t i = substringLength; i < stringLength; i += substringLength)
        {
            std::string_view checkingSubstring = numberStringView.substr(i, substringLength);

            if (testingSubstring != checkingSubstring)
            {
                doesNumberHaveRepetitions = false;
                break;
            }
        }

        if (doesNumberHaveRepetitions) return true;
    }

    return false;
}

std::vector<long long> repeatingValues(long long lowerBounds, long long upperBounds, bool part2 = false) // This wouldn't exist in reality
{
    std::vector<long long> repeatedValue;

    if (lowerBounds < 0 || upperBounds < 0)
    {
        // Something's gone wrong here
        return repeatedValue;
    }

    auto checkerFunction = part2 ? doNumbersRepeatPart2 : doNumbersRepeatPart1;

    for (long long i = lowerBounds; i <= upperBounds; i++)
    {
        if (checkerFunction(i))
        {
            std::cout << "The number: " << i << " does repeat!" << std::endl;
            repeatedValue.push_back(i);
        }
    }

    return repeatedValue;
}

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
        std::cerr << "No input found! Place your input in inputs/day02.txt" << std::endl;
        return 1;
    }

    // Part 1
    long long part1 = 0;

    // Using the aoc.h ai version which is the exact same I just implemented above lol. Keeping the one above because learning!
    auto allBoundsStrings = aoc::split(lines[0], ',');

    // for (const auto &boundsString : allBoundsStrings)
    // {
    //     auto [lowerBound, upperBound] = parseBounds(boundsString);

    //     auto repeatedValues = repeatingValues(lowerBound, upperBound);

    //     for (const auto &value : repeatedValues)
    //     {
    //         part1 += value;
    //     }
    // }

    // std::cout << "Part 1: " << part1 << std::endl;

    // Part 2
    long long part2 = 0;

    for (const auto &boundsString : allBoundsStrings)
    {
        auto [lowerBound, upperBound] = parseBounds(boundsString);

        auto repeatedValues = repeatingValues(lowerBound, upperBound, true);

        for (const auto &value : repeatedValues)
        {
            part2 += value;
        }
    }

    std::cout << "Part 2: " << part2 << std::endl;

    return 0;
}
