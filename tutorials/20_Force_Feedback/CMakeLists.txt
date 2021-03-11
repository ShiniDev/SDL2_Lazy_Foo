add_executable(
    Force_Feedback
    main.cpp
)
add_custom_command(
        TARGET Force_Feedback POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/*.png
                ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(Force_Feedback lib-sdl2 my-sdlfunctions l_texture)