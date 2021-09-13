#include <string>

#include "TCPServer.h"

/**
 * The main of the server.
 * @param argc int.
 * @param argv char*[]
 * @return int.
 */
int main(int argc, char *argv[]) {
    if (std::string(argv[1]) == "UDP") {
    } else if (std::string(argv[1]) == "TCP") {
        TCPServer::TcpServer();
    } else {
        perror("Wrong protocol");
    }
}