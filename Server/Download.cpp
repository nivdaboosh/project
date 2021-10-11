#include <fstream>

#include "Download.h"
#include "TCPServer.h"

void Download::execute(Knn &knn, int client_sock) {
    string letsGo = "enter a file path";
    TCPServer::sendMessage(letsGo, client_sock);

    string input = TCPServer::readMessage(client_sock);

    std::vector<string> list = Iris::strToVector(knn.getTypes(), '$');
    std::ofstream fout(input);
    for (int i = 0; i < list.size() - 1; ++i) {
        fout << list[i] << endl;
    }
    fout << list[list.size() - 1];
    fout.close();

    TCPServer::sendMessage(input, client_sock);

    TCPServer::readMessage(client_sock);
}