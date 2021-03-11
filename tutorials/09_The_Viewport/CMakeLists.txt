add_executable(
    The_Viewport
    main.cpp
)
add_custom_command(
        TARGET The_Viewport POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/pixeltv.png
                ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(The_Viewport lib-sdl2 my-sdlfunctions)
