#pragma once
#include <vector>
#include <cmath>
#include "algorithm.hpp"

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
    int m;
    int RCLsize;
    
  public:
    GraspAlgorithm(std::string newName, int newIterationsLimit, int newM, int newRCLsize);
    ~GraspAlgorithm() {}
    
    Solution run();
    std::vector <int> preprocessing();
    std::vector <int> constructSolution();
    std::vector <int> makeRCL(std::vector<int> currentSolution);
    std::vector <int> localSearch(std::vector <int> solution);

    std::vector <int> notSelectedNodes(std::vector<int> checkSelected, int nodeNumber);
};