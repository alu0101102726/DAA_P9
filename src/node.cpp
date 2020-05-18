#include "node.hpp"

/**
 * @brief Construye un objeto node a partir del valor de la distancia
 * del nodo y el valor de la cota superior
 * 
 * @param newValue Valor nuevo de la distancia del nodo
 * @param newUpperBound Valor de la cota superior
 */
Node::Node(float newValue, float newUpperBound):
  partialSol() {
    upperBound = newUpperBound;
    value = newValue;
    is_prun = false;
    visited = false;
}

/**
 * @brief Devuelve el valor de la cota superior del nodo
 * 
 * @return float valor de la cota superior del nodo
 */
float Node::getUpperBound() {
  return upperBound;
}

/**
 * @brief Modifica el valor de la cota superior del nodo
 * 
 * @param newUpperBound Nuevo del valor de la cota superior del nodo
 */
void Node::setUpperBound(float newUpperBound) {
  upperBound = newUpperBound;
}

/**
 * @brief Devuelve el valor de la distancia del nodo
 * 
 * @return float valor de la distancia del nodo
 */
float Node::getValue() {
  return value;
}

/**
 * @brief Modifica el valor de la distancia del nodo
 * 
 * @param newValue Nuevo valor de la distancia del nodo
 */
void Node::setValue(float newValue) {
  value = newValue;
}

/**
 * @brief Devuelve si el nodo está podado o no
 * 
 * @return true El nodo se ha podado
 * @return false El nodo NO se ha podado
 */
bool Node::isPrun() {
  return is_prun;
}

/**
 * @brief Modifica el estado de poda del nodo
 * 
 * @param newValue Nuevo valor de poda del nodo (true o false)
 */
void Node::setPruned(bool newValue) {
  is_prun = newValue;
}

/**
 * @brief Devuelve si el nodo está visitado o no
 * 
 * @return true El nodo se ha visitado
 * @return false El nodo NO se ha visitado
 */
bool Node::isVisited() {
  return visited;
}

/**
 * @brief Modifica el estado de visitado del nodo
 * 
 * @param newValue Nuevo valor de visitado del nodo (true o false)
 */
void Node::setVisited(bool newValue) {
  visited = newValue;
}

/**
 * @brief Devuelve la solución parcial asociada al nodo
 * 
 * @return std::vector<int> Valor de la solución parcial
 * del nodo
 */
std::vector<int> Node::getVector() {
  return partialSol;
}

/**
 * @brief Modifica la solución parcial asociada al nodo
 * 
 * @param newVect Nuevo valor de la solución parcial del nodo
 */
void Node::setVector(std::vector<int> newVect) {
  partialSol = newVect;
}

/**
 * @brief Representa la impresión del nodo
 * 
 * @param os Objeto para la impresion ostream
 * @param otherNode Nodo que se va a imprimir
 * @return std::ostream& Objeto para la impresion ostream
 */
std::ostream& operator<<(std::ostream& os, Node otherNode) {
  os << " Nodo [" << otherNode.getVector()[0] << "]: " << otherNode.getValue() << "\n";
  return os;
}
