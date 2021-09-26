#ifndef UNTITLED_KNN_H
#define UNTITLED_KNN_H

#include <vector>
#include "../Iris.h"

class Knn {
private:
    int k;
    string distanceType;
    string train;
    string test;
    string types;
    std::vector<string> allTypes;
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
    std::vector<string> run(string classified, string unclassified);

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

    /**
     * Returns the K.
     * @return int.
     */
    int getK();

    /**
     * Returns the distance type.
     * @return string.
     */
    string getDistance();

    /**
     * Sets the train file.
     * @param x string.
     */
    void setTrain(string x);

    /**
     * Sets the test file.
     * @param x string.
     */
    void setTest(string x);

    /**
     * Returns the train file.
     * @return string.
     */
    string getTrain();

    /**
     * Returns the test file.
     * @return string.
     */
    string getTest();

    /**
     * Sets the types.
     * @param x string.
     */
    void setTypes(string x);

    /**
     * Returns the types.
     * @return string.
     */
    string getTypes();

    /**
     * Returns the vector of all types.
     * @return std::vector<string>.
     */
    std::vector<string> getAllTypes();
};

#endif //UNTITLED_KNN_H