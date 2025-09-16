cmake_minimum_required(VERSION 3.16)
project(lab1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()
qt_add_executable(lab1
  src/main.cpp
  src/action1.cpp
  src/action1_diag1.cpp
  src/action1_diag1.h
  src/action1_diag2.cpp
  src/action1_diag2.h
  src/action2.cpp
)

target_link_libraries(lab1 PRIVATE Qt6::Core Qt6::Widgets)

add_custom_target(run
  COMMAND $<TARGET_FILE:lab1>
  DEPENDS lab1
  WORKING_DIRECTORY $<TARGET_FILE_DIR:lab1>
)
