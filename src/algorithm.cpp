#include "../include/algorithm.hpp"

/**
 * @brief Este método se encarga de determinar la dispersión media, que
 * se define por:
 *                Σi,j∈S  d(i,j)
 *              ___________________
 *                      |S| 
 * 
 * @param currentNodeSet Representa el conjunto de nodos que contiene
 * actualmente, sobre el que va a medir la dispersión media
 * @param currentGraph Representa el grafo con las distancias (aristas)
 * @return float Devuelve el valor de la dispersión media
 */
float Algorithm::getMedianDispersion(std::vector<int> currentNodeSet, Graph currentGraph) {
  float sumOfEdges = 0;
  if (currentNodeSet.size() == 0) {
    return -INFINITY;
  }
  for(int i = 0; i < currentNodeSet.size() - 1; i++) {
    for(int j = i + 1; j < currentNodeSet.size(); j++) {
      sumOfEdges += currentGraph.getNodeValue(currentNodeSet[i], currentNodeSet[j]);
    }
  }
  return sumOfEdges / currentNodeSet.size();
}

/**
 * @brief Esta funcion se va a encargar de devolver el valor peor de la dispersión
 * media, además en caso de que el tamaño del vector sea nulo, devuelve un valor -1, que
 * será el que usemos apra gestionar ese caso.
 * 
 * @param actualSolution Representa el vector sobre el que se va a evaluar
 * @param currentGraph Representa el grafo que contiene las distancias entre los nodos
 * @return int Devuelve un elemento aleatorio dentro del vector, debido a que puede que hayan
 * varias soluciones con el mismo valor y para evitar siempre devolver la primera.
 */
int Algorithm::getWorstMediaDispersion(std::vector<int> actualSolution, Graph currentGraph) {
    std::vector<int> kVertex;
    kVertex.push_back(-1);
    float current = getMedianDispersion(actualSolution, currentGraph);
    for(int i = 0; i < actualSolution.size(); i++) {
      const int vertex = actualSolution[i];
      actualSolution.erase(actualSolution.begin() + i);
      float testValue = getMedianDispersion(actualSolution, currentGraph);
      actualSolution.insert(actualSolution.begin() + i, vertex);
      if(testValue > current) {
        current = testValue;
        kVertex.clear();
        kVertex.push_back(i);
      } else if(testValue == current) {
        kVertex.push_back(i);
      }
    }
    
    int selectedK = rand() %  (kVertex.size());
    return kVertex[selectedK]; 
}