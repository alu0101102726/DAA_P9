#pragma once
#include <vector>
#include "algorithm.hpp"
#include "vectors.hpp"
#include "file.hpp"
#include "solution.hpp"
#include <chrono>
#include <ctime>

/**
 * @brief Al aplicar el patrón Strategy, es necesario tener una clase que actúe
 * como context y que gestione las otras. En nuestro caso, la clase exec va a ser
 * la encargada de esto.
 * 
 */
class Exec {
  private:
    Vectors currentVectors;
    Algorithm *algorithm;

  public:
    Exec(std::string fileName);
    ~Exec() {}

    void changeAlgorithm(Algorithm *newAlgorithm);
    Vectors getData();
    void solve();
    std::chrono::time_point<std::chrono::system_clock> getRunTime();
};