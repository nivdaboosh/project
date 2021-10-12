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

    /**
     * Static function for Knn::run.
     * @param knn Knn.
     * @param classified string.
     * @param unclassified string.
     * @return std::vector<string>.
     */
    static void theRun(Knn *knn);
};


#endif //CLIENT_CLASSIFY_H