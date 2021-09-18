#ifndef CLIENT_COMMAND_H
#define CLIENT_COMMAND_H

#include <string>
#include "Knn.h"

using namespace std;

// abstract
class Command {
protected:
    string description;
public:
    virtual string execute(Knn knn);
    string getDescription();
    static sockaddr_in connecting();
};


#endif //CLIENT_COMMAND_H
