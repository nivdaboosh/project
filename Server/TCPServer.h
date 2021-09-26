#ifndef CLIENT_CPP_TCPSERVER_H
#define CLIENT_CPP_TCPSERVER_H


class TCPServer {
public:
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
};


#endif //CLIENT_CPP_TCPSERVER_H