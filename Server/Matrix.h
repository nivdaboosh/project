#ifndef CLIENT_MATRIX_H
#define CLIENT_MATRIX_H


#include "Command.h"

class Matrix : public Command{
public:
    /**
     * Constructor.
     */
    Matrix() {
        this->description = "display algorithm confusion matrix";
    }

    void execute(Knn& knn, int client_sock);
};


#endif //CLIENT_MATRIX_H