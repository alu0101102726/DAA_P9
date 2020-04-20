#include "../include/fichero.hpp"

/**
 * @brief Construye un fichero y lo abre
 * 
 * @param nombreFichero Representa el nombre del fichero a abrir
 */
Fichero::Fichero(std::string nombreFichero) {
  grafo.open(nombreFichero, std::fstream::out);
}

/**
 * @brief En caso de que el fichero esté abierto, lo cierra
 * 
 */
Fichero::~Fichero() {
  if(grafo.is_open()){
      grafo.close();
  }
}

/**
 * @brief Cierra el fichero y devuelve un 0 en caso de que se haya
 * cerrado correctamente.
 * 
 * @return int Representa el error, si es 0 quiere decir que todo está
 * correcto, en otro caso salta error.
 */
int Fichero::cerrarFichero() {
  grafo.close();
  return 0;
}

/**
 * @brief Comprueba si la sintaxis del fichero es la correcta
 * 
 * @return std::vector <std::vector < std::pair <int, float> > > Devuelve un vector con la matriz
 * diagonal de la representación del grafo.
 */
std::vector <std::vector < std::pair <int, float> > > Fichero::comprobarSintaxis() {
  if(grafo.is_open()) {
    int numVertices;
    grafo >> numVertices;
    std::vector <std::vector < std::pair <int, float> > > grafoAlmacenado;
    grafoAlmacenado.resize(numVertices);
    for (int currentIndex = 0; currentIndex < numVertices; currentIndex++) {
      for (int nextNode = currentIndex + 1; nextNode < numVertices; nextNode++) {
        std::pair<int, float> info;
        grafo >> info.second;
        info.first = nextNode;
        grafoAlmacenado[currentIndex].push_back(info);
      }
    }
  cerrarFichero();
  return grafoAlmacenado;
  }
}