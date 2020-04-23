#include "../include/exec.hpp"
#include "../include/gready-algorithm.hpp"
#include <iostream>
#include <vector>
#include <utility>

int main(void) {
  std::string fileName = "../ejemplos/max-mean-div-10.txt";
  Exec newExec(fileName);
  Algorithm *algoritmo = new GreedyAlgorithm();
  std::vector <int> sol;
  sol = algoritmo->run(newExec.getGraph());
  for(int i = 0; i < sol.size(); i++) {
    std::cout << sol[i] << " ";
  }
}