#include "../include/gready-algorithm.hpp"
#include <vector>
#include <cmath>
#include <algorithm>

std::vector <int> GreadyAlgorithm::run(Graph currentGraph) {
  std::vector < int > solution = currentGraph.getMaxAfinnity();
  std::vector < int > auxSolution;

  while (auxSolution != solution) {
    float max = -9999999;
    auxSolution = solution;
    int Kmax;
    std::vector <int> auxPossibleEdge;
    for (int currentRow = 0; currentRow < currentGraph.getSize(); currentRow++) {
      if(std::find(solution.begin(), solution.end(), currentRow) == solution.end()) {
        auxPossibleEdge = solution;
        auxPossibleEdge.push_back(currentRow);
        float auxK = getMedianDispersion(auxPossibleEdge, currentGraph);
        if (auxK > max) {
          max = auxK;
          Kmax = currentRow;
        }        
      }
    }

    if(max >= getMedianDispersion(solution, currentGraph)) {
      solution.push_back(Kmax);
    }
  }

  return auxSolution;
}
