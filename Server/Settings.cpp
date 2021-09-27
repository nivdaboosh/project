#include "cstring"

#include "Settings.h"
#include "Knn.h"
#include "TCPServer.h"

void Settings::execute(Knn knn, int client_sock) {
    string output = "The current KNN parameters are: K = " + std::to_string(knn.getK())
                    + ", distance metric = " + knn.getDistance();
    TCPServer::sendMessage(output, client_sock);

    string buffer = TCPServer::readMessage(client_sock);
    char input[4096];
    strcpy(input, buffer.c_str());

    std::vector<string> strings=Iris::strToVector(input, ' ');
    string isDouble = strtok(input, ".");
    // Let's assume we only enter a number and then a string.
    int newK = stoi(strings[0]);
    string newType = strings[1];
    bool continueInput = true;
    while (continueInput) {
        if (newK > 10 || newK < 1 || isDouble != input) {
            output = "Invalid value for K";
            TCPServer::sendMessage(output, client_sock);
        } else if (newType != "EUC" && newType != "MAN" && newType != "CHE") {
            output = "Invalid value for distance type";
            TCPServer::sendMessage(output, client_sock);
        } else {
            knn.setK(newK);
            knn.setDistanceType(newType);
            continueInput = false;
        }
    }
    TCPServer::sendMessage("Great success", client_sock);

    TCPServer::readMessage(client_sock);
}