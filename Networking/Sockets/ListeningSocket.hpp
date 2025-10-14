//
// Created by manik on 9/24/25.
//

#ifndef CPP_WEB_SERVER_LISTENINGSOCKET_HPP
#define CPP_WEB_SERVER_LISTENINGSOCKET_HPP

#include "BindingSocket.hpp"

namespace HDE {
    class ListeningSocket:  public BindingSocket {
    private:
        int backlog;
        int  listening{};
    public:
        ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int bklg);
        void start_listening();
        int get_backlog() const;
    };

}

#endif //CPP_WEB_SERVER_LISTENINGSOCKET_HPP