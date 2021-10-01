#include "cstring"

#include "Classify.h"
#include "Knn.h"
#include "TCPServer.h"

void Classify::execute(Knn& knn, int client_sock) {
    std::vector<string> list = knn.run(knn.getTrain(), knn.getTest());
    knn.setTypes(Iris::vectorToStr(list, '$'));
    string output = "classifying data complete";
    TCPServer::sendMessage(output, client_sock);

    TCPServer::readMessage(client_sock);
}