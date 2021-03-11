add_library(
    l_timer
    LTimer.cpp
)
target_link_libraries(l_timer lib-sdl2)
target_include_directories(l_timer PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")