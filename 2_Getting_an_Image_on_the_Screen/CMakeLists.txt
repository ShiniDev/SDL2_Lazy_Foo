cmake_minimum_required(VERSION 3.5)

project(Getting_An_Image_on_Screen)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb -std=c++14")

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(
    main
    main.cpp
    )

target_link_libraries(main ${SDL2_LIBRARIES})
