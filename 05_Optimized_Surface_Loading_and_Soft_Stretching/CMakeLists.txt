cmake_minimum_required(VERSION 3.5)

project(OSLASS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb -std=c++14")
add_subdirectory(sdl2)
include_directories(../WrapperClasses)
add_executable(
    main
    main.cpp
    ../WrapperClasses/LButton.cpp
    ../WrapperClasses/LTexture.cpp
    )
target_link_libraries(main sdl2_dependencies)