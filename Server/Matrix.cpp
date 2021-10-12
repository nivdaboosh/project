#include <map>

#include "Matrix.h"
#include "Knn.h"
#include "TCPServer.h"

void Matrix::execute(Knn& knn, int client_sock) {
    std::vector<string> calculated = Iris::strToVector(knn.getTypes(), '$');
    std::vector<Iris> nullVector;
    std::vector<Iris> origin = knn.input(knn.getTest(), true, nullVector);
    std::vector<string> strings = knn.getAllTypes();
    double precents[strings.size() * strings.size()];
    double numType[strings.size()];
    for (int i = 0; i < origin.size(); ++i) {
        for (int j = 0; j < strings.size(); ++j) {
            if (origin[i].getType() == strings[j]) {
                for (int k = 0; k < strings.size(); ++k) {
                    if (calculated[i] == strings[k]) {
                        ++precents[strings.size() * j + k];
                    }
                }
                ++numType[j];
            }
        }
    }

    std::vector<string> list;
    string line;
    for (int i = 0; i < strings.size() * strings.size(); i++) {
        if (i % strings.size() == 0) {
            if (i != 0) {
                list.push_back(line);
                line = "";
            }
            line += strings[i / strings.size()] + "\t";
        }
        if (i % strings.size() != strings.size() - 1)
            line += to_string(100 * precents[i] / numType[i / strings.size()]) + "%" + "\t";
        else
            line += to_string(100 * precents[i] / numType[i / strings.size()]) + "%";
    }
    list.push_back(line);
    list.push_back("The current KNN parameters are: K = " + std::to_string(knn.getK())
                   + ", distance metric = " + knn.getDistance());

    string output = Iris::vectorToStr(list, '$');
    TCPServer::sendMessage(output, client_sock);

    TCPServer::readMessage(client_sock);
}