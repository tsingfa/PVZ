cmake_minimum_required(VERSION 3.27)
project(PVZ)

set(CMAKE_CXX_STANDARD 17)

# 递归包含所有 include 目录下的头文件
file(GLOB_RECURSE INCLUDES "${CMAKE_SOURCE_DIR}/include/*.h" "${CMAKE_SOURCE_DIR}/include/*.hpp")
include_directories(${CMAKE_SOURCE_DIR}/include)

# 递归搜索 src 目录及其所有子目录中的所有源文件
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.cxx" "src/*.cc")

# 添加可执行文件
add_executable(PVZ ${SOURCES} ${INCLUDES}
)
