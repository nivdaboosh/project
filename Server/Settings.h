#ifndef CLIENT_SETTINGS_H
#define CLIENT_SETTINGS_H


#include "Command.h"

class Settings : public Command{
public:
    /**
     * Constructor.
     */
    Settings() {
        this->description = "algorithm settings";
    }

    void execute(Knn knn, int client_sock);
};


#endif //CLIENT_SETTINGS_H