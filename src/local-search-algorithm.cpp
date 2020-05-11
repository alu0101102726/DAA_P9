#include "local-search-algorithm.hpp"

/**
 * @brief Construye la segunda version del algoritmo greedy con un nombre asociado, además
 * de una dimensión que es la que va a tener los vectores
 * 
 * @param newName Nuevo nombre del algoritmo
 * @param newM Tamaño de la solución
 */
LocalSearch::LocalSearch(std::string newName, int newM) {
  name = newName;
  m = newM;
}

std::vector<int> LocalSearch::randomSolution() {
  std::vector<int> auxSolution;
  for (int currentSolution = 0; currentSolution < m; currentSolution++) {
    int randomSol = rand() % currentVectors.getSize();
    auxSolution.push_back(randomSol);
  }
  return auxSolution;
}

Solution LocalSearch::run() {
  std::vector<int> solution = randomSolution();
  float distance = getTotalDistance(solution);
  std::vector<int> bestSolution = solution;
}