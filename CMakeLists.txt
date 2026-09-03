cmake_minimum_required(VERSION 4.2)
project(resize)

set(CMAKE_CXX_STANDARD 20)


find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(resize
        main.cpp)
target_link_libraries(resize ${OpenCV_LIBS})
