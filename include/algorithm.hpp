#pragma once
#include <vector>
#include "graph.hpp"

/**
 * @brief Representa una clase que va a permitir aplicar
 * el patrón estrategia 
 */
class Algorithm {

	public:
    /**
    * @brief Representa el método que es virtual y nulo que va a ser
    * sobreescrito por las clases hijas, debido a que todos los algoritmos
    * que se van a ejecutar son similares pero funcionan de forma distinta
    * 
    * @return int Que contiene la mejor solucion
    */
    virtual std::vector <int> run(Graph currentGraph) = 0;
    float getMedianDispersion(std::vector<int> solution, Graph currentGraph);

};
