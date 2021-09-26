#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

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

void CLI::start() {
    const int server_port = 55755;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }

    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
    }

    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);

    if (client_sock < 0) {
        perror("error accepting client");
    }

    std::vector<Command> commands = {Upload(), Settings(), Classify(), Display(), Download(), Matrix()};
    std::vector<string> list;
    list.emplace_back("Welcome to the KNN Classifier Server. Please choose an option:");
    int counter = 1;
    for (Command command:commands) {
        list.push_back(to_string(counter) + "." + "\t" + command.getDescription());
        ++counter;
    }
    list.push_back(to_string(counter) + "." + "\t" + "exit");
    string output = Iris::vectorToStr(list, '$');

    while (true) {
        TCPServer::sendMessage(output, client_sock);

        string input=TCPServer::readMessage(client_sock);
        if (stoi(input) > 7) {
            output= "Wrong number";
            TCPServer::sendMessage(output, client_sock);
        } else if (stoi(input) == 7) {
            close(sock);
            exit(1);
        } else {
            Knn knn = Knn();
            commands[stoi(input) - 1].execute(knn, client_sock);
        }
    }
}