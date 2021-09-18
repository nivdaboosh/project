#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <vector>

#include "Command.h"

string Command::getDescription(){
    return this->description;
}

sockaddr_in Command::connecting() {
    const char *ip_address = "127.0.0.1";
    const int port_no = 55755;

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);

    return sin;
}