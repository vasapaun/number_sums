cmake_minimum_required(VERSION 3.10)
project(SFML_Project)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)
# Uncomment if cmake can't find sfml packages
# include_directories("/usr/include/SFML")
add_executable(main main.cpp Square.cpp Board.cpp Cursor.cpp)
target_link_libraries(main sfml-graphics sfml-window sfml-system)
