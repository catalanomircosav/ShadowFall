file(GLOB_RECURSE ENGINE_SOURCES "src/*.cpp")

add_library(engine STATIC ${ENGINE_SOURCES})

target_include_directories(engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)