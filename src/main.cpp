#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <ctime>
#include "solution.hpp"
#include "file.hpp"
#include "exec.hpp"
#include "algorithm.hpp"
#include "greedy-algorithm-2.hpp"
#include "grasp-algorithm.hpp"
#include "local-search-algorithm.hpp"
#include "branching-pruning-algorithm.hpp"

/**
 * @brief Función principal del programa que se encarga de hacer
 * la lectura del fichero (creando el pertinente objeto y haciendo
 * una llamada a un método definido en el mismo que lo gestiona), luego
 * crea exec, que es un objeto que se encarga de gestionar los algoritmos,
 * impresiones, etc. Y para acabar va llamando a los diferentes algoritmos,
 * ejecutándolos. Los métodos Grasp, Multiarraque y GVNS tienen un valor antes
 * del nombre que representa que tipo de búsqueda local quieren hacer. Si está un
 * 0 quiere decir que quieren hacer una búsqueda ansiosa, y si hay un 1 es local.
 * 
 * @return int Devuelvve un 0 si el programa se ha ejecutado correctamente.
 */
int main(void) {
  srand(time(NULL));
  
  int totalIterations, noImprovementIterations = 100, improvementIterations = 1000, env = 3, defaultValues;
  int localSearch = 0;
  std::string fileName = "../ejemplos/max_div_15_2.txt";
  // std::string newFileName;
  // system("clear");
  // std::cout << "Introduce el grafo a ejecutar: \n";
  // std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
  // std::cout << "Grafos disponibles: \n";
  // system("ls ../ejemplos");
  // std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
  // std::cout << " >> "; std::cin >> newFileName;
  // fileName += newFileName;

  // try {
  //   File file(fileName);
  // }
  // catch (const std::exception& e) {
  //    std::cout << e.what();   
  // }

  Exec newExec(fileName);
  Algorithm* algoritmo = new GreedyAlgorithm("Greedy", 6);
  algoritmo->setInfo(newExec.getData());

  newExec.changeAlgorithm(algoritmo);
  Solution Greedy = newExec.solve();
  delete algoritmo;

  algoritmo = new NewGreedyAlgorithm("New Greedy", 3);
  algoritmo->setInfo(newExec.getData());

  newExec.changeAlgorithm(algoritmo);
  newExec.solve();
  delete algoritmo;

  algoritmo = new GraspAlgorithm("Grasp", 10, 3, 2);
  algoritmo->setInfo(newExec.getData());

  newExec.changeAlgorithm(algoritmo);
  newExec.solve();
  delete algoritmo;

  algoritmo = new LocalSearch("Local Search", 3, "Greedy", Greedy);
  algoritmo->setInfo(newExec.getData());

  newExec.changeAlgorithm(algoritmo);
  newExec.solve();
  delete algoritmo;

  algoritmo = new BranchingPruningAlgorithm("BPA", 6, Greedy, true);
  algoritmo->setInfo(newExec.getData());

  newExec.changeAlgorithm(algoritmo);
  newExec.solve();
  delete algoritmo;

  return 0;
}