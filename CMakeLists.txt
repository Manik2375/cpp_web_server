cmake_minimum_required(VERSION 4.0)
project(cpp_web_server)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_web_server hoothootNetwork.cpp
        hoothootNetwork.hpp)
