#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>

#include "../Iris.h"
#include "Knn.h"

/**
 * Creates a new Knn.
 */
Knn::Knn() {
    this->k = 5;
    this->distanceType = "EUC";
}

/**
 *
 * @param iris - the iris to classify.
 * @param others - classified irises.
 * @return the type of unclassified iris.
 */
string Knn::theType(Iris iris, std::vector<Iris> others) {
    std::vector<double> distances;
    std::map<double, Iris> map;
    for (int i = 0; i < others.size(); i++) {
        distances.push_back(iris.getDistance(others[i]));
        map.insert(std::pair<double, Iris>(distances[i], others[i]));
    }
    std::sort(distances.begin(), distances.end());
    std::map<string, int> numMap;
    string theKey;
    for (int i = 0; i < k; ++i) {
        auto iterator = map.find(distances[i]);

        if (!numMap.count(iterator->second.getType())) {
            numMap.insert(std::pair<string, int>(iterator->second.getType(), 1));
            this->allTypes.push_back(iterator->second.getType());
        } else {
            numMap.insert(std::pair<string, int>(iterator->second.getType(),
                                                 numMap.find(iterator->second.getType())->second + 1));
        }

        int max = 0;
        for (const auto &myPair : numMap) {
            if (numMap.find(myPair.first)->second > max) {
                max = numMap.find(myPair.first)->second;
                theKey = myPair.first;
            }
        }
    }
    return theKey;
}

/**
 * input function.
 * @param path - the path to files classified or unclassified.
 * @param isClassified - bool param - present classify or not.
 * @param others - classified irises
 * @param k - the amount of the nearest irises to classify by.
 * @return irises vector.
 */
std::vector<Iris> Knn::input(string path, bool isClassified, std::vector<Iris> others) {
    ifstream file(path);
    std::vector<Iris> irises;
    string myText;
    while (std::getline(file, myText)) {
        double x = std::stod(std::strtok(const_cast<char *>(myText.c_str()), ","));
        double y = std::stod(std::strtok(nullptr, ","));
        double z = std::stod(std::strtok(nullptr, ","));
        double w = std::stod(std::strtok(nullptr, ","));
        string isType;
        if (isClassified) {
            isType = std::strtok(nullptr, ",");
        }
        string type;
        if (isClassified) {
            type = isType;
        } else {
            Iris helper = Iris(x, y, z, w, "", this->distanceType);
            type = theType(helper, others);
        }
        irises.emplace_back(x, y, z, w, type, this->distanceType);
    }
    file.close();
    return irises;
}

/**
 * main - starts the program.
 * @return 0.
 */
std::vector<string> Knn::run(string classified, string unclassified) {
    string pathC = std::move(classified);
    string pathU = std::move(unclassified);
    std::vector<Iris> nullVector;
    std::vector<Iris> classifieds = input(std::string(pathC), true, nullVector);
    std::vector<Iris> irises = input(std::string(pathU), false, classifieds);
    std::vector<string> output;
    for (int i = 0; i < irises.size(); ++i) {
        output.push_back(irises[i].getType());
    }
    return output;
}

void Knn::setK(int x) {
    this->k = x;
}

void Knn::setDistanceType(string x) {
    this->distanceType = std::move(x);
}

int Knn::getK() {
    return this->k;
}

string Knn::getDistance() {
    return this->distanceType;
}

void Knn::setTrain(string x) {
    this->train = std::move(x);
}

void Knn::setTest(string x) {
    this->test = std::move(x);
}

string Knn::getTrain() {
    return this->train;
}

string Knn::getTest() {
    return this->test;
}

string Knn::getTypes() {
    return this->types;
}

void Knn::setTypes(string x) {
    this->types = std::move(x);
}

std::vector<string> Knn::getAllTypes() {
    return this->allTypes;
}