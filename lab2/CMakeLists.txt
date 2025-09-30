cmake_minimum_required(VERSION 3.16)
project(lab2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()
add_executable(lab2
    src/main.cpp
    src/shape.h
    src/shape.cpp
    src/editor.h
    src/editor.cpp
    src/canvas.h
    src/canvas.cpp
)

target_link_libraries(lab2 PRIVATE Qt6::Core Qt6::Widgets)

add_custom_target(run
  COMMAND $<TARGET_FILE:lab2>
  DEPENDS lab2
  WORKING_DIRECTORY $<TARGET_FILE_DIR:lab2>
)
