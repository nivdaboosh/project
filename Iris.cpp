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


Iris::Iris(double x, double y, double z, double w, string type, string distanceType) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
    this->distanceType = std::move(distanceType);
    this->type = std::move(type);
}

double Iris::getDistance(Iris other) {
    double powX = pow(this->x - other.x, 2);
    double powY = pow(this->y - other.y, 2);
    double powZ = pow(this->z - other.z, 2);
    double powW = pow(this->w - other.w, 2);
    if (this->distanceType == "EUC") {
        return sqrt(powX + powY + powZ + powW);
    } else if (this->distanceType == "MAN") {
        return abs(powX) + abs(powY) + abs(powZ) + abs(powW);
    } else if (this->distanceType == "CHE") {
        return max(max(abs(powX), abs(powY)), max(abs(powZ), abs(powW)));
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