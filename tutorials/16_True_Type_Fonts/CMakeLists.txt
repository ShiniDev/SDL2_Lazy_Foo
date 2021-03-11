add_executable(
    True_Type_Fonts
    main.cpp
)
add_custom_command(
        TARGET True_Type_Fonts POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/*.ttf
                ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(True_Type_Fonts lib-sdl2 my-sdlfunctions l_texture)