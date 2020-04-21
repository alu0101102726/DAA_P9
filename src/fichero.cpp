#include "../include/fichero.hpp"

/**
 * @brief Construye un fichero y lo abre
 * 
 * @param nombreFichero Representa el nombre del fichero a abrir
 */
Fichero::Fichero(std::string nombreFichero) {
  ficheroGrafo.open(nombreFichero, std::fstream::out);
}

/**
 * @brief En caso de que el fichero esté abierto, lo cierra
 * 
 */
Fichero::~Fichero() {
  if(ficheroGrafo.is_open()){
      ficheroGrafo.close();
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
  ficheroGrafo.close();
  return 0;
}

/**
 * @brief Comprueba si la sintaxis del fichero es la correcta
 * 
 * @return std::vector <std::vector < std::pair <int, float> > > Devuelve un vector con la matriz
 * diagonal de la representación del grafo.
 */
std::vector <std::vector < float > > Fichero::comprobarSintaxis() {
  if(ficheroGrafo.is_open()) {
    int numVertices;
    ficheroGrafo >> numVertices;
    std::vector <std::vector < float > > grafoAlmacenado;
    grafoAlmacenado.resize(numVertices);
    for (int currentIndex = 0; currentIndex < numVertices; currentIndex++) {
      grafoAlmacenado[currentIndex].resize(numVertices);
      for (int nextNode = currentIndex + 1; nextNode < numVertices; nextNode++) {
        float info;
        ficheroGrafo >> info;
        grafoAlmacenado[currentIndex][nextNode] = (info);
      }
    }
  cerrarFichero();
  return grafoAlmacenado;
  }
}