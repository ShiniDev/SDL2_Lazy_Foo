add_executable(
    Key_States
    main.cpp
)
add_custom_command(
        TARGET Key_States POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/*.png
                ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(Key_States lib-sdl2 my-sdlfunctions l_texture)