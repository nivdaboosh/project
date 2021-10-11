#include "cstring"
#include <string>

#include "Settings.h"
#include "Knn.h"
#include "TCPServer.h"

void Settings::execute(Knn &knn, int client_sock) {
    string output = "The current KNN parameters are: K = " + std::to_string(knn.getK())
                    + ", distance metric = " + knn.getDistance();
    TCPServer::sendMessage(output, client_sock);

    string input = TCPServer::readMessage(client_sock);
    char buffer[4096];
    strcpy(buffer, input.c_str());

    std::vector<string> strings = Iris::strToVector(input, ' ');

    bool continueInput = true;
    if (input == "This is enter my friend. Hala Madrid") {
        continueInput = false;
    }
    while (continueInput) {
        string isDouble = strtok(buffer, ".");
        // Let's assume we only enter a number and then a string.
        int newK = stoi(strings[0]);
        string newType = strings[1];
        if (newK > 10 || newK < 1 || isDouble != input) {
            output = "Invalid value for K";
            TCPServer::sendMessage(output, client_sock);
            input = TCPServer::readMessage(client_sock);
        } else if (newType != "EUC" && newType != "MAN" && newType != "CHE") {
            output = "Invalid value for distance type";
            TCPServer::sendMessage(output, client_sock);
            input = TCPServer::readMessage(client_sock);
        } else {
            knn.setK(newK);
            knn.setDistanceType(newType);
            continueInput = false;
            TCPServer::sendMessage("Great success", client_sock);
            TCPServer::readMessage(client_sock);
        }
        strcpy(buffer, input.c_str());
        strings = Iris::strToVector(input, ' ');
    }
}