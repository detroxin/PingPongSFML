cmake_minimum_required(VERSION 3.28)
project(PingPong LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(PingPong 
    src/main.cpp
    src/RandomGenerator.cpp
    src/bat.cpp
    src/ball.cpp)

target_compile_features(PingPong PRIVATE cxx_std_17)

target_include_directories(PingPong PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(PingPong PRIVATE SFML::Graphics SFML::Audio)