//
// Created by manik on 9/24/25.
//

#include "WebServer.hpp"

#include <cstring>

HDE::WebServer::WebServer(): SimpleServer(AF_INET, SOCK_STREAM, 0, 4202, INADDR_ANY, 10) {
    int opt = 1;
    if (setsockopt(get_socket()->get_socket(), SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt failed");
    }
    memset(buffer, 0, sizeof(buffer));
    WebServer::launch();
}

void HDE::WebServer::accepter() {
    struct sockaddr_in address = get_socket()->get_address();
    int addrLen = sizeof(address);
    new_socket = accept(get_socket()->get_socket(), reinterpret_cast<struct sockaddr *>(&address), reinterpret_cast<socklen_t *>(&addrLen));
    if (new_socket < 0) {
        perror("accept");
        return;
    }
    memset(buffer, 0, sizeof(buffer));
    ssize_t bytes_read = read(new_socket, buffer, sizeof(buffer) - 1);  // Leave space for null terminator
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0';  // Null terminate
        std::cout << "Bytes read: " << bytes_read << std::endl;
    } else if (bytes_read == 0) {
        std::cout << "Client disconnected" << std::endl;
    } else {
        perror("read");
    }

}


void HDE::WebServer::handler() {
    std::cout << "=== REQUEST START ===" << std::endl;

    // Replace \r\n with actual line breaks for readability
    std::string request(buffer);
    size_t pos = 0;
    while ((pos = request.find("\r\n", pos)) != std::string::npos) {
        request.replace(pos, 2, "\n");
        pos += 1;
    }

    std::cout << request << std::endl;
    std::cout << "=== REQUEST END ===" << std::endl;
}


void HDE::WebServer::responder() {
    const char *msg = "HTTP/1.1 200 OK\r\nContent-Length: 5\r\n\r\nhello";
    write(new_socket, msg, strlen(msg));
    close(new_socket);
}

void HDE::WebServer::launch() {
    while (true) {
        std::cout << "***************Waiting for connection****************" << std::endl;
        accepter();
        handler();
        responder();
    }
}