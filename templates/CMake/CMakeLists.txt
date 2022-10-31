# version of cmake
cmake_minimum_required(VERSION 3.24.2)

# setup c++ version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project name
project(PROJECT_NAME VERSION 1.0)

# specify name of the executible file and the source files (easier way)
file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(out main.cpp ${SOURCES})

target_include_directories(out PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# For adding sub-directory (library) (need to have CMakeLists.txt in the subdirectory)
# add_subdirectory(LibraryName)
# target_link_libraries(out PUBLIC LibraryName)