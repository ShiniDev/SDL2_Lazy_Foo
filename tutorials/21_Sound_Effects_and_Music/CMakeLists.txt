add_executable(
    SFX_Music
    main.cpp
)
add_custom_command(
        TARGET SFX_Music POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_CURRENT_SOURCE_DIR}/Assets
                ${CMAKE_CURRENT_BINARY_DIR}/Assets)
target_link_libraries(SFX_Music lib-sdl2 my-sdlfunctions l_texture)