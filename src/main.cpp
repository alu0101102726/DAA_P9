#include "exec.hpp"
#include "greedy-algorithm.hpp"
#include "second-greedy-algorithm.hpp"
#include "grasp-algorithm.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

int main(void) {
  std::string fileName = "../ejemplos/max-mean-div-10.txt";
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
}