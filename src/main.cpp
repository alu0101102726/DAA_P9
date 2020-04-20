#include "../include/fichero.hpp"
#include <iostream>
#include <vector>
#include <utility>

int main(void) {
  std::string nombreFichero = "../ejemplos/max-mean-div-10.txt";
  Fichero nuevoGrafo(nombreFichero);
  std::vector < std::vector < std::pair <int, float> > > grafo = nuevoGrafo.comprobarSintaxis();
    for (int currentIndex = 0; currentIndex < grafo.size(); currentIndex++) {
      for (int nextNode = 0; nextNode < grafo[currentIndex].size(); nextNode++) {
        std::cout << "(" << currentIndex << "," << grafo[currentIndex][nextNode].first << ") val: " << grafo[currentIndex][nextNode].second << " | ";
      }
      std::cout << "\n";
    }
}