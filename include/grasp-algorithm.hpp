#pragma once
#include <vector>
#include "algorithm.hpp"
#include "graph.hpp"
#include <cmath>

/**
 * @brief Esta clase representa el algoritmo GRASP que se va a aplicar,
 * vamos a tener tres fases en el mismo:
 *  - Preprocesamiento
 *  - Construcción
 *  - Búsqueda
 */
class GraspAlgorithm : public Algorithm {

  private:
    std::string name;
    int iterationsLimit;
    int noImprovementiterationsLimit;
    
  public:
    GraspAlgorithm(std::string newName, int newIterationsLimit, int noImprovementiterationsLimit);
    ~GraspAlgorithm() {}

    std::string getAlgorithmName();
    int getIterationsLimit();
    int getnoImprovementiterationsLimit();
    
    Solution run(Graph currentGraph);
    std::vector <int> preprocessing(Graph currentGraph);
    std::vector <int> constructSolution(std::vector <int> solution, Graph currentGraph);
    std::vector <int> makeRCL(std::vector<int> currentSolution, std::vector <int> RCL, Graph currentGraph);
    std::vector <int> localSearch(std::vector <int> solution, Graph currentGraph);

    std::vector <int> notSelectedNodes(std::vector<int> checkSelected, int nodeNumber);
};