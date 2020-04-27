#include "../include/file.hpp"

/**
 * @brief Construye un fichero y lo abre
 * 
 * @param nombreFichero Representa el nombre del fichero a abrir
 */
File::File(std::string fileName) {
  fileGraph.open(fileName, std::fstream::out);
  if (!fileGraph.good())
    throw std::runtime_error("Error al abrir el fichero");
}

/**
 * @brief En caso de que el fichero esté abierto, lo cierra
 * 
 */
File::~File() {
  if(fileGraph.is_open()){
    fileGraph.close();
  }
}

/**
 * @brief Cierra el fichero y devuelve un 0 en caso de que se haya
 * cerrado correctamente.
 * 
 * @return int Representa el error, si es 0 quiere decir que todo está
 * correcto, en otro caso salta error.
 */
int File::closeFile() {
  fileGraph.close();
  return 0;
}

/**
 * @brief Este método se encarga de devolver el número de nodos
 * 
 * @return int Valor del número de nodos
 */
int File::getNumberNodes() {
  return nodeNumber;
}

/**
 * @brief Comprueba si la sintaxis del fichero es la correcta
 * 
 * @return std::vector <std::vector < std::pair <int, float> > > Devuelve un vector con la matriz
 * diagonal de la representación del grafo.
 */
std::vector < std::vector < float > > File::checkFileSyntax() {
  if(fileGraph.is_open()) {
    fileGraph >> nodeNumber;
    std::vector < std::vector < float > > graph;
    graph.resize(nodeNumber);
    for (int currentIndex = 0; currentIndex < nodeNumber; currentIndex++) {
      graph[currentIndex].resize(nodeNumber);
      for( int nextNode = currentIndex + 1; nextNode < nodeNumber; nextNode++) {
        fileGraph >> graph[currentIndex][nextNode];
      }
    }

    for (int currentIndex = 0; currentIndex < nodeNumber; currentIndex++) {
      for( int nextNode = currentIndex + 1; nextNode < nodeNumber; nextNode++) {
        graph[nextNode][currentIndex] = graph[currentIndex][nextNode];
      }
    }
  closeFile();
  return graph;
  }
}