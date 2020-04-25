#include "../include/second-greedy-algorithm.hpp"
#include <vector>
#include <cmath>
#include <algorithm>

/**
 * @brief Construye la variante del algoritmo greedy con un nombre
 * 
 * @param newName Nombre del algoritmo
 */
SecondGreedyAlgorithm::SecondGreedyAlgorithm(std::string newName) {
  name = newName;
}

/**
 * @brief Representa la variante del algoritmo voraz que consiste
 * en partir de un vector que está lleno de todos los elementos y
 * en vez de ir añadiendo, en este caso se van eliminando
 * 
 * @param currentGraph Representa el grafo actual
 * @return std::vector <int> Representa la solución
 */
Solution SecondGreedyAlgorithm::run(Graph currentGraph) {
  std::vector < int > solution;
  for (int currentNode = 0; currentNode < currentGraph.gentNodeNumber(); currentNode++) {
    solution.push_back(currentNode);
  }
  std::vector < int > auxSolution;

  while (auxSolution != solution) {
    float max = -INFINITY;
    auxSolution = solution;
    int Kmax;
    std::vector <int> auxPossibleEdge;
    for (int currentRow = 0; currentRow < currentGraph.getSize(); currentRow++) {
      if(std::find(solution.begin(), solution.end(), currentRow) != solution.end()) {
        auxPossibleEdge = solution;
        auxPossibleEdge.erase(std::find(auxPossibleEdge.begin(), auxPossibleEdge.end(), currentRow));
        float auxK = getMedianDispersion(auxPossibleEdge, currentGraph);
        if (auxK > max) {
          max = auxK;
          Kmax = currentRow;
        }  
      } 
    }

    if(max >= getMedianDispersion(solution, currentGraph)) {
      solution.erase(std::find(solution.begin(), solution.end(), Kmax));
    }
  }

  Solution newSolution(auxSolution, getMedianDispersion(auxSolution, currentGraph), getAlgorithmName());
  
  return newSolution;
}

/**
 * @brief Devuelve el nombre del algoritmo
 * 
 * @return std::string nombre del algoritmo
 */
std::string SecondGreedyAlgorithm::getAlgorithmName() {
  return name;
}