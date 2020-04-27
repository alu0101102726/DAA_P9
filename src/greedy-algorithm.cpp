#include "greedy-algorithm.hpp"
#include <vector>
#include <cmath>
#include <algorithm>
 /**
  * @brief Construye el algoritmo grady, asignando un nombre.
  * 
  * @param newName Representa el nombre del algoritmo
  */
GreedyAlgorithm::GreedyAlgorithm(std::string newName) {
  name = newName;
}

/**
 * @brief Se va a encargar de ejecutar el algoritmo greedy, para
 * ello se van a hacer iteraciones hasta que las soluciones sean
 * iguales, determinando en otro bucle (que recorre el número de
 * nodos del grafo), hallando la dispersion media en cada momento
 * y comrpobando si es la máxima. En caso de que lo sea se vuelve
 * a asignar al máximo.
 * 
 * En el caso de la solución se pasa un 2 para indicar que en las búsquedas
 * greedy no hay distinción de búsqueda local greedy o ansiosa.
 * 
 * @param currentGraph Representa el grafo con las distancias entre nodos
 * @return Solution Representa el objeto solución que contiene la solución del
 * problema
 */
Solution GreedyAlgorithm::run(Graph currentGraph) {
  const int HASNOTLOCALSEARCH = 2;
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
        float auxK = getMeanDispersion(auxPossibleEdge, currentGraph);

        if (auxK > max) {
          max = auxK;
          Kmax = currentRow;
        }        
      }
    }

    if(max >= getMeanDispersion(solution, currentGraph)) {
      solution.push_back(Kmax);
    }
  }

  Solution newSolution(auxSolution, getMeanDispersion(auxSolution, currentGraph), getAlgorithmName(), HASNOTLOCALSEARCH);

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