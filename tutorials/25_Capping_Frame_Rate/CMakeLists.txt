add_executable(
    Frame_Rate_Capping
    main.cpp
)
add_custom_command(
    TARGET Frame_Rate_Capping POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/*.ttf
    ${CMAKE_CURRENT_BINARY_DIR}
)
target_link_libraries(Frame_Rate_Capping lib-sdl2 l_texture l_timer my-sdlfunctions)