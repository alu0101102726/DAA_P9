#pragma once
#include <vector>
#include "algorithm.hpp"
#include "graph.hpp"

/**
 * @brief Esta clase representa el algoritmo GRASP que se va a aplicar,
 * vamos a tener tres fases en el mismo:
 *  - Preprocesamiento
 *  - Construcción
 *  - Búsqueda
 */
class GraspAlgorithm : public Algorithm {
    
  public:
    GraspAlgorithm() {}
    ~GraspAlgorithm() {}
    
    Solution run(Graph currentGraph);
    Graph preprocessing(Graph currentGraph);
    std::vector <int> construcSolution(std::vector <int> solution);
    int localSearch(std::vector <int> solution);

};