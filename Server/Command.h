#ifndef CLIENT_COMMAND_H
#define CLIENT_COMMAND_H

#include <string>
#include <netinet/in.h>
#include "Knn.h"

using namespace std;

// abstract
class Command {
protected:
    string description;
public:
    /**
     * Execute.
     * @param knn Knn.
     * @param client_sock int.
     */
    virtual void execute(Knn& knn, int client_sock) = 0;

    /**
     * Returns the description of the command.
     * @return string.
     */
    string getDescription();
};


#endif //CLIENT_COMMAND_H