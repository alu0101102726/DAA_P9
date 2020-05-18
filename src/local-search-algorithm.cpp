#include "local-search-algorithm.hpp"

/**
 * @brief Construye la segunda version del algoritmo greedy con un nombre asociado, además
 * de una dimensión que es la que va a tener los vectores
 * 
 * @param newName Nuevo nombre del algoritmo
 * @param newM Tamaño de la solución
 * @param otherAlgorithm Nombre del algoritmo que da el valor de la solución inicial
 * @param algSolution Solución proporcionada por otro algoritmo
 */
LocalSearch::LocalSearch(std::string newName, int newM, std::string otherAlgorithm, Solution algSolution){
  name = newName;
  m = newM;
  sol = algSolution.getSolution();
}

/**
 * @brief Algoritmo que se encarga de hacer la búsqueda local. Parte de una
 * solución inicial proporcionada por otro algoritmo. A partir de esta va haciendo
 * búsquedas locales hasta que la solución que obtenga sea peor a la mejor obtenida.
 * La búsqueda local se basa en un intercambio de los elementos que se encuentran en
 * la solución y aquellos que no lo están.
 * 
 * @return Solution Valor de la solución del algoritmo
 */
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

/**
 * @brief La búsqueda local se basa en un intercambio de los elementos que se encuentran en
 * la solución y aquellos que no lo están. En caso de que mejore se modifica la mejor
 * solución.
 * 
 * @param solution Vector sobre el que se va a hacer la búsqueda local.
 * @return std::vector <int> Nueva solución obtenida
 */
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