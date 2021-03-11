add_executable(
    Advanced_Timers
    main.cpp
)
add_custom_command(
        TARGET Advanced_Timers POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/*.ttf
                ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(Advanced_Timers lib-sdl2 my-sdlfunctions l_timer l_texture)