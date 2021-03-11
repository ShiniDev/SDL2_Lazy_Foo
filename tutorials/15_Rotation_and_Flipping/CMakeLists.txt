add_executable(
    Rotation_Flipping
    main.cpp
)
add_custom_command(
        TARGET Rotation_Flipping POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/*.png
                ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(Rotation_Flipping lib-sdl2 my-sdlfunctions l_texture)