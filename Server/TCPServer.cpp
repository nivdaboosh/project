#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <cstring>
#include <netinet/in.h>

#include "TCPServer.h"

using namespace std;


string TCPServer::readMessage(int client_sock) {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        perror("Connection is closed");
    } else if (read_bytes < 0) {
        perror("Error reading message");
    }
    string output = strtok(buffer, "@");
    return output;
}

void TCPServer::sendMessage(string message, int client_sock) {
    message += "@";
    char data_addr[message.size()];
    strcpy(data_addr, message.c_str());
    int data_len = sizeof(data_addr);
    int sent_bytes = send(client_sock, data_addr, data_len, 0);
    if (sent_bytes < 0) {
        perror("Error sending message");
    }
}

void TCPServer::createSocket() {
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
    TCPServer::theSocket = sock;
}

int TCPServer::acceptSocket() {
    int sock = TCPServer::theSocket;

    struct timeval timeval;
    memset(&timeval, 0, sizeof(timeval));
    // Timeout is 60 seconds.
    timeval.tv_sec = 20;

    fd_set fdSet;
    FD_ZERO(&fdSet);
    FD_SET(sock, &fdSet);

    if (select(sock + 1, &fdSet, NULL, NULL, &timeval) < 0) {
        perror("select error");
    }
    // If a connection has been made to connect to the server, and the timeout hasn't passed yet.
    if (FD_ISSET(sock, &fdSet)) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);

        if (client_sock < 0) {
            perror("error accepting client");
        }
        return client_sock;
    }
    return -1;
}