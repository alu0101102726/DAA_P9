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
float Algorithm::getMeanDispersion(std::vector<int> currentNodeSet, Graph currentGraph) {
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
 * @brief Este método se ha creado para que no sea necesario calcular desde 0
 * la dispersion media sino que se parta del resultado anterior.
 * 
 * @param currentSol Representa el vector sobre el que se va a calcular la dispersion
 * media.
 * @param currentEdgeSum Representa el valor del sumatorio de las aristas
 * @param currentNode Representa el nodo que se va a eliminar de la solución
 * @param currentGraph Representa el grafo con las distancias entre nodos
 * @return float Devuelve el valor de la dispersión media
 */
float Algorithm::getNewMeanDispersionErase(std::vector<int> currentSol, float currentEdgeSum, int currentNode, Graph currentGraph){
  float sumOfEdges = currentEdgeSum;
  if(currentSol.size() == 0 ){
    return -INFINITY;
  }
  for(int i = 0; i < currentSol.size(); i++) {
    sumOfEdges -= currentGraph.getNodeValue(currentSol[i], currentNode);
  }
  return sumOfEdges / (currentSol.size() - 1);
}

/**
 * @brief Esta funcion se va a encargar de devolver el valor peor de la dispersión
 * media, se aplica de forma greedy además en caso de que el tamaño del vector sea nulo, devuelve un valor -1, que
 * será el que usemos apra gestionar ese caso.
 * 
 * @param actualSolution Representa el vector sobre el que se va a evaluar
 * @param currentGraph Representa el grafo que contiene las distancias entre los nodos
 * @return int Devuelve un elemento aleatorio dentro del vector, debido a que puede que hayan
 * varias soluciones con el mismo valor y para evitar siempre devolver la primera.
 */
int Algorithm::getWorstMeanDispersionGreedy(std::vector<int> actualSolution, Graph currentGraph) {
    std::vector<int> kVertex;
    kVertex.push_back(-1);
    float current = getMeanDispersion(actualSolution, currentGraph);
    float currentEdgeSum =  current * actualSolution.size();
    for(int i = 0; i < actualSolution.size(); i++) {
      const int vertex = actualSolution[i];
      float testValue = getNewMeanDispersionErase(actualSolution, currentEdgeSum, vertex, currentGraph);
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

/**
 * @brief Esta funcion se va a encargar de devolver el valor peor de la dispersión
 * media, se aplica de forma ansiosa, es decir, desde que se encuentre alguno mejor se va a
 * devolver. En caso de que el vector esté vacío o no haya ninguno mejor se va a retornar un -1
 *  
 * @param actualSolution Representa el vector sobre el que se va a evaluar
 * @param currentGraph Representa el grafo que contiene las distancias entre los nodos
 * @return int Devuelve un elemento aleatorio dentro del vector, debido a que puede que hayan
 * varias soluciones con el mismo valor y para evitar siempre devolver la primera.
 */
int Algorithm::getWorstMeanDispersionAnxious(std::vector<int> actualSolution, Graph currentGraph) {
    float current = getMeanDispersion(actualSolution, currentGraph);
    float currentEdgeSum =  current * actualSolution.size();
    for(int i = 0; i < actualSolution.size(); i++) {
      const int vertex = actualSolution[i];
      float testValue = getNewMeanDispersionErase(actualSolution, currentEdgeSum, vertex, currentGraph);
      if(testValue > current) {
        current = testValue;
        return i;
      }
    }
    return -1;
}