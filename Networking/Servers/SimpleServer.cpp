//
// Created by manik on 9/24/25.
//

#include "SimpleServer.hpp"

HDE::SimpleServer::SimpleServer(int domain, int service, int protocol, int port, u_long interface, int bklg) {
    socket = new ListeningSocket(domain, service, protocol, port, interface, bklg);

    int opt = 1;
    if (setsockopt(socket->get_socket(), SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt failed");
    }
}

HDE::SimpleServer::~SimpleServer() {
    std::cout << "SimpleServer destructor called" << std::endl;
    if (socket != nullptr) {
        close(socket->get_socket());
        delete socket;
        socket = nullptr;
    }
}

HDE::ListeningSocket *HDE::SimpleServer::get_socket() {
    return socket;
}