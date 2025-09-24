//
// Created by manik on 9/24/25.
//

#include "./ConnectingSocket.hpp"

HDE::ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port, u_long interface) : SimpleSocket(
    domain, service, protocol, port, interface) {
    // ReSharper disable once CppAbstractVirtualFunctionCallInCtor
    connect_to_network(get_socket(), get_address());
}

int HDE::ConnectingSocket::connect_to_network(int sock, struct sockaddr_in address) {
    return connect(sock, reinterpret_cast<struct sockaddr *>(&address), sizeof(address));
}
