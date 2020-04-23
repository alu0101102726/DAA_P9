
#include "../include/exec.hpp"

/**
 * @brief Construye un nuevo exec, llama al constructor del
 * grafo que se va a encargar de llamar al fichero y gestionar
 * todo.
 * 
 * @param fileName Nombre del fichero
 */
Exec::Exec(std::string fileName):
  currentGraph(fileName) {}


/**
 * @brief Se encarga de cambiar el algoritmo con el que se 
 * pasa por parámetro.
 * 
 * 
 * @param newAlgorithm Representa el algoritmo al que se va a
 * cambiar.
 */
void Exec::changeAlgorithm(Algorithm *newAlgorithm) {
  algorithm = newAlgorithm;
}


Graph Exec::getGraph() {
  return currentGraph;
}