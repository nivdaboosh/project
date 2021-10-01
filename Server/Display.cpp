#include "cstring"

#include "Display.h"
#include "TCPServer.h"

void Display::execute(Knn &knn, int client_sock) {
    std::vector<string> theOutput = Iris::strToVector(knn.getTypes(), '$');
    std::vector<string> output;
    int counter = 1;
    for (string x:theOutput) {
        output.push_back(to_string(counter) + "\t" + x);
        ++counter;
    }
    TCPServer::sendMessage(Iris::vectorToStr(output, '$'), client_sock);

    TCPServer::readMessage(client_sock);
}