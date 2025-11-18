file(GLOB_RECURSE GAME_SOURCES "src/*.cpp")

add_executable(ShadowFall ${GAME_SOURCES})

target_include_directories(ShadowFall
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/engine/include
)

target_link_libraries(ShadowFall PRIVATE engine)

add_custom_command(
    TARGET ShadowFall POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets
)