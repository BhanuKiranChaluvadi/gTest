cmake_minimum_required(VERSION 3.15)

# Set the project name
project(gmock)

# Add an library for the example classes
# add_library(example_gmock
#   main.cpp
# )

#############################################
# Unit tests

add_subdirectory(3rd_party/google-test)

# enable CTest testing
enable_testing()

# Add a testing executable
add_executable(mock_tests main.cpp)

target_link_libraries(mock_tests
#  example_gmock
  GTest::GTest 
  GTest::Main
  GMock::GMock
  GMock::Main
)

add_test(test_all mock_tests)