#ifndef CLIENT_COMMAND_H
#define CLIENT_COMMAND_H

#include <string>

using namespace std;

// abstract
class Command {
protected:
    string description;
public:
    virtual void execute(sockaddr_in sin, string input);
    string getDescription();
    static sockaddr_in connecting();
};


#endif //CLIENT_COMMAND_H
