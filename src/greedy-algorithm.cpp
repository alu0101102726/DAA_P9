#include "greedy-algorithm.hpp"

GreedyAlgorithm::GreedyAlgorithm(std::string newName, int newM):
  currentVectors() {
  name = newName;
  m = newM;
}

int GreedyAlgorithm::getMvalue() {
  return m;
}

std::string GreedyAlgorithm::getAlgorithmName() {
  return name;
}

void GreedyAlgorithm::setInfo(Vectors newVector) {
  currentVectors = newVector;
}

Solution GreedyAlgorithm::run() {
  std::vector <int> Elem;
  std::vector <int> S;
  for (int i = 0; i < currentVectors.getSize(); i++) {
    Elem.push_back(i);
  }
  std::vector <float> SC = getGravityCenter(Elem, currentVectors);
  while(S.size() != getMvalue()) {
    int furthest = getFurthestElement(Elem, SC);
    S.push_back(furthest);
    Elem.erase(std::find(Elem.begin(), Elem.end(), furthest));
    SC = getGravityCenter(S, currentVectors);
  }

  Solution newSolution(currentVectors, S, getAlgorithmName());
  return newSolution;
}

int GreedyAlgorithm::getFurthestElement(std::vector <int> currentElem, std::vector <float> currentSC) {
    float distance = 0;
    int sol;
    std::vector<int> repeat;

    for (int i = 0; i < currentElem.size(); i++){
      float aux = 0;
      for(int j = 0; j < currentVectors.getDimension(); j++){
        aux += pow(currentSC[j] - currentVectors.getDataValue(currentElem[i], j), 2);
      }

      aux = sqrt(aux);
      if (aux > distance) {
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