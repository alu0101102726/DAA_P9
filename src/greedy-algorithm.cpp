#include "../include/greedy-algorithm.hpp"
#include <vector>
#include <cmath>
#include <algorithm>

GreedyAlgorithm::GreedyAlgorithm(std::string newName) {
  name = newName;
}

Solution GreedyAlgorithm::run(Graph currentGraph) {
  std::vector < int > solution = getMaxAfinnity(currentGraph);
  std::vector < int > auxSolution;

  while (auxSolution != solution) {
    float max = -INFINITY;
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

  Solution newSolution(auxSolution, getMedianDispersion(auxSolution, currentGraph), getAlgorithmName());

  return newSolution;
}


/**
 * @brief Este método se encarga de encontrar la arista que tiene
 * una mayor afinidad
 * 
 * @return std::vector < int > Representa los nodos cuya arista es la mayor
 */
std::vector < int > GreedyAlgorithm::getMaxAfinnity(Graph currentGraph) {
  float max = -9999999;
  std::vector < std::pair <int, int> > maxElements;
  for(int i = 0; i < currentGraph.getSize() - 1; i++) {
    for(int j = i + 1; j < currentGraph.getSize(); j++) {
      if(currentGraph.getNodeValue(i, j) > max) {
        max = currentGraph.getNodeValue(i, j);
      }
      else if(currentGraph.getNodeValue(i, j) == max) {
        maxElements.push_back(std::make_pair(i, j));        
      }
    }
  }

  srand(time(NULL));
  std::vector <int> aux;

  int index = rand() % maxElements.size();
  aux.push_back(maxElements[index].first);
  aux.push_back(maxElements[index].second);

  return aux;
}

/**
 * @brief Devuelve el nombre del algoritmo
 * 
 * @return std::string nombre del algoritmo
 */
std::string GreedyAlgorithm::getAlgorithmName() {
  return name;
}