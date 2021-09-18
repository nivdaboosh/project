#include <sys/socket.h>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <netinet/in.h>

#include "CLI.h"
#include "TCPClient.h"

using namespace std;

void CLI::start() {
    sockaddr_in sin=TCPClient::connecting();
    while (true) {
        cout << "7." << "\t" << "exit" << endl;
        string input;
        getline(cin, input);
        TCPClient::TcpClient(input, sin);
        if (input == "7") {
            exit(1);
        }
    }
}
