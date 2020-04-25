#pragma once
#include <vector>
#include "algorithm.hpp"
#include "graph.hpp"
#include "solution.hpp"
#include <algorithm>

/**
 * @brief Esta clase representa el algoritmo multiarranque
 */
class VariableNeighborhoodSearch : public Algorithm {

  private:
    std::string name;
    int iterationsLimit;
    int noImprovementiterationsLimit;
    int kmax;
    
  public:
    VariableNeighborhoodSearch(std::string newName, int newIterationsLimit, int noImprovementiterationsLimit, int newKmax);
    ~VariableNeighborhoodSearch() {}

    std::string getAlgorithmName();
    int getIterationsLimit();
    int getnoImprovementiterationsLimit();
    int getKmax();
    
    Solution run(Graph currentGraph);
    std::vector <int> shake(std::vector <int> solution, int currentK, int newSolution);
    std::vector <int> constructSolution(std::vector <int> candidates, int size);
    std::vector <int> greedyLocalSearch(std::vector <int> solution, Graph currentGraph);
};