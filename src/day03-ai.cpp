// Advent of Code 2025 - Day 03 Template
#include "aoc.h"

// std::string fileName = "day03-testing.txt";
std::string fileName = "day03.txt";

int largestPossibleNumberPart1(const std::vector<int> &numbers)
{
    int largestNumber = -1;
    int secondLargestNumber = -1;

    for (size_t i = 0; i < numbers.size(); i++)
    {
        int currentNumber = numbers[i];
        if (currentNumber > largestNumber)
        {
            // Make sure we aren't at the end
            if (i != numbers.size() - 1)
            {
                largestNumber = currentNumber;
                secondLargestNumber = -1;
                continue;
            }
        }

        if (currentNumber > secondLargestNumber)
        {
            secondLargestNumber = currentNumber;
        }
    }

    return largestNumber * 10 + secondLargestNumber;
}

long long largestPossibleNumberPart2(std::vector<int> numbers, int size)
{
    std::vector<int> largestNumber(size, 0);

    for (size_t i = 0; i < numbers.size(); i++)
    {
        int currentNumber = numbers[i];

        int a = numbers.size() - i - size; // idk what to call this number
        int startCheckingIndex = a >= 0 ? 0 : std::abs(a);

        for (size_t j = startCheckingIndex; j < size; j++)
        {
            if (currentNumber > largestNumber[j])
            {
                largestNumber[j] = currentNumber;
                // Clear all remaining numbers
                for (size_t k = j + 1; k < size; k++)
                {
                    largestNumber[k] = 0;
                }

                break;
            }
        }
    }

    long long result = 0;
    // Change: Use accumulation instead of std::pow
    for (int digit : largestNumber)
    {
        result = (result * 10) + digit;
    }

    return result;
}

std::vector<int> stringToNumbers(const std::string &line)
{
    std::vector<int> numbers;

    for (auto character : line)
    {
        numbers.push_back(character - '0'); // The conversion from char to an int is so dumb
    }

    return numbers;
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
        std::cerr << "No input found! Place your input in inputs/day03.txt" << std::endl;
        return 1;
    }

    // Part 1
    long long part1 = 0;

    for (const auto &line : lines)
    {
        std::vector<int> numbers = stringToNumbers(line);
        int largestNumber = largestPossibleNumberPart1(numbers);
        std::cout << "Line: " << line << " | " << largestNumber << std::endl;
        part1 += largestNumber;
    }

    std::cout << "Part 1: " << part1 << std::endl;

    // Part 2
    long long part2 = 0;

    for (const auto &line : lines)
    {
        std::vector<int> numbers = stringToNumbers(line);
        long long largestNumber = largestPossibleNumberPart2(numbers, 12);
        // std::cout << "Line: " << line << " | " << largestNumber << std::endl;
        part2 += largestNumber;
    }

    std::cout << "Part 2: " << part2 << std::endl;

    return 0;
}
