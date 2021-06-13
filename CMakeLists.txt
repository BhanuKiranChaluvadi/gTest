cmake_minimum_required(VERSION 3.15)

# Set the project name
project(example_gmock)

# Add an library for the example classes
add_library(example_gmock
  src/MetaDataProcessor.cpp
  src/MovieData.cpp
)

target_include_directories(example_gmock
  PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
)

#############################################
# Unit tests

add_subdirectory(3rd_party/google-test)

# enable CTest testing
enable_testing()

# Add a testing executable
add_executable(example_gmock_tests 
  tests/main.cpp
  tests/MetaDataProcessorTest.cpp)

target_include_directories(example_gmock_tests
  PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(example_gmock_tests
  example_gmock
  GTest::GTest 
  GTest::Main
  GMock::GMock
  GMock::Main
)

add_test(test_all example_gmock_tests)