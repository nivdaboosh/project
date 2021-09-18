#include<sstream>
#include <sys/socket.h>
#include <netinet/in.h>

#include "Settings.h"
#include "Knn.h"

Settings::Settings() {
    this->description = "algorithm settings";
}

string Command::execute(Knn knn) {
    // return pair.
    return "The current KNN parameters are: K = " + std::to_string(knn.getK())
           + ", distance metric = " + knn.getDistance();
}