cmake_minimum_required(VERSION 3.17)
project(ShadowFall LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add SDL3 as a submodule
add_subdirectory(external/SDL3)
add_subdirectory(external/SDL3_image)
add_subdirectory(external/spdlog)

# Add engine and game modules
add_subdirectory(engine)
add_subdirectory(game)