#ifndef CLIENT_DOWNLOAD_H
#define CLIENT_DOWNLOAD_H


#include "Command.h"

class Download : public Command{
public:
    /**
     * Constructor.
     */
    Download() {
        this->description = "download results";
    }

    /**
     * Execute.
     * @param knn Knn.
     * @param client_sock int.
     */
    void execute(Knn& knn, int client_sock);
};


#endif //CLIENT_DOWNLOAD_H