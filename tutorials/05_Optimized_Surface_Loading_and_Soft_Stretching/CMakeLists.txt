add_executable(
    Optimized_Loading
    main.cpp
)
add_custom_command(
        TARGET Optimized_Loading POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/stretch.bmp
                ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(Optimized_Loading lib-sdl2 my-sdlfunctions)