#ifndef UNTITLED_KNN_H
#define UNTITLED_KNN_H

#include <vector>
#include "../Iris.h"

class Knn {
private:
    int k;
    string distanceType;
public:
    /**
     * Creates a new Knn.
     */
    Knn();

    /**
     * Finds the type of an Iris.
     * @param iris Iris.
     * @param others std::vector<Iris>.
     * @param k int.
     * @return string.
     */
    string theType(Iris iris, std::vector<Iris> others);

    /**
     * Takes the input from a file with a given path.
     * @param path string.
     * @param isClassified bool.
     * @param others std::vector<Iris>.
     * @return std::vector<Iris>.
     */
    std::vector<Iris> input(string path, bool isClassified, std::vector<Iris> others);

    /**
     * Runs the Knn.
     * @param unclassified string.
     * @return std::vector<string>.
     */
    std::vector<string> run(string unclassified);

    /**
     * Sets the K.
     * @param x int
     */
    void setK(int x);

    /**
     * Sets the distance type.
     * @param x string.
     */
    void setDistanceType(string x);
};


#endif //UNTITLED_KNN_H