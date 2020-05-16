#include "local-search-algorithm.hpp"

/**
 * @brief Construye la segunda version del algoritmo greedy con un nombre asociado, además
 * de una dimensión que es la que va a tener los vectores
 * 
 * @param newName Nuevo nombre del algoritmo
 * @param newM Tamaño de la solución
 */
LocalSearch::LocalSearch(std::string newName, int newM, std::string otherAlgorithm, Solution Greedy){
  name = newName;
  m = newM;
  greedy.setAtributtes(otherAlgorithm, newM);
  sol = Greedy.getSolution();
}

Solution LocalSearch::run() {
  std::vector<int> solution = sol;
  float distance = getTotalDistance(sol);
  bool isEqual = true;
  while (isEqual) {
    std::vector<int> bestSolution = localSearch(solution);
    if (getTotalDistance(bestSolution) > distance) {
      solution = bestSolution;
      distance = getTotalDistance(bestSolution);
    }
    else {
      isEqual = false;
    }
  }

  Solution newSolution(currentVectors, solution, name);
  return newSolution;
}

std::vector <int> LocalSearch::localSearch(std::vector <int> solution) {
    float distance = getTotalDistance(sol);
    std::vector<int> optimum;
    std::vector<int> aux = sol;
    bool change = false;
    do {
      std::vector<int> cand = getCandidates(aux);
      change = false;
      for(int i = 0; i < aux.size(); i++){
        int auxItem = aux[i];
        for (int j = 0; j < cand.size(); j++){
          aux[i] = cand[j];
          float auxDistance = getTotalDistance(aux);
          if (auxDistance > distance) {
            distance = auxDistance;
            optimum = aux;
            change = true;
          }
        }
        aux[i] = auxItem;
      }
    } while (change);
    return optimum;
}