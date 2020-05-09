
#include "../include/solution.hpp"
 /**
  * @brief  Construye la solución, a partir de un vector, un valor
  * y un nombre de un algoritmo
  * 
  * @param currentSolution Representa el vector que contiene la solución
  * @param currentMedia Representa el valor de la media de dispersión de la solución
  * @param newAlgorithmName Representa el nombre del algoritmo
  */
Solution::Solution(Vectors newData, std::vector <int> currentSolution, std::string newAlgorithmName):
  data(newData.getData()),
  solution(currentSolution) {
    algorithmName = newAlgorithmName;
}

/**
 * @brief Devuelve el vector de solución
 * 
 * @return std::vector <int> Vector de solución
 */
std::vector <int> Solution::getSolution() {
  return solution;
}

/**
 * @brief Devuelve el valor de la solución en la posición que
 * se haya obtenido por parámetro
 * 
 * @param position Posición a buscar en el vector
 * @return int Valor en la posición del vector
 */
int Solution::getSolutionValue(int position) {
  return solution[position];
}

/**
 * @brief Devuelve el tiempo de ejecución 
 * 
 * @return int Valor del tiempo de ejecución
 */
int Solution::getRunTime() {
  return runTime;
}

Vectors Solution::getInfo() {
  return data;
}

/**
 * @brief Devuelve el nombre del algoritmo de la solución
 * 
 * @return std::string Valor del nombre del nombre del algoritmo
 */
std::string Solution::getAlgorithmName() {
  return algorithmName;
}

/**
 * @brief Modifica el valor de tiempo de ejecución
 * 
 * @param newRunTime Nuevo tiempo de ejecución
 */
void Solution::setRunTime(int newRunTime) {
  runTime = newRunTime;
}

/**
 * @brief Representa la sobrecarga del operador <<, que va a hacer la impresión
 * de la solución
 * 
 * @param os Ostream para imprimir
 * @param currentSolution Solución que se va aimprimir
 * @return std::ostream& valor de impresión
 */
std::ostream& operator <<(std::ostream& os, Solution currentSolution) {
  std::cout << "La solución al aplicar el algoritmo " << currentSolution.getAlgorithmName() << " es:  \n";
  float maxValue = 0;
  std::vector <int> solution = currentSolution.getSolution();
  for (int i = 0; i < solution.size(); i++) {
    std::cout << "\n[" << solution[i] << "]: ";
    for (int j = 0; j < currentSolution.getInfo().getElementSize(i); j++) {
      std::cout << currentSolution.getInfo().getDataValue(solution[i],j) << " ";
    }
  }
  std::cout << "\n";

  float distance = 0;
  for(int i = 0; i < solution.size(); i++) {
    for(int j = i + 1; j < solution.size(); j++) {
      distance += currentSolution.getInfo().getEuclideanDistance(solution[i], solution[j]);
    }
  }

  std::cout << "Distancia: " << distance << "\n";  
  std::cout << "Run Time: " << currentSolution.getRunTime() << " microseconds \n";
  std::cout << " - - - - - - - - - - - - - - - - - - - \n";
}