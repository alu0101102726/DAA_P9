#pragma once
#include <vector>
#include "algorithm.hpp"
#include "graph.hpp"
#include "solution.hpp"

/**
 * @brief Esta clase representa el segundo algoritmo constructivo
 * voraz del cual la idea ha sido partir de una lista con todo el
 * conjunto de nodos e ir eliminando de la misma.
 */
class SecondGreedyAlgorithm : public Algorithm {

  private:
    std::string name;
    
  public:
    SecondGreedyAlgorithm(std::string newName);
    ~SecondGreedyAlgorithm() {}
    
    Solution run(Graph currentGraph);
    std::string getAlgorithmName();

};