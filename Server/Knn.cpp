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
    for (int i = 0; i < this->k; ++i) {
        auto iterator = map.find(distances[i]);

        if (!numMap.count(iterator->second.getType())) {
            numMap.insert(std::pair<string, int>(iterator->second.getType(), 1));
            if (!std::count(this->allTypes.begin(), this->allTypes.end(), iterator->second.getType()))
                this->allTypes.push_back(iterator->second.getType());
        } else {
            numMap.insert(std::pair<string, int>(iterator->second.getType(),
                                                 numMap.find(iterator->second.getType())->second + 1));
        }
    }
    int max = 0;
    for (const auto &myPair : numMap) {
        if (numMap.find(myPair.first)->second > max) {
            max = numMap.find(myPair.first)->second;
            theKey = myPair.first;
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
    if (!isClassified) {
        int theSize = this->allTypes.size();
        for (int i = 0; i < theSize; ++i) {
            this->allTypes.pop_back();
        }
    }
    ifstream file(path);
    std::vector<Iris> irises;
    string myText;
    string isNull = "not null";
    string type;
    while (std::getline(file, myText)) {
        std::vector<double> pars;
        pars.push_back(std::stod(std::strtok(const_cast<char *>(myText.c_str()), ",")));
        while (isNull != "") {
            isNull = std::strtok(nullptr, ",");
            try {
                pars.push_back(std::stod(isNull));
            }
            catch (exception exception) {
                type = isNull;
                break;
            }
        }

        if (!isClassified) {
            Iris helper = Iris(pars, "", this->distanceType);
            type = theType(helper, others);
        }
        irises.emplace_back(pars, type, this->distanceType);
    }
    file.close();
    return irises;
}

/**
 * main - starts the program.
 * @return 0.
 */
void Knn::run(string classified, string unclassified) {
    string pathC = std::move(classified);
    string pathU = std::move(unclassified);
    std::vector<Iris> nullVector;
    std::vector<Iris> classifieds = input(std::string(pathC), true, nullVector);
    std::vector<Iris> irises = input(std::string(pathU), false, classifieds);
    std::vector<string> output;
    for (int i = 0; i < irises.size(); ++i) {
        output.push_back(irises[i].getType());
    }
    this->setTypes(Iris::vectorToStr(output, '$'));
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