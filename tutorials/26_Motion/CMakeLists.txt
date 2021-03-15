add_executable(
    Motion
    main.cpp
)
add_custom_command(
    TARGET Motion POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/dot.png
    ${CMAKE_CURRENT_BINARY_DIR}
)
target_link_libraries(Motion lib-sdl2 dot my-sdlfunctions l_timer)