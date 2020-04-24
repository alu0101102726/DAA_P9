#pragma once
#include <vector>
#include "algorithm.hpp"
#include "graph.hpp"
#include "solution.hpp"

/**
 * @brief Esta clase representa el algoritmo constructivo
 * voraz del cual teniamos el pseudocódigo.
 */
class GreedyAlgorithm : public Algorithm {

  private:
    std::string name;
    
  public:
    GreedyAlgorithm(std::string newName);
    ~GreedyAlgorithm() {}
    
    Solution run(Graph currentGraph);
    std::string getAlgorithmName();
    std::vector < int > getMaxAfinnity(Graph currentGraph);

};