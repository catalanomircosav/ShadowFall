file(GLOB_RECURSE GAME_SOURCES "src/*.cpp")

add_executable(ShadowFall ${GAME_SOURCES})

target_include_directories(ShadowFall
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/engine/include
)

target_link_libraries(ShadowFall PRIVATE engine)