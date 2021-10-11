#ifndef CLIENT_CPP_TCPSERVER_H
#define CLIENT_CPP_TCPSERVER_H

#include "string"

using namespace std;

class TCPServer {
public:
    static int theSocket;

    /**
     * Reads a message.
     * @param client_sock int.
     * @return string.
     */
    static string readMessage(int client_sock);

    /**
     * Sends a message.
     * @param message string.
     * @param client_sock int.
     */
    static void sendMessage(string message, int client_sock);

    /**
     * Accepting the socket.
     * @return int.
     */
    static int acceptSocket();

    /**
     * Creating a socket.
     */
    static void createSocket();
};


#endif //CLIENT_CPP_TCPSERVER_H