add_executable(
    Mouse_Events
    main.cpp
)
add_custom_command(
        TARGET Mouse_Events POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/*.png
                ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(Mouse_Events lib-sdl2 my-sdlfunctions l_texture l_button)