//
// Created by manik on 9/22/25.
//

#include "SimpleSocket.hpp"

HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol, u_long interface) {
        // address is getting set here
        address.sin_family = domain;
        address.sin_port = htons(service);
        address.sin_addr.s_addr = htons(interface);
        // this is connection
        sock = socket(domain, service, protocol);
        test_connection(sock);
}

void HDE::SimpleSocket::test_connection(int item_test) {
     if (item_test < 0) { // we will be passing sock and connection whose value is < 0 on error
         std::cerr << "Test connection failed" << std::endl;
         exit(EXIT_FAILURE);
     }
}

struct sockaddr_in HDE::SimpleSocket::get_address() {
    return address;
}
int HDE::SimpleSocket::get_socket() {
    return sock;
}
int HDE::SimpleSocket::get_connection() {
    return connection;
}
void HDE::SimpleSocket::set_connection(int con) {
    connection = con;
}

