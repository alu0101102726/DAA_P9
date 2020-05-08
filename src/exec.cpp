
#include "../include/exec.hpp"

/**
 * @brief Construye un nuevo exec, llama al constructor del
 * grafo que se va a encargar de llamar al fichero y gestionar
 * todo.
 * 
 * @param fileName Nombre del fichero
 */
Exec::Exec(std::string fileName):
  currentVectors(fileName) {}


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

/**
 * @brief Devuelve un vector con la información
 * 
 * @return Vectors 
 */
Vectors Exec::getData() {
  return currentVectors;
}

/**
 * @brief Devuelve el tiempo de ejecución actual
 * 
 * @return std::chrono::time_point<std::chrono::system_clock> Tiempo actual 
 */
std::chrono::time_point<std::chrono::system_clock> Exec::getRunTime() {
  return std::chrono::system_clock::now();
}

/**
 * @brief Programa principal que se encarga de calcular el tiempo de ejecución
 * de un determinado algoritmo, realizar el mismo e imprimir su solución, así como
 * el tiempo que ha tardado en ejecutarlo
 * 
 */
void Exec::solve() {
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = getRunTime();
  algorithm->setInfo(getData());
  Solution solution = algorithm->run();
  end = getRunTime();
  solution.setRunTime(std::chrono::duration_cast<std::chrono::microseconds>(end-start).count());
  std::cout << solution;
  
}