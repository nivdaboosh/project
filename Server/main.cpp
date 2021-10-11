#include <string>

#include "TCPServer.h"
#include "CLI.h"

/**
 * The main of the server.
 * @param argc int.
 * @param argv char*[]
 * @return int.
 */
int main(int argc, char *argv[]) {
    CLI c = CLI();
    c.start();
}