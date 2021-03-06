#include <unistd.h>
#include <thread>

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
    int client_sock = 0;
    int numClients = 0;
    while (true) {
        client_sock = TCPServer::acceptSocket();
        numClients++;
        if (client_sock == -1) {
            numClients--;
            break;
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

        std::thread thread(CLI::oneClient, output, commands, client_sock, &numClients);
        thread.detach();
    }
    while (numClients) {}
}

void CLI::oneClient(string output, std::vector<Command *> commands, int client_sock, int *numClients) {
    Knn knn = Knn();
    while (true) {
        TCPServer::sendMessage(output, client_sock);
        string input = TCPServer::readMessage(client_sock);
        try {
            if (stoi(input) > 7 || stoi(input) < 1) {
                TCPServer::sendMessage("Wrong number", client_sock);
                TCPServer::readMessage(client_sock);
            } else if (input == "7") {
                (*numClients)--;
                close(client_sock);
                break;
            } else {
                commands[stoi(input) - 1]->execute(knn, client_sock);
            }
        } catch (exception e) {
            TCPServer::sendMessage("Wrong choice", client_sock);
            TCPServer::readMessage(client_sock);
        }
    }
}
