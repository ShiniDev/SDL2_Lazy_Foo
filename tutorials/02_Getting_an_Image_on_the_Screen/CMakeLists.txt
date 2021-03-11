add_executable(
    Getting_Image
    main.cpp
)
add_custom_command(
        TARGET Getting_Image POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/shinidev.bmp
                ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(Getting_Image lib-sdl2 my-sdlfunctions)