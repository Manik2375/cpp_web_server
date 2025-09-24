//
// Created by manik on 9/24/25.
//

#ifndef CPP_WEB_SERVER_SIMPLESERVER_HPP
#define CPP_WEB_SERVER_SIMPLESERVER_HPP

#include "../Sockets/hoothoot-sockets.hpp";
#include <unistd.h>

namespace HDE {
    class SimpleServer{ // Remember: A server is *not* a socket, but it *has* sockets
    private:
        ListeningSocket * socket;
        virtual void accepter() = 0;
        virtual void handler() = 0;
        virtual void responder() = 0;
    public:
        virtual ~SimpleServer();

        SimpleServer(int domain, int service, int protocol, int port, u_long interface, int bklg);
        virtual void launch() = 0;
        ListeningSocket * get_socket();
    };


}

#endif //CPP_WEB_SERVER_SIMPLESERVER_HPP