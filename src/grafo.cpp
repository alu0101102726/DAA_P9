#include "../include/grafo.hpp"
#include "../include/fichero.hpp"
#include <string>

/**
 * @brief Construye un objeto grafo y almacena la información
 * de los nodos y sus distancias en su atributo informacion
 * 
 * @param nombreFichero Representa el nombre del fichero que se
 * va a abrir para poder extraer los datos.
 */
Grafo::Grafo(std::string nombreFichero) {
  Fichero nuevoFichero(nombreFichero);
  informacion = nuevoFichero.comprobarSintaxis();
}

/**
 * @brief Esta funcion se encarga de cambiar entre los distintos
 * algoritmos, cambiando al que obtiene por parámetro.
 * 
 * @param nuevoAlgoritmo Representa el algoritmo por el que se va
 * a cambiar.
 */
void Grafo::cambiarAlgoritmo(Algoritmo  *nuevoAlgoritmo) {
  algoritmo = nuevoAlgoritmo;
}

/**
 * @brief Se encarga de devolver el valor de la distancia que hay entre
 * el nodo i, y el nodo j, o viceversa.
 * 
 * @param i Nodo necesario para obtener la distancia entre este y otro.
 * @param j Nodo necesario para obtener la distancia entre este y otro.
 * @return float Devuelve el valor de la distancia
 */
float Grafo::getDatoNodo(int i, int j) {
  return informacion[i][j];
}

/**
 * @brief Se encarga de devolver el tamaño del vector
 * 
 * @return int Valor del tamaño del vector
 */
int Grafo::getTamano() {
  return informacion.size();
}

/**
 * @brief Sobrecarga del operador de salida para poder mostrar el grafo
 * 
 * @param os Representa el std::cout para la impresión
 * @param grafoImprimir El grafo que se va a imprimir
 * @return std::ostream& Valor de lo que ha impreso
 */
std::ostream& operator <<(std::ostream& os, Grafo grafoImprimir) {
  for (int currentIndex = 0; currentIndex < grafoImprimir.getTamano(); currentIndex++) {
    for (int nextNode = currentIndex + 1; nextNode < grafoImprimir.getTamano(); nextNode++) {
      os << "(" << currentIndex << "," << nextNode << ") val: " << grafoImprimir.getDatoNodo(currentIndex, nextNode) << " | ";
    }
    os << "\n";
  }
  return os;
}
