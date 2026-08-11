cmake_minimum_required(VERSION 3.14)
project(MyATMController LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(GTest REQUIRED)

enable_testing()

add_library(bankLib STATIC
    src/Bank.cpp
    src/Account.cpp
)
target_include_directories(bankLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(ATMController ATMController.cpp)
target_link_libraries(ATMController PRIVATE bankLib)

include(GoogleTest)

# gtest_discover_tests()