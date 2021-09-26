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
    static int connecting();

    /**
     * Sending the message.
     * @param message string.
     * @param sin sockaddr_in.
     */
    static void sendMessage(string message, int sock);

    /**
     * Sending the message.
     * @param sin sockaddr_in.
     * @return std::vector<string>.
     */
    static std::vector<string> readMessage(int sock);
};


#endif //CLIENT_CPP_TCPCLIENT_H