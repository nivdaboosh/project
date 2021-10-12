#include <unistd.h>

#include "Knn.h"
#include "CLI.h"
#include "Command.h"
#include "Upload.h"
#include "Settings.h"
#include "Classify.h"
#include "Display.h"
#include "Download.h"
#include "Matrix.h"
#include "TCPServer.h"

int TCPServer::theSocket = 0;

void CLI::start() {
    TCPServer::createSocket();
    int client_sock = TCPServer::acceptSocket();
    if (client_sock < 0) {
        close(client_sock);
        return;
    }
    std::vector<Command *> commands = {new Upload(), new Settings(), new Classify(), new Display(), new Download(),
                                       new Matrix()};
    std::vector<string> list;
    list.emplace_back("Welcome to the KNN Classifier Server. Please choose an option:");
    int counter = 1;
    for (Command *command:commands) {
        list.push_back(to_string(counter) + "." + "\t" + command->getDescription());
        ++counter;
    }
    list.push_back(to_string(counter) + "." + "\t" + "exit");
    string output = Iris::vectorToStr(list, '$');
    Knn knn = Knn();

    while (true) {
        TCPServer::sendMessage(output, client_sock);

        string input = TCPServer::readMessage(client_sock);
        try {
            if (stoi(input) > 7 || stoi(input) < 1) {
                TCPServer::sendMessage("Wrong number", client_sock);
                TCPServer::readMessage(client_sock);
            } else if (input == "7") {
                close(client_sock);
                exit(1);
            } else {
                commands[stoi(input) - 1]->execute(knn, client_sock);
            }
        } catch (exception e) {
            TCPServer::sendMessage("Wrong choice", client_sock);
            TCPServer::readMessage(client_sock);
        }
    }
}