cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

project(order_book_test LANGUAGES CXX)

set(TEST_HEADERS
    "test.h"
)
set(TEST_SOURCES
    "test.cpp"
)

add_executable(order_book_test
    ${TEST_HEADERS}
    ${TEST_SOURCES}
    )


include(GoogleTest)
gtest_discover_tests(order_book_test)


target_link_libraries(
  order_book_test
  PUBLIC
  order_book_lib
  GTest::gtest_main
)