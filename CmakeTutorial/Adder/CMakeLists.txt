# no need to specify version and all in subdirectories

# creating a custom library (src and headers)
add_library(Adder STATIC add.cpp)
target_include_directories(Adder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)