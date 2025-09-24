//
// Created by manik on 9/23/25.
//

#include "BindingSocket.hpp"

HDE::BindingSocket::BindingSocket(int domain, int service, int protocol, u_long interface) : SimpleSocket(
    domain, service, protocol, interface) {
    // ReSharper disable once CppAbstractVirtualFunctionCallInCtor
    set_connection(connect_to_network(get_socket(), get_address()));
    test_connection(get_connection());;
}

int HDE::BindingSocket::connect_to_network(int sock, struct sockaddr_in address) {
    return bind(sock, reinterpret_cast<struct sockaddr *>(&address), sizeof(address));
}
