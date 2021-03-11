add_executable(
    Animated_Sprites
    main.cpp
)
add_custom_command(
        TARGET Animated_Sprites POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/*.png
                ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(Animated_Sprites lib-sdl2 my-sdlfunctions l_texture)