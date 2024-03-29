cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src/proto)

# Create an executable named "my_app" using the specified source files.
add_executable(my_app src/main.cpp)

# Define private compile definitions for the target "my_app".
# In this case, set the C++ standard to C++11.
target_compile_definitions(my_app PRIVATE cxx_std_20)

# Link the "my_app" target with my protobuf lib.
# this imports the dependencies
target_link_libraries(my_app PUBLIC myproto)

