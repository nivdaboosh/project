#include "cstring"
#include <thread>

#include "Classify.h"
#include "Knn.h"
#include "TCPServer.h"

std::vector<string> Classify::theRun(Knn knn, string classified, string unclassified) {
    return knn.run(classified, unclassified);
}

void Classify::execute(Knn &knn, int client_sock) {
    //std::thread thread(Classify::theRun, knn, knn.getTrain(), knn.getTest());

    std::vector<string> list = knn.run(knn.getTrain(), knn.getTest());
    knn.setTypes(Iris::vectorToStr(list, '$'));

    string output = "classifying data complete";
    TCPServer::sendMessage(output, client_sock);

    TCPServer::readMessage(client_sock);
}