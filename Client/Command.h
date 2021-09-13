#ifndef CLIENT_COMMAND_H
#define CLIENT_COMMAND_H

#include <string>
using namespace std;
// abstract
class Command {
protected:
    string description;
    // abstract
    void execute();
    string getDescription();
};


#endif //CLIENT_COMMAND_H
