add_executable(
    Gamepads_Joysticks
    main.cpp
)
add_custom_command(
        TARGET Gamepads_Joysticks POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/*.png
                ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(Gamepads_Joysticks lib-sdl2 my-sdlfunctions l_texture)