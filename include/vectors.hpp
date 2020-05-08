#pragma once
#include <vector>
#include <string>
#include <cmath>
#include "file.hpp"

class Vectors {

  private:
    std::vector < std::vector < float > > data;
    int dimension;

  public:
    Vectors() {}
    Vectors(std::string fileName);
    Vectors(std::vector < std::vector < float > > otherVect);
    ~Vectors() {};

    int getDimension();
    float getDataValue(int currentElement, int K);
    std::vector < std::vector < float > > getData();
    friend std::ostream& operator <<(std::ostream& os, Vectors currentData);
    int getSize();
    int getElementSize(int position);
    float getEuclideanDistance(int firstVect, int secondVect);
};