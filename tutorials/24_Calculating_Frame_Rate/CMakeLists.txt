add_executable(
    Calculating_Frame_Rate
    main.cpp
)
add_custom_command(
    TARGET Calculating_Frame_Rate POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/*.ttf
    ${CMAKE_CURRENT_BINARY_DIR}
)
target_link_libraries(Calculating_Frame_Rate lib-sdl2 l_timer l_texture my-sdlfunctions)