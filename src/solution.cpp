
#include "../include/solution.hpp"
 /**
  * @brief  Construye la solución, a partir de un vector, un valor
  * y un nombre de un algoritmo
  * 
  * @param currentSolution Representa el vector que contiene la solución
  * @param currentMedia Representa el valor de la media de dispersión de la solución
  * @param newAlgorithmName Representa el nombre del algoritmo
  */
Solution::Solution(std::vector <int> currentSolution, float currentMedia, std::string newAlgorithmName):
  solution(currentSolution) {
    mediaValue = currentMedia;
    algorithmName = newAlgorithmName;
}

/**
 * @brief Devuelve el valor de la media de dispersión
 * 
 * @return float Valor de la media de dispersión
 */
float Solution::getMedia () {
  return mediaValue;
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
  std::cout << "La solución al aplicar el algoritmo " << currentSolution.getAlgorithmName() << " es: S = { ";
  for(int i = 0; i < currentSolution.solution.size(); i++) {
    std::cout << currentSolution.getSolutionValue(i) << " ";
  }
  std::cout << "} \n";
  std::cout << "Median dispersion: " << currentSolution.getMedia() << "\n";
  std::cout << "Run Time: " << currentSolution.getRunTime() << " milliseconds \n";
  std::cout << " - - - - - - - - - - - - - - - - - - - \n";
}