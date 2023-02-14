cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

project(order_book_src LANGUAGES CXX)


set(HEADERS
    "interfaces.h"
    "order_book.h"
)
set(SOURCES
    "order_book.cpp"
    "main.cpp"
)

add_executable(order_book
    ${HEADERS}
    ${SOURCES}
    )

 add_library(order_book_lib STATIC 
    ${HEADERS}
    ${SOURCES}
 )