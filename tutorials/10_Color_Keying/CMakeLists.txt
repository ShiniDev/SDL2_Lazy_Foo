add_executable(
    Color_Keying
    main.cpp
)
add_custom_command(
        TARGET Color_Keying POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/*.png
                ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(Color_Keying lib-sdl2 my-sdlfunctions l_texture)