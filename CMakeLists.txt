cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

project(order_book LANGUAGES CXX)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test) 
add_subdirectory(benchmark) 
