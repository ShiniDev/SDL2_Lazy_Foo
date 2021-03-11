add_executable(
    Color_Modulation
    main.cpp
)
add_custom_command(
        TARGET Color_Modulation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/*.jpeg
                ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(Color_Modulation lib-sdl2 my-sdlfunctions l_texture)