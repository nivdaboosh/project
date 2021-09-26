#include "cstring"

#include "Display.h"
#include "TCPServer.h"

void Display::execute(Knn knn, int client_sock) {
    string output = knn.getTypes();
    TCPServer::sendMessage(output, client_sock);

    TCPServer::readMessage(client_sock);
}