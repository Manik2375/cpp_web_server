//
// Created by manik on 9/23/25.
//

#ifndef CPP_WEB_SERVER_BINDINGSOCKET_HPP
#define CPP_WEB_SERVER_BINDINGSOCKET_HPP

#include "./SimpleSocket.hpp"

namespace HDE {
    class BindingSocket : public SimpleSocket {
    public:
        BindingSocket(int domain, int service, int protocol, int port, u_long interface);
        int connect_to_network(int sock, struct sockaddr_in address) override;
    };
}


#endif //CPP_WEB_SERVER_BINDINGSOCKET_HPP
