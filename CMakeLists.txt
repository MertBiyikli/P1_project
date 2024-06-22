cmake_minimum_required(VERSION 3.10)

project(GraphMicroservice)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(graph_service src/main.cpp)

find_package(SQLite3 REQUIRED)
target_link_libraries(graph_service SQLite::SQLite3)

# Enable testing
enable_testing()

# Fetch googletest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# The following lines ensure googletest is downloaded and added to your build
FetchContent_MakeAvailable(googletest)

# Now you can create your test executable and link against GTest targets
add_executable(
        tests
        Google_tests/test_main.cpp
)
target_link_libraries(
        tests
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
