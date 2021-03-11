add_library(
    l_button
    LButton.cpp
)
target_link_libraries(l_button lib-sdl2 l_texture)
target_include_directories(l_button PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")