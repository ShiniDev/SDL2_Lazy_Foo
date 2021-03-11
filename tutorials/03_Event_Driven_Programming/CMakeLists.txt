add_executable(
    Event_Driven
    main.cpp
)
add_custom_command(
        TARGET Event_Driven POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/ubuntu-icon-2.bmp
                ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(Event_Driven lib-sdl2 my-sdlfunctions)