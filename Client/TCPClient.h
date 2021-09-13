#include <string>

using namespace std;

#ifndef CLIENT_CPP_TCPCLIENT_H
#define CLIENT_CPP_TCPCLIENT_H

class TCPClient {
public:
    /**
     * Connecting to TCP.
     * @return sockaddr_in.
     */
    static sockaddr_in connecting();

    /**
     * Running the TCP client.
     * @param unClassified string.
     * @param sin sockaddr_in.
     * @return std::vector<string>
     */
    static std::vector<string> TcpClient(string unClassified, sockaddr_in sin);
};


#endif //CLIENT_CPP_TCPCLIENT_H