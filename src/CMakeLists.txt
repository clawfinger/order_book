cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

project(order_book LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
  abseil
  GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
  GIT_TAG        20230125.0
)
FetchContent_MakeAvailable(abseil)

if(NOT abseil_POPULATED)
	message(FAILED)
endif()

set(SOURCES	
	"array/order_book.cpp"
	"array/order_book.h"
	"b_tree/order_book.h"
	"b_tree/order_book.cpp"
	"b_tree/order_book.h"
	"common.h"
	"main.cpp"
)

get_filename_component(PARENT_DIR ../ ABSOLUTE)
include_directories(${PARENT_DIR}/src)

add_executable(order_book ${SOURCES} )

add_library(order_book_lib  STATIC ${SOURCES})
target_link_libraries(order_book absl::container_common)
target_link_libraries(order_book_lib absl::container_common)