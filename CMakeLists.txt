cmake_minimum_required(VERSION 3.14)

project(luna)

set(CMAKE_CXX_STANDARD 17)

set(XLIB_SOURCES src/xlib/visual/canvas.cpp src/xlib/visual/writer.cpp)

add_library(xlib ${XLIB_SOURCES})

find_package(png REQUIRED)
target_include_directories(xlib PRIVATE ${PNG_INCLUDE_DIRS})
target_link_libraries(xlib PRIVATE ${PNG_LIBRARIES})

add_executable(luna src/main.cpp)

target_link_libraries(luna PRIVATE xlib)
