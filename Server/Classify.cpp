#include "cstring"
#include <thread>

#include "Classify.h"
#include "Knn.h"
#include "TCPServer.h"

void Classify::theRun(Knn *knn) {
    knn->run(knn->getTrain(), knn->getTest());
}

void Classify::execute(Knn &knn, int client_sock) {
    std::thread thread(Classify::theRun, &knn);
    thread.detach();

    string output = "classifying data complete";
    TCPServer::sendMessage(output, client_sock);

    TCPServer::readMessage(client_sock);
}