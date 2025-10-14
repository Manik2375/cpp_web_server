//
// Created by manik on 9/24/25.
//

#ifndef CPP_WEB_SERVER_WEBSERVER_HPP
#define CPP_WEB_SERVER_WEBSERVER_HPP

#include "SimpleServer.hpp"
#include <unistd.h>
#include <fstream>
#include <filesystem>
#include <vector>

namespace HDE {
    class WebServer: public SimpleServer {
    private:
        char buffer[30000]{};
        int new_socket{};
        void accepter() override;
        void handler() override;
        void responder() override;

        int port;
        std::string path_requested;
        std::string content_type;
    public:
        WebServer(int port);
        void launch() override;
        void path_extractor(const std::string &httpRequest);
        std::vector<char> file_extractor(const std::string &path);
    };
}


#endif //CPP_WEB_SERVER_WEBSERVER_HPP