cmake_minimum_required(VERSION 4.0)
project(cpp_web_server)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_web_server
#        hoothoot.cpp
#        hoothoot.hpp
        Networking/Sockets/SimpleSocket.hpp
        Networking/Sockets/SimpleSocket.cpp
        Networking/Sockets/BindingSocket.cpp
#        Networking/Sockets/ConnectingSocket.hpp
#        Networking/Sockets/ConnectingSocket.cpp
        Networking/Sockets/ListeningSocket.hpp
        Networking/Sockets/ListeningSocket.cpp
        Networking/hoothoot-network.hpp
        Networking/Sockets/hoothoot-sockets.hpp
        Networking/Servers/SimpleServer.hpp
        Networking/Servers/SimpleServer.cpp
        Networking/Servers/WebServer.hpp
        Networking/Servers/WebServer.cpp
        Networking/Servers/test.cpp
)
