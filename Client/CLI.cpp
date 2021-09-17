#include <iostream>
#include <algorithm>
#include <string>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <vector>

#include "CLI.h"
#include "Command.h"
#include "Upload.h"
#include "Settings.h"
#include "Classify.h"
#include "Display.h"
#include "Download.h"
#include "Matrix.h"

using namespace std;

void CLI::start() {
    Command commands[] = {Upload(), Settings(), Classify(), Display(), Download(), Matrix()};
    int counter = 1;
    while (true) {
        cout << "Welcome to the KNN Classifier Server. Please choose an option:" << endl;
        for (Command command:commands) {
            cout << counter++ << "." << "\t" << command.getDescription() << endl;
        }
        cout << "7." << "\t" << "exit" << endl;
        string input;
        getline(cin, input);
        if (input == "7") {
            exit(1);
        }
        sockaddr_in sin=Command::connecting();
        commands[stoi(input)].execute(sin);
        counter = 1;
    }
}
