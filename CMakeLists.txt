cmake_minimum_required(VERSION 3.22)

#project name
project(PAOO)

# Specify the required C++ standard
if(CMAKE_VERSION GREATER "3.22")
    set(CMAKE_CXX_STANDARD 14) #we request C++14
    set(CMAKE_CXX_STANDARD_REQUIRED ON) #we request that CMake verifies the compiler
    set(CMAKE_CXX_EXTENSIONS OFF) #we request -std=c++14 in the compiler  flags instead of –std=gnu++14
else()
    if(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    endif()
endif()

#define the executable
add_executable(${PROJECT_NAME} main.cpp)