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
  for(int i = 0; i < currentNodeSet.size() - 1; i++) {
    for(int j = i + 1; j < currentNodeSet.size(); j++) {
      sumOfEdges += currentGraph.getNodeValue(currentNodeSet[i], currentNodeSet[j]);
    }
  }
  return sumOfEdges / currentNodeSet.size();
}

/**
 * @brief Esta funcion se encarga de imprimir la solución que ha
 * obtenido el algoritmo en un determinado tiempo de ejecución
 * 
 * @param solution Representa la solución del algoritmo 
 * @param runTime Representa el tiempo de ejecución que ha tardado el
 * algoritmo en hallar la solución.
 */
void Algorithm::printSolution(std::vector <int> solution, int runTime, Graph currentGraph) {
}