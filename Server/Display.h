#ifndef CLIENT_DISPLAY_H
#define CLIENT_DISPLAY_H


#include "Command.h"

class Display : public Command{
public:
    /**
     * Constructor.
     */
    Display() {
        this->description="display results";
    }

    void execute(Knn knn, int client_sock);
};


#endif //CLIENT_DISPLAY_H