//
// Created by manik on 9/22/25.
//

#ifndef CPP_WEB_SERVER_SIMPLESOCKET_H
#define CPP_WEB_SERVER_SIMPLESOCKET_H

#include <cstdio>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

namespace HDE {
    class SimpleSocket {
    private:
        int sock;
        struct sockaddr_in address;
    public:
        virtual ~SimpleSocket() = default;

        SimpleSocket(int domain, int service, int protocol, int port, u_long interface);

        // the reason I'm creating a virtual function is because, otherwise we have 2 functions to use. Bind in server side and connect in client side. Virtual function let user write their own functoin here
        virtual int connect_to_network(int sock, struct sockaddr_in address) = 0;

        void test_connection(int);

        struct sockaddr_in get_address();
        int get_socket();
    };
}


#endif //CPP_WEB_SERVER_SIMPLESOCKET_H