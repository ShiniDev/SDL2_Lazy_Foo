add_executable(
    Texture_Loading
    main.cpp
)
add_custom_command(
        TARGET Texture_Loading POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/5.jpg
                ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(Texture_Loading lib-sdl2 my-sdlfunctions)