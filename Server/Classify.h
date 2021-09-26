#ifndef CLIENT_CLASSIFY_H
#define CLIENT_CLASSIFY_H


#include "Command.h"

class Classify : public Command {
public:
    /**
     * Constructor.
     */
    Classify() {
        this->description = "classify data";
    }

    void execute(Knn knn, int client_sock);
};


#endif //CLIENT_CLASSIFY_H