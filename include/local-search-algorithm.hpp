#pragma once
#include "algorithm.hpp"
#include "greedy-algorithm.hpp"
#include "vectors.hpp"
#include <algorithm>

/**
 * @brief Esta clase representa el algoritmo LocalSearch, que realiza
 * una búsqueda local a partir de una solución obtenida por otro algoritmo,
 * intentando mejorarla.
 */
class LocalSearch : public Algorithm {

  private:
    std::string name;
    int m;
    std::vector<int> sol;
  
  public:
    LocalSearch(std::string newName, int newM, std::string otherAlgorithm, Solution algSolution);
    ~LocalSearch() {}

    Solution run();
    std::vector <int> localSearch(std::vector <int> solution);
};