cmake_minimum_required(VERSION 3.2)
project(MutilThread)
 
 
find_package(Threads REQUIRED)
add_executable(course1_node  course1.cpp)

target_link_libraries(course1_node Threads::Threads)