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

### Day 1

#### Initial Thoughts

WE HAVE TO DECORATE THE NORTH POLE IN 12 DAYS???!?!?! Ok seems like we need to open a safe. So we have a dial we have to crack, Lx, x being the number of notches and Rx, x being the number of notches. It's a loop between 0 - 99 so we'll be using modulus. However the TRUE password is the time the dial is left point at 0 after any rotation the sequence.

#### Part 1 Done

Well that took longer than I'd like to admit. I've gotten so used to console logging that it's actually really annoying to do it in C++ so I've resorted to actually reading my code closer and running it in my head better before just running it hoping for the best. The modulo bit stuffed me up a bit. I remember from doing these sort of wrapping things in games that it's really annoying the negative number modulo doesn't operate how I would want to use it. Got'er done in the end :)

#### Part 2 Done

This one was really frustrating for me. I could imagine it so clearly but I was obviously missing *SOMETHING* maths related. I thought I had covered the bases of both it landing on 0 by checking if it was 0, checking the whole wrapping if the number of turns obviously meant we would go past 0 and checking if we had passed 0 in the mean time.

#### AI Review

##### Part 1

It suggested I make constants for the dial size and start position which makes sense, just didn't know or assumed the compiler might optimise it out for me. It suggested passing in the reference to the string in the parseLockLine function which makes sense to avoid a copy. This is something I hope to understand better when it comes to references vs pointers vs copies, etc.

##### Part 2

Yeah it isn't happy with my brute force approach. It actually suggested a different approach which was to determine the distance to 0 and see if our change is greater than that distance and also of course find how many time we would wrap around regardless (using just an integer division).
