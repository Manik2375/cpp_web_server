//
// Created by manik on 9/24/25.
//

#ifndef CPP_WEB_SERVER_WEBSERVER_HPP
#define CPP_WEB_SERVER_WEBSERVER_HPP

#include "SimpleServer.hpp"
#include <unistd.h>
#include <fstream>

namespace HDE {
    class WebServer: public SimpleServer {
    private:
        char buffer[30000]{};
        int new_socket{};
        void accepter() override;
        void handler() override;
        void responder() override;

        std::string path_requested;
    public:
        WebServer(int port);
        void launch() override;
        static std::string path_extractor(const std::string &httpRequest);
        static std::string file_extractor(const std::string &path);
    };
}


#endif //CPP_WEB_SERVER_WEBSERVER_HPP