file(GLOB_RECURSE ENGINE_SOURCES "src/**/*.cpp")

add_library(engine STATIC ${ENGINE_SOURCES})

target_include_directories(engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../external/SDL3/include/
        ${CMAKE_CURRENT_SOURCE_DIR}/../external/SDL3_image/include/
        ${CMAKE_CURRENT_SOURCE_DIR}/../external/spdlog/include/
)

target_link_libraries(engine PUBLIC SDL3::SDL3 SDL3_image::SDL3_image spdlog::spdlog)