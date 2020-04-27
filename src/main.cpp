#include "exec.hpp"
#include "greedy-algorithm.hpp"
#include "second-greedy-algorithm.hpp"
#include "grasp-algorithm.hpp"
#include "multiboot-algorithm.hpp"
#include "variable-neighborhood-search-algorithm.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <ctime>

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
  system("clear");
  std::cout << " - - PRÁCTICA 8: MAX-MEAN DISPERSION PROBLEM - -\n";
  std::cout << " Autor: Carlos Díaz Calzadilla \n";
  std::cout << " Introduce el número de iteraciones a ejecutar por cada algoritmo: " << "\n >> ";
  std::cin >> totalIterations;

  std::cout << "\n Introduce un 0 para usar los valores por defecto y otro número real para modificarlos:\n ";
  std::cout << "\t- Iteraciones sin mejora -> " << noImprovementIterations << "\n";
  std::cout << "\t- Iteraciones con mejora -> " << improvementIterations << "\n";
  std::cout << "\t- Tamaño del entorno (VNS) -> " << env << "\n";
  std::cout << "\t- Busqueda Local (0: Greedy | 1: Ansioso) -> " << localSearch << "\n" << " >> ";
  std::cin >> defaultValues;

  if (defaultValues != 0) {
    std::cout << "\n\t- Iteraciones sin mejora -> "; std::cin >> noImprovementIterations;
    std::cout << "\n\t- Iteraciones con mejora -> "; std::cin >> improvementIterations;
    std::cout << "\n\t- Tamaño del entorno (VNS) -> "; std::cin >> env;
    std::cout << "\n\t- Busqueda Local (0: Greedy | 1: Ansioso) -> "; std::cin >> localSearch;
  }

  std::cout << "\n";
  system("clear");
  for(int i = 0; i < totalIterations; i++) {
    std::cout << " - - - - - - - - - - ITERACION [" << i + 1 << "] - - - - - - - - - - \n";
    std::cout << "El numero de nodos es: " << newExec.getGraph().gentNodeNumber() << "\n\n";
    Algorithm *algoritmo = new GreedyAlgorithm("Greedy");
    newExec.changeAlgorithm(algoritmo);
    newExec.solve();
    delete algoritmo;

    algoritmo = new SecondGreedyAlgorithm("Segundo Greedy");
    newExec.changeAlgorithm(algoritmo);
    newExec.solve();
    delete algoritmo;

    algoritmo = new GraspAlgorithm(localSearch, "Grasp", improvementIterations, noImprovementIterations);
    newExec.changeAlgorithm(algoritmo);
    newExec.solve();
    delete algoritmo;
    
    algoritmo = new MultibootAlgorithm(localSearch, "Multiarranque", improvementIterations, noImprovementIterations);
    newExec.changeAlgorithm(algoritmo);
    newExec.solve();
    delete algoritmo;
    
    algoritmo = new VariableNeighborhoodSearch(localSearch, "VNS", improvementIterations, noImprovementIterations, env);
    newExec.changeAlgorithm(algoritmo);
    newExec.solve();
    delete algoritmo;
    std::cout << "\n\n";
  }
  return 0;
}