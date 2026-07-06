cmake_minimum_required(VERSION 3.16)
project(cpp_black_jack VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
file(GLOB_RECURSE PROJECT_SOURCES
    "${SOURCE_DIR}/*.cpp"
    "${SOURCE_DIR}/*.cc"
    "${SOURCE_DIR}/*.cxx"
)

list(FILTER PROJECT_SOURCES EXCLUDE REGEX "/main\\.cpp$")

if(NOT PROJECT_SOURCES)
    message(FATAL_ERROR "No C++ source files found in ${SOURCE_DIR}. Add sources to the repository.")
endif()

add_library(blackjack_lib STATIC ${PROJECT_SOURCES})

target_include_directories(blackjack_lib PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

add_executable(blackjack "${SOURCE_DIR}/main.cpp")
target_link_libraries(blackjack PRIVATE blackjack_lib)

option(BUILD_TESTING "Enable building tests" ON)
if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()
