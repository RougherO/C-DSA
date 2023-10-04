cmake_minimum_required(VERSION 3.21.0)
project(DSA LANGUAGES C CXX)

add_executable(DSA src/main.c)

target_link_libraries(DSA m)