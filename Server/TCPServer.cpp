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

string TCPServer::readMessage(int client_sock) {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        perror("Connection is closed");
    } else if (read_bytes < 0) {
        perror("Error reading message");
    }
    return buffer;
}

void TCPServer::sendMessage(string message, int client_sock) {
    char data_addr[message.size()];
    strcpy(data_addr, message.c_str());
    int data_len = sizeof(data_addr);
    int sent_bytes = send(client_sock, data_addr, data_len, 0);
    if (sent_bytes < 0) {
        perror("Error sending message");
    }
}
