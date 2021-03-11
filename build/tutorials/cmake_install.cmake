# Install script for directory: /home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/tutorials

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/01_Hello_SDL/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/02_Getting_an_Image_on_the_Screen/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/03_Event_Driven_Programming/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/04_Key_Presses/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/05_Optimized_Surface_Loading_and_Soft_Stretching/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/06_Extension_Libraries_and_Loading_Other_Image_Formats/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/07_Texture_Loading_and_Rendering/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/08_Geometry_Rendering/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/09_The_Viewport/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/10_Color_Keying/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/11_Clip_Rendering_and_Sprite_Sheets/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/12_Color_Modulation/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/13_Alpha_Blending/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/14_Animated_Sprites_and_Vsync/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/15_Rotation_and_Flipping/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/16_True_Type_Fonts/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/17_Mouse_Events/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/18_Key_States/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/19_Gamepads_and_Joysticks/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/20_Force_Feedback/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/21_Sound_Effects_and_Music/cmake_install.cmake")
  include("/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/22_Timing/cmake_install.cmake")

endif()

