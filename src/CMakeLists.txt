cmake_minimum_required(VERSION 3.20.0)
project(DSA VERSION 0.1.0 LANGUAGES C CXX)

add_executable(DSA main.c)

target_include_directories(DSA PRIVATE "${CMAKE_SOURCE_DIR}/../include/")
target_link_directories(DSA PRIVATE "${CMAKE_SOURCE_DIR}/../lib/")