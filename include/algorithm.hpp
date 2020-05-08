#pragma once
#include <vector>
#include <cmath>
#include "vectors.hpp"
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
    virtual Solution run() = 0;
    virtual void setInfo(Vectors newVector) = 0;
    float getMaxDiversity(Vectors currentVectors);
    std::vector <float> getGravityCenter(std::vector <int> currentElement, Vectors currentVector);
    float getEuclideanDistance(int firstVect, int secondVect, std::vector < std::vector <float> > data);
};
