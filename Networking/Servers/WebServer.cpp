//
// Created by manik on 9/24/25.
//

#include "WebServer.hpp"

#include <cstring>
#include <sstream>

HDE::WebServer::WebServer(int port) : SimpleServer(AF_INET, SOCK_STREAM, 0, port, INADDR_ANY, 10) {
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
    new_socket = accept(get_socket()->get_socket(), reinterpret_cast<struct sockaddr *>(&address),
                        reinterpret_cast<socklen_t *>(&addrLen));

    memset(buffer, 0, sizeof(buffer));
    ssize_t bytes_read = read(new_socket, buffer, sizeof(buffer) - 1); // Leave space for null terminator
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0'; // Null terminate
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

    path_requested = HDE::WebServer::path_extractor(request);

    std::cout << request << std::endl;
    std::cout << "=== REQUEST END ===" << std::endl;
}


void HDE::WebServer::responder() {
    std::string message = HDE::WebServer::file_extractor(path_requested);

    std::string response;
    if (message.empty()) {
        message = "<h1 style=\"color: red;\">404 Error </h1>";

        response = std::string("HTTP/1.1 404 Not Found\r\n") +
                   "Content-Type: text/html; charset=UTF-8\r\n" +
                   "Content-Length: " + std::to_string(message.size()) + "\r\n" +
                   "\r\n" +
                   message;
    } else {
        response = std::string("HTTP/1.1 200 OK\r\n") +
                   "Content-Type: text/html; charset=UTF-8\r\n" +
                   "Content-Length: " + std::to_string(message.size()) + "\r\n" +
                   "\r\n" +
                   message;
    }


    size_t total_sent = 0;
    const size_t message_length = response.size();
    const char *msg_ptr = response.c_str();

    while (total_sent < message_length) {
        ssize_t bytes_sent = send(new_socket, msg_ptr, message_length - total_sent, 0);
        if (bytes_sent < 0) {
            std::cerr << "Error sending message" << std::endl;
            return;
        }
        total_sent += bytes_sent;
    }

    close(new_socket);
    std::cout << "socket closed" << std::endl;
}

void HDE::WebServer::launch() {
    while (true) {
        std::cout << "***************Waiting for connection****************" << std::endl;
        accepter();
        handler();
        responder();
    }
}

std::string HDE::WebServer::path_extractor(const std::string &httpRequest) {
    std::istringstream req(httpRequest); // treat like std::cin
    std::string method, path, version;

    req >> method >> path >> version;

    if (path == "/") return "/index.html";
    return path;
}

std::string HDE::WebServer::file_extractor(const std::string &path) {
    std::ifstream htmlFile("./assets" + path);
    if (!htmlFile) {
        std::cerr << "Failed to open the file" << std::endl;
        return "";
    }
    std::ostringstream fileContent;
    fileContent << htmlFile.rdbuf();
    return fileContent.str();
}
