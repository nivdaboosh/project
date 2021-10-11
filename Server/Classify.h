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

    /**
     * Execute.
     * @param knn Knn.
     * @param client_sock int.
     */
    void execute(Knn &knn, int client_sock);

    static std::vector<string> theRun(Knn knn, string classified, string unclassified);
};


#endif //CLIENT_CLASSIFY_H