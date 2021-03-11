add_executable(
    Loading_Formats
    main.cpp
)
add_custom_command(
        TARGET Loading_Formats POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/1.jpg
                ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(Loading_Formats lib-sdl2 my-sdlfunctions)