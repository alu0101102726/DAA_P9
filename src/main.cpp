#include "../include/fichero.hpp"
#include "../include/grafo.hpp"
#include <iostream>
#include <vector>
#include <utility>

int main(void) {
  std::string nombreFichero = "../ejemplos/max-mean-div-10.txt";
  Grafo nuevoGrafo(nombreFichero);
  std::cout << nuevoGrafo;
}