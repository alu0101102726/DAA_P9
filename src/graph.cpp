#include "../include/graph.hpp"
#include "../include/file.hpp"
#include <string>
#include <limits>

/**
 * @brief Construye un objeto grafo y almacena la información
 * de los nodos y sus distancias en su atributo informacion
 * 
 * @param nombreFichero Representa el nombre del fichero que se
 * va a abrir para poder extraer los datos.
 */
Graph::Graph(std::string fileName) {
  File newFile(fileName);
  information = newFile.checkFileSyntax();
  nodeNumber = newFile.getNumberNodes();
}

/**
 * @brief Se encarga de devolver el valor de la distancia que hay entre
 * el nodo position.
 * 
 * @param position Representa la posición en el vector del nodo.
 * @return float Devuelve el valor de la distancia
 */
float Graph::getNodeValue(int positioni, int positionj) {
  return information[positioni][positionj];
}

/**
 * @brief Se encarga de devolver el tamaño del vector
 * 
 * @return int Valor del tamaño del vector
 */
int Graph::getSize() {
  return information.size();
}


/**
 * @brief Se encarga de devolver el número de nodos del grafo
 * 
 * @return int Representa el número de nodos del grafo
 */
int Graph::gentNodeNumber() {
  return nodeNumber;
}

/**
 * @brief Sobrecarga del operador de salida para poder mostrar el grafo
 * 
 * @param os Representa el std::cout para la impresión
 * @param grafoImprimir El grafo que se va a imprimir
 * @return std::ostream& Valor de lo que ha impreso
 */
std::ostream& operator <<(std::ostream& os, Graph printGraph) {
  os << " - - - - GRAFO - - - - \n";
  os << "i|j\t";

  for(int currentCol = 1; currentCol <= printGraph.getSize(); currentCol++) {
    os << currentCol << "\t";
  }

  os << "\n";
  
  for(int currentRow = 0; currentRow < printGraph.getSize(); currentRow++) {
    os << currentRow + 1 << "\t";
    for(int currentCol = 0; currentCol < printGraph.information[currentRow].size(); currentCol++) {
      os << printGraph.getNodeValue(currentRow,currentCol) << "\t";
    }
    os << "\n";
  }
  return os;
}
