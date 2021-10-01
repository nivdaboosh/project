#include "cstring"

#include "Upload.h"
#include "TCPServer.h"

void Upload::execute(Knn& knn, int client_sock) {
    string output="Please upload your local train CSV file.";
    TCPServer::sendMessage(output, client_sock);

    string input=TCPServer::readMessage(client_sock);
    knn.setTrain(input);

    output="Please upload your local test CSV file.";
    TCPServer::sendMessage(output, client_sock);

    input=TCPServer::readMessage(client_sock);
    knn.setTest(input);

    output="Upload complete";
    TCPServer::sendMessage(output, client_sock);
    int x=0;
    TCPServer::readMessage(client_sock);
}