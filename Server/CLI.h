#ifndef CLIENT_CLI_H
#define CLIENT_CLI_H


#include "Command.h"

class CLI {
public:
    /**
    * Starts the program.
    */
    void start();

    /**
     * One client.
     * @param output string.
     * @param commands std::vector<Command *>.
     * @param client_sock int.
     * @param numClients int&.
     */
    static void oneClient(string output, std::vector<Command *> commands, int client_sock, int *numClients);
};


#endif //CLIENT_CLI_H