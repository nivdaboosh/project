#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <vector>

#include "../Iris.h"
#include "TCPClient.h"

using namespace std;


int TCPClient::connecting() {
    const char *ip_address = "127.0.0.1";
    const int port_no = 55755;

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }

    return sock;
}

void TCPClient::sendMessage(string message, int sock) {
    int sent_bytes = send(sock, message.c_str(), strlen(message.c_str()), 0);

    if (sent_bytes < 0) {
        perror("error sending message");
    }
}

std::vector<string> TCPClient::readMessage(int sock) {
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
