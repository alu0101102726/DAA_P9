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
 * ejecutándolos. Los métodos Grasp, LocalSearch y Branching and Pruning tienen
 * algunos atributos añadidos, como lo son el tamaño del LRC, el tamaño de la
 * solución y el numero de iteraciones. Además para el algoritmo de ramificación y poda
 * hay un booleano que determina si se coge la menor cota (booleano a false) o si
 * se utiliza la función de profundidad (booleano a true).
 * 
 * @return int Devuelvve un 0 si el programa se ha ejecutado correctamente.
 */
int main(void) {
  srand(time(NULL));
  
  int totalIterations = 10, lrc = 3, m = 3;
  bool isDepth = true;
  std::string fileName = "../ejemplos/";
  std::string newFileName;
  system("clear");
  std::cout << "Introduce el grafo a ejecutar: \n";
  std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
  std::cout << "Grafos disponibles: \n";
  system("ls ../ejemplos");
  std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
  std::cout << " >> "; std::cin >> newFileName;
  fileName += newFileName;

  try {
    File file(fileName);
  }
  catch (const std::exception& e) {
     std::cout << e.what();   
  }
Exec newExec(fileName);  

  Algorithm *algoritmo = new GreedyAlgorithm("Greedy", m);
  algoritmo->setInfo(newExec.getData());

  newExec.changeAlgorithm(algoritmo);
  Solution Greedy = newExec.solve();
  delete algoritmo;

  algoritmo = new NewGreedyAlgorithm("New Greedy", m);
  algoritmo->setInfo(newExec.getData());

  newExec.changeAlgorithm(algoritmo);
  newExec.solve();
  delete algoritmo;

  algoritmo = new GraspAlgorithm("Grasp", totalIterations, m, lrc);
  algoritmo->setInfo(newExec.getData());

  newExec.changeAlgorithm(algoritmo);
  newExec.solve();
  delete algoritmo;

  algoritmo = new LocalSearch("Local Search", m, "Greedy", Greedy);
  algoritmo->setInfo(newExec.getData());

  newExec.changeAlgorithm(algoritmo);
  newExec.solve();
  delete algoritmo;

  algoritmo = new BranchingPruningAlgorithm("Branching and Pruning", m, Greedy, isDepth);
  algoritmo->setInfo(newExec.getData());

  newExec.changeAlgorithm(algoritmo);
  newExec.solve();
  delete algoritmo;

  return 0;
}