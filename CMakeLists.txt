cmake_minimum_required(VERSION 2.8)
project(week5)
add_executable(week5 main.cpp)
find_package(OpenCV REQUIRED)
target_link_libraries(week5 ${OpenCV_LIBS})
