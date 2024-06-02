cmake_minimum_required(VERSION 3.27)
project(PVZ)

set(CMAKE_CXX_STANDARD 17)

add_executable(PVZ src/main.cpp
        include/PVZ/CoreMinimal.h)
