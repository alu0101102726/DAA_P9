#include "../include/algorithm.hpp"

/**
 * @brief Devuelve el valor del centro de gravedad del vector actual
 * 
 * @param currentElement Representa el vector del que se va a calcular el centro
 * de gravedad (este también es un vector)
 * @return std::vector <float> Valor del centro de gravedad calculado
 */
std::vector <float> Algorithm::getGravityCenter(std::vector <int> currentElement) {
  std::vector <float> center;
  for (int index = 0; index < currentVectors.getDimension(); index++) {
    float currentSum = 0;
    for (int i = 0; i < currentElement.size(); i++) {
      currentSum += currentVectors.getDataValue(currentElement[i], index);
    }
    center.push_back(currentSum / currentElement.size());
  }
  return center;
}

/**
 * @brief Se encarga de inicializar la información recogida del fichero,
 * es decir, los vectores y asignarlos al atributo de la clase que lo va
 * a almacenar.
 * 
 * @param newVector El elemento que se va a asignar
 */
void Algorithm::setInfo(Vectors newVector) {
  currentVectors = newVector;
}