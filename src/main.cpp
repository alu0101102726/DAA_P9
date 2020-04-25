#include "exec.hpp"
#include "greedy-algorithm.hpp"
#include "second-greedy-algorithm.hpp"
#include "grasp-algorithm.hpp"
#include "multiboot-algorithm.hpp"
#include "variable-neighborhood-search-algorithm.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

/**
 * @brief Función principal del programa que se encarga de hacer
 * la lectura del fichero (creando el pertinente objeto y haciendo
 * una llamada a un método definido en el mismo que lo gestiona), luego
 * crea exec, que es un objeto que se encarga de gestionar los algoritmos,
 * impresiones, etc. Y para acabar va llamando a los diferentes algoritmos,
 * ejecutándolos.
 * 
 * @return int Devuelvve un 0 si el programa se ha ejecutado correctamente.
 */
int main(void) {
  std::string fileName = "../ejemplos/max-mean-div-15.txt";
  Exec newExec(fileName);
  Algorithm *algoritmo = new GreedyAlgorithm("Greedy");
  newExec.changeAlgorithm(algoritmo);
  newExec.solve();
  delete algoritmo;

  algoritmo = new SecondGreedyAlgorithm("Segundo Greedy");
  newExec.changeAlgorithm(algoritmo);
  newExec.solve();
  delete algoritmo;

  algoritmo = new GraspAlgorithm("Grasp", 1000, 50);
  newExec.changeAlgorithm(algoritmo);
  newExec.solve();
  delete algoritmo;
  
  algoritmo = new MultibootAlgorithm("Multiarranque", 1000, 50);
  newExec.changeAlgorithm(algoritmo);
  newExec.solve();
  delete algoritmo;
  
  algoritmo = new VariableNeighborhoodSearch("GVNS", 1000, 50, 10);
  newExec.changeAlgorithm(algoritmo);
  newExec.solve();
  delete algoritmo;

  return 0;
}