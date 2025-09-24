//
// Created by manik on 9/24/25.
//

#ifndef CPP_WEB_SERVER_WEBSERVER_HPP
#define CPP_WEB_SERVER_WEBSERVER_HPP

#include "SimpleServer.hpp"
#include <unistd.h>
namespace HDE {
    class WebServer: public SimpleServer {
    private:
        char buffer[30000]{};
        int new_socket{};
        void accepter() override;
        void handler() override;
        void responder() override;
    public:
        WebServer();
        void launch() override;
    };
}


#endif //CPP_WEB_SERVER_WEBSERVER_HPP