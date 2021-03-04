cmake_minimum_required(VERSION 3.5)
project(GamepadsJoysticks)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb -std=c++14")
INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})
add_executable(
    main
    main.cpp
    ../WrapperClasses/LTexture.cpp
    ../WrapperClasses/LButton.cpp
    )
target_link_libraries(main ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES})
