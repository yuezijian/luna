cmake_minimum_required(VERSION 3.14)

project(luna)

set(CMAKE_CXX_STANDARD 17)


set(XLIB_SOURCES
        xlib/visual/canvas.cpp
        xlib/visual/image.cpp
        xlib/visual/viewer.cpp
        xlib/visual/writer.cpp
        )

add_library(xlib ${XLIB_SOURCES})

find_package(png REQUIRED)
target_include_directories(xlib PRIVATE ${PNG_INCLUDE_DIRS})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt5 CONFIG REQUIRED Core Gui Widgets)

target_link_libraries(xlib PRIVATE ${PNG_LIBRARIES} Qt5::Core Qt5::Gui Qt5::Widgets)


add_executable(luna main.cpp)

target_link_libraries(luna PRIVATE xlib)


add_executable(test_line test/line.cpp)
target_include_directories(test_line PRIVATE ./)
target_link_libraries(test_line PRIVATE xlib)

add_executable(test_fill test/fill.cpp)
target_include_directories(test_fill PRIVATE ./)
target_link_libraries(test_fill PRIVATE xlib)
