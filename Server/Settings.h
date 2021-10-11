#ifndef CLIENT_SETTINGS_H
#define CLIENT_SETTINGS_H


#include "Command.h"

class Settings : public Command {
public:
    /**
     * Constructor.
     */
    Settings() {
        this->description = "algorithm settings";
    }

    /**
     * Execute.
     * @param knn Knn.
     * @param client_sock int.
     */
    void execute(Knn &knn, int client_sock);
};


#endif //CLIENT_SETTINGS_H