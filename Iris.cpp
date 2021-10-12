#include "Iris.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using namespace std;

Iris::Iris(std::vector<double> par, string type, string distanceType) {
    this->par = par;
    this->distanceType = std::move(distanceType);
    this->type = std::move(type);
}

double Iris::getDistance(Iris other) {
    double theDistance = 0;
    for (int i = 0; i < this->par.size(); ++i) {
        if (this->distanceType == "EUC") {
            theDistance += pow(this->par[i] - other.getPar()[i], 2);
        } else if (this->distanceType == "MAN") {
            theDistance += abs(this->par[i] - other.getPar()[i]);
        } else if (this->distanceType == "CHE") {
            if (theDistance < abs(this->par[i] - other.getPar()[i])) {
                theDistance = abs(this->par[i] - other.getPar()[i]);
            }
        }
    }
    if (this->distanceType == "EUC") {
        return sqrt(theDistance);
    }
    if (this->distanceType == "MAN" || this->distanceType == "CHE") {
        return theDistance;
    }
}

string Iris::getType() {
    return this->type;
}

std::vector<string> Iris::strToVector(const std::string &str, const char identifier) {
    std::stringstream ss(str);
    std::string theString;
    std::vector<std::string> output;
    while (std::getline(ss, theString, identifier)) {
        output.push_back(theString);
    }
    return output;
}

string Iris::vectorToStr(std::vector<string> list, char identifier) {
    string str;
    for (string string1:list) {
        str += string1;
        str += identifier;
    }
    return str;
}

std::vector<double> Iris::getPar() {
    return this->par;
}
