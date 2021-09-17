#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <vector>

#include "Settings.h"

Settings::Settings() {
    this->description = "algorithm settings";
}

void Command::execute(sockaddr_in sin, string input) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }

    int sent_bytes = send(sock, input.c_str(), strlen(input.c_str()), 0);

    if (sent_bytes < 0) {
        perror("error sending message");
    }

    std::vector<string> output;
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        perror("connection is closed");
    } else if (read_bytes < 0) {
        perror("error reading message");
    } else {
        output = Iris::strToVector(buffer, '$');
    }

    int sent_bytes = send(sock, input.c_str(), strlen(input.c_str()), 0);

    if (sent_bytes < 0) {
        perror("error sending message");
    }

    std::vector<string> output;
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        perror("connection is closed");
    } else if (read_bytes < 0) {
        perror("error reading message");
    } else {
        output = Iris::strToVector(buffer, '$');
    }
    close(sock);
    return output;
}