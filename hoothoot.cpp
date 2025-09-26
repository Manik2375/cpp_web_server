#include <fstream>
#include <filesystem>
#include "Networking/Servers/WebServer.hpp"

int main() {

    std::ifstream htmlFile("../assets/index.html");
    if (!htmlFile) {
        std::cerr << "Failed to open the file" << std::endl;
    }
    std::ostringstream fileContent;
    fileContent << htmlFile.rdbuf();

    HDE::WebServer server(4003, fileContent.str());
}