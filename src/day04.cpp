// Advent of Code 2025 - Day 04
#include "aoc.h"

// const std::string fileName = "day04-testing.txt";
const std::string fileName = "day04.txt";

bool isCharRoll(char c)
{
    return c == '@';
}

bool inBounds(int index, int arraySize)
{
    return index > 0 && index < arraySize;
}

bool isCharRollInPosition(int i, const std::string_view &allRolls)
{
    return inBounds(i, allRolls.length()) && isCharRoll(allRolls[i]);
}

long long numberOfAvailableRollsPart1(const std::string_view &allRolls, int lineWidth)
{
    long long availableRolls = 0;

    int stringLength = allRolls.length();

    // std::string debugString = "";

    for (size_t i = 0; i < stringLength; i++)
    {
        bool isRoll = isCharRoll(allRolls[i]);

        if (!isRoll)
        {
            // debugString += '.';

            // Debugging
            // if ((i + 1) % lineWidth == 0)
            // {
            //     // std::cout << allRolls.substr(i - lineWidth, lineWidth) << std::endl;
            //     std::cout << debugString << std::endl;
            //     debugString = "";
            // }
            continue;
        }

        int rollsNearby = 0;

        bool isOnVeryLeft = i % lineWidth == 0;
        bool isOnVeryRight = (i + 1) % lineWidth == 0;

        // Check left
        if (!isOnVeryLeft && isCharRollInPosition(i - 1, allRolls))
        {
            rollsNearby++;
        }

        // Check right
        if (!isOnVeryRight && isCharRollInPosition(i + 1, allRolls))
        {
            rollsNearby++;
        }

        // Check top
        if (isCharRollInPosition(i - lineWidth, allRolls))
        {
            rollsNearby++;
        }

        // Check bottom
        if (isCharRollInPosition(i + lineWidth, allRolls))
        {
            rollsNearby++;
        }

        // Check top left
        if (!isOnVeryLeft && isCharRollInPosition(i - lineWidth - 1, allRolls))
        {
            rollsNearby++;
        }

        // Check top right
        if (!isOnVeryRight && isCharRollInPosition(i - lineWidth + 1, allRolls))
        {
            rollsNearby++;
        }

        // Check bottom left
        if (!isOnVeryLeft && isCharRollInPosition(i + lineWidth - 1, allRolls))
        {
            rollsNearby++;
        }

        // Check bottom right
        if (!isOnVeryRight && isCharRollInPosition(i + lineWidth + 1, allRolls))
        {
            rollsNearby++;
        }

        if (rollsNearby < 4)
        {
            // debugString += 'x';
            availableRolls++;
        }
        else
        {
            // debugString += '@';
        }

        // Debugging
        // if ((i + 1) % lineWidth == 0)
        // {
        //     // std::cout << allRolls.substr(i - lineWidth, lineWidth) << std::endl;
        //     std::cout << debugString << std::endl;
        //     debugString = "";
        // }
    }

    return availableRolls;
}

long long numberOfAvailableRollsPart2(std::string &allRolls, int lineWidth)
{
    long long availableRolls = 0;

    std::vector<int> removedRollIndexes;

    int stringLength = allRolls.length();

    // std::string debugString = "";

    for (size_t i = 0; i < stringLength; i++)
    {
        bool isRoll = isCharRoll(allRolls[i]);

        if (!isRoll)
        {
            // debugString += '.';

            // Debugging
            // if ((i + 1) % lineWidth == 0)
            // {
            //     // std::cout << allRolls.substr(i - lineWidth, lineWidth) << std::endl;
            //     std::cout << debugString << std::endl;
            //     debugString = "";
            // }
            continue;
        }

        int rollsNearby = 0;

        bool isOnVeryLeft = i % lineWidth == 0;
        bool isOnVeryRight = (i + 1) % lineWidth == 0;

        // Check left
        if (!isOnVeryLeft && isCharRollInPosition(i - 1, allRolls))
        {
            rollsNearby++;
        }

        // Check right
        if (!isOnVeryRight && isCharRollInPosition(i + 1, allRolls))
        {
            rollsNearby++;
        }

        // Check top
        if (isCharRollInPosition(i - lineWidth, allRolls))
        {
            rollsNearby++;
        }

        // Check bottom
        if (isCharRollInPosition(i + lineWidth, allRolls))
        {
            rollsNearby++;
        }

        // Check top left
        if (!isOnVeryLeft && isCharRollInPosition(i - lineWidth - 1, allRolls))
        {
            rollsNearby++;
        }

        // Check top right
        if (!isOnVeryRight && isCharRollInPosition(i - lineWidth + 1, allRolls))
        {
            rollsNearby++;
        }

        // Check bottom left
        if (!isOnVeryLeft && isCharRollInPosition(i + lineWidth - 1, allRolls))
        {
            rollsNearby++;
        }

        // Check bottom right
        if (!isOnVeryRight && isCharRollInPosition(i + lineWidth + 1, allRolls))
        {
            rollsNearby++;
        }

        if (rollsNearby < 4)
        {
            // debugString += 'x';
            availableRolls++;
            removedRollIndexes.push_back(i);
        }
        else
        {
            // debugString += '@';
        }

        // Debugging
        // if ((i + 1) % lineWidth == 0)
        // {
        //     // std::cout << allRolls.substr(i - lineWidth, lineWidth) << std::endl;
        //     std::cout << debugString << std::endl;
        //     debugString = "";
        // }
    }

    for(const int& index : removedRollIndexes)
    {
        allRolls[index] = '.';
    }

    return availableRolls;
}


int getFirstLineLength(std::string filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 0;
    }
    std::string line;
    if (std::getline(file, line))
    {
        return line.length();
    }

    return 0;
}

int main()
{
    auto text = aoc::read_file(fileName);
    int lineLength = getFirstLineLength(fileName);

    // If running from project root, try alternate path
    if (text.empty())
    {
        text = aoc::read_file("../" + fileName);
        lineLength = getFirstLineLength("../" + fileName);
    }

    if (text.empty())
    {
        std::cerr << "No input found! Place your input in inputs/day04.txt" << std::endl;
        return 1;
    }

    // Part 1
    long long part1 = 0;

    text.erase(std::remove(text.begin(), text.end(), '\n'), text.cend());

    std::string_view allLines(text);

    part1 = numberOfAvailableRollsPart1(allLines, lineLength);

    std::cout << "Part 1: " << part1 << std::endl;

    // Part 2
    long long part2 = 0;

    int removedRolls = 0;
    do
    {
        removedRolls = numberOfAvailableRollsPart2(text, lineLength);
        part2 += removedRolls;
    } while (removedRolls > 0);
    
    std::cout << "Part 2: " << part2 << std::endl;

    return 0;
}
