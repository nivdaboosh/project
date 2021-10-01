#ifndef CLIENT_UPLOAD_H
#define CLIENT_UPLOAD_H


#include "Command.h"

class Upload : public Command {
public:
    /**
     * Constructor.
     */
    Upload() {
        this->description="upload an unclassified csv data file";
    }

    void execute(Knn& knn, int client_sock);
};


#endif //CLIENT_UPLOAD_H