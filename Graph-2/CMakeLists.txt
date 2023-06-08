cmake_minimum_required(VERSION 3.0)
project(Safe)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp)

# Ustalanie folderu z plikami testowymi
set(TESTS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests)

# Dodawanie plików testowych
file(GLOB TEST_FILES "${TESTS_DIRECTORY}/test*.txt")

# Ustawianie argumentów dla programu
target_compile_definitions(main PRIVATE TEST_FILES="${TEST_FILES}")