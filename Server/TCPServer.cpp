#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <vector>

#include "Knn.h"
#include "TCPServer.h"

using namespace std;

int TCPServer::TcpServer() {

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

    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        perror("Connection is closed");
    } else if (read_bytes < 0) {
        perror("Error reading message");
    }

    Knn knn = Knn();
    std::vector<string> list = knn.run(buffer);
    string output;

    for (int i = 0; i < list.size(); ++i) {
        output += list[i];
        output += "$";
    }
    char data_addr[output.size()];
    strcpy(data_addr, output.c_str());
    int data_len = sizeof(data_addr);
    int sent_bytes = send(client_sock, data_addr, data_len, 0);
    if (sent_bytes < 0) {
        perror("Error reading message");
    }
    close(sock);
    return 0;
}