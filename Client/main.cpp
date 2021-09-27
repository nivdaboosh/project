#include <sys/socket.h>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

#include "TCPClient.h"
#include "../Iris.h"

/**
 * The main of the client.
 * @return int.
 */
int main() {
    int sock = TCPClient::connecting();
    string input;
    while (input != "7") {
        std::vector<string> output = TCPClient::readMessage(sock);
        for (string string1:output) {
            cout << string1 << endl;
        }
        cin >> input;
        TCPClient::sendMessage(input, sock);
    }
    return 0;
}