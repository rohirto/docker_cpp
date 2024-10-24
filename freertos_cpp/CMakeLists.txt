cmake_minimum_required(VERSION 3.16)

## Project Name ##
project(MyCppProject)

## C++ Standard ##
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

## Add FreeRTOS-Cpp Submodule ##
set(FREERTOS_CPP_PATH ${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS-Cpp)  # Adjust the path accordingly
add_subdirectory(${FREERTOS_CPP_PATH})

## Include Directories ##
include_directories(${FREERTOS_CPP_PATH}/include)

## Source Files ##
set(SOURCE_FILES
    main.cpp              # Your main C++ source file
    static_mem/static_mem_alloc.c  # Add your C source file here
)

## Header Files ##
set(HEADER_FILES
    static_mem/static_mem_alloc.h  # Add your C header file here
)

## Main Executable ##
add_executable(MyCppExecutable ${SOURCE_FILES} ${HEADER_FILES})

## Link FreeRTOS-Cpp ##
target_link_libraries(MyCppExecutable FreeRTOS-Cpp)

## Link Other Libraries If Needed ##
# target_link_libraries(MyCppExecutable other_library)

