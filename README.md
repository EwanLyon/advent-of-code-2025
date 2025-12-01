# Advent of Code 2025 - C++ Setup

## Project Structure

```
AdventOfCode2025/
├── src/           # Source files (day01.cpp, day02.cpp, etc.)
├── include/       # Header files (aoc.h with common utilities)
├── inputs/        # Input files (day01.txt, day02.txt, etc.)
├── build/         # Build output directory
└── .vscode/       # VS Code configuration
```

## Adding New Days

1. Create `src/dayXX.cpp` (copy from day01.cpp template)
2. Create `inputs/dayXX.txt` with your puzzle input
3. Rebuild - CMake will automatically detect the new file

## Debugging

1. Open the day's `.cpp` file
2. Set breakpoints by clicking left of line numbers
3. Press `F5` to start debugging

## Common Utilities (include/aoc.h)

```cpp
// Read input
auto lines = aoc::read_lines("day01.txt");
auto content = aoc::read_file("day01.txt");

// Parse numbers from string
auto nums = aoc::parse_ints("1 2 -3 4");  // {1, 2, -3, 4}

// Split strings
auto parts = aoc::split("a,b,c", ',');    // {"a", "b", "c"}

// Grid helpers
aoc::DIRS4  // 4 directions: up, down, left, right
aoc::DIRS8  // 8 directions: including diagonals
aoc::in_bounds(row, col, rows, cols)  // boundary check
```

## Blog

### Day 0

This is my first Advent of Code ever. My goal is to have fun and learn C++ again. It's been a long time since I did C++ and it's something I *need* to be better in if I want to call myself a competent programmer. I aim to complete ALL challenges.

However, I will give an honest go at every challenge WITHOUT AI but that does not mean I will forever abstain from it. I want to learn to program C++ ideally. I am not in the business of learning how to setup toolchains and such right now. AI made the framework for this project and the `aoc.h` file. I plan to write complete each AoC challenge and then make a separate file where I have AI refine my solution. If I want to learn C++ I need someone/something to actually look over my shoulder and point out potential improvements.

If I am completely stuck then I will try to use AI to at least get me unstuck as little as possible. Perhaps I am just not seeing the forest through the trees or could be completely off the path.
