cmake_minimum_required(VERSION 2.8.0)
project(atari-2600-emulator)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/src)

set(SOURCES
        src/atari-2600-emulator.cpp)

add_executable(emulator ${PROJECT_SOURCE_DIR}/src/atari-2600-emulator.cpp ${SOURCES})