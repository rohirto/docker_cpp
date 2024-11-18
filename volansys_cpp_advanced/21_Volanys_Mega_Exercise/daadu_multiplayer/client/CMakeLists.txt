cmake_minimum_required(VERSION 3.16)

## Project Name ##
project(daadu_client)

## C++ Standard ##
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add nlohmann_json via FetchContent
include(FetchContent)

# Use the nlohmann_json GitHub repository to fetch the header-only library
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3  # You can specify the version here
)

# Make sure to update the library
FetchContent_MakeAvailable(nlohmann_json)


## Include Directories ##
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

## Source Files ##
file(GLOB SOURCE_FILES
    src/*.cpp              # Your main C++ source file(s)
)

## Header Files ##
file(GLOB HEADER_FILES
    inc/*.h  # Add your h header file here
)

## Main Executable ##
add_executable(DaaduClientExecutable ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(DaaduClientExecutable PRIVATE nlohmann_json::nlohmann_json)

