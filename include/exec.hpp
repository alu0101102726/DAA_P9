#pragma once
#include <vector>
#include "algorithm.hpp"
#include "graph.hpp"
#include "file.hpp"

/**
 * @brief Al aplicar el patrón Strategy, es necesario tener una clase que actúe
 * como context y que gestione las otras. En nuestro caso, la clase exec va a ser
 * la encargada de esto.
 * 
 */
class Exec {
  private:
    Graph currentGraph;
    Algorithm *algorithm;

  public:
    Exec(std::string fileName);
    ~Exec() {}

    void changeAlgorithm(Algorithm *newAlgorithm);
    Graph getGraph();
};