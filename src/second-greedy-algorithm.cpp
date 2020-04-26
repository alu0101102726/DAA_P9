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
 * en vez de ir añadiendo, en este caso se van eliminando.
 * 
 * En el caso de la solución se pasa un 2 para indicar que en las búsquedas
 * greedy no hay distinción de búsqueda local greedy o ansiosa.
 * 
 * @param currentGraph Representa el grafo actual
 * @return std::vector <int> Representa la solución
 */
Solution SecondGreedyAlgorithm::run(Graph currentGraph) {  
  const int HASNOTLOCALSEARCH = 2;
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
        float auxK = getMeanDispersion(auxPossibleEdge, currentGraph);
        if (auxK > max) {
          max = auxK;
          Kmax = currentRow;
        }  
      } 
    }

    if(max >= getMeanDispersion(solution, currentGraph)) {
      solution.erase(std::find(solution.begin(), solution.end(), Kmax));
    }
  }

  Solution newSolution(auxSolution, getMeanDispersion(auxSolution, currentGraph), getAlgorithmName(), HASNOTLOCALSEARCH);
  
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