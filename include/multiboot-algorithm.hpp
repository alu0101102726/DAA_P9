#pragma once
#include <vector>
#include "algorithm.hpp"
#include "graph.hpp"
#include "solution.hpp"
#include <algorithm>

/**
 * @brief Esta clase representa el algoritmo multiarranque
 */
class MultibootAlgorithm : public Algorithm {

  private:
    std::string name;
    int iterationsLimit;
    int noImprovementiterationsLimit;
    
  public:
    MultibootAlgorithm(std::string newName, int newIterationsLimit, int noImprovementiterationsLimit);
    ~MultibootAlgorithm() {}

    std::string getAlgorithmName();
    int getIterationsLimit();
    int getnoImprovementiterationsLimit();
    
    Solution run(Graph currentGraph);
    std::vector <int> preprocessing(Graph currentGraph);
    std::vector <int> constructSolution(std::vector <int> solution, Graph currentGraph);
    std::vector <int> greedyLocalSearch(std::vector <int> solution, Graph currentGraph);
    std::vector <int> anxiousLocalSearch(std::vector <int> solution, Graph currentGraph);

    std::vector <int> notSelectedNodes(std::vector<int> checkSelected, int nodeNumber);
};