#pragma once
#include <vector>
#include <cmath>
#include "graph.hpp"
#include "solution.hpp"

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
    virtual Solution run(Graph currentGraph) = 0;
    float getMeanDispersion(std::vector<int> solution, Graph currentGraph);
    int getWorstMeanDispersionGreedy(std::vector<int> actualSolution, Graph currentGraph);
    int getWorstMeanDispersionAnxious(std::vector<int> actualSolution, Graph currentGraph);
    float getNewMeanDispersionErase(std::vector<int> solution, float currentEdgeSum, int currentNode, Graph currentGraph);
    void printSolution(std::vector<int> solution, int runTime, Graph currentGraph);
};
