cmake_minimum_required(VERSION 3.30.3)

project(App VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB project_SOURCES
    src/*.cpp
)
add_executable(app ${project_SOURCES})