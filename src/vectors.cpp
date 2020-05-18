#include "vectors.hpp"

/**
 * @brief Construye el objeto donde vamos a guardar la información del fichero
 * 
 * @param fileName Nombre del fichero
 */
Vectors::Vectors(std::string fileName) {
  File newFile(fileName);
  data = newFile.checkFileSyntax();
  dimension = data[0].size();
}

/**
 * @brief Construct de copia Vectors object
 */
Vectors::Vectors(std::vector < std::vector < float > > otherVect) {
  data = otherVect;
}

/**
 * @brief Devuelve el valor de la dimensión
 * 
 * @return int Valor de la dimensión
 */
int Vectors::getDimension() {
  return dimension;
}

/**
 * @brief Devuelve el valor del vector en la posición currentElement, K
 * 
 * @param currentElement Representa el vector a elegir
 * @param K Representa dentro del vector el valor a obtener
 * @return float 
 */
float Vectors::getDataValue(int currentElement, int K) {
  return data[currentElement][K];
}

/**
 * @brief Devuelve el tamaño del vector
 * 
 * @return int Valor de la distancia
 */
int Vectors::getSize() {
  return data.size();
}

/**
 * @brief Devuelve el vector que contiene la información
 * 
 * @return std::vector < std::vector < float > > vector con la información
 */
std::vector < std::vector < float > > Vectors::getData() {
  return data;
}

/**
 * @brief Devuelve el tamaño del vector en la posición pasada por parámetro
 * 
 * @param position Posicion para elegir el vector del que se obtiene la distancia
 * @return int Valor de la distancia
 */
int Vectors::getElementSize(int position) {
  return data[position].size();
}

/**
 * @brief Devuelve el valor de la distancia euclídea obtenida
 * 
 * @param firstVect Representa el primer vector del que se va a calcular la distancia euclídea
 * @param secondVect Representa el segundo vector del que se va a calcular la distancia euclídea
 * @return float Valor de la distancia euclídea
 */
float Vectors::getEuclideanDistance(int firstVect, int secondVect) {
  float sumVal = 0;
  for (int currentElement = 0; currentElement < data[firstVect].size(); currentElement++) {
    sumVal += pow((data[firstVect][currentElement] - data[secondVect][currentElement]), 2);
  }
  return sqrt(sumVal);
}

/**
 * @brief Esta funcion se encarga de la impresion de la información almacenada
 * 
 * @param os Representa la salida
 * @param currentData El elemento del que se va a imprimir su información
 * @return std::ostream& 
 */
std::ostream& operator <<(std::ostream& os, Vectors currentData) {
  for (int currentIndex = 0; currentIndex < currentData.getSize(); currentIndex++) {
    os << currentIndex << " \t";
    for( int nextNode = 0; nextNode < currentData.getElementSize(currentIndex); nextNode++) {
      os << currentData.getDataValue(currentIndex, nextNode) << " ";
    }
    os << "\n";
  }
  return os;
}