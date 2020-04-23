#pragma once
#include <vector>
#include "algorithm.hpp"
#include "graph.hpp"

/**
 * @brief Esta clase representa el algoritmo constructivo
 * voraz del cual teniamos el pseudocódigo.
 * 
 */
class GreedyAlgorithm : public Algorithm {
    
  public:
    GreedyAlgorithm() {}
    ~GreedyAlgorithm() {}
    
    std::vector <int> run(Graph currentGraph);
    std::pair <int, int> getMaxEdge(std::vector <int> solution, Graph currentGraph);

};