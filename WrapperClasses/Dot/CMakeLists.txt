add_library(
    dot
    dot.cpp
)
target_link_libraries(dot lib-sdl2 l_texture my-sdlfunctions)
target_include_directories(dot PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")