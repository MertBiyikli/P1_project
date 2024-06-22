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
        smoke_test
        Google_tests/smoke_test/smoke_test.cpp
        # Google_tests/test_main.cpp
)

add_executable(
        unit_test
        Google_tests/unit_test/unit_test.cpp
        # Google_tests/test_main.cpp
)
target_link_libraries(
        smoke_test
        gtest_main
)

target_link_libraries(
        unit_test
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(smoke_test)
gtest_discover_tests(unit_test)
