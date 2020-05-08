#include "greedy-algorithm-2.hpp"

NewGreedyAlgorithm::NewGreedyAlgorithm(std::string newName, int newM):
  currentVectors() {
  name = newName;
  m = newM;
}

int NewGreedyAlgorithm::getMvalue() {
  return m;
}

std::string NewGreedyAlgorithm::getAlgorithmName() {
  return name;
}

void NewGreedyAlgorithm::setInfo(Vectors newVector) {
  currentVectors = newVector;
}

Solution NewGreedyAlgorithm::run() {
  std::vector <int> Elem;
  for (int i = 0; i < currentVectors.getSize(); i++) {
    Elem.push_back(i);
  }
  std::vector <int> S = Elem;
  std::vector <float> SC = getGravityCenter(Elem, currentVectors);
  while(S.size() != getMvalue()) {
    int closest = getClosestElement(Elem, SC);
    S.erase(std::find(S.begin(), S.end(), closest));
    Elem.erase(std::find(Elem.begin(), Elem.end(), closest));
    SC = getGravityCenter(S, currentVectors);
  }

  Solution newSolution(currentVectors, S, getAlgorithmName());
  return newSolution;
}

int NewGreedyAlgorithm::getClosestElement(std::vector <int> currentElem, std::vector <float> currentSC) {
    float distance = INFINITY;
    int sol;
    std::vector<int> repeat;

    for (int i = 0; i < currentElem.size(); i++){
      float aux = 0;
      for(int j = 0; j < currentVectors.getDimension(); j++){
        aux += pow(currentSC[j] - currentVectors.getDataValue(currentElem[i], j), 2);
      }

      aux = sqrt(aux);
      if (aux < distance) {
        distance = aux;
        sol = currentElem[i];
        repeat.clear();
        repeat.push_back(currentElem[i]);
      } else if (aux == distance) {
        repeat.push_back(currentElem[i]);
      }
    }

    if (repeat.size() > 1){
      int index = rand() % repeat.size();
      return repeat[index];
    }
    return sol;
}