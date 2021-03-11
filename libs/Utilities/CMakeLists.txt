add_library(
    my-sdlfunctions
    INTERFACE
)
target_link_libraries(my-sdlfunctions INTERFACE lib-sdl2)
target_include_directories(my-sdlfunctions INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")