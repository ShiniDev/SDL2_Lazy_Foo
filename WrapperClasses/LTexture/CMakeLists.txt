add_library(
    l_texture
    LTexture.cpp
)
target_link_libraries(l_texture lib-sdl2 my-sdlfunctions)
target_include_directories(l_texture PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")