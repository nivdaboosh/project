#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

#ifndef UNTITLED_IRIS_H
#define UNTITLED_IRIS_H

/**
 * class Iris.
 * double x,y,w,z
 */
class Iris {
private:
    std::vector<double> par;
    string type;
    string distanceType;
public:
    /**
     * Constructor. Creates a new Iris.
     * @param par std::vector<double>.
     * @param type string.
     * @param distanceType string.
     */
    Iris(std::vector<double> par, string type, string distanceType);

    /**
     * Calculates the distance from a Iris to an other Iris.
     * @param other - the iris to get the distance from.
     * @return -double distance.
     */
    double getDistance(Iris other);

    /**
     * @return Returns the type of the Iris.
     */
    string getType();

    /**
     * Turns a vector to a string.
     * @param list std::vector<string>
     * @param identifier char
     * @return std::vector<string>.
     */
    static string vectorToStr(std::vector<string> list, char identifier);

    /**
     * Turns a string to a vector.
     * @param str const std::string &
     * @param identifier const char
     * @return std::vector<string>.
     */
    static std::vector<string> strToVector(const std::string &str, const char identifier);

    std::vector<double> getPar();
};

#endif //UNTITLED_IRIS_H};