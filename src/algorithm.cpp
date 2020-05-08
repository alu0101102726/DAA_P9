#include "../include/algorithm.hpp"

std::vector <float> Algorithm::getGravityCenter(std::vector <int> currentElement, Vectors currentVector) {
  std::vector <float> center;
  for (int index = 0; index < currentVector.getDimension(); index++) {
    float currentSum = 0;
    for (int i = 0; i < currentElement.size(); i++) {
      currentSum += currentVector.getDataValue(currentElement[i], index);
    }
    center.push_back(currentSum / currentElement.size());
  }
  return center;
}