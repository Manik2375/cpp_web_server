cmake_minimum_required(VERSION 3.20)
project(cpp_web_server)

set(CMAKE_CXX_STANDARD 20)

add_library(hoothoot_core STATIC
        Networking/Sockets/SimpleSocket.cpp
        Networking/Sockets/BindingSocket.cpp
        Networking/Sockets/ListeningSocket.cpp
        Networking/Servers/SimpleServer.cpp
        Networking/Servers/WebServer.cpp
        Networking/Sockets/ConnectingSocket.cpp
)

add_executable(cpp_web_server
    hoothoot.cpp
)

target_include_directories(hoothoot_core PUBLIC ${CMAKE_SOURCE_DIR})

target_compile_features(hoothoot_core PUBLIC cxx_std_20)
target_compile_features(cpp_web_server PRIVATE cxx_std_20)

target_compile_options(hoothoot_core PRIVATE -Wall -Wextra -Wpedantic)
target_compile_options(cpp_web_server PRIVATE -Wall -Wextra -Wpedantic)


target_link_libraries(cpp_web_server PRIVATE hoothoot_core)

set_target_properties(cpp_web_server PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
