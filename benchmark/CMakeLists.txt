cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

project(benchmarks LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
  google_benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG d572f4777349d43653b21d6c2fc63020ab326db2
)
FetchContent_MakeAvailable(google_benchmark)

add_executable(benchmarks main.cpp "benchmark.h" "benchmark.cpp")
target_link_libraries(benchmarks order_book_lib benchmark::benchmark) 