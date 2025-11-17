cmake_minimum_required(VERSION 3.17)
project(ShadowFall LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add engine and game modules
add_subdirectory(engine)
add_subdirectory(game)