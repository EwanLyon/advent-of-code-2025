cmake_minimum_required(VERSION 3.16)
project(AdventOfCode2025 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directory for common headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Function to add a day's executable
function(add_day DAY_NUM)
    set(DAY_NAME "day${DAY_NUM}")
    set(SOURCE_FILE "${CMAKE_SOURCE_DIR}/src/${DAY_NAME}.cpp")
    
    if(EXISTS ${SOURCE_FILE})
        add_executable(${DAY_NAME} ${SOURCE_FILE})
        target_compile_features(${DAY_NAME} PRIVATE cxx_std_20)
        
        # Set output directory
        set_target_properties(${DAY_NAME} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )
        
        # Copy input file to build directory if it exists
        set(INPUT_FILE "${CMAKE_SOURCE_DIR}/inputs/${DAY_NAME}.txt")
        if(EXISTS ${INPUT_FILE})
            configure_file(${INPUT_FILE} "${CMAKE_BINARY_DIR}/bin/${DAY_NAME}.txt" COPYONLY)
        endif()
    endif()
endfunction()

# Add all days (1-25)
foreach(DAY RANGE 1 25)
    if(DAY LESS 10)
        add_day("0${DAY}")
    else()
        add_day("${DAY}")
    endif()
endforeach()

# Also support non-zero-padded day names (day1.cpp, day2.cpp, etc.)
foreach(DAY RANGE 1 25)
    set(DAY_NAME "day${DAY}")
    set(SOURCE_FILE "${CMAKE_SOURCE_DIR}/src/${DAY_NAME}.cpp")
    
    if(EXISTS ${SOURCE_FILE})
        add_executable(${DAY_NAME} ${SOURCE_FILE})
        target_compile_features(${DAY_NAME} PRIVATE cxx_std_20)
        set_target_properties(${DAY_NAME} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )
    endif()
endforeach()
