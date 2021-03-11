add_executable(
    Alpha_Blending
    main.cpp
)
add_custom_command(
        TARGET Alpha_Blending POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/*.png
                ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(Alpha_Blending lib-sdl2 my-sdlfunctions l_texture)
