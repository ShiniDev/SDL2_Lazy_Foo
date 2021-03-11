add_executable(
    Clip_Render_Sprite_Sheets
    main.cpp
)
add_custom_command(
        TARGET Clip_Render_Sprite_Sheets POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/*.png
                ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(Clip_Render_Sprite_Sheets lib-sdl2 my-sdlfunctions l_texture)