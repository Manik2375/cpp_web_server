//
// Created by manik on 9/24/25.
//

#ifndef CPP_WEB_SERVER_CONNECTINGSOCKET_HPP
#define CPP_WEB_SERVER_CONNECTINGSOCKET_HPP

#include "SimpleSocket.hpp"

namespace HDE {
    class ConnectingSocket : public SimpleSocket {
    public:
        ConnectingSocket(int domain, int service, int protocol, u_long interface);
        int connect_to_network(int sock, struct sockaddr_in address) override;
    };
}



#endif //CPP_WEB_SERVER_CONNECTINGSOCKET_HPP