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
 * ejecutándolos. Los métodos Grasp, Multiarraque y GVNS tienen un valor antes
 * del nombre que representa que tipo de búsqueda local quieren hacer. Si está un
 * 0 quiere decir que quieren hacer una búsqueda ansiosa, y si hay un 1 es local.
 * 
 * @return int Devuelvve un 0 si el programa se ha ejecutado correctamente.
 */
int main(void) {
  int iterations = 10;
  std::string fileName = "../ejemplos/max-mean-div-100.txt";
  Exec newExec(fileName);
  for(int i = 0; i < iterations; i++) {
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

    algoritmo = new GraspAlgorithm(0, "Grasp", 100, 10);
    newExec.changeAlgorithm(algoritmo);
    newExec.solve();
    delete algoritmo;
    
    algoritmo = new MultibootAlgorithm(1, "Multiarranque", 100, 10);
    newExec.changeAlgorithm(algoritmo);
    newExec.solve();
    delete algoritmo;
    
    algoritmo = new VariableNeighborhoodSearch(0, "GVNS", 1000, 50, 4);
    newExec.changeAlgorithm(algoritmo);
    newExec.solve();
    delete algoritmo;
    std::cout << "\n\n";
  }
  return 0;
}