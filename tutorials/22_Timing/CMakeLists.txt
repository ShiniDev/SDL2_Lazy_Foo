add_executable(
    Timing
    main.cpp
)
add_custom_command(
        TARGET Timing POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/*.ttf
                ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(Timing lib-sdl2 my-sdlfunctions l_texture)