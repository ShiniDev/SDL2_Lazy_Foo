cmake_minimum_required(VERSION 3.5)

project(EXLALOIMF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb -std=c++14")

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})

add_executable(
    main
    main.cpp
    )

target_link_libraries(main ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
